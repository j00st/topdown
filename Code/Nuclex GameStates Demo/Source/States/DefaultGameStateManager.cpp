#pragma region CPL License
/*
Nuclex Native Framework
Copyright (C) 2002-2013 Nuclex Development Labs

This library is free software; you can redistribute it and/or
modify it under the terms of the IBM Common Public License as
published by the IBM Corporation; either version 1.0 of the
License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
IBM Common Public License for more details.

You should have received a copy of the IBM Common Public
License along with this library
*/
#pragma endregion // CPL License

// If the library is compiled as a DLL, this ensures symbols are exported
#define NUCLEX_GAME_SOURCE 1

#include "DefaultGameStateManager.h"
#include "GameState.h"

#include <stdexcept>

namespace Nuclex { namespace Game { namespace States {

  // ------------------------------------------------------------------------------------------- //

  DefaultGameStateManager::DefaultGameStateManager() {}

  // ------------------------------------------------------------------------------------------- //

  DefaultGameStateManager::~DefaultGameStateManager() {
    while(!this->activeStates.empty()) {
      Pop();
    }
  }

  // ------------------------------------------------------------------------------------------- //

  std::shared_ptr<GameState> DefaultGameStateManager::Peek() const {
    if(this->activeStates.empty()) {
      return std::shared_ptr<GameState>();
    } else {
      return this->activeStates.at(this->activeStates.size() - 1).first;
    }
  }

  // ------------------------------------------------------------------------------------------- //

  void DefaultGameStateManager::Push(
    const std::shared_ptr<GameState> &state, Modality::Enum modality /* = Modality::Exclusive */
  ) {
    this->activeStates.push_back(std::make_pair(state, modality));

    if(modality == Modality::Exclusive) {
      this->exposedDrawables.clear();
      this->exposedUpdateables.clear();
    }

    addToDrawablesOrUpdateables(state.get());

    notifyObscuredStates();

    state->Entered();
  }

  // ------------------------------------------------------------------------------------------- //

  std::shared_ptr<GameState> DefaultGameStateManager::Pop() {
    if(this->activeStates.empty()) {
      throw std::runtime_error("Attempted to pop from an empty game state stack");
    }

    GameStateModalityPair popped = this->activeStates.at(this->activeStates.size() - 1);
    popped.first->Exiting();
    this->activeStates.pop_back();

    if(popped.second == Modality::Exclusive) {
      rebuildUpdateableAndDrawableQueues();
    } else {
      removeFromDrawablesOrUpdateables(popped.first.get());
    }

    notifyRevealedStates();

    return popped.first;
  }

  // ------------------------------------------------------------------------------------------- //

  void DefaultGameStateManager::Update(float elapsedTime) {
    for(std::size_t index = 0; index < this->exposedUpdateables.size(); ++index) {
      this->exposedUpdateables.at(index)->Update(elapsedTime);
    }
  }

  // ------------------------------------------------------------------------------------------- //

  void DefaultGameStateManager::Draw(float elapsedFrameTime) {
    for(std::size_t index = 0; index < this->exposedDrawables.size(); ++index) {
      this->exposedDrawables.at(index)->Draw(elapsedFrameTime);
    }
  }

  // ------------------------------------------------------------------------------------------- //

  void DefaultGameStateManager::addToDrawablesOrUpdateables(GameState *gameState) {
    Drawable *drawable = dynamic_cast<Drawable *>(gameState);
    if(drawable) {
      this->exposedDrawables.push_back(drawable);
    }

    Updateable *updateable = dynamic_cast<Updateable *>(gameState);
    if(updateable) {
      this->exposedUpdateables.push_back(updateable);
    }
  }

  // ------------------------------------------------------------------------------------------- //

  void DefaultGameStateManager::removeFromDrawablesOrUpdateables(GameState *gameState) {
    Drawable *drawable = dynamic_cast<Drawable *>(gameState);
    if(drawable) {
      this->exposedDrawables.pop_back();
    }

    Updateable *updateable = dynamic_cast<Updateable *>(gameState);
    if(updateable) {
      this->exposedUpdateables.pop_back();
    }
  }

  // ------------------------------------------------------------------------------------------- //

  void DefaultGameStateManager::rebuildUpdateableAndDrawableQueues() {
    this->exposedUpdateables.clear();
    this->exposedDrawables.clear();

    if(this->activeStates.empty()) {
      return;
    }

    // Reverse scan the active states until we hit either the beginning or an Hiding state
    std::size_t index = this->activeStates.size() - 1;
    while(index > 0) {
      if(this->activeStates.at(index).second == Modality::Exclusive) {
        break;
      }
      --index;
    }

    // Now go forward again and fill the lists of exposed Updateables and Drawables
    while(index < this->activeStates.size()) {
      addToDrawablesOrUpdateables(this->activeStates.at(index).first.get());
      ++index;
    }
  }

  // ------------------------------------------------------------------------------------------- //

  void DefaultGameStateManager::notifyObscuredStates() {
    if(this->activeStates.size() < 2) {
      return;
    }

    // Reverse scan until we hit either the beginning or find the next Hiding state
    std::size_t index = this->activeStates.size() - 2;
    while(index > 0) {
      if(this->activeStates.at(index).second == Modality::Exclusive) {
        break;
      }
      --index;
    }

    // Now go forward (up until the second-to-last state) and notify the obscured states
    while(index < this->activeStates.size() - 1) {
      this->activeStates.at(index).first->Obscuring();
    }
  }

  // ------------------------------------------------------------------------------------------- //

  void DefaultGameStateManager::notifyRevealedStates() {
    if(this->activeStates.empty()) {
      return;
    }

    // Reverse scan until we hit either the beginning or find the next Hiding state
    std::size_t index = this->activeStates.size() - 1;
    while(index > 0) {
      if(this->activeStates.at(index).second == Modality::Exclusive) {
        break;
      }
      --index;
    }

    // Now go forward and notify all revealed state
    while(index < this->activeStates.size()) {
      this->activeStates.at(index).first->Revealed();
    }
  }

  // ------------------------------------------------------------------------------------------- //

}}} // namespace Nuclex::Game::States

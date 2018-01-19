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

#ifndef NUCLEX_GAME_STATES_GAMESTATEMANAGER_H
#define NUCLEX_GAME_STATES_GAMESTATEMANAGER_H

#include <memory>

#include "Modality.h"

namespace Nuclex { namespace Game { namespace States {

  // ------------------------------------------------------------------------------------------- //

  class GameState; // forward declaration so we don't need the header

  // ------------------------------------------------------------------------------------------- //

  /// <summary>Interface for a stack-based game state manager</summary>
  class GameStateManager {

    /// <summary>
    ///   Destroys the game state manager, leaving and dropping any active game state
    /// </summary>
    public: virtual ~GameStateManager() {}

    /// <summary>Returns the currently active game state</summary>
    /// <returns>The lastmost game state on the stack</returns>
    public: virtual std::shared_ptr<GameState> Peek() const = 0;

    /// <summary>Appends a new game state to the stack</summary>
    /// <param name="state">Game state that will be pushed onto the stack</param>
    /// <param name="modality">Whether the state completely obscures the state below it</param>
    public: virtual void Push(
      const std::shared_ptr<GameState> &state, Modality::Enum modality = Modality::Exclusive
    ) = 0;

    /// <summary>Removes the lastmost game state from the stack</summary>
    /// <returns>The state that has been removed from the stack</returns>
    public: virtual std::shared_ptr<GameState> Pop() = 0;

    /// <summary>Replaces the lastmost game state on the stack</summary>
    /// <param name="state">State the lastmost state on the stack will be replaced with</param>
    /// <param name="modality">Whether the state completely obscures the state below it</param>
    /// <returns>The previously lastmost state on the stack that was replaced</returns>
    /// <remarks>
    ///   This method is mostly just syntactic sugar for a call to Pop() followed by Push(),
    ///   except that it will also work if the game state stack is currently empty, in which
    ///   case it will equal the Push() method and return an empty smart pointer.
    /// </remarks>
    public: virtual std::shared_ptr<GameState> Switch(
      const std::shared_ptr<GameState> &state, Modality::Enum modality = Modality::Exclusive
    ) {
      std::shared_ptr<GameState> currentState = Peek();
      if(currentState) {
        Pop();
      }

      Push(state, modality);

      return currentState;
    }

  };

  // ------------------------------------------------------------------------------------------- //

}}} // namespace Nuclex::Game::States

#endif // NUCLEX_GAME_STATES_GAMESTATEMANAGER_H

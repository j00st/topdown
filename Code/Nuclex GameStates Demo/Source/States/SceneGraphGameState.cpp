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

#include "Nuclex/Game/States/SceneGraphGameState.h"
#include <cassert>

namespace Nuclex { namespace Game { namespace States {

  // ------------------------------------------------------------------------------------------- //

  SceneGraphGameState::SceneGraphGameState() :
    areSceneNodesAdded(false),
    areSceneNodesCreated(false) {}

  // ------------------------------------------------------------------------------------------- //

  SceneGraphGameState::~SceneGraphGameState() {
    using namespace std;

    assert(
      !this->areSceneNodesCreated &&
      "Game state was destroyed while it was still active (scene nodes created). "
      "Sorry, the destructor of the SceneGraphGameState cannot call your virtual "
      "DoDetachSceneNodes() or DoCreateSceneNodes() methods, so it's up to your "
      "game state manager to exit its game states before destroying them."
    );
  }

  // ------------------------------------------------------------------------------------------- //

}}} // namespace Nuclex::Game::States

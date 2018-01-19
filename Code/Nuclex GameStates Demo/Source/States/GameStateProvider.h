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

#ifndef NUCLEX_GAME_STATES_GAMESTATEPROVIDER_H
#define NUCLEX_GAME_STATES_GAMESTATEPROVIDER_H

#include <memory>
#include <string>

namespace Nuclex { namespace Game { namespace States {

  // ------------------------------------------------------------------------------------------- //

  class GameState; // forward declaration so we don't need the header

  // ------------------------------------------------------------------------------------------- //

  /// <summary>
  ///   Repository interface for game states so they can be retrieved from a central place
  /// </summary>
  /// <remarks>
  ///   <para>
  ///     This is just an interface provided so you don't end up with additional dependencies
  ///     if you manage game states by name and you want to let your states switch to other
  ///     states on their own.
  ///   </para>
  ///   <para>
  ///     The implementation is free to handle construction and destruction of game states
  ///     as needed. An intelligent game state provider might keep game states that are
  ///     often used alive once constructed and only destroy those states that use up
  ///     a large amount of memory.
  ///   </para>
  ///   <para>
  ///     Identifying game states by name gives the added benefit of not hardcoding which
  ///     states are used for which role. It is thinkable, for example, to use a completely
  ///     different main menu on gaming consoles. If the main menu is obtainable through
  ///     the game state provider under the name "main menu", the logic for deciding which
  ///     type of menu to use on what system doesn't seep into the game states themselves.
  ///   </para>
  /// </remarks>
  class GameStateProvider {

    /// <summary>Destroys the game state manager</summary>
    public: virtual ~GameStateProvider() = 0;

    /// <summary>Provides the state with the specified name</summary>
    /// <param name="name">Name of the game state that will be provided</param>
    /// <returns>A new game or reused game state registered under the specified name</returns>
    public: virtual std::shared_ptr<GameState> GetGameState(const std::string &name) = 0;

  };

  // ------------------------------------------------------------------------------------------- //

}}} // namespace Nuclex::Game::States

#endif // NUCLEX_GAME_STATES_GAMESTATEPROVIDER_H

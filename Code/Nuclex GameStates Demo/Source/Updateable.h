#pragma region CPL License
/*
Nuclex Native Framework
Copyright (C) 2002-2012 Nuclex Development Labs

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

#ifndef NUCLEX_GAME_UPDATEABLE_H
#define NUCLEX_GAME_UPDATEABLE_H

namespace Nuclex { namespace Game {

  // ------------------------------------------------------------------------------------------- //

  /// <summary>Can be implemented by game states to be notified of Update() calls</summary>
  class Updateable {

    /// <summary>Destroys the updateable object</summary>
    public: virtual ~Updateable() {}

    /// <summary>Called when the game state should advance its simulation state</summary>
    /// <param name="elapsedTime">Time by which to advance the simulation</param>
    /// <remarks>
    ///   In this call, the game state should advance its own simulation according to
    ///   the amount of passed time. It is generally useful to manage the game's state
    ///   independent of its scene graph so game servers can run the game purely calling
    ///   this method without rendering and game clients can run the Update() cycle threaded
    ///   while rendering the most recent scene graph to the screen.
    /// </remarks>
    public: virtual void Update(float elapsedTime) = 0;

  };

  // ------------------------------------------------------------------------------------------- //

}} // namespace Nuclex::Game

#endif // NUCLEX_GAME_UPDATEABLE_H

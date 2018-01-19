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

#ifndef NUCLEX_GAME_DRAWABLE_H
#define NUCLEX_GAME_DRAWABLE_H

namespace Nuclex { namespace Game {

  // ------------------------------------------------------------------------------------------- //

  /// <summary>Can be implemented by game states to be notified of Draw() calls</summary>
  class Drawable {

    /// <summary>Destroys the drawable object</summary>
    public: virtual ~Drawable() {}

    /// <summary>Called when the game state should draw itself</summary>
    /// <param name="elapsedFrameTime">Time elapsed since the last frame</param>
    /// <remarks>
    ///   In this call, the game state can either draw itself to the screen outright or
    ///   update the rendering engine's scene graph.
    /// </remarks>
    public: virtual void Draw(float elapsedFrameTime) = 0;

  };

  // ------------------------------------------------------------------------------------------- //

}} // namespace Nuclex::Game

#endif // NUCLEX_GAME_DRAWABLE_H

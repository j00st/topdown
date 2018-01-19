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

#ifndef NUCLEX_GAME_STATES_MODALITY_H
#define NUCLEX_GAME_STATES_MODALITY_H

namespace Nuclex { namespace Game { namespace States {

  // ------------------------------------------------------------------------------------------- //

  namespace Modality {

    /// <summary>
    ///   Possible behaviors of a game state in respect to the states below it on the stack
    /// </summary>
    enum Enum {

      /// <summary>
      ///   The game state takes exclusive ownership of the screen does not require the state
      ///   below it in the stack to be updated as long as it's active.
      /// </summary>
      Exclusive,
    
      /// <summary>
      ///   The game state sits on top of the state below it in the stack, but does
      ///   not completely obscure it or requires it to continue being updated.
      /// </summary>
      Popup

    };

  } // namespace Modality

  // ------------------------------------------------------------------------------------------- //

}}} // namespace Nuclex::Game::States

#endif // NUCLEX_GAME_STATES_MODALITY_H

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

#ifndef NUCLEX_GAME_STATES_SCENEGRAPHGAMESTATE_H
#define NUCLEX_GAME_STATES_SCENEGRAPHGAMESTATE_H

#include "../Config.h"
#include "GameState.h"

namespace Nuclex { namespace Game { namespace States {

  // ------------------------------------------------------------------------------------------- //

  /// <summary>Game state for games using a scene graph</summary>
  /// <remarks>
  ///   <para>
  ///     This class translates the Entered()/Exiting() and Revealed()/Hiding() methods
  ///     into something that is a better match for games using a retained rendering system,
  ///     for example a scene graph, where the game state is not directly responsible for
  ///     drawing to the screen, but manipulates nodes in a scene graph instead.
  ///   </para>
  ///   <para>
  ///     A scene graph game state can be in 3 states. To go from the first to the last
  ///     state or back, it has to go over the middle state.
  ///   </para>
  ///   <list>
  ///     <item>
  ///       <term>Created</term>
  ///       <description>
  ///         An instance of the game state has been created, but it has not built
  ///         its scene nodes yet. Scene states are typically in this state if you store
  ///         them in a repository, allowing for minimal resource usage (as no models and
  ///         textures that would be part of the scene nodes are loaded).
  ///       </description>
  ///     </item>
  ///     <item>
  ///       <term>Prepared</term>
  ///       <description>
  ///         In this state, the scene nodes have been created but have not been attached
  ///         to the game's scene graph yet. The game state is in this state when it has
  ///         been obscured by another state (eg. a menu sitting on top of it), allowing
  ///         it to be quickly restored to working oder.
  ///       </description>
  ///     </item>
  ///     <item>
  ///       <term>Attached</term>
  ///       <description>
  ///         The game state has attached its scene nodes to the game's scene graph and is
  ///         actively updating these nodes.
  ///       </description>
  ///     </item>
  ///   </list>
  /// </remarks>
  class SceneGraphGameState : public GameState {

    /// <summary>Initializes a new scene graph game state</summary>
    public: NUCLEX_GAME_API SceneGraphGameState();

    /// <summary>Destroys the game state</summary>
    public: NUCLEX_GAME_API virtual ~SceneGraphGameState();

    /// <summary>Notifies the game state that it has been obscured by another state</summary>
    /// <remarks>
    ///   This happens when another game state has been pushed on top of this state. A typical
    ///   scenario would be if you leave your game's main menu on the state stack during
    ///   the whole game, as soon as the game play state is entered, it would always draw over
    ///   your main menu, thus the main menu should no longer bother drawing (or even actively
    ///   remove its menu items from the game's GUI).
    /// </remarks>
    public: void Hiding() {
      if(this->areSceneNodesCreated) {
        if(this->areSceneNodesAdded) {
          DetachSceneNodes();
          this->areSceneNodesAdded = false;
        }
      }
    }

    /// <summary>Notifies the game state that it is no longer obscured</summary>
    /// <remarks>
    ///   This notification will be issued when the game state was obscured by another state
    ///   sitting on top of it but that state has now been removed. If the revealed state
    ///   was the game's main menu, for example, it should now resume drawing or perhaps
    ///   re-add the menu items to the game's GUI in case it removed them when it was
    ///   first obscured.
    /// </remarks>
    public: void Revealed() {
      if(this->areSceneNodesCreated) {
        if(!this->areSceneNodesAdded) {
          AttachSceneNodes();
          this->areSceneNodesAdded = true;
        }
      }
    }

    /// <summary>Notifies the game state it is about to be exited</summary>
    /// <remarks>
    ///   <para>
    ///     This happens when the game state is completely removed from the game state manager.
    ///     Depending on your game's design, the state may be kept somewhere (presumably some
    ///     state repository that's responsible for creating an storing states) or it may be
    ///     deleted immediately following its removal from the game state manager.
    ///   </para>
    ///   <para>
    ///     Upon receiving this notification, the game state should remove any nodes it has
    ///     added to the game's scene graph, disconnect itself from input callbacks and so
    ///     on. You may even want to destroy memory-intensive resources if the game state may
    ///     be kept alive in your game.
    ///   </para>
    /// </remarks>
    public: void Exiting() {
      if(this->areSceneNodesCreated) {
        if(this->areSceneNodesAdded) {
          DetachSceneNodes();
          this->areSceneNodesAdded = false;
        }

        DestroySceneNodes();
        this->areSceneNodesCreated = false;
      }
    }

    /// <summary>Notifies the game state that it has been entered</summary>
    /// <remarks>
    ///   This call allows the game state to add any nodes it requires to the game's scene
    ///   graph or to connect to the callbacks of an input manager, etc.
    /// </remarks>
    public: void Entered() {
      if(!this->areSceneNodesCreated) {
        CreateSceneNodes();
        this->areSceneNodesCreated = true;

        if(!this->areSceneNodesAdded) {
          AttachSceneNodes();
          this->areSceneNodesAdded = true;
        }
      }
    }

    /// <summary>Called when the state should create its scene nodes</summary>
    protected: virtual void CreateSceneNodes() {}

    /// <summary>Called when the state should destroy its scene nodes</summary>
    protected: virtual void DestroySceneNodes() {}

    /// <summary>Called when the state should add its nodes to the scene graph</summary>
    protected: virtual void AttachSceneNodes() {}

    /// <summary>Called when the state should remove its nodes from the scene graph</summary>
    protected: virtual void DetachSceneNodes() {}

    /// <summary>
    ///   Whether the game state has currently added its contents to the scene graph
    /// </summary>
    private: bool areSceneNodesAdded;
    /// <summary>
    ///   Whether the game state currently created its scene nodes
    /// </summary>
    private: bool areSceneNodesCreated;

  };

  // ------------------------------------------------------------------------------------------- //

}}} // namespace Nuclex::Game::States

#endif // NUCLEX_GAME_STATES_SCENEGRAPHGAMESTATE_H

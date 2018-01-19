#include <iostream>
#include <memory>

#include "States/DefaultGameStateManager.h"
#include "States/GameState.h"

using namespace std;
using namespace Nuclex::Game;
using namespace Nuclex::Game::States;

// --------------------------------------------------------------------------------------------- //

/// <summary>Game state that would display the main menu</summary>
class MainMenuGameState : public GameState,
  public virtual Updateable, public virtual Drawable {

  /// <summary>Called when the game state is entered</summary>
  public: void Entered() {
    cout << "MainMenuGameState has been entered" << endl;
  }

  /// <summary>Called when the game state is about to be exited</summary>
  public: void Exiting() {
    cout << "MainMenuGameState is exiting" << endl;
  }

  /// <summary>Updates the time in the game state's simulation</summary>
  /// <param name="elapsedTime">Time by which to advance the simulation</param>
  public: void Update(float elapsedTime) {
    cout << "MainMenuGameState has been updated" << endl;
  }

  /// <summary>Updates the time in the game state's simulation</summary>
  /// <param name="elapsedFrameTime">Time elapsed since the last frame</param>
  public: void Draw(float elapsedFrameTime) {
    cout << "MainMenuGameState has been drawn" << endl;
  }

  /// <summary>Game state manager through which game states can be switched</summary>
  private: std::shared_ptr<GameStateManager> gameStateManager;

};

// --------------------------------------------------------------------------------------------- //

/// <summary>Game state that would play the introduction video</summary>
class IntroGameState : public GameState,
  public virtual Updateable {

  /// <summary>Initializes a new intro game state</summary>
  /// <param name="gameStateManager">
  ///   Game state manager that will be used to switch to the main menu when
  ///   the introduction has finished
  /// </param>
  public: IntroGameState(const std::shared_ptr<GameStateManager> &gameStateManager) :
    gameStateManager(gameStateManager) {}

  /// <summary>Called when the game state is entered</summary>
  public: void Entered() {
    cout << "IntroGameState has been entered" << endl;
  }

  /// <summary>Called when the game state is about to be exited</summary>
  public: void Exiting() {
    cout << "IntroGameState is exiting" << endl;
  }

  /// <summary>Updates the time in the game state's simulation</summary>
  /// <param name="elapsedTime">Time by which to advance the simulation</param>
  public: void Update(float elapsedTime) {
    cout << "IntroGameState updated, switching to MainMenuGameState" << endl;
    this->gameStateManager->Switch(std::shared_ptr<GameState>(new MainMenuGameState()));
  }

  /// <summary>Game state manager through which game states can be switched</summary>
  private: std::shared_ptr<GameStateManager> gameStateManager;

};

// --------------------------------------------------------------------------------------------- //

/// <summary>The application's main entry point</summary>
/// <returns>Exit code the process should terminate with</returns>
int main() {
  std::shared_ptr<DefaultGameStateManager> gameStateManager =
    std::make_shared<DefaultGameStateManager>();

  // Set the initial game state the game will use after it has started
  cout << "*** Pushing intro game state onto the stack ***" << endl;
  gameStateManager->Push(std::make_shared<IntroGameState>(gameStateManager));
  
  // Simulate the game's main loop for a bit
  for(std::size_t index = 0; index < 3; ++index) {
    cout << endl;
    cout << "*** Main loop cycle " << (index + 1) << " ***" << endl;
    gameStateManager->Draw(1.0f);
    gameStateManager->Update(1.0f);
  }

  // Shut everything down again
  cout << endl;
  cout << "*** Shutting down game state manager ***" << endl;
  gameStateManager.reset();
}

// --------------------------------------------------------------------------------------------- //

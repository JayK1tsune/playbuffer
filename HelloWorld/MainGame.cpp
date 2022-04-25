<<<<<<< HEAD
#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"
=======

#include "Player.h"
>>>>>>> parent of 60b24cf (Merge branch 'HelloWorld' of https://github.com/JayK1tsune/playbuffer into HelloWorld)

int DISPLAY_WIDTH = 1280;
int DISPLAY_HEIGHT = 720;
int DISPLAY_SCALE = 1;

<<<<<<< HEAD
struct Gamestate
{
	float timer = 0;
	int spriteId = 0;
};
Gamestate gameState;

// The entry point for a PlayBuffer program
void MainGameEntry( PLAY_IGNORE_COMMAND_LINE )
{
	Play::CreateManager( DISPLAY_WIDTH, DISPLAY_HEIGHT, DISPLAY_SCALE );
	Play::CentreAllSpriteOrigins();
	//Play::LoadBackground("E:\\UNI\\playbuffer\\HelloWorld\\Data\\Backgrounds\\Frogger.png");
=======
Player player = Player();

struct GameState
{
	float timer = 0;
	int spriteID = 0;
};

GameState gameState;

// The entry point for a PlayBuffer program
//:: = scope 
void MainGameEntry( PLAY_IGNORE_COMMAND_LINE )
{
	Play::CreateManager( DISPLAY_WIDTH, DISPLAY_HEIGHT, DISPLAY_SCALE );

	player.InitPlayer("paddle", DISPLAY_WIDTH * 0.5f, DISPLAY_HEIGHT * 0.75);
>>>>>>> parent of 60b24cf (Merge branch 'HelloWorld' of https://github.com/JayK1tsune/playbuffer into HelloWorld)
}

// Called by PlayBuffer every frame (60 times a second!)
bool MainGameUpdate( float elapsedTime )
{
<<<<<<< HEAD
	Play::ClearDrawingBuffer( Play::cOrange );
	Play::DrawDebugText({ DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2 },
		Play::GetSpriteName(gameState.spriteId),
		Play::cWhite);
	Play::DrawSprite(gameState.spriteId, Play::GetMousePos(), gameState.timer);
	if (Play::KeyPressed(VK_SPACE))
		gameState.spriteId++;
	//Play::DrawDebugText( { DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2 }, "Hello World!" );
	Play::PresentDrawingBuffer();
	return Play::KeyDown( VK_ESCAPE );
=======
<<<<<<< HEAD
	Play::ClearDrawingBuffer( Play::cOrange );
	Play::DrawDebugText( { DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2 }, "Frogger!" );
=======
	Play::ClearDrawingBuffer( Play::cBlack);

	//Play::DrawDebugText({ DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2 },
	//	Play::GetSpriteName(gameState.spriteID),
	//	Play::cWhite);

	player.UpdatePlayer();

>>>>>>> fedd651f216a26e0fd1718cfcbb9e4ec12a6311d
	Play::PresentDrawingBuffer();
	return Play::KeyDown( VK_ESCAPE );
	
>>>>>>> parent of 60b24cf (Merge branch 'HelloWorld' of https://github.com/JayK1tsune/playbuffer into HelloWorld)
}

// Gets called once when the player quits the game 
int MainGameExit( void )
{
	Play::DestroyManager();
	return PLAY_OK;
}


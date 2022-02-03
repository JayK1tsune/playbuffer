
#include "Player.h"

int DISPLAY_WIDTH = 1280;
int DISPLAY_HEIGHT = 720;
int DISPLAY_SCALE = 1;

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
}

// Called by PlayBuffer every frame (60 times a second!)
bool MainGameUpdate( float elapsedTime )
{
	Play::ClearDrawingBuffer( Play::cBlack);

	//Play::DrawDebugText({ DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2 },
	//	Play::GetSpriteName(gameState.spriteID),
	//	Play::cWhite);

	player.UpdatePlayer();

	Play::PresentDrawingBuffer();
	return Play::KeyDown( VK_ESCAPE );
	
}

// Gets called once when the player quits the game 
int MainGameExit( void )
{
	Play::DestroyManager();
	return PLAY_OK;
}


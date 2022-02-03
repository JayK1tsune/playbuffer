#pragma once
//includes
#include "Play.h"

class Player
{
	int PlayerID = 0;
public :
	Player();
	~Player();

	void InitPlayer(std::string spriteName, float StartX, float StartY);
	void HandlePlayerInput();
	void UpdatePlayer();
};


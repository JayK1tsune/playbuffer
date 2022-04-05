#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER

#include "Player.h"


Player::Player()
{

}

Player::~Player()
{
}

void Player::InitPlayer(std::string spriteName, float StartX, float StartY)
{
	PlayerID = Play::CreateGameObject(0, { StartX,StartY }, 50, spriteName.c_str());
}

void Player::HandlePlayerInput()
{
	GameObject& obj_player = Play::GetGameObject(PlayerID);

	if (Play::KeyDown(VK_LEFT))
	{
		
		obj_player.acceleration = { -1,0 };
		

	}
	else if (Play::KeyDown(VK_RIGHT))
	{
		obj_player.acceleration = { 1,0 };

	}
	else // if left or right is not being pressed
	{
		obj_player.acceleration = { 0,0 };
		if (obj_player.velocity.x > 5)
		{
			obj_player.velocity *= 0.5f;
		}
	
	}
}

void Player::UpdatePlayer()
{
	GameObject& obj_player = Play::GetGameObject(PlayerID);
	HandlePlayerInput();

	Play::UpdateGameObject(obj_player);

	if (Play::IsLeavingDisplayArea(obj_player))
	{
		obj_player.pos = obj_player.oldPos;
		obj_player.velocity = { 0,0 };
		obj_player.acceleration = { 0,0 };
	}
	Play::DrawObject(obj_player);
}

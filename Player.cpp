#include "Player.h"

Player::Player(const char * name, const char * description, Room * room) : Creature(name, description, room);
{
	type = PLAYER;
}

Player::~Player()
{
}

void Player::Go(const vector<string>& args)
{

}

void Player::Look(const vector<string>& args)
{
}


bool Player::Drop(const vector<string>& args)
{
	return false;
}

void Player::Inventory()
{
}

bool Player::Pick(const vector<string>& args)
{
	return false;
}

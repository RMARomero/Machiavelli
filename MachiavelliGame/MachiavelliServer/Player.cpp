#include "Player.h"

using namespace std;

Player::~Player()
{
}

void Player::build(int idx)
{
	auto it = std::next(m_Hand.begin(), idx);
	move(it, it, back_inserter(m_Buildings));
	m_Hand.erase(it);
}

int Player::stealMoney()
{
	int ret = m_iCoins;
	m_iCoins = 0;
	return ret; 
}

#include "stdafx.h"
#include "IPlayer.h"

using namespace std;

IPlayer::~IPlayer()
{
}

void IPlayer::build(int idx)
{
	auto it = std::next(m_Hand.begin(), idx);
	move(it, it, back_inserter(m_Buildings));
	m_Hand.erase(it);
}

int IPlayer::stealMoney()
{
	int ret = m_iCoins;
	m_iCoins = 0;
	return ret; 
}

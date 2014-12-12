#pragma once
#include "stdafx.h"

namespace std {
	class BuildingCard
	{
	public:
		BuildingCard(int cost, string name, string flavour, CardColor color) 
			: m_iCost{ cost }, m_sName{ name }, m_sFlavourTxt{ flavour }, m_eColor{ color }{}

		string getName() { return m_sName; }
		string getFlavour() { return m_sFlavourTxt; }


		virtual ~BuildingCard();
		virtual int countPoints() { return m_iCost; }
		virtual vector<string> getOptions() {}
		virtual bool destroy() { return true; };
		virtual CardColor checkColor(CardColor playerColor){ return m_eColor; }
		virtual void Run();

	protected:
		int m_iCost;
		string m_sName;
		string m_sFlavourTxt;
		CardColor m_eColor;



	};
}// namespace std


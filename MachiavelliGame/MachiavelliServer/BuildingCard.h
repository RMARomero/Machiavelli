#pragma once
#include "stdafx.h"

	class BuildingCard
	{
	public:
		BuildingCard(int cost, std::string name, std::string flavour, CardColor color)
			: m_iCost{ cost }, m_sName( name ), m_sFlavourTxt(flavour), m_eColor{ color }{}
		virtual ~BuildingCard();

		std::string getName() { return m_sName; }
		std::string getFlavour() { return m_sFlavourTxt; }

		
		virtual int countPoints() { return m_iCost; }
		virtual std::vector<std::string> getOptions() { return std::vector <std::string> {}; }
		virtual bool destroyable() { return true; }
		virtual CardColor checkColor(CardColor playerColor){ return m_eColor; }
		virtual void Run();

	protected:
		int m_iCost;
		std::string m_sName;
		std::string m_sFlavourTxt;
		CardColor m_eColor;



	};


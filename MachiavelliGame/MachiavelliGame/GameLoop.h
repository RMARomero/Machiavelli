#pragma once
class GameLoop
{
public:
	GameLoop();
	virtual ~GameLoop();
private:
	char* m_cIP;
	int m_iPort;
	void getServerInformation();
};


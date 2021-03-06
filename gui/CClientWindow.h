// ETH32 - an Enemy Territory cheat for windows
// Copyright (c) 2007 eth32 team
// www.cheatersutopia.com & www.nixcoders.org

#pragma once

#include "CWindow.h"
#include "CScrollBar.h"
#include "CButtons.h"

typedef enum {
	CLIENT_NONE,
	CLIENT_TEAM,
	CLIENT_ENEMY,
	CLIENT_SPEC
} clientType_t;

typedef struct {
	int x, y, x2, y2;
	int w, h;
	int clientNum;
	bool valid;
	clientType_t type;
} clientButton_t;

class CClientWindow : public CWindow
{
public:
	CClientWindow(char *wlabel, int wx, int wy, int ww, int wh);
	~CClientWindow(void);

	void Display(void);
	int ProcessMouse(int mx, int my, UINT mevent, CControl **mhook, CControl **khook);
	int MouseWheel(int mx, int my, int wheel);
	void SetProps(const char *props, float xScale, float yScale) {   }
private:
	bool CheckClientSelect(int mx, int my);
	void UpdateClients(void);
	void ClearClients(void);

	void InitClientButtons(void);
	void DrawClientButtons(void);
	clientButton_t* FindOpenSpecSlot(void);
	void DrawClientInfo(void);

	int selectedClientNum;

	clientButton_t	buttons[2][32];
	int numTeam, numEnemy, numSpec;

	int leftPaneWidth, rightPaneWidth;
	float lgFontScale;
	int	lgFontSize;
};
#pragma once
#include "Vector3.h"
class Loading
{
private:
	int m_loadingHandle;
	Vector3 m_loadingPos;
public:
	Loading();
	~Loading();
	void Update();
	void Draw();
};


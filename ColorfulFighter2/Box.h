#pragma once
struct Box
{
	int x1;//��
	int y1;//��
	int x2;//�E
	int y2;//��

	Box()
	{
		x1 = 0;
		y1 = 0;
		x2 = 0;
		y2 = 0;
	}

	Box(int X1,int Y1,int X2,int Y2)
	{
		x1 = X1;
		y1 = Y1;
		x2 = X2;
		y2 = Y2;
	}
};

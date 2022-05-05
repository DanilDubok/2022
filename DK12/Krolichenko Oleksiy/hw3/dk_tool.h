#define _CRT_SECURE_NO_WARNINGS

#ifndef dk_tool_h
#define dk_tool_h


typedef struct tagPoint {
	int x;
	int y;
}Point;


typedef struct tagEllipse {
	Point* O;
	int R;
	int r;
}Ellipse;


Ellipse* createEllipse(Point* Centre, int* R, int* r);
void destroyEllipse(Ellipse* aEllipse);
float SquareOfEllipse(Ellipse* aEllipse);
void printEllipse(Ellipse* aEllipse);

#endif 
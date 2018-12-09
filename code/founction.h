#include<stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<string.h>
#include<conio.h>
#define maps_num  9
typedef struct Map {


	char map[50][50];
	int level;
	int h;
	int len;
	char last_map[100][50][50];
	int aim_count;
	int aimx[50];
	int aimy[50];

}Map;
void intgame();
Map* LoadMap(int level);

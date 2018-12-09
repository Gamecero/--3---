   
#include"founction.h"
int game(int level);
char key = 0;
int isEnd = 0;
int scenes = 0;
int step_num=0;
int aim_x[50] = { 0 }, aim_y[50] = { 0 };
int main(int level)
{
	system("title BoxGame");
	//定义主界面
	char scenes_main0[9][30] = {
		"\n\n\n\n",
		"\t\t\t\t\t\t      made by Gamecero",
		"\t\t\t\t\t\t         版本2.0",
		"\t\t\t\t\t\t   ◤███████◥ \n",
		"\t\t\t\t\t\t     █☆☆☆☆☆█\n",
		"\t\t\t\t\t\t    █<开始(空格)>█\n",
		"\t\t\t\t\t\t     █退出(ESC)█\n",
		"\t\t\t\t\t\t     █☆☆☆☆☆█\n",
		"\t\t\t\t\t\t   ◣███████◢",
	};
	while (1)
	{
		system("cls");
		for (int x = 0; x < 9; x++)
		{
			puts(scenes_main0[x]);
		}
		key =getch();
		if (key == ' ')
		{
			game(level);
			break;
		}
		else
			key == 27;
		{
			return 0;
			break;
		}
	}
}

		
int x, y;

int game(int level)
{
	int aim_achieve_mount = 0;
	Map *map;
	map = LoadMap(level);
	int k = 0;
	char last_map[100][50][50];//#
	char input;
	int reVel = 0;
	/*下面定义一个二维数组，其中的元素是不同图像的ID号，在后面的函数中将讲解不同数字分别代表的图像元素*/
	while (1)   //死循环，等待用户命令
	{
		system("CLS");
		//记录每一步的地图B#
		for (x = 0; x < 10; x++)
		{
			for (y = 0; y < 12; y++)
			{
				last_map[k][x][y] = map->map[x][y];
			}
		}
		for (x = 0;x < 12;x++)
		{
			printf("%d", x);
		}
		printf("\n");
		printf("\n");
		//游戏界面//把数字地图以图形打印出来并居中
		printf("\n\n\n\n\n\n\n\n\n");
		for (x = 0;x < 10;x++)
		{
			for (y = 0;y < 12;y++)
			{
				switch (map->map[x][y])
				{
					//地面：（0）}  墙：（1）█ }  箱子：(2)□；}   目的地：（3）☆ }
						//人：（4）♀ }  箱子—目：（5） ★ } 人—目：（7）♀
				case '0':
					printf("  ");
					break;
				case '1':
					printf("█");
					break;
				case '2':
					printf("□");
					break;
				case '3':
					printf("☆");
					break;
				case '4':
					printf("♀");
					break;
				case '5':
					printf("★");
					break;
				case '7':
					printf("♀");
					break;
				}
			}
			printf("\n");    //分行输出
		}
		// 游戏界面显示在下方的信息
		printf("\t\t\t\t    人(♀) 箱子(□) 目的地(☆) 离开游戏(Esc) ");
		printf("\n\n\t\t\t\t\t\t    步数:%d", step_num);
		printf("\n\n\n\t\t\t\t\t\t    即将登顶");
		// 找到人物的坐标，才能移动
		for (y = 0; y < 20; y++)
		{
			for (x = 0; x < 20; x++)
			{
				if (map->map[y][x] == '4' || map->map[y][x] == '7')
					break;
			}
			if (map->map[y][x] == '4' || map->map[y][x] == '7')
				break;
		}
		char opinion;
		opinion = getch();
		switch (scenes)
		{
		case 0:
			switch (opinion)
			{
			case 27:
				return 0;
				break;
			case 'u'://C
				if (k < 100 && k>0)
				{
					for (int x = 0; x < map->h; x++)
					{
						for (int y = 0; y < map->len; y++)
						{
							map->map[x][y] = last_map[k - 1][x][y];
						}
					}
					k = k - 2;
				}
				break;
			case 'w':
			case 'W':
				if (map->map[y - 1][x] == '0' || map->map[y - 1][x] == '3')
				{
					map->map[y][x] -= 4;
					map->map[y - 1][x] += 4;
					step_num++;
				}
				//判断人上面是不是箱子
				else if (map->map[y - 1][x] == '2' || map->map[y - 1][x] == '5')
				{
					//判断箱子上面是不是空地或目的地
					if (map->map[y - 2][x] == '0' || map->map[y - 2][x] == '3')
					{
						map->map[y - 2][x] += 2;
						map->map[y - 1][x] += 2;
						map->map[y][x] -= 4;
						step_num++;
					}
				}

				break;
			case 's':
			case 'S':
				if (map->map[y + 1][x] == '0' || map->map[y + 1][x] == '3')
				{
					map->map[y][x] = map->map[y][x] - 4;
					map->map[y + 1][x] += 4;
					step_num++;
				}
				//判断人下面是不是箱子
				else if (map->map[y + 1][x] == '2' || map->map[y + 1][x] == '5')
				{
					//判断箱子下面是不是空地或目的地
					if (map->map[y + 2][x] == '0' || map->map[y + 2][x] == '3')
					{
						map->map[y + 2][x] += 2;
						map->map[y + 1][x] += 2;
						map->map[y][x] -= 4;
						step_num++;
					}
				}
				break;
			case 'a':
			case 'A':
				if (map->map[y][x - 1] == '0' || map->map[y][x - 1] == '3')
				{
					map->map[y][x] = map->map[y][x] - 4;
					map->map[y][x - 1] += 4;
					step_num++;
				}
				//判断人左面是不是箱子
				else if (map->map[y][x - 1] == '2' || map->map[y][x - 1] == '5')
				{
					//判断箱子左面是不是空地或目的地
					if (map->map[y][x - 2] == '0' || map->map[y][x - 2] == '3')
					{
						map->map[y][x - 2] += 2;
						map->map[y][x - 1] += 2;
						map->map[y][x] -= 4;
						step_num++;
					}
				}

				break;
			case 'd':
			case 'D':
				if (map->map[y][x + 1] == '0' || map->map[y][x + 1] == '3')
				{
					map->map[y][x] = map->map[y][x] - 4;
					map->map[y][x + 1] += 4;
					step_num++;
				}
				//判断人左面是不是箱子
				else if (map->map[y][x + 1] == '2' || map->map[y][x + 1] == '5')
				{
					//判断箱子左面是不是空地或目的地
					if (map->map[y][x + 2] == '0' || map->map[y][x + 2] == '3')
					{
						map->map[y][x + 2] += 2;
						map->map[y][x + 1] += 2;
						map->map[y][x] -= 4;
						step_num++;
					}
					break;
				}
			}
		}
	}
	//判断终点有箱子的数目
	int aim_mount = 8;
		for (int x = 0; x < 10; x++)
		{
			for (int y = 0; y < 12; y++)
				if (map->map[x][y] == '5')
				{
					aim_achieve_mount++;
					//如果终点有箱子的数目与终点的数目相同，则通关；
					if (aim_mount == aim_achieve_mount)
					{
						printf("恭喜过关");
						return 0;
						break;
					}
				}
		}
	}

Map* LoadMap(int level)
{
	Map* temp = (Map*)malloc(sizeof(Map));//为指针temp分配内存空间
	char buffer[256];
	FILE *fp;
	sprintf(buffer, "source/map/%d.txt", level);
	fp = fopen(buffer, "r");
	temp->level = level;
	for (int i = 0;; i++)
	{
		fgets(temp->map[i], 256, fp);
		temp->map[i][strlen(temp->map[i]) - 1] = '\0';//在字符串末尾手动加上结束符'\0'
		if (temp->map[i][1] == '9')
		{
			temp->map[i][1] = '2';
			temp->h = i + 1;
			break;
		}
		for (int j = 0; temp->map[1][j] != '\0'; j++)
		{
			temp->len = j + 1;
		}
	}
	fclose(fp);
	return temp;
}


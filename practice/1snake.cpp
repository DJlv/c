#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#define max 100
HWND hwnd = NULL;
//数据分析
//定义 坐标
typedef struct Point
{
	int x;
	int y;
}MYPOINT;

struct mySnake
{
	int num;
	MYPOINT xy[max];
	char postion;
}snake;

struct myfood
{
	MYPOINT fdxy;
	int flag;
	int eatgrade;
}food;

enum movpostion
{
	right=72,
	left=75,
	down=77,
	up=80
};

//过程
void initsnake();//初始化蛇
void drawsnake();//打印蛇
void movesnake();//移动蛇
void keydown();//控制蛇
void initfood();//初始化食物
void drawfood();//打印食物
void eatfood();//吃食物




//主函数
int main()
{
	srand((unsigned int)time(NULL));
	//初始化窗口界面
	hwnd=initgraph(640,480);
	setbkcolor(WHITE);
	cleardevice();
	initsnake();
	
	while (1)
	{
		cleardevice();
		drawsnake();
		if (food.flag == 0)
		{
			initfood();
		}
		drawfood();
		eatfood();
		movesnake();
		while (_kbhit())
		{
			keydown();
		}
		Sleep(100);
	}
	getchar();
	return 0;
}
void initsnake()
{
	snake.xy[2].x = 0;
	snake.xy[2].y = 0;
	snake.xy[1].x =10;
	snake.xy[1].y = 0;
	snake.xy[0].x = 20;
	snake.xy[0].y = 0;
	snake.num = 3;
	snake.postion = right;
	food.flag = 0;
}
void drawsnake()
{
	for (int i = 0; i < snake.num; i++)
	{
		setlinecolor(BLACK);
		setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
		fillrectangle(snake.xy[i].x, snake.xy[i].y, snake.xy[i].x + 10, snake.xy[i].y + 10);
	}
}
void movesnake()
{
	for (int i = snake.num - 1; i > 0; i--)
	{
		snake.xy[i].x = snake.xy[i - 1].x;
		snake.xy[i].y = snake.xy[i - 1].y;
	}
	switch(snake.postion)
	{
		case right:
			snake.xy[0].x += 10;
			break;
		case left:
			snake.xy[0].x -= 10;
			break;
		case down:
			snake.xy[0].y += 10;
			break;
		case up:
			snake.xy[0].y -= 10;
			break;
		default:
			break;
	}
}
void keydown()
{
	char ch = '0';
	ch = _getch();
	switch (ch)
	{
	case right:
		if (snake.postion != down)
		{
			snake.postion = up;
		}
		break;
	case left:
		if (snake.postion != right)
			snake.postion = left;
		break;
	case down:
		if (snake.postion != left)
		{
			snake.postion = right;
		}
		break;
	case up:
		if (snake.postion != up)
		{
			snake.postion = down;
		}
		break;
	default:
		break;
	}
}//

void initfood()//初始化食物
{
	food.fdxy.x = rand() % 65*10;
	food.fdxy.y = rand() % 48*10;
	food.flag = 1;
	//食物不与蛇重复
	for (int i = 0; i < snake.num; i++)
	{
		if (food.fdxy.x == snake.xy[i].x&&food.fdxy.y == snake.xy[i].y)
		{
			food.fdxy.x = rand() % 65*10;
			food.fdxy.y = rand() % 48*10;
		}
	}
}
void drawfood()//打印食物
{
	setlinecolor(BLACK);
	setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
	fillrectangle(food.fdxy.x, food.fdxy.y, food.fdxy.x + 10, food.fdxy.y + 10);
}

void eatfood()//吃食物
{
	if (food.fdxy.x == snake.xy[0].x&&food.fdxy.y == snake.xy[0].y)
	{
		snake.num++;
		food.eatgrade + 10;
		food.flag = 0;
	}
}
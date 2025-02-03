
#include<iostream>
#include<cmath>
#include<conio.h>
#include<windows.h>
using namespace std;
bool gameOver;
int width = 20;
int height =20;
int tailX[100], tailY[100];
int ntail=0;
int x, y, fruitx, fruity, score , p;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;
void Setup()
{
	gameOver = false;
	x = width / 2;
	y = height / 2;
	fruitx = rand() % width;
	fruity = rand() % height;
	score = 0;
    // dir=STOP;
}
void Draw()
{
	system("CLS");
	for (int i = 0; i < width+2; i++)
	{
		cout << "#";
	}cout << endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0 )
			{
				cout << "#";
			}
			if (j == x && i == y)
			{
				cout << "O";
			}
			else if (j == fruitx && i == fruity)
			{
				if (p % 3== 0)
					cout << "F";
				else
				{
					cout << "f";

				}
					

			}
			else
			{
				bool print = false;
				for (int k = 0; k < ntail; k++)
				{
					if (tailX[k] == j && tailY[k] ==i)
					{
						if (p % 3 == 1)
						{
							cout << "O";

						}
						else
						{
							cout << "o";
						}
						
						print = true;

					}
				}
				if (!print)
				{
					cout << " ";
				}
				
			}
			if (j == width - 1)
			{
				cout << "#";
			}
		}cout << endl;
	}
	
	for (int i = 0; i < width+2; i++)
	{
		cout << "#";
	}cout << endl;
	cout << "Score = " << score << endl;
	cout << "Tail length = " << ntail << endl;


}
void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
            gameOver=true;
			break;
		}
	}

}
void Logic()
{
	int prevx = tailX[0];
	int prevy = tailY[0];
	int prev2x, prev2y;

	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < ntail; i++)
	{
		prev2x = tailX[i];
		prev2y = tailY[i];
		tailX[i] = prevx;
		tailY[i] = prevy;
		prevx = prev2x;
		prevy = prev2y;



	}
	if (x == fruitx && y == fruity)
	{
		
		fruitx = rand() % width;
		fruity = rand() % height;
		p += 10;
		if (p% 3 == 1)
		{
			ntail += 2;
			score += 20;
			
		}
			
		else
		{
			ntail++;
			score += 20;
			

		}
			
		   


	}

	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	if (x < 0 || x > width || y < 0 || y > height)
		gameOver = true;
	//if (x < 0) x = width - 1; else if (x >= width) x = 0;
	//if (y < 0)y = height - 1; else if (y >= height)y = 0;
	for (int i = 0; i < ntail; i++)
	{
		if (tailX[i] == x && tailY[i] == y)
		{
			gameOver = true;
		}


	}
}
int main()
{
	Setup();
	while (!gameOver)
	{
		Draw();
		Sleep(50);
		Input();
		Logic();
	}
	return 0;
	std::cout << "Hello World!\n";
}
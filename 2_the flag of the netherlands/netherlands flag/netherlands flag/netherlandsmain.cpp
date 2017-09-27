#include <iostream>

using namespace std;
#define numofcolor 20//";"remove

int flag_color[numofcolor];//global

void init()//generate the flag data sequence
{
	int i = 0;
	cout << "Disordered color sequence:" << endl;
	for (i = 0; i < 20; ++i)
	{
		flag_color[i] = rand() % 3;
		cout << flag_color[i] << " ";
	}
	cout << endl;
}
void swapp(int &var1, int &var2)
{
	int temp = var1;
	var1 = var2;
	var2 = temp;
}
void shuffle(int * flaginit)
{
	int current = 0;
	int end = numofcolor - 1;
	int beginp = 0;
	while (current <= end)
	{
		if (flaginit[current] == 0)
		{
			swapp(flaginit[current], flaginit[beginp]);
			current++;
			beginp++;
		}
		else if (flaginit[current] == 2)
		{
			swapp(flaginit[current], flaginit[end]);
			end--;
			//current++;这一项要重新进行判定所以不能够增加这一部分的指针
		}
		else
		{
			current++;
		}
	}
	cout << "Row of data:" << endl;
	for (int i = 0; i < numofcolor; ++i)
	{
		cout << flaginit[i] << " ";
	}
	cout << endl;
}
int main()
{
	init();
	shuffle(flag_color);
	system("pause");
	return 0;
}
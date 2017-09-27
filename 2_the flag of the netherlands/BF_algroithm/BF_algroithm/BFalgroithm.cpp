#include <iostream>
using namespace std;
static int* GetFailureFun(string ps)
{
	const char *p = ps.c_str();
	int *next = new int[ps.length()];
	next[0] = -1;
	unsigned int j = 0;
	int k = -1;
	while (j < (ps.length() - 1))
	{
		if ((k == -1) || (ps[k] == ps[j]))
		{
			next[++j] = ++k;
			//cout << "";
		}
		else
		{
			k = next[k];
		}
	}
	return next;
}
int KMP(string ps,string ts)
{
	const char *p = ps.c_str();
	const char *t = ts.c_str();
	
	int* next = GetFailureFun(ps);
	for (unsigned int i = 0; i < ps.length(); ++i)
	{
		cout << *(next + i) << " ";
	}
	cout << endl;
	int ti = 0;
	int pi = 0;
	//while (ti < (ts.length() - ps.length() + 1))
	while (ti < (int)ts.length() && pi < (int)ps.length())
	{
		if ((p[pi] == t[ti]) || (pi==-1))
		{
			pi++;
			ti++;
		}
		else
		{
			pi = next[pi];
		}
	}
	if (pi == ps.length())
	{
		return ti - pi;
	}
	else
	{
		return -1;
	}
	
}
int main()
{
	string tagettextstring = "ctcaatcacaatca";
	string patterntextstring = "caatcat";
	int result = KMP(patterntextstring, tagettextstring);
	if (result == -1)
	{
		cout << "can not find out the string!!" << endl;
	}
	else
	{
		cout << "the pattern string position is: " << result << endl;
	}
	system("pause");
	return 0;
}
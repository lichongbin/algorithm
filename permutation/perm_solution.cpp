/*****************************************************************************
The Problem:

	Given the list of numbers 1, 2, 3, ..., n, we choose to list 
	permutations in numerical order (i.e. when you think 1,2,3 as 123 and 3,2,1 as 321,
	the numbers are in ascending order). For example, with n=3, our list 
	would be:

	1,2,3
	1,3,2
	2,1,3
	2,3,1
	3,1,2
	3,2,1

	Given a value of n, the problem is to determine the kth permutation. 
	Thus, for n=3 (see above) and k=4, the corresponding permutation is 
	2,3,1.

	Write a function which (given values of n and k) produces the kth 
	permutation of the numbers 1 through n.

	Your solution will be evaluated on efficiency, coding style, readibility,
	and correctness. Please also include your test cases.

The Output:

	Print the permutation with each element separated by spaces on a line by itself. 
	Example: For the input n=3, k=4, the output would be:

	2 3 1

*****************************************************************************/

#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;


void FindByHead(vector<int> &res, int* candidates, int n, int k);
int Factorial(int num);


// Feel free to ignore the style used for the framework code and 
// use your own coding style within this function.
void placer(int n, int k)
{
	cout << "n = " << n << "  k = " << k << " ->";

	int *candidates = new int[n];
	for (int i = 0; i < n; i++)
	{
		candidates[i] = i + 1;
	}
	vector<int> res;

#if 0 // recursive method

	FindByHead(res, candidates, n, k);

#else // non-recursive method

	while (res.size() < n)
	{
		if (0 == k)
		{
			for (int i = n - 1; i >= 0; i--)
			{
				if (candidates[i] != 0)
				{
					res.push_back(candidates[i]);
				}
			}
			break;
		}

		int fac = Factorial(n - 1 - res.size());
		int est_int = k / fac;
		int est_rem = k % fac;

		if (1 == k)
		{
			for (int i = 0; i < n; i++)
			{
				if (candidates[i] != 0)
				{
					res.push_back(candidates[i]);
				}
			}
			break;
		}

		int f = 0;
		for (int i = 0; i < n; i++)
		{
			if (candidates[i] != 0)
			{
				f++;
				if ((0 == est_rem && f >= est_int) || (0 != est_rem && f > est_int))
				{
					res.push_back(candidates[i]);
					candidates[i] = 0;
					break;
				}
			}
		}
		k -= est_int * fac;
	}

#endif // 0

	for (auto iter = res.begin(); iter != res.end(); iter++)
	{
		cout << setw(6) << *iter ;
	}
	cout << "\n\n";

	delete[] candidates;
}

// Notes:
// This is a recursive function, but it can be re-coded to a non-recursive function.
//
// Parameters:
// res        --- result during recursiving
// candidates --- an array for candidate numbers, which is initialized like this when k = 4: 
//                1 2 3 4
//                During recursiving, if '3' is selected, this array will be 1 2 0 4.
// n          --- the count of numbers
// k          --- refer to the problem
void FindByHead(vector<int> &res, int* candidates, int n, int k)
{
	if (0 == k)
	{
		for (int i = n-1; i >= 0; i--)
		{
			if (candidates[i] != 0)
			{
				res.push_back(candidates[i]);
			}
		}
		return;
	}

	int fac = Factorial(n - 1 - res.size());
	int est_int = k / fac;
	int est_rem = k % fac;

	if (1 == k)
	{
		for (int i = 0; i < n; i++)
		{
			if (candidates[i] != 0)
			{
				res.push_back(candidates[i]);
			}
		}
		return;
	}

	int f = 0;
	for (int i = 0; i < n; i++)
	{
		if (candidates[i] != 0)
		{
			f++;
			if ( (0 == est_rem && f >= est_int) || (0 != est_rem && f > est_int) )
			{
				res.push_back(candidates[i]);
				candidates[i] = 0;
				break;
			}
		}
	}

	if (res.size() >= n)
	{
		return;
	}

	FindByHead(res, candidates, n, k - est_int * fac);
}

// This function can calculate the factorial of a number.
// For example, x = Factorial(3), x will be 3*2*1 = 6.
// If the returns of this function are cached in memory, 
// the efficiency will be impoved significantly.
int Factorial(int num)
{
	if (num < 0)
	{
		return 0;
	}

	int c = 1;
	for (int i = 2; i <= num; i++)
	{
		c *= i;
	}
	return c;
}

// main entry point
int main(int argc, char* argv[])
{
	placer(3, 4);  // 2 3 1
	placer(10, 1); // 1 2 3 4 5 6 7 8 9 10
	placer(4, 24); // 4 3 2 1
	// TODO: generate your additional test cases here

	// a few test cases of my own.
	placer(3, 3);  // 2 1 3
	placer(6, 3);  // 1 2 3 5 4 6
	placer(6, 4);  // 1 2 3 5 6 4

	// test completely
	for (int n = 3; n < 6; n++)
	{
		int h = Factorial(n);
		for (int k = 0; k < h; k++)
		{
			placer(n, k+1);
		}
		cout << endl;
	}

	// this will prevent the console window from closing.
	int i;
	cin >> i;
	return 0;
}

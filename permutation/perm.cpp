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

// Feel free to ignore the style used for the framework code and 
// use your own coding style within this function.
void placer(int n, int k)
{
	// TODO: write me
}

// main entry point
int main(int argc, char* argv[])
{
	placer(3, 4);  // 2 3 1
	placer(10, 1); // 1 2 3 4 5 6 7 8 9 10
	placer(4, 24); // 4 3 2 1
	// TODO: generate your additional test cases here
	return 0;
}

//     Name: Scott Ng
// Due Date: 3-22-17
// Compiler: Visual Studio 2012
//    Brief: Create the Sieve of Eratosthenes using masm
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	const int MAXSIZE = 100;               
	int maxSquareRoot = pow(MAXSIZE, 0.5);      // finding the max for the multiples (eax) to reach
	bool PrimeList[MAXSIZE];

	for (unsigned int i = 0; i < MAXSIZE; i++)
		PrimeList[i] = true;

	__asm
	{
		// utilizing a for loop and while loop

		xor esi, esi                           // clearing the conents of esi
		mov ecx, MAXSIZE                       // this is for the counter (100)
		mov eax, 2                             // setting my base to start as 2
		
L1:
		cmp eax, maxSquareRoot                 // checking if eax is the square root of the max size
		ja finish                              // jumps to the end if true

		push eax                               // saving eax, because mul will modify it later
		mul eax                                // *starting with the square of a number
		mov esi, eax                           // moving the result into esi
		pop eax                                // *restoring the original counter into eax
		                                       // *the original eax will be used for incrementing esi

L2:
		cmp esi, MAXSIZE                       // array bounds check
		ja done                                // condition to exit loop here, if ESI > Maxsize, then move to next multiple
		mov PrimeList[esi-1], 0                // if not, set current index to false
		add esi, eax                           // moving to the next multiple EX: 4 then 6 then 8 then 10
		jmp L2

done:                                          // exit condition for L2, done with current eax increment
		inc eax                                // incrementing eax
		loop L1

finish:                                        // exit condition for L1                                
		
	};

	for (unsigned int i = 3; i < MAXSIZE; i++) // displaying contents of true parts of array
		if (PrimeList[i - 1] == true)          // if current part is true -> display number
			cout << i << "\t";

	system("pause");
	return 0;
}
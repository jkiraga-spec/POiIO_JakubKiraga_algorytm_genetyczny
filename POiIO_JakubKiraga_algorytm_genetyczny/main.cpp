#include <iostream>
#include <cstdlib> // srand
#include <time.h>
#include <vector>

#include "TAlgorithm.h"

using namespace std;


int main()
{
	srand(time(0));

	TCandidate* pattern;
	int count = 0;
	int _type = -1;

	cout << "Ktory osobnik [1-3]: ";
	cin >> _type;
	cout << "Ilu osobniow w populacji? ";
	cin >> count;

	switch (_type)
	{
	case 1: 
		pattern = new TCandidate_Zad1{};
		break;
	case 2:
		pattern = new TCandidate_Zad2{};
		break;
	case 3:
		pattern = new TCandidate_Zad3{};
		break;
	default:
		pattern = new TCandidate_Zad1{};
	}
	
	unsigned int candidates_count = count;
	unsigned int max_population_count = 20;
	unsigned int min_improvement_proc = 2;

	TAlgorithm task{pattern,
		candidates_count,
		max_population_count,
		min_improvement_proc
	};
	task.run();
	std::cout << "\n\n\n";
	return 0;
}
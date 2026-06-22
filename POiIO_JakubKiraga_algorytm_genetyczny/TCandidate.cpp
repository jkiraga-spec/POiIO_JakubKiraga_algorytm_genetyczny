#include <iostream>
#include <string>
#include <cstdlib>

#include "TCandidate.h"

using namespace std;

TCandidate::TCandidate()
{
	//init_vector();
	gens_count = genotype.size();

	mark = 0;
	rand_gens_val();
}

TCandidate::TCandidate(const TCandidate& oryginal)
{
	mark = oryginal.get_mark();
	for (int i = 0; i < gens_count; i++)
	{
		double x_start = oryginal.genotype[i].get_x_start();
		double x_end = oryginal.genotype[i].get_x_end();
		double dx = oryginal.genotype[i].get_dx();
		genotype[i].set_range(x_start, x_end, dx);

		double val = oryginal.genotype[i].get_val();
		genotype[i].set_val(val);
	}

}

void TCandidate::rand_gens_val()
{
	for (int i = 0; i < gens_count; i++)
	{
		genotype[i].set_rand_val();
	}
}
/*
void TCandidate::rate()
{
	double x1 = genotype[0].get_val();
	double x2 = genotype[1].get_val();

	mark = pow(x1, 2) + x2;
}

void TCandidate::init_vector()
{
	genotype.push_back({ "x1", 0, 100, 1 });
	genotype.push_back({ "x2", 0, 100, 1 });
}
*/
void TCandidate::info()
{
	cout << "\n\n";
	cout << "====================\n==\n";
	cout << "== gens count: "<< gens_count<<"\n";
	for (int i = 0; i < gens_count; i++)
	{
		cout << "== \"" << genotype[i].get_name() << "\" value: " << genotype[i].get_val() << "\n";
	}

	cout << "==\n";
	cout << "== rate: " << mark << "\n";
	cout << "====================\n\n";
}
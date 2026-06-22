#include <iostream>
#include <algorithm>

#include "TPopulation.h"

using namespace std;

//unsigned int TPopulation::_id = 0;
unsigned int TPopulation::population_count = 0;
//unsigned int TPopulation::_id = 0;

TPopulation::TPopulation(unsigned int cands_count)
{
	_id = population_count;
	population_count++;

	candidates_count = cands_count;
}

TPopulation::TPopulation(unsigned int cands_count, TCandidate* pattern)
{
	_id = population_count;
	population_count++;

	candidates_count = cands_count;

	for (int i = 0; i < candidates_count; i++) candidates.push_back(pattern->create());
}

TPopulation::TPopulation(const TPopulation& oryginal)
{
	_id = oryginal._id;

	candidates_count = oryginal.get_candidates_count();
	best_val = oryginal.get_best_val();

	for (int i = 0; i < candidates_count; i++)
	{
		const TCandidate* wsk_os_org = oryginal.get_candidate_wsk(i);
		TCandidate* copy = wsk_os_org->create_copy();
		candidates.push_back(copy);
	}

	//cout << "Liczba osobnikow: " << candidates.size() << endl;
}

void TPopulation::calculate()
{
	double best_val = 0.0;

	for (int i = 0; i < candidates_count; i++)
	{
		candidates[i]->rate();
		double val = candidates[i]->get_mark();

		if (i == 0) best_val = val;
		else		best_val = max(best_val, val);
	}

	this->best_val = best_val;
}

TCandidate* TPopulation::get_best_candidate()
{
	int i = 0;

	while (candidates[i]->get_mark() != best_val) i++;

	return candidates[i];
}

void TPopulation::info()
{
	cout << "\n\n";
	cout << "==== POPULATION #" << _id << "====\n";

	for (int i = 0; i < candidates_count; i++)
	{
		cout << "== candidate#" << i << ": " << candidates[i]->get_mark() << "\n";
	}

	cout << "====================\n\n";
}

void TPopulation::best_candidate_info() 
{
	cout << "Najlepszy osobnik: ";
	TCandidate* candidate = get_best_candidate();
	candidate->info();
}

void TPopulation::push_candidate(TCandidate* cand)
{
	candidates.push_back(cand);
}

TCandidate* TPopulation::promote_candidate()
{
	double total_mark = 0.0;
	for (int i = 0; i < candidates_count; i++)
	{
		total_mark += get_candidate_wsk(i)->get_mark();
	}
	
	double random_point = (double)rand() / RAND_MAX * total_mark;
	double current_sum = 0.0;
	int selected_index = 0;

	for (int j = 0; j < candidates_count; j++)
	{
		current_sum += candidates[j]->get_mark();
		if (current_sum >= random_point)
		{
			selected_index = j;
			break;
		}
	}
	return candidates[selected_index];
}

void TPopulation::crossover()
{
	for (int i = 0; i < candidates_count - 1; i += 2)
	{
		TCandidate* parent1 = candidates[i];
		TCandidate* parent2 = candidates[i + 1];

		int gens_count = parent1->get_gens_count();

		if (gens_count > 1)
		{
			int crossover_point = rand() % (gens_count - 1) + 1;

			for (int i = crossover_point; i < gens_count; i++)
			{
				double temp_val = parent1->get_gen(i).get_val();

				parent1->get_gen(i).set_val(parent2->get_gen(i).get_val());
				parent2->get_gen(i).set_val(temp_val);
			}
		}
	}
}
void TPopulation::mutate()
{
	double max_mutation_step = 1;
	for (int i = 0; i < candidates_count; i++)
	{
		int gens_count = candidates[i]->get_gens_count();

		for (int j = 0; j < gens_count; j++)
		{
			double current_val = candidates[i]->get_gen(j).get_val();
			double deviation = ((double)rand() / RAND_MAX * 2.0 - 1.0) * max_mutation_step;
			double new_val = current_val + deviation;
			candidates[i]->get_gen(j).set_val(new_val);
		}
	}
}

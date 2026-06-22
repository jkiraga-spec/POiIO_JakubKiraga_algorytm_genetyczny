#pragma once
#include "TCandidate_Zad1.h"
#include "TCandidate_Zad2.h"
#include "TCandidate_Zad3.h"
#include <vector>

class TPopulation
{
	static unsigned int population_count;
	unsigned int candidates_count;
	std:: vector<TCandidate*> candidates;
	double best_val = 0;
	unsigned int _id;


public:
	TPopulation(unsigned int cands_count);
	TPopulation(unsigned int cands_count, TCandidate* pattern);
	TPopulation(const TPopulation& oryginal);
	void calculate();
	TCandidate* get_best_candidate();
	
	void best_candidate_info();

	unsigned int get_candidates_count() const { return candidates.size(); };
	unsigned int get_id() { return _id; };
	double get_best_val() const { return best_val; };
	void info();
	void push_candidate(TCandidate* cand);
	TCandidate* promote_candidate();
	void crossover();
	void mutate();
private:
	const TCandidate* get_candidate_wsk(int i) const { return candidates[i]; };
};


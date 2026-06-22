#pragma once

#include "TCandidate.h"
class TCandidate_Zad1 : public TCandidate
{
public:
	TCandidate_Zad1() : TCandidate() 
	{
		init_vector();
	}
	TCandidate_Zad1(const TCandidate_Zad1& oryginal) : TCandidate(oryginal) {}

	TCandidate* create()
	{
		return new TCandidate_Zad1();
	}

	TCandidate* create_copy() const
	{
		return new TCandidate_Zad1(*this);
	}

	void rate()
	{
		double x1 = genotype[0].get_val();
		double x2 = genotype[1].get_val();

		mark = 2 * (x1 + x2);
	}
protected:
	inline void init_vector();
};

void TCandidate_Zad1::init_vector()
{
	genotype.push_back({ "x1", 0, 100, 1 });
	genotype.push_back({ "x2", 0, 100, 1 });

	gens_count = genotype.size();
}
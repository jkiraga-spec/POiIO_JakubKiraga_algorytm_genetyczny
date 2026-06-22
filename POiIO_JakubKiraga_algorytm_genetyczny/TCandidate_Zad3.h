#pragma once
#include "TCandidate.h"

class TCandidate_Zad3 : public TCandidate
{
public:
	TCandidate_Zad3() : TCandidate()
	{
		init_vector();
	}
	TCandidate_Zad3(const TCandidate_Zad3& oryginal) : TCandidate(oryginal) {}
	
	TCandidate* create()
	{
		return new TCandidate_Zad3();
	}

	TCandidate* create_copy() const
	{
		return new TCandidate_Zad3(*this);
	}

	void rate()
	{
		double x1 = genotype[0].get_val();
		double x2 = genotype[1].get_val();
		double x3 = genotype[2].get_val();

		mark = 100 * x1 + 10* x2 + x3;
	}
protected:
	inline void init_vector();
};

void TCandidate_Zad3::init_vector()
{
	genotype.push_back({ "x1", 0, 10, 1 });
	genotype.push_back({ "x2", 0, 10, 1 });
	genotype.push_back({ "x3", 0, 10, 1 });

	gens_count = genotype.size();
}
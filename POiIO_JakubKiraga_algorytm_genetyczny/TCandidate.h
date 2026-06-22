#pragma once
#include <vector>
#include "TParam.h"


class TCandidate
{
protected:
	int gens_count = 0;
	std::vector<TParam> genotype;

	double mark;
public:
	TCandidate();
	TCandidate(const TCandidate& oryginal);

	virtual TCandidate* create() = 0;
	virtual TCandidate* create_copy() const = 0;

	double get_mark() const { return mark; };
	int get_gens_count() const { return gens_count; };
	TParam& get_gen(int gen_id) { return genotype[gen_id]; };
	virtual void rate() = 0;
	void info();
protected:
	virtual void init_vector() = 0;
	void rand_gens_val();
	TParam get_x(int x_id) const { return genotype[x_id]; }
};


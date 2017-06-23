#ifndef __OFFER_H__
#define __OFFER_H__

#include <queue>
#include "../include/job.h"

class Offer {

public:
	Offer(int, int);
	~Offer();

	void addJob(Job &job);
	void step();
	void printStats();
	int availableUnits() {
		return no_units;
	}

private:
	int node_id;
	int no_units;
	int no_jobs_executed;
	std::vector<Job> jobList;

};

#endif //__OFFER_H__

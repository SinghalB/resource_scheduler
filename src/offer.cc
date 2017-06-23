#include <iostream>
#include "../include/offer.h"

extern unsigned int CURRENT_TIME;
extern unsigned int running_jobs;

Offer::Offer(int node, int units) {
	node_id = node;
	no_units = units;
	no_jobs_executed = 0;
}

Offer::~Offer() {
}

void Offer::addJob(Job &job) {
	std::cout<<"Assigning Job at Node "<<node_id<<" for res units"<<job.getResUnits()<<" for duration"<<job.getTimeUnits()<<" at time"<<CURRENT_TIME<<std::endl;
	no_units = no_units - job.getResUnits();
	jobList.push_back(job);
	running_jobs++;
}

void Offer::step() {
	size_t count = 0;
	for(std::vector<Job>::iterator jobItr = jobList.begin(); jobItr != jobList.end(); jobItr++) {
		count++;
		if (jobItr->getStartTime() + jobItr->getTimeUnits() == CURRENT_TIME) {
			jobItr->setEndTime(CURRENT_TIME);
			no_units = no_units + jobItr->getResUnits();
			no_jobs_executed++;
			std::cout<<"Job completed at Node "<<node_id<<" at "<<jobItr->getEndTime()<<std::endl;
			jobList.erase(jobItr);
			count--;
			running_jobs--;
			if(jobList.empty()||count == jobList.size()) {
				break;
			}
		}
	}
}

void Offer::printStats() {
	std::cout<<"Node id:"<<node_id<<" Resources Available:"<<no_units<<" Jobs Executed:"<<no_jobs_executed<<std::endl;
}


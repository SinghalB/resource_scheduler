#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "../include/job.h"
#include "../include/offer.h"

unsigned int CURRENT_TIME = 0;
unsigned int running_jobs = 0;

std::vector<Offer> offerVec;
std::vector<Job> jobVec;

void schedule() {
	while(running_jobs != 0 || !jobVec.empty()) {

		if(!jobVec.empty()) {
			/* try to schedule a job */
			std::vector<Job>::iterator jItr = jobVec.begin();
			std::vector<Offer>::iterator oItr = offerVec.begin();
			while(jItr != jobVec.end() && oItr != offerVec.end()) {
				if (jItr->getResUnits() <= oItr->availableUnits()) {
					oItr->addJob((*jItr));
					jItr = jobVec.erase(jItr);
					if (jobVec.empty()) {
						break;
					}
				} else {
					oItr++;
				}
			}
		}

		for(auto &offer : offerVec) {
			offer.step();
		}
		CURRENT_TIME++;
	}
}

void printAllStats() {

}

void insertOffer(int id, int units) {
	if (offerVec.empty()) {
		Offer offer(id, units);
                offerVec.push_back(offer);
		return;
	}
	std::vector<Offer>::iterator oItr = offerVec.begin();
	for(; oItr != offerVec.end(); oItr++) {
		if ((*oItr).availableUnits() < units) {
			continue;
		} else {
			break;
		}
	}
	if(oItr == offerVec.end()) {
		Offer offer(id, units);
		offerVec.push_back(offer);
	} else {
		Offer offer(id, units);
		offerVec.insert(oItr, offer);
	}
}

void insertJobs(int runits, int tunits) {
	if (jobVec.empty()) {
                Job job(runits, tunits);
                jobVec.push_back(job);
		return;
	}
	std::vector<Job>::iterator jItr = jobVec.begin();
        for(; jItr != jobVec.end(); jItr++) {
                if ((*jItr).getResUnits() < runits) {
                        continue;
                } else {
                        break;
                }
        }
        if(jItr == jobVec.end()) {
                Job job(runits, tunits);
                jobVec.push_back(job);
        } else {
                Job job(runits, tunits);
                jobVec.insert(jItr, job);
        }
}

int main(int argc, char *argv[]) {
	if (argc != 3) {
		std::cout<<"Usage ./scheduler offers jobs"<<std::endl;
		return -1;
	}
	char *offerFileName = argv[1];
	char *jobsFileName = argv[2];
	std::string line;	

	std::ifstream offerStream(offerFileName, std::ifstream::in);
	if (!offerStream.good()) {
		std::cout<<"Error reading file "<<offerFileName<<std::endl;
		return -1;
	}
	while(std::getline(offerStream, line)) {
		std::istringstream iss(line);
		int id;
		int units;
		iss >> id;
		iss >> units;

		/* Insert in vector sorted on increasing number of units */
		insertOffer(id, units);
	}

	std::ifstream jobsStream(jobsFileName, std::ifstream::in);
	if (!jobsStream.good()) {
		std::cout<<"Error reading file "<<jobsFileName<<std::endl;
		return -1;
	}
	while(std::getline(jobsStream, line)) {
		std::istringstream iss(line);
		int runits;
		int tunits;
		iss >> runits;
		iss >> tunits;

		/* Insert in vector sorted on decreasing tunits */
		insertJobs(runits, tunits);
	}

	schedule();

	printAllStats();

	return 0;
}

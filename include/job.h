#ifndef __JOB_H__
#define __JOB_H__

#include <queue>
extern unsigned int CURRENT_TIME;

class Job {

public:
	Job(int runits, int tunits) {
		res_units = runits;
		time_units = tunits;
		queue_time = CURRENT_TIME;
		start_time = 0;
		end_time = 0;
	}

	void startJob() {
		start_time = CURRENT_TIME;
	}

	unsigned long getQueueTime() {
		return queue_time;
	}

	unsigned long getStartTime() {
		return start_time;
	}

	unsigned long getEndTime() {
		return end_time;
	}

	int getResUnits() {
		return res_units;
	}

	int getTimeUnits() {
		return time_units;
	}

	void setEndTime(unsigned long etime) {
		end_time = etime;
	}

private:
	int res_units;
	int time_units;
	unsigned long start_time;
	unsigned long end_time;
	unsigned long queue_time;

};

#endif //__JOB_H__

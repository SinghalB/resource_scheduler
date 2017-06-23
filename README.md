# resource_scheduler
Resource Scheduler Problem

Usage: ./scheduler offers.txt jobs.txt

offers.txt - contains tuples of node and resources like
	1 1
	2 2
	3 5

jobs.txt - contains tuples of jobs with resources and time required
	1 3
	2 5

Approach:
Shortest Job First. Both the offers and jobs are sorted in ascending order wrt number of resources.

Output:
Shows assigning and completion steps.
Assigning Job at Node 7 for res units1 for duration3 at time0
Assigning Job at Node 2 for res units1 for duration4 at time0
Assigning Job at Node 8 for res units3 for duration4 at time0
Assigning Job at Node 2 for res units4 for duration7 at time0
Assigning Job at Node 1 for res units5 for duration4 at time0
Assigning Job at Node 1 for res units9 for duration3 at time0
Job completed at Node 7 at 3
Job completed at Node 1 at 3
Job completed at Node 2 at 4
Job completed at Node 8 at 4
Job completed at Node 1 at 4
Job completed at Node 2 at 7



Code:
Header File:
include/job.h - All task/job related declarations and defintions
include/offer.h - All node or resource offer related declarations

Source Files:
src/offer.cc - add job to a particular nodes job list
src/scheduler.cc - scheduling and main function


TBD:
Better print messages
Multiple offers from same node are not accumulated.


#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "PriorityMember.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class PriorityQueue {
private:
	priority_queue<PriorityMember> PQueue;

public:
	void rePrioritize(const vector<employee>* empvec) {
		if (PQueue.empty()) { return;}
		if (PQueue.front == PQueue.back)  { return;}
		//do until at the end of the priority_queue
			//call priorityMember.setPriority(empvec)
		//once all of the member's priorities are updated, quick sort the queue by highest priority to the front
	}

};

#endif
#ifndef QueueMember_H
#define QueueMember_H

#include <iostream>

class QueueMember {

private:
	const long employeeIndex;
	long priority;

public:
	PriorityQueue(const long emplyIndex) {
		employeeIndex = emplyIndex;
		priority = 0;
	}
	PriorityQueue(const long emplyIndex, long prty) {
		employeeIndex = emplyIndex;
		priority = prty;
	}
	bool operator < (const QueueMember& other) {
		return this->priority < other.priority;
	}
	bool operator > (const QueueMember& other) {
		return this->priority > other.priority;
	}
	bool operator <= (const QueueMember& other) {
		return this->priority <= other.priority;
	}
	bool operator >= (const QueueMember& other) {
		return this->priority >= other.priority;
	}
	bool operator == (const QueueMember& other) {
		return this->priority == other.priority;
	}
	bool operator < (long other) {
		return this->priority < other;
	}
	bool operator > (long other) {
		return this->priority > other;
	}
	bool operator <= (long other) {
		return this->priority <= other;
	}
	bool operator >= (long other) {
		return this->priority >= other;
	}
	bool operator == (long other) {
		return this->priority == other;
	}
	int getEmpIndex() {
		return this->employeeIndex;
	}
	void setPriority(long prior) {
		this->priority = prior;
	}
	void setPriority(const vector<employee>* empvec) {
		empvec[emplIndex].updatePriority();
		this->priority = empvec[employeeIndex].getPriority();
	}
	int getPriority() {
		return this->priority;
	}
};

#endif
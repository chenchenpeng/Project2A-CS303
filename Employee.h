#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {

private:

	std::string name;
	int waitTime;
	int retainTime;

public:

	Employee() {
		name = "unknown";
		waitTime = 0;
		retainTime = 0;
	}

	Employee(const std::string& newName) {
		name = newName;
		waitTime = 0;
		retainTime = 0;
	}

	void setName(const std::string& newName) {
		name = newName;
	}

	void addwait(int wait) {
		waitTime += wait;
	}

	void addretain(int retain) {
		retainTime += retain;
	}

	std::string getName() const {
		return name;
	}

	int getWait() const {
		return waitTime;
	}

	int getRetain() const {
		return retainTime;
	}

	int getPriority() const {
		return waitTime - retainTime;
	}
};

#endif

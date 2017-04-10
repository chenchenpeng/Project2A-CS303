#ifndef BOOK_H
#define BOOK_H

#include "Date.h"
#include "Employee.h"
#include "Priority_Queue.h"
#include <list>
#include <string>

class Book {

private:

	std::string name;
	Date startDate;
	Date endDate;
	bool archived;
	Priority_Queue<Employee*> waiting;  // Pointers to each waiting employee.
	Date lastHeld;

public:

	Book(const std::string& bookName) {
		name = bookName;
	}

	Book(const std::string& bookName, const Date& start) {
		name = bookName;
		startDate = start;
	}
	
	std::string getname() const {
		return name;
	}

	Date getstartDate() const {
		return startDate;
	}

	Date getendDate() const {
		return endDate;
	}

	bool getarchived() const {
		return archived;
	}

	Date getHeld() const {
		return lastHeld;
	}

	void setname(const std::string& newName) {
		name = newName;
	}

	void setstartDate(const Date& newDate) {
		startDate = newDate;
	}

	void setendDate(const Date& newDate) {
		endDate = newDate;
	}

	void setarchived(const bool& newBool) {
		archived = newBool;
	}

	void setHeld(const Date& date) {
		lastHeld = date;
	}

	void populate_queue(std::list<Employee>& employ) { 
		Employee* pte;
		for (std::list<Employee>::iterator itr = employ.begin(); itr != employ.end(); itr++) {
			int priority = itr->getPriority();
			pte = &(*itr);
			waiting.add_item(pte, priority);  // Add pointers to each employee and their priority.
		}
	}

	Employee* pop_max() {
		return waiting.pop_max();
	}

	bool isEmpty() const {
		return waiting.empty();
	}

	void reprioritize() {
		waiting.reprioritize();
	}

	Priority_Queue<Employee*>& get_waiting() {
		return waiting;
	}
};

#endif

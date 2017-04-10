#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "Employee.h"
#include <list>
#include <string>

class Library {

private:

	std::list<Book> toBeCirculated;
	std::list<Book> archived;
	std::list<Employee> employeeList;

public:

	void add_book(const std::string& newBook) {
		Book B = Book(newBook);
		toBeCirculated.push_back(B);
	}

	void add_employee(const std::string& name) {  // Employees that get books later on.
		Employee tempEmployee(name);
		employeeList.push_back(tempEmployee);
	}

	void circulate_book(const std::string& bookToMove, const Date& dayStart) {
		for (std::list<Book>::iterator itr = toBeCirculated.begin(); itr != toBeCirculated.end(); itr++) {
			if (itr->getname() == bookToMove) {
				itr->setstartDate(dayStart);  // Set the starting circulating date.
				itr->setHeld(dayStart);  // Set that the held data.
				itr->populate_queue(employeeList); // Put the waiting employees in the queue.
				break;
			}
		}
	}

	void pass_on(const std::string& bookToMove, const Date& date) {
		// Find the book and its priority queue.
		Employee* EmployeeReturn, EmployeeBorrow;
		bool erased = false;
		for (std::list<Book>::iterator itr = toBeCirculated.begin(); itr != toBeCirculated.end(); itr++) {
			if (itr->getname() == bookToMove)
			{
				// Adjust retaining time for the employee who returns the book.
				EmployeeReturn = itr->get_waiting().peek_max();
				EmployeeReturn->addretain(date - itr->getHeld());
				itr->pop_max();  // Remove the top one.

								 // Adjust waiting time for the employee who borrows the book.
				if (!(itr->isEmpty()))
				{
					EmployeeReturn = itr->get_waiting().peek_max();
					EmployeeReturn->addwait(date - itr->getstartDate());
					itr->setHeld(date);
				}
				else  // If the waiting queue for the book is empty.
				{
					itr->setarchived(true);
					itr->setendDate(date);
					archived.push_back(*itr);
					toBeCirculated.erase(itr);
					erased = true;
				}

				// Adjust the queues they are in.
				for (std::list<Book>::iterator itr2 = toBeCirculated.begin(); itr2 != toBeCirculated.end(); itr2++) {
					itr2->reprioritize();
				}

				if (erased) break;
			}
		}
	}
};

#endif

//#ifndef LIBRARY_h
//#define LIBRARY_h

#include<iostream>
#include<list>
#include "PriorityQueue.h"
#include <list>
#include "Date.h"
#include "Employee.h"
#include "Book.h"


using namespace std;

class Library{
private:
	list<Book> Archived_Books;
	list<Book> Circulated_Books;
	vector<Employee> Employees;
	PriorityQueue pQueue;

public:
	void add_book(string book_name){
		Book* new_book = new Book(book_name); // we create a new book to add to the list of books
		Archived_Books.push_back(new_book);
	}

	void add_employee(string employee_name){
		Employee* new_employee = new Employee(employee_name); // we create a new employee and add him/her to the employees list
		 Employees.push_back(*new_employee);
	}
	Book FindBook(string name, list<Book> &a_list)
	{
		Book book;
		list<Book>::iterator book_item;

		for (book_item = a_list.begin(); book_item != a_list.end(); ++book_item)
		{
			if ((*book_item).getname() == name)
			{
				book = book_item;
				return book;
			}
		}
		return NULL;
	}

	void circulate_book(string book_name, Employee *requester){

		Employee *temp_emp = Employees*.pop_back();

		Book *temp_book = FindBook(book_name, Archived_Books);
		
		if (temp_book != NULL) {
			Circulated_Books.push_back(*temp_book);
			*temp_book.setstartDate(cirDate);
			*temp_book.add_employee(*requester); 
			Circulated_Books.push_back(*temp_book);
		}
		else{
			Book *temp_book = FindBook(book_name, Circulated_Books);
			if (temp_book != NULL) {
				Employees.push_back(*requester);
				pQueue.rePrioritize(Employees);
			}
			else
				cout << "The book was not found";
		}
	}

	Employee pass_on(string book_name, Date cirDate){
		Book *temp_book = books.get_book(book_name);
		temp_book.set_cir_end_date(cirDate);
		
		Employee *temp_emp = Employees.get_emp_front();
		Book *temp_book = books.get_book(book_name);
		temp_book.set_cir_start_date(cirDate);


	}
	void delete_book(string book_name)
	{
		Circulated_Books.delete(book_name);
		Archived_Books.delete(book_name);


	}
	void delet_emplyee(string emplyee_name)
	{
		Employees.delete(employee_name);
	}

	Book FindBook(string name, list<Book> &a_list)
	{
		Book book;
		list<Book>::iterator book_item;

		for (book_item = a_list.begin(); book_item != a_list.end(); ++book_item)
		{
			if ((*book_item).getname() == name)
			{
				book = book_item;
				return book;
			}
		}
		return NULL;
	}



};

//#endif
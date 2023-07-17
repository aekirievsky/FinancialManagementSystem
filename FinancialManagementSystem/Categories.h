#pragma once
#include<iostream>


class Categories
{
public:
	double sum;
	std::string date;
	std::string name;

	Categories(double sum_p, std::string date_p) : sum{ sum_p } {

		this->date = date_p;
	}
	std::string getDate() {
		return date;
	}
	std::string getName() { return name; }

	~Categories() = default;
};

class Products :public Categories
{
public:
	Products(double sum_p, std::string date_p) :Categories(sum_p, date_p) {
		this->name = "Products";
	}

	~Products() = default;
};

class Gasoline : public Categories
{
public:
	Gasoline(double sum_p, std::string date_p) :Categories(sum_p, date_p) {
		this->name = "Gasoline";
	}

	~Gasoline() = default;
};

class CommunalServices : public Categories
{
public:
	CommunalServices(double sum_p, std::string date_p) : Categories(sum_p, date_p) {
		this->name = "Communal Services";
	}


	~CommunalServices() = default;
};

class Debet :public Categories {
public:
	Debet(double sum_p, std::string date_p) : Categories(sum_p, date_p) {
		this->name = "Debet";
	}

	~Debet() = default;
};

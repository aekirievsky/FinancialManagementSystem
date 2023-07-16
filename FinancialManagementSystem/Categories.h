#pragma once
#include<iostream>


class Categories
{
public:
	double sum;
	std::string date;

	Categories(double sum_p, char* date_p) : sum{ sum_p } {

		this->date += date_p;
	}
	std::string getDate() {
		return date;
	}
	std::string getName() { return ""; };

	friend std::ostream& operator<<(std::ostream& out, const Categories& other) {
		out << other.sum << " " << other.date;
		return out;
	}

	friend std::istream& operator>>(std::istream& input, Categories& other) {
		input >> other.sum;
		return input;
	}

	~Categories() = default;
};

class Products :public Categories
{
public:
	Products() = default;
	Products(double sum_p, char* date_p) :Categories(sum_p, date_p) {}

	std::string getName() {
		return "Products";
	}

	friend std::istream& operator>>(std::istream& input, Products& other) {
		input >> other.sum;
		return input;
	}

	~Products() = default;
};

class Gasoline : public Categories
{
public:
	Gasoline() = default;
	Gasoline(double sum_p, char* date_p) :Categories(sum_p, date_p) {}

	std::string getName() {
		return "Gasoline";
	}

	~Gasoline() = default;
};

class CommunalServices : public Categories
{
public:
	CommunalServices() = default;
	CommunalServices(double sum_p, char* date_p) : Categories(sum_p, date_p) {}

	std::string getName() {
		return "Communal Services";
	}

	~CommunalServices() = default;
};

class Debet :public Categories {
public:
	Debet() = default;
	Debet(double sum_p, char* date_p) : Categories(sum_p, date_p) {}

	std::string getName() {
		return "Debet";
	}

	~Debet() = default;
};

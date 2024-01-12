#pragma once
#include <iostream>
#include <string>

constexpr double EPS = 1e-10;

struct ComplexNumber {

public:
	ComplexNumber(double real = 0.0, double imag = 0.0);

	double get_real() const;
	double get_imag() const;

	void set_real(double real);
	void set_imag(double imag);

	std::string to_string() const;

	ComplexNumber operator+(ComplexNumber other) const;
	ComplexNumber operator-(ComplexNumber other) const;

	ComplexNumber operator/(ComplexNumber other) const;
	ComplexNumber operator/(double number) const;

	ComplexNumber operator*(ComplexNumber other) const;
	ComplexNumber operator*(double number) const;

	bool operator==(ComplexNumber other) const;
	bool operator!=(ComplexNumber other) const;

	ComplexNumber pow(int exp) const;

	double abs() const;

	friend std::ostream& operator<<(std::ostream& os, ComplexNumber complex);

	
private:
	double real;
	double imag;
};


bool are_equal(double number1, double number2);

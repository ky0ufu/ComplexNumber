#include "ComplexNumber.h"
#include <cmath>

ComplexNumber::ComplexNumber(double real, double imag) : real(real), imag(imag) {}


double ComplexNumber::get_real() const {
	return this->real;
}

double ComplexNumber::get_imag() const {
	return this->imag;
}

void ComplexNumber::set_real(double real) {
	this->real = real;
}

void ComplexNumber::set_imag(double imag) {
	this->imag = imag;
}

std::string ComplexNumber::to_string() const {
	return std::to_string(this->real) + "+" + std::to_string(this->imag) + "i";
}

ComplexNumber ComplexNumber::operator+(ComplexNumber other) const {
	return ComplexNumber(this->real + other.real, this->imag + other.imag);
}

ComplexNumber ComplexNumber::operator-(ComplexNumber other) const {
	return ComplexNumber(this->real - other.real, this->imag - other.imag);
}

ComplexNumber ComplexNumber::operator*(ComplexNumber other) const {
	return ComplexNumber(this->real * other.real - this->imag * other.imag, this->real * other.imag + this->imag * other.real);
}

ComplexNumber ComplexNumber::operator*(double number) const {
	return ComplexNumber(this->real * number, this->imag * number);
}

ComplexNumber ComplexNumber::operator/(ComplexNumber other) const {
	double division = std::pow(other.real, 2) + std::pow(other.imag, 2);

	if (std::fabs(division) < EPS)
		throw std::runtime_error("division by zero complex number");

	return ComplexNumber(this->real * other.real + this->imag * other.imag, this->imag * other.real - this->real * other.imag) / division;
}

ComplexNumber ComplexNumber::operator/(double number) const {
	if (std::fabs(number) < EPS)
		throw std::runtime_error("division by zero");

	return ComplexNumber(this->real / number, this->imag / number);
}

bool ComplexNumber::operator==(ComplexNumber other) const {
	return are_equal(this->real, other.real) && are_equal(this->imag, other.imag);
}

bool ComplexNumber::operator!=(ComplexNumber other) const {
	return !are_equal(this->real, other.real) || !are_equal(this->imag, other.imag);
}

ComplexNumber ComplexNumber::pow(int exp) const {
	double abs = this->abs();
		
	if (std::fabs(abs) < EPS)
		throw std::runtime_error("division by zero");

	double exp_phi = std::acos(this->real / abs) * exp;

	double cos_exp = std::cos(exp_phi);
	double sin_exp = std::sin(exp_phi);

	return ComplexNumber(cos_exp, sin_exp) * std::pow(abs, exp);
}

std::ostream& operator<<(std::ostream& os, ComplexNumber complex) {
	os << complex.to_string();
	return os;
}

double ComplexNumber::abs() const {
	return std::sqrt(std::pow(this->real, 2) + std::pow(this->imag, 2));
}


bool are_equal(double number1, double number2) {
	return std::fabs(number1 - number2) <= EPS;
}
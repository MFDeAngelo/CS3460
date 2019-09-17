#include <iostream>

double add(double left, double right) {
	return left + right;
}

double multiply(double left, double right) {
	return left * right;
}

double binary_op(double left, double right, double (*f)(double, double)) {
	return (*f)(left, right);
}



double testFunction(double value) {
	return value * value - value;
}

double relativeError(double exact, double approximation) {
	return abs(exact - approximation);
}

double absoluteError(double exact, double approximation) {
	return abs((approximation - exact) / exact);
}

double machineEpsilon() {
	double x = 1;
	double h = 1;
	while (x + h != x) {
		h /= 2;
	}
	return h;
}

double derivative(double (*f)(double), double x) {
	double h = 1;
	double value;
	while (x + h != x - h){
		value = ((*f)(x + h) - (*f)(x - h)) / ((x + h) - (x - h));
		h /= 2;
	}
	return value;
}

double testerFunction(double x) {
	return x * x - x + 3 * x * x * x - 4;
}

int main() {
	double a = 5.0;
	double b = 10.0;

	std::cout << "Add: " << binary_op(a, b, add) << std::endl;
	std::cout << "Multiply: " << binary_op(a, b, multiply) << std::endl;

	std::cout << "relative: " << relativeError(10, 12) << std::endl;
	std::cout << "absolute: " << absoluteError(10, 1.2) << std::endl;
	


	std::cout << "epsilon: " << machineEpsilon() << std::endl;

	std::cout << "Derivative at x=2 is: " << derivative(testerFunction, 2) << std::endl;



	return 0;
}
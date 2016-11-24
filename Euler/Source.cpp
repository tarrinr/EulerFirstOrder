#include "Twin.h"

int main() {

	double a, dt, lt, ut, iy;
	std::vector<double> result;

	Twin t("Euler's Method");
	
	t.println("For the equation (D + a) * y(t) = 0, enter a.");
	t.println("Example: 1.2");
	t.getInput(a);

	t.println("Enter lower bound of t.");
	t.println("Example: 2.3");
	t.getInput(lt);

	t.println("Enter upper bound of t.");
	t.println("Example: 3.4");
	t.getInput(ut);

	t.println("Enter step size of t.");
	t.println("Example: .25");
	t.getInput(dt);

	t.println("Enter initial condition, y(");
	t.print(lt);
	t.print(").");
	t.println("Example: 6.5");
	t.getInput(iy);

	t.println("Enter 'd' to show results, or 'f' to save results to file.");
	char d;
	t.getInput(d);

	result.push_back(iy);
	for (double i = lt + dt; i <= ut; i += dt)
		result.push_back((1 - dt * a) * result.back());

	t.println("Values of y for (D + ");
	t.print(a * -1);
	t.print(") * y(t) = 0 when t is between ");
	t.print(lt);
	t.print(" and ");
	t.print(ut);
	t.print(" with a step size of ");
	t.print(dt);
	t.print(", and ");
	t.print("y(");
	t.print(lt);
	t.print(") = ");
	t.print(iy);
	t.print(".");

	t.println();
	t.printmulti(result);
	t.println();

	if (d != 'd' && d != 'D') t.toFile();

	t.exit();
	return EXIT_SUCCESS;
}

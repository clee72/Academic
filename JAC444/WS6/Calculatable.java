
/**
Workshop 6
Section: NEE
Name: Wonhwa Lee
Student No.: 076 086 149
Email: wlee72@myseneca.ca
*/

package shapes;

/**
 	(Functional Programming and Lambda Expressions)			

		  Calculatable(interface) - getArea()
			   |
 	+-------------------------------------+   					          
	|				      |
	Rectangle			      Circle
	|
	Square
			               
*/


@FunctionalInterface
public interface Calculatable {
	double getArea();
}

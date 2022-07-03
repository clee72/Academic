/**
Workshop 6
Section: NEE
Name: Wonhwa Lee
Student No.: 076 086 149
Email: wlee72@myseneca.ca
*/

package shapes;

public class Rectangle extends Parallelogram implements Shape {

	// Constructor with arguments
	public Rectangle(String name, double width, double height) throws ParallelogramException {
		super(name, width, height);
	}

	@Override
	public String toString() {
		// Create an object of the Calculatable interface type using Lambda Expression
		Calculatable rectangleArea = () -> getWidth() * getHeight();

		return getName() + " {w=" + getWidth() + ", h=" + getHeight() + "} " + "perimeter = "
				+ df.format(getPerimeter()) + " area = " + df.format(rectangleArea.getArea()) 
				+ '\n';
	}
}

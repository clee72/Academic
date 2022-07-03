/**
Workshop 3
Section: NEE
Name: Wonhwa Lee
Student No.: 076 086 149
Email: wlee72@myseneca.ca
*/

package shapes;

import java.text.DecimalFormat;

public class Circle implements Shape {
	DecimalFormat df = new DecimalFormat("##0.0000#");

	// Field
	private String name;
	private double radius;

	// Constructor
	Circle(String name, double radius) throws CircleException {
		if (radius > 0) {
			this.name = name;
			this.radius = radius;
			ShapeMain.shapeCount++;
		} else {
			throw new CircleException("invalid radius!");
		}
	}

	// Setters and Getters
	public double getRadius() {
		return radius;
	}

	public void setRadius(double radius) throws CircleException {
		if (radius > 0) {
			this.radius = radius;
		} else {
			throw new CircleException("invalid radius!");
		}
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	// Method Overriding
	@Override
	public double getPerimeter() {
		return (2 * Math.PI * getRadius());
	}

	@Override
	public String toString() {
		return getName() + " {r=" + getRadius() + "} perimeter = " +
	           df.format(getPerimeter()) + '\n';
	}

}

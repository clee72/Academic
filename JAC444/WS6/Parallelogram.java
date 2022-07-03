/**
Workshop 6
Section: NEE
Name: Wonhwa Lee
Student No.: 076 086 149
Email: wlee72@myseneca.ca
*/

package shapes;

import java.text.DecimalFormat;

public class Parallelogram implements Shape {

	DecimalFormat df = new DecimalFormat("##0.0000##");

	// Field
	private String name;
	private double width;
	private double height;

	// Constructor
	Parallelogram(String name, double width, double height) throws ParallelogramException {
		if (width > 0 && height > 0) {
			this.name = name;
			this.width = width;
			this.height = height;
			ShapeMain.shapeCount++;
		} else {
			throw new ParallelogramException("Invalid side!");
		}
	}

	// Setters and Getters
	public double getWidth() {
		return width;
	}

	public void setWidth(double width) throws ParallelogramException {
		if (width > 0) {
			this.width = width;
		} else {
			throw new ParallelogramException("Invalid side!");
		}
	}

	public double getHeight() {
		return height;
	}

	public void setHeight(double height) throws ParallelogramException {
		if (height > 0) {
			this.height = height;
		} else {
			throw new ParallelogramException("Invalid side!");
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
		return (2 * getWidth() + 2 * getHeight());
	}

	@Override
	public String toString() {
		return getName() + " {w=" + getWidth() + ", h=" + getHeight() + "} " + 
	           "perimeter = "+ df.format(getPerimeter()) + '\n';
	}
}

/**
Workshop 3
Section: NEE
Name: Wonhwa Lee
Student No.: 076 086 149
Email: wlee72@myseneca.ca
*/

package shapes;

import java.text.DecimalFormat;

public class Triangle implements Shape {

	DecimalFormat df = new DecimalFormat("##0.0000#");

/**
	 
	  /\ 
side3/  \ side2
	/____\ 
	 side1
*/
	
	
	// Field
	private String name;
	private double side1;
	private double side2;
	private double side3;

	// Constructor
	Triangle(String name, double side1, double side2, double side3) throws TriangleException {
		double max = 0;
		if (side1 > 0 && side2 > 0 && side3 > 0) {
			// validate if the shape is a triangle
			max = Math.max(side1, Math.max(side2, side3));
			if ((side1 + side2 + side3) - max > max) {
				this.name = name;
				this.side1 = side1;
				this.side2 = side2;
				this.side3 = side3;
				ShapeMain.shapeCount++;
			} else {
				throw new TriangleException("Invalid side(s)!");
			}

		} else {
			throw new TriangleException("Invalid side(s)!");
		}
	}

	// Setters and Getters
	public double getSide1() {
		return side1;
	}

	public void setSide1(double side1) throws TriangleException {
		if (side1 > 0) {
			this.side1 = side1;
		} else {
			throw new TriangleException("Invalid side!");
		}
	}

	public double getSide2() {
		return side2;
	}

	
	public void setSide2(double side2) throws TriangleException {
		setSide1(side2);
	}

	public double getSide3() {
		return side3;
	}


	public void setSide3(double side3) throws TriangleException {
		setSide1(side3);
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
		return getSide1() + getSide2() + getSide3();
	}

	@Override
	public String toString() {
		return getName() + " {s1=" + getSide1() + ", s2=" + getSide2() + ", s3=" + getSide3()
		       + "}" + " perimeter = "+ df.format(getPerimeter()) + '\n';
	}

}

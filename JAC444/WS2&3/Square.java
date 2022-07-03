/**
Workshop 3
Section: NEE
Name: Wonhwa Lee
Student No.: 076 086 149
Email: wlee72@myseneca.ca
*/

package shapes;

public class Square extends Rectangle implements Shape {

	// Constructor
	Square(String name, double width) throws ParallelogramException {
		super(name, width, width );
	}
	
	@Override
	public void setWidth(double width) throws ParallelogramException  {
		super.setWidth(width);
		super.setHeight(width);
	}
	
	@Override
	public void setHeight(double height) throws ParallelogramException  {
		setWidth(height);
	}
	
	@Override
	public String toString() {
		return getName()+" {s=" + getWidth() + "} perimeter = "
	           + df.format(getPerimeter()) + '\n';
	}
}

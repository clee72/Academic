/**
Workshop 3
Section: NEE
Name: Wonhwa Lee
Student No.: 076 086 149
Email: wlee72@myseneca.ca
*/

package shapes;

/**
 	          (Inheritance Relationship Between Classes)	
		
				  Shape(interface) - getPerimeter()
					    |
		+---------------------------+--------------------+   
		|			    |                    |
		Parallelogram		    Triagngle		 Circle
		|
		Rectangle
		|
		Square
					               
*/

public interface Shape {
	double getPerimeter();
}




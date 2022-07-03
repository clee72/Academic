/**
Workshop 3
Section: NEE
Name: Wonhwa Lee
Student No.: 076 086 149
Email: wlee72@myseneca.ca
*/

package shapes;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.IOException;

public class ShapeMain {
	final static String CIRCLE = "Circle";
	final static String TRIANGLE = "Triangle";
	final static String SQUARE = "Square";
	final static String PARALLELOGRAM = "Parallelogram";
	final static String RECTANGLE = "Rectangle";

	// counting object creation
	public static int shapeCount = 0;

	// counting the total number of the file text lines
	@SuppressWarnings("resource")
	public static int countLines() throws IOException {
		File file = new File("shapes.txt");
		FileInputStream fi = new FileInputStream(file);
		byte[] byteArr = new byte[(int) file.length()];
		fi.read(byteArr);
		String data = new String(byteArr);
		String[] stringArr = data.split("\r\n");
		return stringArr.length;
	}

	public static void main(String[] args) {
		int lines = 0;
		try {
			lines = countLines();
		} catch (IOException e) {
			e.printStackTrace();
		}
		Shape[] arr = new Shape[lines];
		Shape sh = null;
		int i = 0;

		System.out.println("------->JAC 444 Assignment 1<-------");
		System.out.println("------->Task 1 ... <-------");

		try (BufferedReader br = new BufferedReader(new FileReader("shapes.txt"))) {
			String strCurrentLine = "";
			String shapeName = "";

			while ((strCurrentLine = br.readLine()) != null) {

				String[] tokens = strCurrentLine.split(",");
				shapeName = tokens[0];

				// reset to false for each loop
				boolean isValidShape = false;
				switch (shapeName) {
				case CIRCLE:
					if (tokens.length == 2) {
						try {
							sh = new Circle(tokens[0], Double.parseDouble(tokens[1]));
							isValidShape = true;
						} catch (CircleException e) {
							System.out.println(e.getMessage());
						}
					}
					break;

				case TRIANGLE:
					if (tokens.length == 4) {
						try {
							sh = new Triangle(tokens[0], Double.parseDouble(tokens[1]),
									 Double.parseDouble(tokens[2]),
									 Double.parseDouble(tokens[3]));
							isValidShape = true;
						} catch (TriangleException e) {
							System.out.println(e.getMessage());
						}
					}
					break;

				case SQUARE:
					if (tokens.length == 2) {
						try {
							sh = new Square(tokens[0], Double.parseDouble(tokens[1]));
							isValidShape = true;
						} catch (ParallelogramException e) {
							System.out.println(e.getMessage());
						}
					}
					break;

				case RECTANGLE:
					if (tokens.length == 3) {
						try {
							sh = new Rectangle(tokens[0], Double.parseDouble(tokens[1]),
									 Double.parseDouble(tokens[2]));
							isValidShape = true;
						} catch (ParallelogramException e) {
							System.out.println(e.getMessage());
						}
					}
					break;

				case PARALLELOGRAM:
					if (tokens.length == 3) {
						try {
							sh = new Parallelogram(tokens[0], Double.parseDouble(tokens[1]),
									Double.parseDouble(tokens[2]));
							isValidShape = true;
						} catch (ParallelogramException e) {
							System.out.println(e.getMessage());
						}
					}
					break;

				default:

				}// switch
				if (isValidShape) {
					arr[i] = sh;
					i++;
				}
			}
			// file exception
		} catch (IOException e) {
			System.out.println(e.getMessage());
		}

		// total number of objects(Shapes) created
		System.out.println("\n" + shapeCount + " shapes were created:");

		for (int j = 0; j < arr.length; j++) {
			if (arr[j] != null)
				System.out.println(arr[j]);
		}

		/************************************
		  				task 2
		 *************************************/
		double min = Double.MAX_VALUE;
		double max = 0;

		// find the maximum value of the circle perimeter
		for (Shape cir : arr) {
			if ((cir instanceof Circle) &&
				(cir.getPerimeter() > max)) {
				max = cir.getPerimeter();
			}
		}
		// if the maximum value, set to null
		for (int k = 0; k < arr.length; k++) {
			if ((arr[k] instanceof Circle) && 
				(arr[k].getPerimeter() == max)) {
				arr[k] = null;
			}
		}
		// find the mininum value of the triangle perimeter
		for (Shape tri : arr) {
			if ((tri instanceof Triangle) && 
				(tri.getPerimeter() < min)) {
				min = tri.getPerimeter();
			}
		}

		// if the minimum value, set to null
		for (int m = 0; m < arr.length; m++) {
			if ((arr[m] instanceof Triangle) && 
				(arr[m].getPerimeter() == min)) {
				arr[m] = null;
			}
		}

		System.out.println("------->Task 2 ... <-------");
		// print only objects without null
		for (int j = 0; j < arr.length; j++) {
			if (arr[j] != null)
				System.out.println(arr[j]);
		}

		/************************************
		  				task 3
		 *************************************/
		double sumPara = 0;
		double sumTri = 0;

		// total perimeter of the parallelogram 
		// by checking if each element is an instance of the parallelogram
		for (Shape para : arr) {
			if ((para instanceof Parallelogram) && 
				!(para instanceof Square) && 
				!(para instanceof Rectangle)) {
				sumPara += para.getPerimeter();
			}
		}

		// total perimeter of the triangle
		//  by checking if each element is an instance of the triangle
		for (Shape tri : arr) {
			if (tri instanceof Triangle) {
				sumTri += tri.getPerimeter();
			}
		}

		System.out.println("------->Task 3 ... <-------");
		System.out.println("Total perimeter of Parallelogram is: " + sumPara);
		System.out.println("Total perimeter of Triangle is: " + sumTri);

	}// main
}// class

/**
Workshop 6
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
		//length type is 'long' so convert the length in int type
		//store texts as byte type into byteArr
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
			if (arr[j] != null) {
				System.out.println(arr[j]);
			}
		}
	}// main
}// class

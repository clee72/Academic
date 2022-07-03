/**
Workshop 5
Section: NEE
Name: Wonhwa Lee
Student No.: 076 086 149
Email: wlee72@myseneca.ca
*/

package application;

import java.io.FileInputStream;
import java.io.ObjectInputStream;

public class ReadFile {

	public Student readFile(String filename) {
		Student tmp = null;
		FileInputStream fsIn = null;
		ObjectInputStream osIn = null;
		try {
			// Create a stream for the file was created before.
			fsIn = new FileInputStream(filename);
			osIn = new ObjectInputStream(fsIn);

			tmp = (Student) osIn.readObject();

			fsIn.close();
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			System.out.println("Student Object has been Deserialized!");
		}
		return tmp;
	}
}// class

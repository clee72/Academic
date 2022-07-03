/**
Workshop 5
Section: NEE
Name: Wonhwa Lee
Student No.: 076 086 149
Email: wlee72@myseneca.ca
*/

package application;

import java.io.FileOutputStream;
import java.io.ObjectOutputStream;

public class WriteFile {
	public static final String FILENAME = "students.bin";

	public void writeFile(Student student, String filename) {
		FileOutputStream fsOut = null;
		ObjectOutputStream osOut = null;
		try {
			// create a new file with an ObjectOutputStream
			fsOut = new FileOutputStream(filename);
			osOut = new ObjectOutputStream(fsOut);

			// write Student object in the file
			osOut.writeObject(student);

			osOut.flush();
			fsOut.close();

		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			System.out.println("Student Object has been Serialized!");
		}
	}
}// class

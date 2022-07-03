package students;

import java.io.FileInputStream;
import java.io.ObjectInputStream;

public class ReadFile {

	public static void main(String[] args) {
		ReadFile rf = new ReadFile();
		Student clone = rf.readFile(WriteFile.FILENAME);

		System.out.println(clone.getStdID() + "\t" + clone.getFirstName() + "\t" + clone.getLastName() + "\t"
				+ clone.getCourses());

	}// main

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
			System.out.println("Student Object has been deserialized!");
		}
		return tmp;
	}

}// class

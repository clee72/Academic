package students;

import java.io.FileOutputStream;
import java.io.ObjectOutputStream;
import java.util.Scanner;

public class WriteFile {
	public static final String FILENAME = "students.bin";

	public static void main(String[] args) {
		Student student = new Student();
		WriteFile wf = new WriteFile();
		wf.getInput(student);
		wf.writeFile(student, WriteFile.FILENAME);
	}// main

	public void getInput(Student student) {
		Scanner scanner = new Scanner(System.in);
		boolean shouldContinue = true;

		while (shouldContinue) {
			// input for Student Id
			int id = 0;
			String sid = "";
			boolean isGoodStudentId = false;

			System.out.print("Enter number for student id: ");
			while (!isGoodStudentId) {
				sid = scanner.next();
				try {
					id = Integer.valueOf(sid);
					if (id < 0) {
						System.err.println("Negative number is not allowed here!");
						scanner.nextLine();
					} else {
						isGoodStudentId = true;
						student.setStdID(id);
					}
				} catch (NumberFormatException e) {
					e.getMessage();
					System.err.println("Character is not allowed here! Please enter number!");
					scanner.nextLine();
				} catch (Exception e) {
					e.getMessage();
				}
			}

			scanner.nextLine();

			// input for first name
			String fName = "";
			while (fName.isEmpty()) {
				System.out.println("Please enter first name:");
				fName = scanner.nextLine();

				if (fName.isEmpty()) {
					System.err.println("blank is not allowed!");
				} else {
					try {
						student.setFirstName(fName);
					} catch (Exception e) {
						e.printStackTrace();
					}
				}
			}

			// input for last name
			String lName = "";
			while (lName.isEmpty()) {
				System.out.println("Please enter last name: ");
				lName = scanner.nextLine();

				if (lName.isEmpty()) {
					System.err.println("blank is not allowed!");
				} else {
					try {
						student.setLastName(lName);
					} catch (Exception e) {
						e.printStackTrace();
					}
				}
			}

			// input for courses, stored into the ArrayList
			String course = "";
			boolean shouldGetMore = true;

			while (shouldGetMore) {
				System.out.println("Please enter courses(type 'n' to exit):");
				course = scanner.nextLine();

				if (course.isEmpty()) {
					System.err.println("blank is not allowed!");
				} else if (course.equalsIgnoreCase("n")) {
					shouldGetMore = false;
				} else {
					try {
						student.setCourses(course);
					} catch (Exception e) {
						e.printStackTrace();
					}
				}
			}

			// Prompt for a user to continue or not
			System.out.println("Please type any key to countinue or enter 'end' to exit");
			String input = scanner.nextLine();

			if (input.contentEquals("end")) {
				shouldContinue = false;
			}
		} // while

		// close scanner
		scanner.close();
	}

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
			System.out.println("Student Object has been serialized!");
		}
	}

}// class

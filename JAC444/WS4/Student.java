package students;

import java.io.Serializable;
import java.util.ArrayList;

public class Student implements Serializable {

	private static final long serialVersionUID = -9153513638418517881L;

	// fields
	private int stdID;
	private String firstName;
	private String lastName;
	private ArrayList<String> courses;

	// constructor
	public Student() {
		stdID = 0;
		firstName = "";
		lastName = "";
		courses = new ArrayList<String>();
	}

	public int getStdID() {
		return stdID;
	}

	// getters and setters
	public void setStdID(int stdID) throws Exception {
		if (stdID > 0) {
			this.stdID = stdID;
		} else {
			throw new Exception("Invalid Number!");
		}

	}

	public String getFirstName() {
		return firstName;
	}

	public void setFirstName(String firstName) throws Exception {
		if (firstName.isEmpty() || firstName == null) {
			throw new Exception("It must be not null or empty!");
		} else {
			this.firstName = firstName;
		}
	}

	public String getLastName() {
		return lastName;
	}

	public void setLastName(String lastName) throws Exception {
		if (lastName.isEmpty() || lastName == null) {
			throw new Exception("It must be not null or empty!");
		} else {
			this.lastName = lastName;
		}
	}

	public ArrayList<String> getCourses() {
		return courses;
	}

	public void setCourses(String course) throws Exception {
		if (course.isEmpty() || course == null) {
			throw new Exception("It must be not null or empty!");
		} else {
			// add a course into ArrayList
			this.courses.add(course);
		}
	}

}

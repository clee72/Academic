/**
Workshop 7
Section: NEE
Name: Wonhwa Lee
Student No.: 076 086 149
Email: wlee72@myseneca.ca
*/

package workshop7;

import java.text.DecimalFormat;

public class Student {
	private String firstName;
	private String lastName;
	private double grade;
	private String dept;

	private static DecimalFormat df = new DecimalFormat("0.00");
	// Constructor
	public Student(String firstName, String lastName, double grade, String dept) throws Exception {

		if ((firstName.isEmpty() || firstName == null) ||
				(lastName.isEmpty() || lastName == null) || 
				(dept.isEmpty() || dept == null)) {
			throw new Exception("It must be not null or empty!");
		} else if (grade < 0) {
			throw new Exception("Invalid number");
		} else {
			this.firstName = firstName;
			this.lastName = lastName;
			this.grade = grade;
			this.dept = dept;
		}
	}

	// Setters and Getters
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

	public double getGrade() {
		return grade;
	}

	public void setGrade(double grade) throws Exception {
		if (grade > 0) {
			this.grade = grade;
		} else {
			throw new Exception("invalid number");
		}
	}

	public String getDept() {
		return dept;
	}

	public void setDept(String dept) throws Exception {
		if (dept.isEmpty() || dept == null) {
			throw new Exception("It must be not null or empty!");
		}
		this.dept = dept;
	}

	public void setName(String firstName, String lastName) throws Exception {
		setFirstName(firstName);
		setLastName(lastName);
	}

	public String getName() {
		return firstName + '\t' + lastName;
	}

	@Override
	public String toString() {
		return getName() + '\t' +df.format(getGrade()) + '\t' + getDept();
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;

		if (obj == null)
			return false;

		if (getClass() != obj.getClass())
			return false;

		Student student = (Student) obj;

		if (firstName == null) {
			if (student.firstName != null)
				return false;
		} else if (!firstName.equals(student.firstName))
			return false;

		if (lastName == null) {
			if (student.lastName != null)
				return false;
		} else if (!lastName.equals(student.lastName))
			return false;

		if (Double.doubleToLongBits(grade) != Double.doubleToLongBits(student.grade))
			return false;

		if (dept == null) {
			if (student.dept != null)
				return false;
		} else if (!dept.equals(student.dept))
			return false;

		return true;
	}

}

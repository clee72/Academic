/**
Workshop 7
Section: NEE
Name: Wonhwa Lee
Student No.: 076 086 149
Email: wlee72@myseneca.ca
*/

package workshop7;

import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class StudentProcess {

	public static void main(String[] args) throws Exception {

		/** Task 1 */

		Student [] students = {
				 new Student("Jack", "Smith", 50.0, "IT"),
				 new Student("Aaron", "Johnson", 76.0, "IT"),
				 new Student("Maaria", "White", 35.8, "Business"),
				 new Student("John", "White", 47.0, "Media"),
				 new Student("Laney", "White", 62.0, "IT"),
				 new Student("Jack", "Jones", 32.9, "Business"),
				 new Student("Wesley", "Jones", 42.89, "Media") };

		List<Student> list = Arrays.asList(students);

		System.out.println("Task 1: \n");
		System.out.println("Complete Student list:");
		list.forEach(System.out::println);

		/** Task 2 */

		System.out.println("\nTask 2: \n");
		System.out.println("Students who got 50.0-100.0 sorted by grade:");

		Stream<Student> stream1 = list.stream();
		// sorted by grade
		stream1.filter(s -> s.getGrade() >= 50.0 && s.getGrade() <= 100.0)
				.sorted((s1, s2) -> ((int) (s1.getGrade() - s2.getGrade())))
				.forEach(System.out::println);

		/** Task 3 */

		System.out.println("\nTask 3: \n");
		System.out.println("First Student who got 50.0-100.0:");

		Stream<Student> stream2 = list.stream();

		stream2.filter(s -> s.getGrade() >= 50.0 && s.getGrade() <= 100.0)
				// find the first student
				.findFirst()
				.ifPresent(s -> System.out.println(s));

		/** Task 4 */

		System.out.println("\nTask 4: \n");

		Stream<Student> stream3 = list.stream();

		List<Student> copyList = stream3.sorted(Comparator.comparing(Student::getLastName)
												.thenComparing(Student::getFirstName))
										.collect(Collectors.toList());

		copyList.forEach(System.out::println);

		System.out.println("\nStudents in descending order by last name then first:");

		Stream<Student> stream4 = copyList.stream();

		stream4.sorted(Comparator.comparing(Student::getLastName)
					   .thenComparing(Student::getFirstName).reversed())
				.forEach(System.out::println);

		/** Task 5 */

		System.out.println("\nTask 5: \n");
		System.out.println("Unique Student last names:");

		Stream<Student> stream5 = list.stream();

		Stream<String> lastName = stream5.map(Student::getLastName);
		lastName.sorted()// default:natural order
				.distinct()
				.forEach(System.out::println);
		
		
		/** Task 6 */
		
		System.out.println("\nTask 6: \n");
		System.out.println("Student names in order by last name then first name:");
		
		Stream<Student> stream6 = list.stream();
		List<Student> sortedList = stream6.sorted(Comparator.comparing(Student::getLastName)
															.thenComparing(Student::getFirstName))
										   .collect(Collectors.toList());
		
		Stream<String> fullName = sortedList.stream().map(Student::getName);
		fullName.forEach(System.out::println);
		
		

	}// main()

}

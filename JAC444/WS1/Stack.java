/**
Workshop 1
Section: NEE
Name: Wonhwa Lee
Student No.: 076 086 149
Email: wlee72@myseneca.ca
*/

package workshop1;

public class Stack {
	// fields
	private char storage[];
	private int size;

	// constructor with no argument
	Stack() {
		storage = new char[] { '\0' };
		size = 0;
	}

	// constructor with an argument
	Stack(String str) {
		storage = new char[str.length()];
		size = 0;
	}

	// add one char into storage[]
	public void push(char c) {
		storage[size++] = c;
	}

	// remove one char from storage, LIFO (last in, first out)
	public char pop() {
		return storage[--size];
	}

	// check if the storage[] is empty or not
	boolean isEmpty() {
		return (size == 0) ? true : false;
	}
}

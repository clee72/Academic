/**
Workshop 1
Section: NEE
Name: Wonhwa Lee
Student No.: 076 086 149
Email: wlee72@myseneca.ca
*/

package workshop1;

public class Palindrome {
	// fields
	private String testStr;
	private boolean isPalindrome;

	// constructor with an argument
	Palindrome(String testStr) {
		this.testStr = testStr;
		isPalindrome = false;
	}

	// check the received string(args[i]) is a palindrome or not
	void runPalTester() {
		Stack st;
		st = new Stack(testStr);

		for (int i = 0; i < testStr.length(); i++) {
			st.push(testStr.charAt(i));
		}
		for (int j = 0; j < testStr.length() / 2; j++) {
			if (!st.isEmpty() && (testStr.charAt(j) == st.pop())) {
				isPalindrome = true;
			} else {
				isPalindrome = false;
				break;
			}
		}
	}

	// display results
	void display() {
		System.out.println("Test String->(" + testStr + "): " + testStr
				+ ((isPalindrome) ? " is Palindrome" : " is NOT Palindrome"));
	}

	public static void main(String[] args) {
		Palindrome[] palindromes = new Palindrome[args.length];
		// create Palindrome object(s) based on the received string(s)
		// and add into palindromes[].
		for (int i = 0; i < args.length; i++) {
			palindromes[i] = new Palindrome(args[i]);
			palindromes[i].runPalTester();
		}

		for (Palindrome pal : palindromes) {
			pal.display();
		}
	}

}

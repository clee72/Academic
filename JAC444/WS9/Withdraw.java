/**
Workshop 9
Section: NEE
Name: Wonhwa Lee
Student No.: 076 086 149
Email: wlee72@myseneca.ca
*/

package workshop9;

public class Withdraw extends Thread {
	private SharedAccount ac;
	private int size;

	public Withdraw(SharedAccount ac, int size) {
		super("Receiver");
		this.ac = ac;
		this.size = size;
	}

	public void run() {
		try {
			Thread.sleep(1000);
			for (int amount = 1; amount <= size; amount++) {
				ac.withdraw(amount);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}

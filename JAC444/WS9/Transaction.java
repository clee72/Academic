/**
Workshop 9
Section: NEE
Name: Wonhwa Lee
Student No.: 076 086 149
Email: wlee72@myseneca.ca
*/

package workshop9;

public class Transaction {
	
	public static void main(String[] args) {
		int numOfTrans = 0;
		
		if (args.length != 1) {
			System.out.printf("ERORR!, Usage: java.Transaction <numOfTrans>");
			System.out.println("e.g. numOfTrans 3");
			System.exit(0);
		}
		
		numOfTrans = Integer.parseInt(args[0]);// numOfTrans = 3
		
		SharedAccount acc = new SharedAccount(0);

		// two threads (Sender, Receiver)
		Deposit sender = new Deposit(acc);
		Withdraw receiver = new Withdraw(acc, numOfTrans);

		sender.start();
		receiver.start();

		try {
			sender.join();
			receiver.join();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}

		System.out.println("All transactions are completed!");

	}// main
}// class

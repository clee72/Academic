/**
Workshop 9
Section: NEE
Name: Wonhwa Lee
Student No.: 076 086 149
Email: wlee72@myseneca.ca
*/

package workshop9;

public class SharedAccount {

	private int balance;
	private String currency;

	public SharedAccount(int balance) {
		this.balance = balance;
		currency = "";
	}

	public synchronized int getBalance() {
		return balance;
	}

	public synchronized void setBalance(int balance) throws Exception {
		if (balance < 0) {
			throw new Exception("invalid amounts");
		}
		this.balance = balance;
	}

	public synchronized String getCurrency() {
		return currency;
	}

	public synchronized void setCurrency(String currency) {
		if ((currency == null) || (currency.isEmpty())) {
			throw new NullPointerException();
		}
		this.currency = currency;
	}

	// deposit money
	public synchronized void deposit(String newType, int amount) throws Exception {
		String threadName = Thread.currentThread().getName();

		// can not deposit, until withdraw
			while(!getCurrency().equals(newType) && getBalance() != 0) {
				Thread.sleep(1000);
				System.err.println("Waiting for withdraw....");
				Thread.sleep(1000);
				System.err.println(threadName + " is unable to deposit " + amount + " " + newType
					+ "...\nDifferent type of the currency, [Current currency type : " + getCurrency() + "].");
				wait();
			}

		balance = getBalance() + amount;
		setCurrency(newType);
		setBalance(balance);

		System.out.println(threadName + " made a deposit of " + amount + " " + getCurrency() + "(s) successfully.");
	
		notify();
	}

	// withdraw money
	public synchronized void withdraw(int amount) throws Exception {
		String threadName = Thread.currentThread().getName();

		// can not withdraw until deposit
			while (getBalance() < amount) {
				System.err.println("Waiting for deposit...");
				Thread.sleep(1000);
				System.err.println("Insufficient Funds!, Current Balance : " + getBalance() + " " + getCurrency()
					+ ".\nWaiting for deposit...");
				wait();
			}
	
		balance = getBalance() - amount;
		setBalance(balance);
		System.out.println(threadName + " withdrew " + amount + " " + getCurrency() + "(s) successfully.");
		
		notify();

	}
}

/**
Workshop 9
Section: NEE
Name: Wonhwa Lee
Student No.: 076 086 149
Email: wlee72@myseneca.ca
*/

package workshop9;

import java.util.LinkedHashMap;
import java.util.Map;

class Deposit extends Thread {

	private SharedAccount ac;

	public Deposit(SharedAccount ac) {
		super("Sender");
		this.ac = ac;
	}

	public void run() {
		Map<String, Integer> depositLists = new LinkedHashMap<String, Integer>();

		// Deposit: 1 Dollar, 2 Euros, 3 Pounds
		depositLists.put("Dollar", 1);
		depositLists.put("Euro", 2);
		depositLists.put("Pound", 3);

		try {
			depositLists.forEach((currency, amount) -> {
				try {
					ac.deposit(currency, amount);
				} catch (Exception e) {
					e.printStackTrace();
				}
			});
		} catch (Exception e) {
			e.printStackTrace();
		}

	}
}

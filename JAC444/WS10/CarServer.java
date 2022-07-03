/**
Workshop 10
Section: NEE
Name: Wonhwa Lee
Student No.: 076 086 149
Email: wlee72@myseneca.ca
*/

package workshop10;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class CarServer {

	public CarServer() {
		try {
			Registrable obj = new RegistrableImpl();
			Registry registry = LocateRegistry.createRegistry(7070);
			registry.rebind("CarPlateService", obj);

		} catch (Exception e) {
			System.err.println("Server Exception: " + e.getMessage());
		}
	}

	public static void main(String[] args) {
		new CarServer();
		System.out.println("Car plate service is ready..");
	}
}

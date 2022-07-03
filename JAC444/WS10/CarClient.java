/**
Workshop 10
Section: NEE
Name: Wonhwa Lee
Student No.: 076 086 149
Email: wlee72@myseneca.ca
*/

package workshop10;

import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.util.ArrayList;
import java.util.List;

public class CarClient {

	public static void main(String[] args) {
		try {
			List<Car> list = new ArrayList<>();

			list.add(new Car("Toyota Corolla", "Black", 1000));
			list.add(new Car("Honda Civic", "White", 2000));
			list.add(new Car("Volovo S70", "Gray", 3000));

			// print each car object before registration
			System.out.println("Registration is required for new cars.");
			list.forEach(System.out::println);

			// registration starts
			Registrable obj = (Registrable) Naming.lookup("rmi://localhost:7070/CarPlateService");

			System.out.println("\nAfter registered..");
			for (int i = 0; i < list.size(); i++) {
				// print each car object after registration
				System.out.println(obj.registerCar(list.get(i)));
			}

		} catch (MalformedURLException | RemoteException | NotBoundException e) {
			System.err.println("Client Exception: " + e.getMessage());
		}
	}
}

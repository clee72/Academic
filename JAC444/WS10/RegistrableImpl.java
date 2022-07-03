/**
Workshop 10
Section: NEE
Name: Wonhwa Lee
Student No.: 076 086 149
Email: wlee72@myseneca.ca
*/

package workshop10;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

@SuppressWarnings("serial")
public class RegistrableImpl extends UnicastRemoteObject implements Registrable {

	public RegistrableImpl() throws RemoteException {
		super();
	}

	@Override
	public Car registerCar(Car car) throws RemoteException {

		try {
			car.setPlate(String.valueOf(car.hashCode()));
		} catch (Exception e) {
			e.printStackTrace();
		}
		return car;
	}
}

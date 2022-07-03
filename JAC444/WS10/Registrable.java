/**
Workshop 10
Section: NEE
Name: Wonhwa Lee
Student No.: 076 086 149
Email: wlee72@myseneca.ca
*/

package workshop10;

import java.rmi.Remote;

public interface Registrable extends Remote {
	public Car registerCar(Car car) throws java.rmi.RemoteException;
}

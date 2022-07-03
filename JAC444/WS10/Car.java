/**
Workshop 10
Section: NEE
Name: Wonhwa Lee
Student No.: 076 086 149
Email: wlee72@myseneca.ca
*/

package workshop10;

import java.io.Serializable;

@SuppressWarnings("serial")
public class Car implements Serializable {
	private String model;
	private String color;
	private double mileage;
	private String plate;

	public Car(String model, String color, double mileage) {
		this.model = model;
		this.color = color;
		this.mileage = mileage;
		plate = "Unregistered";
	}

	public String getModel() {
		return model;
	}

	public void setModel(String model) throws Exception {
		if ((model == null) || (model.isEmpty())) {
			throw new Exception("It must not be null or empty.");
		}
		this.model = model;
	}

	public String getColor() {
		return color;
	}

	public void setColor(String color) throws Exception {
		if ((color == null) || (color.isEmpty())) {
			throw new Exception("It must not be null or empty.");
		}
		this.color = color;
	}

	public double getMileage() {
		return mileage;
	}

	public void setMileage(double mileage) throws Exception {
		if (mileage < 0) {
			throw new Exception("Invalid number.");
		}
		this.mileage = mileage;
	}

	public String getPlate() {
		return plate;
	}

	public void setPlate(String plate) throws Exception {
		if ((plate == null) || (plate.isEmpty())) {
			throw new Exception("It must not be null or empty.");
		}
		this.plate = plate;
	}

	@Override
	public String toString() {
		return "[Model: " + getModel() + ", Color: " + getColor() + ", Mileage: " + getMileage() + ", Plate Number: "
				+ getPlate() + "]";
	}
}

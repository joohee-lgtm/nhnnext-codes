package abstractex;

public class Truck extends Vehicle {
	
	private double distance;
	private double fuel;

	public Truck(double distance, double fuel){
		this.distance = distance;
		this.fuel = fuel;
	}

	@Override
	public double clacFuelEfficiency() {
		return fuel;
	}

	@Override
	public double clacTripDistance() {
		return distance;
	}
}

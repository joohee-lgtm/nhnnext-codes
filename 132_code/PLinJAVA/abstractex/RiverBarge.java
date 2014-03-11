package abstractex;

public class RiverBarge extends Vehicle {

	private double distance;
	private double fuel;

	public RiverBarge(double distance, double fuel){
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

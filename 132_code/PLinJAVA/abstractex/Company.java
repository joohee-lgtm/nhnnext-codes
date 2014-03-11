package abstractex;

import java.util.ArrayList;

public class Company {
	
	public ArrayList<Vehicle> veh = new ArrayList<Vehicle>();

	private Company(){}
	private static Company company = new Company();
	
	public static Company getInstance() {
		return company;
	}
	
	public void addVehicle(Vehicle vehicle) {
		veh.add(vehicle);
	}
}

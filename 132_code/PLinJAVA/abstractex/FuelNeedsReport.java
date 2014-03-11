package abstractex;

import java.io.PrintStream;

public class FuelNeedsReport {

	public FuelNeedsReport(){}
	public void generateText(PrintStream out) {
		Company c = Company.getInstance();
		double temp = 0;
		for  (Vehicle  v : c.veh){
			temp += v.calFuelNeeds();
		}
		out.println(temp);
	}
}

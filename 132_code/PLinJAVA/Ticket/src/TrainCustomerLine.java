import java.util.ArrayList;

import java.util.Collections;


public class TrainCustomerLine {
	
	public static ArrayList<Customer> trainLine = new ArrayList<Customer>();
	
	public void getTrainLine(){
				
		Customer c1;
		Customer c2;
		Customer c3;
		
		do{
			
			c1 = TicketStation.staff1.deCustomer();
			c2 = TicketStation.staff2.deCustomer();
			c3 = TicketStation.staff3.deCustomer();
			
			enCustomer(c1);
			enCustomer(c2);
			enCustomer(c3);
			
		} while ( c1 != null || c2 != null || c3 != null);
		
		Collections.sort(trainLine);
		
	}
	
	void enCustomer(Customer customer){
		if (customer != null){
			trainLine.add(customer);
		}
	}

}

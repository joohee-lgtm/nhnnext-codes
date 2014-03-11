import java.util.ArrayList;

public class Staff {
	
	 // staff 마다 처리할 손님들이 줄서는 리스트
	ArrayList<Customer> customerLine = new ArrayList<Customer>();
	public int worktime = 0;
	
	void workingTime(Customer customer){
		if (customer.ticketing_arrival_time >= worktime ){
			this.worktime = customer.ticketing_arrival_time + customer.ticketing_prog_time;
		}
		else {
			this.worktime = this.worktime + customer.ticketing_prog_time;
		}
	}
	
	void enCustomer(Customer customer){
		this.customerLine.add(customer);
	}
	
	Customer deCustomer(){
		if (customerLine.size() != 0){
			Customer decustomer = this.customerLine.get(0);
			this.customerLine.remove(0);
			return decustomer;
		}
		else {
			return null;
		}
	}
}

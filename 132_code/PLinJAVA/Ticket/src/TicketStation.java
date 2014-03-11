import java.io.IOException;


public class TicketStation {
	
	public static Staff staff1 = new Staff();
	public static Staff staff2 = new Staff();
	public static Staff staff3 = new Staff();
	
	public void getCustomer() throws IOException{
		
		TicketCustomerLine ticketcl = new TicketCustomerLine();
		// 초기 고객 줄 세우기
		ticketcl.makeTicketCustomerLine();
		
		for (int i=0; i< TicketCustomerLine.ticketWaitLine.size() ; i++){
			Customer cst = TicketCustomerLine.ticketWaitLine.get(i);
			// 스텝 3명 중 한명한테 가는 함수
			Staff stf = SelectStaff(cst);
			// 티켓 시간 관련 함수
			cst.getTicketTime(stf);
			// 열차 시간 관련 함수
			cst.getTrainTime();
			// 스텝 일 시간 증가 시켜줌
			
			stf.workingTime(cst);
			//System.out.println( cst.staff +" / " + stf.worktime);
		}
		
		/*
		스태프의 손님줄 확인, 총 일한 시간 확인
		System.out.println("-----");
		
		System.out.println("staff1");
		for (int i=0; i<staff1.customerLine.size(); i++){
			System.out.println(staff1.customerLine.get(i).name);
		}
		System.out.println(staff1.worktime);
		
		System.out.println("staff2");
		for (int i=0; i<staff2.customerLine.size(); i++){
			System.out.println(staff2.customerLine.get(i).name);
		}
		System.out.println(staff2.worktime);

		System.out.println("staff3");
		for (int i=0; i<staff3.customerLine.size(); i++){
			System.out.println(staff3.customerLine.get(i).name);
		}
		System.out.println(staff3.worktime);

		System.out.println("-----");
		*/
	}

	public Staff SelectStaff(Customer customer){
		
		if (staff1.worktime <= staff2.worktime && staff1.worktime <= staff3.worktime){
			customer.staff = "a";
			staff1.enCustomer(customer);
			return staff1;
		}
		else if (staff2.worktime <= staff1.worktime && staff2.worktime <= staff3.worktime){
			customer.staff = "b";
			staff2.enCustomer(customer);
			return staff2;
		}
		else if (staff3.worktime <= staff1.worktime && staff3.worktime <= staff2.worktime){
			customer.staff = "c";
			staff3.enCustomer(customer);
			return staff3;
		}
		else {
			customer.staff = "a";
			staff1.enCustomer(customer);
			return staff1;
		}			
	}
}
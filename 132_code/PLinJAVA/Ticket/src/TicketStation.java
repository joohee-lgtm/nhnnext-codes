import java.io.IOException;


public class TicketStation {
	
	public static Staff staff1 = new Staff();
	public static Staff staff2 = new Staff();
	public static Staff staff3 = new Staff();
	
	public void getCustomer() throws IOException{
		
		TicketCustomerLine ticketcl = new TicketCustomerLine();
		// �ʱ� �� �� �����
		ticketcl.makeTicketCustomerLine();
		
		for (int i=0; i< TicketCustomerLine.ticketWaitLine.size() ; i++){
			Customer cst = TicketCustomerLine.ticketWaitLine.get(i);
			// ���� 3�� �� �Ѹ����� ���� �Լ�
			Staff stf = SelectStaff(cst);
			// Ƽ�� �ð� ���� �Լ�
			cst.getTicketTime(stf);
			// ���� �ð� ���� �Լ�
			cst.getTrainTime();
			// ���� �� �ð� ���� ������
			
			stf.workingTime(cst);
			//System.out.println( cst.staff +" / " + stf.worktime);
		}
		
		/*
		�������� �մ��� Ȯ��, �� ���� �ð� Ȯ��
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
import java.io.IOException;


public class TicketingMain {

	public static void main(String[] args) throws IOException{
		
		// �ʱ� �մ� �ټ���� ~ ���� ��� �Լ� ����		
		TicketStation ts = new TicketStation();
		ts.getCustomer();
	
		// Ƽ�� ���� �Ϸ��� �մԵ� ��� �� �����
		TrainCustomerLine traincl = new TrainCustomerLine();
		traincl.getTrainLine();
		
		// ���� �� ���� ���
		PrintInfo pi = new PrintInfo();
		pi.outputInfo();
	}	
}



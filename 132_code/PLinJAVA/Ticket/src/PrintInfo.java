import java.io.FileOutputStream;
import java.io.IOException;

public class PrintInfo {
	
	public void outputInfo() throws IOException{
		FileOutputStream fos = new FileOutputStream("TrainCustomerdata.txt",true);
		for (int i=0; i<TrainCustomerLine.trainLine.size(); i++ ){
			Customer c = TrainCustomerLine.trainLine.get(i);

			String info = c.num + ". " + c.name;
			
			String ticket = "Ƽ�� ���� �ð� ���� ===>>>> "
						+ "���� : " + c.ticketing_arrival_time + "	| "
						+ "���� : " + c.staff + "	| "
						+ "��� : " + c.ticketing_wait_time + "	| " 
						+ "���� : " + c.ticketing_start_time + "	| "
						+ "���� : " + c.ticketing_prog_time + "	| "
						+ "���� : " + c.ticketing_end_time ;

			String train = "���� ���� �ð� ���� ===>>>> "
						+ "��� : " + c.train_wait_time + "	| " 
						+ "��� : " + c.train_start_time + "	| "
						+ "�̵� : " + c.train_boarding_time + "	| "
						+ "���� : " + c.train_end_time;

			String line = "\n";
			
			
			fos.write(info.getBytes());
			fos.write(line.getBytes());
			fos.write(ticket.getBytes());
			fos.write(line.getBytes());
			fos.write(train.getBytes());
			fos.write(line.getBytes());
			fos.write(line.getBytes());

		}
		fos.close();
		System.out.println("��� �Ϸ�");
	}
	
	
	public void print(){
		
		for( int i=0; i<TrainCustomerLine.trainLine.size(); i++){
			Customer c = TrainCustomerLine.trainLine.get(i);
			

			String info = c.num + ". " + c.name;
			
			String ticket = "Ƽ�� ���� �ð� ���� ===>>>> "
						+ "���� : " + c.ticketing_arrival_time + "	| "
						+ "���� : " + c.staff + "	| "
						+ "��� : " + c.ticketing_wait_time + "	| " 
						+ "���� : " + c.ticketing_start_time + "	| "
						+ "���� : " + c.ticketing_prog_time + "	| "
						+ "���� : " + c.ticketing_end_time ;

			String train = "���� ���� �ð� ���� ===>>>> "
						+ "��� : " + c.train_wait_time + "	| " 
						+ "��� : " + c.train_start_time + "	| "
						+ "�̵� : " + c.train_boarding_time + "	| "
						+ "���� : " + c.train_end_time;

			String line = "\n";
			
			System.out.println(info);
			System.out.println(ticket);
			System.out.println(train);
			System.out.println();

			
			
			/*
			System.out.println("�� ���̵� : " + c.name + " / "
							+ "ǥ ���� �� ���� : " + c.ticketing_arrival_time + "/ "
							+ "ǥ ���� ��� : " + c.ticketing_wait_time + " / " 
							+ "ǥ ���� ���� : " + c.ticketing_start_time + " / "
							+ "ǥ ���� ���� : " + c.ticketing_prog_time + " / "
							+ "ǥ ���� �� : " + c.ticketing_end_time + " / " 
							+ "���� ��� : " + c.train_wait_time + " / " 
							+ "���� ��� : " + c.train_start_time + " / "
							+ "���� ���� : " + c.train_end_time);*/
		}
	}
}

import java.io.FileOutputStream;
import java.io.IOException;

public class PrintInfo {
	
	public void outputInfo() throws IOException{
		FileOutputStream fos = new FileOutputStream("TrainCustomerdata.txt",true);
		for (int i=0; i<TrainCustomerLine.trainLine.size(); i++ ){
			Customer c = TrainCustomerLine.trainLine.get(i);

			String info = c.num + ". " + c.name;
			
			String ticket = "티켓 관련 시간 정보 ===>>>> "
						+ "도착 : " + c.ticketing_arrival_time + "	| "
						+ "스탭 : " + c.staff + "	| "
						+ "대기 : " + c.ticketing_wait_time + "	| " 
						+ "시작 : " + c.ticketing_start_time + "	| "
						+ "진행 : " + c.ticketing_prog_time + "	| "
						+ "종료 : " + c.ticketing_end_time ;

			String train = "열차 관련 시간 정보 ===>>>> "
						+ "대기 : " + c.train_wait_time + "	| " 
						+ "출발 : " + c.train_start_time + "	| "
						+ "이동 : " + c.train_boarding_time + "	| "
						+ "도착 : " + c.train_end_time;

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
		System.out.println("기록 완료");
	}
	
	
	public void print(){
		
		for( int i=0; i<TrainCustomerLine.trainLine.size(); i++){
			Customer c = TrainCustomerLine.trainLine.get(i);
			

			String info = c.num + ". " + c.name;
			
			String ticket = "티켓 관련 시간 정보 ===>>>> "
						+ "도착 : " + c.ticketing_arrival_time + "	| "
						+ "스탭 : " + c.staff + "	| "
						+ "대기 : " + c.ticketing_wait_time + "	| " 
						+ "시작 : " + c.ticketing_start_time + "	| "
						+ "진행 : " + c.ticketing_prog_time + "	| "
						+ "종료 : " + c.ticketing_end_time ;

			String train = "열차 관련 시간 정보 ===>>>> "
						+ "대기 : " + c.train_wait_time + "	| " 
						+ "출발 : " + c.train_start_time + "	| "
						+ "이동 : " + c.train_boarding_time + "	| "
						+ "도착 : " + c.train_end_time;

			String line = "\n";
			
			System.out.println(info);
			System.out.println(ticket);
			System.out.println(train);
			System.out.println();

			
			
			/*
			System.out.println("고객 아이디 : " + c.name + " / "
							+ "표 구입 역 도착 : " + c.ticketing_arrival_time + "/ "
							+ "표 구입 대기 : " + c.ticketing_wait_time + " / " 
							+ "표 구입 시작 : " + c.ticketing_start_time + " / "
							+ "표 구입 진행 : " + c.ticketing_prog_time + " / "
							+ "표 구입 끝 : " + c.ticketing_end_time + " / " 
							+ "기차 대기 : " + c.train_wait_time + " / " 
							+ "기차 출발 : " + c.train_start_time + " / "
							+ "기차 도착 : " + c.train_end_time);*/
		}
	}
}

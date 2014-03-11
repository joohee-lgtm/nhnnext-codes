import java.io.BufferedReader;

import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class TicketCustomerLine {
	
	public static ArrayList<Customer> ticketWaitLine = new ArrayList<Customer>();
	
	public void makeTicketCustomerLine() throws IOException{

		//File file = new File("rawda``ta.txt");
		FileReader fr = new FileReader("rawdata.txt");
		BufferedReader br = new BufferedReader(fr);
		String raw_info;

		while ((raw_info = br.readLine()) != null){
			setCustomer(raw_info);
		}
		br.close();
	}
	
	void setCustomer(String info){
		
		// 1 고객2001 0 2 Seoul Chuncheon
		String[] info_array;
		info_array = info.split(" ");
		
		Customer temp = new Customer();
		
		temp.num = Integer.parseInt(info_array[0]);
		temp.name = info_array[1];
		temp.ticketing_arrival_time = Integer.parseInt(info_array[2]);
		temp.ticketing_prog_time = Integer.parseInt(info_array[3]);
		temp.train_start_place = info_array[4];
		temp.train_end_place = info_array[5];

		ticketWaitLine.add(temp);
	}

}


 
/* 
public class TicketCustomerLine {
	
	//temp
	public static ArrayList<Customer> ticketWaitLine = new ArrayList<Customer>();

	
	public void makeTicketCustomerLine(){
		
		
		makeCustomer("c1", 0, 2, "a", "b");
		makeCustomer("c2", 0, 3, "a", "b");
		makeCustomer("c3", 1, 4, "a", "b");
		makeCustomer("c4", 1, 1, "a", "b");
		makeCustomer("c5", 1, 8, "a", "b");
		makeCustomer("c6", 4, 2, "a", "b");
		makeCustomer("c7", 5, 1, "a", "b");
		makeCustomer("c8", 7, 3, "a", "b");
		makeCustomer("c9", 7, 4, "a", "b");
		makeCustomer("c10", 10, 5, "a", "b");
		
		// 손님이 잘 들어갔는지 검사
		
		for (int i=0; i<10; i++){
			System.out.println(ticketWaitLine.get(i).name + " -> 이름 / "
							+ ticketWaitLine.get(i).ticketing_arrival_time + " -> 티켓팅 도착 시간 / "
							+ ticketWaitLine.get(i).ticketing_prog_time + " -> 티켓팅 진행 시간 / "
							+ ticketWaitLine.get(i).train_start_place + " -> 열차 출발지 / "
							+ ticketWaitLine.get(i).train_end_place + " -> 열차 도착지");
		}

	}
	
	// ex) 1 고객2001 0 2 Seoul Chuncheon
	public void makeCustomer
		(String name, int ticketing_arrival_time, int ticketing_prog_time, String train_start_place, String train_end_place){
		
		Customer temp = new Customer();
				
		temp.name = name;
		temp.ticketing_arrival_time = ticketing_arrival_time;
		temp.ticketing_prog_time = ticketing_prog_time;
		temp.train_start_place = train_start_place;
		temp.train_end_place = train_end_place;
		
		ticketWaitLine.add(temp);
	}	

}
*/

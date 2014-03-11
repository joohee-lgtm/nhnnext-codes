import java.io.IOException;


public class TicketingMain {

	public static void main(String[] args) throws IOException{
		
		// 초기 손님 줄세우기 ~ 정보 얻는 함수 실행		
		TicketStation ts = new TicketStation();
		ts.getCustomer();
	
		// 티켓 과정 완료한 손님들 대기 줄 세우기
		TrainCustomerLine traincl = new TrainCustomerLine();
		traincl.getTrainLine();
		
		// 최종 고객 정보 출력
		PrintInfo pi = new PrintInfo();
		pi.outputInfo();
	}	
}



public class Customer implements Comparable<Customer>{
	
	int num; // 승객ID
	String name; // 승객 이름 (외부에서 제공)
	
	int ticketing_arrival_time; // 티켓팅을 하러 도착한 시간(외부에서 제공)
	int ticketing_prog_time; // 티켓팅 하는데 걸리는 시간 (외부에서 제공)
	
	String staff;

	int ticketing_wait_time; // 티켓팅 대기시간
	int ticketing_start_time; // 티켓팅 시작 시간
	int ticketing_end_time; // 티켓팅이 끝난 시간	
	
	int train_wait_time; // 기차를 기다리는 시간
	int train_start_time; // 기차 출발 시간
	int train_boarding_time; // 기차에 이동하는 시간
	int train_end_time; // 기차에서 도착하는 시간
	
	String train_start_place; // 출발역(외부에서 제공)
	String train_end_place; // 도착역(외부에서 제공)
	
	// 티켓팅 관련 시간을 얻는 함수
	void getTicketTime(Staff staff){
		
		// 티켓팅 대기시간
		if (ticketing_arrival_time >= staff.worktime){
			this.ticketing_wait_time = 0;
		}
		else {
			this.ticketing_wait_time = staff.worktime - ticketing_arrival_time;
		}
		
		// 티켓팅 시작 시간
		this.ticketing_start_time = ticketing_arrival_time + this.ticketing_wait_time;
		// 티켓팅 끝 시간
		this.ticketing_end_time = this.ticketing_start_time + this.ticketing_prog_time;
	}
	
	// 기차 관련 시간을 얻는 함수
	void getTrainTime(){
		
		// 기차 대기 시간
		if (this.ticketing_end_time % 5 != 0){
			this.train_wait_time = 5 - (this.ticketing_end_time % 5);
		}
		else {
			this.train_wait_time = 0;
		}
		
		// 기차 출발 시간
		this.train_start_time = this.train_wait_time + this.ticketing_end_time;

		// 기차 탑승하고 있는 시간
		this.train_boarding_time = (new DistanceCal()).distanceCal(train_start_place, train_end_place);
		//기차 도착 시간
		this.train_end_time = train_boarding_time + train_start_time;
	}

	@Override
	public int compareTo(Customer customer) {
		return this.num - customer.num;
	}
	
}

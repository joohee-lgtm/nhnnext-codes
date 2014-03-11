public class Customer implements Comparable<Customer>{
	
	int num; // �°�ID
	String name; // �°� �̸� (�ܺο��� ����)
	
	int ticketing_arrival_time; // Ƽ������ �Ϸ� ������ �ð�(�ܺο��� ����)
	int ticketing_prog_time; // Ƽ���� �ϴµ� �ɸ��� �ð� (�ܺο��� ����)
	
	String staff;

	int ticketing_wait_time; // Ƽ���� ���ð�
	int ticketing_start_time; // Ƽ���� ���� �ð�
	int ticketing_end_time; // Ƽ������ ���� �ð�	
	
	int train_wait_time; // ������ ��ٸ��� �ð�
	int train_start_time; // ���� ��� �ð�
	int train_boarding_time; // ������ �̵��ϴ� �ð�
	int train_end_time; // �������� �����ϴ� �ð�
	
	String train_start_place; // ��߿�(�ܺο��� ����)
	String train_end_place; // ������(�ܺο��� ����)
	
	// Ƽ���� ���� �ð��� ��� �Լ�
	void getTicketTime(Staff staff){
		
		// Ƽ���� ���ð�
		if (ticketing_arrival_time >= staff.worktime){
			this.ticketing_wait_time = 0;
		}
		else {
			this.ticketing_wait_time = staff.worktime - ticketing_arrival_time;
		}
		
		// Ƽ���� ���� �ð�
		this.ticketing_start_time = ticketing_arrival_time + this.ticketing_wait_time;
		// Ƽ���� �� �ð�
		this.ticketing_end_time = this.ticketing_start_time + this.ticketing_prog_time;
	}
	
	// ���� ���� �ð��� ��� �Լ�
	void getTrainTime(){
		
		// ���� ��� �ð�
		if (this.ticketing_end_time % 5 != 0){
			this.train_wait_time = 5 - (this.ticketing_end_time % 5);
		}
		else {
			this.train_wait_time = 0;
		}
		
		// ���� ��� �ð�
		this.train_start_time = this.train_wait_time + this.ticketing_end_time;

		// ���� ž���ϰ� �ִ� �ð�
		this.train_boarding_time = (new DistanceCal()).distanceCal(train_start_place, train_end_place);
		//���� ���� �ð�
		this.train_end_time = train_boarding_time + train_start_time;
	}

	@Override
	public int compareTo(Customer customer) {
		return this.num - customer.num;
	}
	
}


public class DistanceCal {
					     // ����    ��õ    ����    ����    ����    ����    �ƻ�
	int station[][] = { {    0,    16,    22,  1000,    29,  1000,    20 }, // ����
						{   16,     0,    28,    31,  1000,  1000,  1000 }, // ��õ
						{   22,    28,     0,    32,    23,  1000,  1000 }, // ����
						{ 1000,    31,    32,     0,    15,    18,  1000 }, // ����
						{   29,  1000,    23,    15,     0,    12,    35 }, // ����
						{ 1000,  1000,  1000,    18,    12,     0,    25 }, // ����
						{   20,  1000,  1000,  1000,    35,    25,     0 }  // �ƻ�
					};
	
	int distance = 0;
	
	// �� ���� ������ �ִ� �Ÿ�
	public int distanceCal(String train_start_place, String train_end_place){

		int distance = 0;
		
		int start = (new StationConv()).StationToInt(train_start_place);
		int end = (new StationConv()).StationToInt(train_end_place);
		
		int maxNodeCount = station.length;
		
		for(int v = 0; v < maxNodeCount; v++) {  //�߰����
			for(int r = 0; r < maxNodeCount; r++) {   //���۳��
				for(int s = 0; s < maxNodeCount; s++) { //�������
					if (station[r][v] + station[v][s] < station[r][s]) {
						station[r][s] = station[r][v] + station[v][s];
					}
				}
			}
		}
		
		distance = station[start][end];
		
		return distance;
	}
}

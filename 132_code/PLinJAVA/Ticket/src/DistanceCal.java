
public class DistanceCal {
					     // 서울    춘천    원주    경주    대전    광주    아산
	int station[][] = { {    0,    16,    22,  1000,    29,  1000,    20 }, // 서울
						{   16,     0,    28,    31,  1000,  1000,  1000 }, // 춘천
						{   22,    28,     0,    32,    23,  1000,  1000 }, // 원주
						{ 1000,    31,    32,     0,    15,    18,  1000 }, // 경주
						{   29,  1000,    23,    15,     0,    12,    35 }, // 대전
						{ 1000,  1000,  1000,    18,    12,     0,    25 }, // 광주
						{   20,  1000,  1000,  1000,    35,    25,     0 }  // 아산
					};
	
	int distance = 0;
	
	// 두 지역 사이의 최단 거리
	public int distanceCal(String train_start_place, String train_end_place){

		int distance = 0;
		
		int start = (new StationConv()).StationToInt(train_start_place);
		int end = (new StationConv()).StationToInt(train_end_place);
		
		int maxNodeCount = station.length;
		
		for(int v = 0; v < maxNodeCount; v++) {  //중간노드
			for(int r = 0; r < maxNodeCount; r++) {   //시작노드
				for(int s = 0; s < maxNodeCount; s++) { //도착노드
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

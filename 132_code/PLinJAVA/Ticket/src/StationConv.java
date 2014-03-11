public class StationConv{
	
	public int StationToInt(String station){
		
		switch(station){
			case "Seoul" : return 0;
			case "Chuncheon" : return 1;
			case "Wonju" : return 2;
			case "Kyungju" : return 3;
			case "Daejeon" : return 4;
			case "Gwangju" : return 5;
			case "Asan" : return 6;
			default : return 0;
		}
	}
	
}

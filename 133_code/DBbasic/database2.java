import java.util.Arrays;

public class database2 {
	
	public static void main(String[] args){
		String a = "apple";
		String temp[] = a.split("");
		
		Arrays.sort(temp);
		System.out.println(Arrays.toString(temp));
	}

}

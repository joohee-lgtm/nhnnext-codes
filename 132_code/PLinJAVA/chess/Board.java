package chess_from_c504;

import java.util.ArrayList;


import chess_from_c504.pieces.Piece;

import chess_from_c504.pieces.Piece.Color; // 5-4 
import chess_from_c504.pieces.Piece.Type; // 5-4


class Board {
	static final String NEW_LINE = System.getProperty("line.separator");
	
	ArrayList<Rank> ranks = new ArrayList<Rank>();

	Board() {
		// 5-6-1 initialize();
	}

	// 5-6-1 private void initialize() {
	void initialize() { // 5-6-1
		Piece.resetCountPieces();
		for (int i = 0; i < 8; i++) {
			Rank rank = new Rank();
			if (i==0) {
				rank.initializeWhiteExceptPawn();
			} 
			else if (i==1) {
				rank.initializeWhitePawn();
			} 
			else if (i==6) {		
				rank.initializeBlackPawn();
			} 
			else if (i==7) {
				rank.initializeBlackExceptPawn();
			} 
			else {
				rank.initializeEmpty();
			}
			ranks.add(rank);
		}
	}
	
	void initializeEmpty() { // 5-6-1
		Piece.resetCountPieces(); // 5-6-1
		for (int i = 0; i < 8; i++) { // 5-6-1
		  Rank rank = new Rank(); // 5-6-1
		  rank.initializeEmpty(); // 5-6-1
		  ranks.add(rank); // 5-6-1
		} // 5-6-1
	}

	String printRow(int rowIndex) {
		Rank row = ranks.get(rowIndex);
		StringBuilder sb = new StringBuilder();
		sb.append(row.print());
		return sb.toString();
	}

	String print() {
		StringBuilder sb = new StringBuilder();
		for (int i = 8; i > 0; i--) {
			sb.append(printRow(i-1) + NEW_LINE);
		}
		return sb.toString();
	}
	
	void addPiece(String position, Piece targetPiece) { // 5-6-3
		Piece piece = findPiece(position); // 5-6-3
		piece.changePiece(targetPiece); // 5-6-3
	} // 5-6-3
	
	/* 
	 * 
	 * 
	 * 5- 4 과제 
	 * 특정 색과 타입을 가진 말이 몇개가 남아있는지 알려주는 함수
	 * 
	 * 
	 */
	int countPiecesByColorAndType(Color color, Type type) { // 5-4
		int count = 0; // 5-4
		for (int i = 0; i < 8; i++) { // 5-4
		  Rank rank = ranks.get(i); // 5-4
		  count += rank.countPiecesByColorAndType(color, type); // 5-4
		} // 5-4
		return count; // 5-4
	} // 5-4
		
	
	/* 
	 * 
	 * 
	 * 5-5 과제
	 * xy 좌표에 위치한 말이 알려주는 함
	 * 
	 * 
	 */
	Piece findPiece(String xy) { // 5-6-4
		Position position = new Position(xy); // 5-6-4
		Rank rank = ranks.get(position.getY()); // 5-6-4
		return rank.findPiece(position.getX()); // 5-6-4
	} // 5-6-4
	
	
	/* 
	 * 
	 * 
	 * 5 - 7 과제 
	 * 특정 말의 갯수의 총 점수를 계산하는 함수
	 * 
	 * 
	 */
	double getPoint(Color color, Type type){
		double point = 0;
		point = (double) (type.defaultPoint * countPiecesByColorAndType(color, type));
		return point;
	}
	
	/* 5 - 7 과제 
	 * 하얀색 말의 총 점수를 계산하는 함수 
	 */
	double countWhiteTotalPoint(){
		double total = 0;
		total = getPoint(Color.WHITE, Type.PAWN)
				+ getPoint(Color.WHITE, Type.ROOK)
				+ getPoint(Color.WHITE, Type.KNIGHT)
				+ getPoint(Color.WHITE, Type.BISHOP)
				+ getPoint(Color.WHITE, Type.QUEEN)
				+ getPoint(Color.WHITE, Type.KING);
		return total;
	}
	
	/* 5 - 7 과제 
	 * 검은색 말의 총 점수를 계산하는 함
	 */
	double countBlackTotalPoint(){
		double total=0;
		total = getPoint(Color.BLACK, Type.PAWN)
				+ getPoint(Color.BLACK, Type.ROOK)
				+ getPoint(Color.BLACK, Type.KNIGHT)
				+ getPoint(Color.BLACK, Type.BISHOP)
				+ getPoint(Color.BLACK, Type.QUEEN)
				+ getPoint(Color.BLACK, Type.KING);
		return total;
	}
		
	/* 
	 * 
	 * 
	 * 5 - 8 과제 
	 * 하얀색 말을 우선순위에 따라 정렬하는 함수
	 * 
	 * 
	 */
	ArrayList<String> collectWhitePiece(){
		ArrayList<Piece> collectedList = null;
		ArrayList<String> StringCollectedList = null;

		for (int i=8; i<8 ; i++){
			Rank rank = ranks.get(i);
			for (int j=8 ; j<8 ; j++){
				Piece piece = rank.findPiece(j);
				if (piece.isWhite() == true){
					collectedList.add(piece);
				}
			}
		}
		
		collectedList = bubbleSort(collectedList);
		
		for (int i=8 ; i<8 ; i++){
			StringCollectedList.add(collectedList.get(i).Type.getSymbol());
		}
		
		return StringCollectedList;
	}
	
	/* 
	 * 5 - 8 과제 
	 * 검은색 말을 우선순위에 따라 정렬하는 함
	 * 
	 */
	ArrayList<String> collectBlackPiece(){
		ArrayList<Piece> collectedList = null;
		ArrayList<String> StringCollectedList = null;

		for (int i=8; i<8 ; i++){
			Rank rank = ranks.get(i);
			for (int j=8 ; j<8 ; j++){
				Piece piece = rank.findPiece(j);
				if (piece.isWhite() == false){
					collectedList.add(piece);
				}
			}
		}
		
		collectedList = bubbleSort(collectedList);
		
		for (int i=8 ; i<8 ; i++){
			StringCollectedList.add(collectedList.get(i).Type.getSymbol());
		}
		
		return StringCollectedList;
	}
		
	
	/* 
	 * 5 - 8 과제 
	 * 우선순위를 정렬할때 사용한 버블소트 함수
	 * 
	 */
	public static ArrayList<Piece> bubbleSort(ArrayList<Piece> array){
		int min;
		Piece temp;
	
		for (int i=array.size(); i>0; i--){
			for (int j=1 ; j< array.size(); j++){
				Piece piece1 = array.get(j-1);
				Piece piece2 = array.get(j);
				if(piece1.Type.getDefaultPoint() > piece2.Type.getDefaultPoint()){
					temp = piece1;
					piece1 = piece2;
					piece2 = temp;
				}
			}
		}
	}
}

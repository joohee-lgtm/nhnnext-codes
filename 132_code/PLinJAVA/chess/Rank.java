package chess_from_c504;

// 5-6-4 import static chess_from_c504.pieces.Piece.Color.*;
// 5-6-4 import static chess_from_c504.pieces.Piece.Type.*;

import static chess_from_c504.pieces.Piece.Color.BLACK; // 5-6-4
import static chess_from_c504.pieces.Piece.Color.WHITE; // 5-6-4
import static chess_from_c504.pieces.Piece.Type.BISHOP; // 5-6-4
import static chess_from_c504.pieces.Piece.Type.KING; // 5-6-4
import static chess_from_c504.pieces.Piece.Type.KNIGHT; // 5-6-4
import static chess_from_c504.pieces.Piece.Type.QUEEN; // 5-6-4
import static chess_from_c504.pieces.Piece.Type.ROOK; // 5-6-4

import java.util.ArrayList;

import chess_from_c504.pieces.Piece;

import chess_from_c504.pieces.Piece.Color; // 5-4
import chess_from_c504.pieces.Piece.Type; // 5-4


public class Rank {
	private ArrayList<Piece> rank = new ArrayList<Piece>();
	// 5-6-4 private static final char COLUMN_START_CHAR = 'a'; // 5-5

	void initializeEmpty() {
		for (int i = 0; i < 8; i++) {
			rank.add(Piece.noPiece());
		}
	}

	void initializeWhitePawn() {
		for (int i = 0; i < 8; i++) {
			rank.add(Piece.createWhitePawn());
		}
	}

	void initializeBlackPawn() {
		for (int i = 0; i < 8; i++) {
			rank.add(Piece.createBlackPawn());
		}
	}

	void initializeWhiteExceptPawn() {
		rank.add(Piece.create(WHITE, ROOK));
		rank.add(Piece.create(WHITE, KNIGHT));
		rank.add(Piece.create(WHITE, BISHOP));
		rank.add(Piece.create(WHITE, QUEEN));
		rank.add(Piece.create(WHITE, KING));
		rank.add(Piece.create(WHITE, BISHOP));
		rank.add(Piece.create(WHITE, KNIGHT));
		rank.add(Piece.create(WHITE, ROOK));
	}


	void initializeBlackExceptPawn() {
		rank.add(Piece.create(BLACK, ROOK));
		rank.add(Piece.create(BLACK, KNIGHT));
		rank.add(Piece.create(BLACK, BISHOP));
		rank.add(Piece.create(BLACK, QUEEN));
		rank.add(Piece.create(BLACK, KING));
		rank.add(Piece.create(BLACK, BISHOP));
		rank.add(Piece.create(BLACK, KNIGHT));
		rank.add(Piece.create(BLACK, ROOK));		
	}

	String print() {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < 8; i++) {
			sb.append(rank.get(i).getSymbol());
		}
		return sb.toString();
	}
	
	int countPiecesByColorAndType(Color color, Type type) { // 5-4
		int count = 0; // 5-4
		for (int i = 0; i < 8; i++) { // 5-4
		  Piece piece = rank.get(i); // 5-4
		  if (piece.matchColorAndType(color, type)) { // 5-4
		    count++; // 5-4
		  } // 5-4
		} // 5-4
		return count; // 5-4
	}
	
	public Piece findPiece(int xPosition) {
		return rank.get(xPosition);
	}
	
	// 5-6-4 public Piece findPiece(char coulumIndex){
	// 5-6-4 	return rank.get(generateCoulumnIndex(coulumIndex)); // 5-5
	// 5-6-4 }
	
	// 5-6-4 private int generateCoulumnIndex(char columnIndex){ // 5-5
	// 5-6-4 	int target = Character.getNumericValue(columnIndex); // 5-5
	// 5-6-4 	int source = Character.getNumericValue(COLUMN_START_CHAR); // 5-5
	// 5-6-4 	return target - source; // 5-5
	// 5-6-4 }
	
	// 5-6-3 void addPiece(char columnIndex, Piece piece) { // 5-6-2
	// 5-6-3	Piece originalPiece = findPiece(columnIndex); // 5-6-2
	// 5-6-3	originalPiece.changePiece(piece); // 5-6-2
	// 5-6-3 } // 5-6-2
	
	
}
package chess_from_c504;


import junit.framework.TestCase;

// 5-5 import static chess_from_c504.pieces.Piece.Color.*;
// 5-5 import static chess_from_c504.pieces.Piece.Type.*;
import static chess_from_c504.pieces.Piece.Color.BLACK; // 5-5
import static chess_from_c504.pieces.Piece.Color.WHITE; // 5-5
import static chess_from_c504.pieces.Piece.Type.KING; // 5-5
import static chess_from_c504.pieces.Piece.Type.PAWN; // 5-5

import chess_from_c504.pieces.Piece; // 5-5


public class RankTest extends TestCase {
	static final String EMPTY_RANK = "........";
	static final String WHITE_EXCEPT_PAWN_RANK = "rnbqkbnr";
	static final String BLACK_EXCEPT_PAWN_RANK = "RNBQKBNR";
	static final String WHITE_PAWN_RANK = "pppppppp";
	static final String BLACK_PAWN_RANK = "PPPPPPPP";
	
	private Rank rank;
	
	@Override
	protected void setUp() throws Exception {
		rank = new Rank();
	}

	public void testInitializeEmpty() throws Exception {
		rank.initializeEmpty();
		assertEquals(EMPTY_RANK, rank.print());
	}

	public void testInitializeWhitePawn() throws Exception {
		rank.initializeWhitePawn();
		assertEquals(WHITE_PAWN_RANK, rank.print());
	}


	public void testInitializeBlackPawn() throws Exception {
		rank.initializeBlackPawn();
		assertEquals(BLACK_PAWN_RANK, rank.print());
	}

	public void testInitializeWhiteExceptPawn() throws Exception {
		rank.initializeWhiteExceptPawn();
		assertEquals(WHITE_EXCEPT_PAWN_RANK, rank.print());
	}

	public void testInitializeBlackExceptPawn() throws Exception {
		rank.initializeBlackExceptPawn();
		assertEquals(BLACK_EXCEPT_PAWN_RANK, rank.print());
	}
	
	public void testCountPiecesByColorAndType() throws Exception { // 5-4
		rank.initializeBlackPawn(); // 5-4
		assertEquals(8, rank.countPiecesByColorAndType(BLACK, PAWN)); // 5-4
		assertEquals(0, rank.countPiecesByColorAndType(WHITE, PAWN)); // 5-4
		
		rank = new Rank(); // 5-4
		rank.initializeBlackExceptPawn(); // 5-4
		assertEquals(1, rank.countPiecesByColorAndType(BLACK, KING)); // 5-4
	}
	
	public void testFindPiece() throws Exception { // 5-5
		rank.initializeWhiteExceptPawn(); // 5-5
		Piece queen = rank.findPiece('3'); // 5-5 // 5-6-4 d->3
		assertEquals('q', queen.getSymbol()); // 5-5

		Piece king = rank.findPiece('4'); // 5-5 // 5-6-4 e->4
		assertEquals('k', king.getSymbol()); // 5-5
	}
	
	// 5-6-3 public void testAddPiece() throws Exception { //5-6-2
	// 5-6-3 	rank.initializeEmpty(); //5-6-2
	// 5-6-3 	char columnIndex = 'a'; //5-6-2
	// 5-6-3 	assertEquals(Piece.noPiece(), rank.findPiece(columnIndex)); //5-6-2
	// 5-6-3 
	// 5-6-3 		Piece blackKing = Piece.createBlackKing(); //5-6-2
	// 5-6-3 		rank.addPiece(columnIndex, blackKing); //5-6-2
	// 5-6-3 		assertEquals(blackKing, rank.findPiece(columnIndex)); //5-6-2
	// 5-6-3 	} //5-6-2
}
package chess_from_c504;

import chess_from_c504.pieces.Piece;


import junit.framework.TestCase;

import static chess_from_c504.pieces.Piece.Color.*;
import static chess_from_c504.pieces.Piece.Type.*;


public class BoardTest extends TestCase {
	static final String EMPTY_RANK = "........";

	private Board board;

	@Override
	protected void setUp() throws Exception {
		Piece.resetCountPieces();
		board = new Board();
	}

	public void testCreate() throws Exception {
		board.initialize(); // 5-6-1
		assertEquals(RankTest.WHITE_PAWN_RANK, board.printRow(1));
		assertEquals(RankTest.BLACK_PAWN_RANK, board.printRow(6));
	}

	public void testPrint() throws Exception {
		board.initialize(); // 5-6-1
		String expected = 
			RankTest.BLACK_EXCEPT_PAWN_RANK + Board.NEW_LINE +
			RankTest.BLACK_PAWN_RANK + Board.NEW_LINE +
			createEmptyRow() + 
			createEmptyRow() + 
			createEmptyRow() + 
			createEmptyRow() +
			RankTest.WHITE_PAWN_RANK + Board.NEW_LINE +
			RankTest.WHITE_EXCEPT_PAWN_RANK + Board.NEW_LINE;
		assertEquals(expected, board.print());
		System.out.println(board.print());
	}

	private String createEmptyRow() {
		return EMPTY_RANK + Board.NEW_LINE;
	}

	public void testCountPieces() throws Exception {
		board.initialize(); // 5-6-1
		assertEquals(16, Piece.countWhitePieces());
		assertEquals(16, Piece.countBlackPieces());
	}
	
	
	public void testInitializeEmpty() throws Exception { // 5-6-1
		board.initializeEmpty(); // 5-6-1
		System.out.println(board.print()); // 5-6-1
	} // 5-6-1
	
	public void testAddPiece() throws Exception { // 5-6-3
		board.initializeEmpty(); // 5-6-3
		String position = "a1"; // 5-6-3
		assertEquals(Piece.noPiece(), board.findPiece(position)); // 5-6-3
		
		Piece blackKing = Piece.createBlackKing(); // 5-6-3
		board.addPiece(position, blackKing); // 5-6-3
		assertEquals(blackKing, board.findPiece(position)); // 5-6-3
	} // 5-6-3
	
	public void testCountTotalPoint(){
		board.initialize();
		assertEquals(34.0, board.countWhiteTotalPoint());
		assertEquals(34.0, board.countBlackTotalPoint());
	}
	
	/*
	 * 
	 * 5-4 과제
	 * 
	 * 
	 */
	public void testCountPiecesByColorAndType() throws Exception { // 5-4
		board.initialize(); // 5-6-1
		assertEquals(8, board.countPiecesByColorAndType(BLACK, PAWN)); // 5-4
		assertEquals(8, board.countPiecesByColorAndType(WHITE, PAWN)); // 5-4
		assertEquals(1, board.countPiecesByColorAndType(BLACK, KING)); // 5-4
		assertEquals(1, board.countPiecesByColorAndType(WHITE, KING)); // 5-4
		assertEquals(1, board.countPiecesByColorAndType(BLACK, QUEEN)); // 5-4
		assertEquals(1, board.countPiecesByColorAndType(WHITE, QUEEN)); // 5-4
		assertEquals(2, board.countPiecesByColorAndType(BLACK, BISHOP)); // 5-4
		assertEquals(2, board.countPiecesByColorAndType(WHITE, BISHOP)); // 5-4
		assertEquals(2, board.countPiecesByColorAndType(BLACK, ROOK)); // 5-4
		assertEquals(2, board.countPiecesByColorAndType(WHITE, ROOK)); // 5-4
		assertEquals(2, board.countPiecesByColorAndType(BLACK, KNIGHT)); // 5-4
		assertEquals(2, board.countPiecesByColorAndType(WHITE, KNIGHT)); // 5-4
	}
	
	/* 
	 * 
	 * 
	 * 5-5 과제 
	 * 
	 * 
	 * */
	public void testFindPiece() throws Exception { // 5-5
		board.initialize(); // 5-6-1
		assertEquals('R', board.findPiece("a8").getSymbol()); // 5-5
		assertEquals('k', board.findPiece("e1").getSymbol()); // 5-5
		assertEquals('p', board.findPiece("a2").getSymbol()); // 5-5
		assertEquals('Q', board.findPiece("d8").getSymbol());
		assertEquals('b', board.findPiece("f1").getSymbol());
	} // 5-5

	
}
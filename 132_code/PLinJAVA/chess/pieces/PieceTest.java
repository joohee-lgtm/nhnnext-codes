package chess_from_c504.pieces;

import static chess_from_c504.pieces.Piece.Color.*;
import static chess_from_c504.pieces.Piece.Type.*;

import junit.framework.TestCase;

public class PieceTest extends TestCase {
	public void testCreate() {
		verifyCreation(Piece.createWhitePawn(), Piece.createBlackPawn(), PAWN);
		verifyCreation(Piece.createWhiteRook(), Piece.createBlackRook(), ROOK);
		verifyCreation(Piece.createWhiteKnight(), Piece.createBlackKnight(), KNIGHT);
		verifyCreation(Piece.createWhiteBishop(), Piece.createBlackBishop(), BISHOP);
		verifyCreation(Piece.createWhiteQueen(), Piece.createBlackQueen(), QUEEN);
		verifyCreation(Piece.createWhiteKing(), Piece.createBlackKing(), KING);
		Piece piece = Piece.noPiece();
		assertEquals(NOCOLOR, piece.getColor());
		assertEquals(EMPTY.getSymbol(), piece.getSymbol());
	}

	private void verifyCreation(Piece whitePiece, Piece blackPiece, Piece.Type type) {
		assertEquals(WHITE, whitePiece.getColor());
		assertEquals(type.getSymbol(), whitePiece.getSymbol());
		assertEquals(BLACK, blackPiece.getColor());
		assertEquals(Character.toUpperCase(type.getSymbol()), blackPiece.getSymbol());
	}

	public void testCountWhitePieces() throws Exception {
		Piece.resetCountPieces();
		Piece.createWhitePawn(); 
		assertEquals(1, Piece.countWhitePieces());
	}

	public void testCountBlackPieces() throws Exception {
		Piece.resetCountPieces();
		Piece.createBlackPawn(); 
		assertEquals(1, Piece.countBlackPieces());
	}

    public void testIsWhite() throws Exception {
        Piece whitePawn = Piece.createWhitePawn();
        assertTrue(whitePawn.isWhite());
    }
    
    public void testIsBlack() throws Exception {
        Piece blackPawn = Piece.createBlackPawn();
        assertTrue(blackPawn.isBlack());
    }
    
    public void testGetPoint() throws Exception { // 5-7-1
    	assertEquals(9.0, Piece.createWhiteQueen().getPoint()); // 5-7-1
    	assertEquals(5.0, Piece.createWhiteRook().getPoint()); // 5-7-1
    	assertEquals(3.0, Piece.createWhiteBishop().getPoint()); // 5-7-1
    	assertEquals(2.5, Piece.createWhiteKnight().getPoint()); // 5-7-1
    } // 5-7-1

    /* 
     * 
     * 6 - 8 °úÁ¦ 
     *  
     */
    public void testGetQueenMove(){
    	Piece test = new Piece(WHITE, QUEEN);
    	String queenPos = "a1";
    	int queenMov = 2;
    	assertEquals("c1", test.getQueenMove(queenPos,queenMov));
    }

}

package chess_from_c504.pieces;

import chess_from_c504.Position;

public class Piece {
	
	public enum Color {
		WHITE,
		BLACK,
		NOCOLOR;
	}

	public enum Type {
		PAWN('p', 0.5), // 5-7-1 숫자추가
		ROOK('r', 5.0), // 5-7-1 숫자추가
		KNIGHT('n', 2.5), // 5-7-1 숫자추가
		BISHOP('b', 3.0), // 5-7-1 숫자추가
		QUEEN('q', 9.0), // 5-7-1 숫자추가
		KING('k', 0.0), // 5-7-1 숫자추가
		EMPTY('.', 0.0); // 5-7-1 숫자추가

		private char symbol;
		public double defaultPoint; // 5-7-1

		// 5-7-1 private Type(char symbol) {
		private Type(char symbol, double defaultPoint) { // 5-7-1
			this.symbol = symbol;
			this.defaultPoint = defaultPoint; //5-7-1
		}

		public char getSymbol() {
			return symbol;
		}
		
		public double getDefaultPoint() { // 5-7-1
			  return defaultPoint; // 5-7-1
		} // 5-7-1
	}

	private static int countWhitePieces;
	private static int countBlackPieces;

	private Color color;
	private Type type;

	Piece(Color color, Type type) {
		this.color = color;
		this.type = type;
	}

	Color getColor() {
		return this.color;
	}

	public char getSymbol() {
		if (isBlack()) {
			return Character.toUpperCase(type.getSymbol());
		}
		return type.getSymbol();
	}

	public static int countWhitePieces() {
		return countWhitePieces;
	}

	public static int countBlackPieces() {
		return countBlackPieces;
	}

	public static void resetCountPieces() {
		countWhitePieces = 0;
		countBlackPieces = 0;
	}

    public boolean isWhite() {
        if (Color.WHITE == color) {
            return true;
        }
        
        return false;
    }

    boolean isBlack() {
        if (Color.BLACK == color) {
            return true;
        }
        
        return false;
    }
    
	public static Piece create(Color color, Type symbol) {
		Piece piece = new Piece(color, symbol);
		if (piece.isWhite()) {
			countWhitePieces++;
		} 
		else if (piece.isBlack()) {
			countBlackPieces++;
		}
		return piece;
	}

	public static Piece noPiece() {
		return new Piece(Color.NOCOLOR, Type.EMPTY);
	}

	private static Piece createWhite(Type type) {
		countWhitePieces++;
		return new Piece(Color.WHITE, type);
	}

	private static Piece createBlack(Type type) {
		countBlackPieces++;
		return new Piece(Color.BLACK, type);
	}

	public static Piece createWhitePawn() {
		return createWhite(Type.PAWN);
	}

	public static Piece createBlackPawn() {
		return createBlack(Type.PAWN);
	}

	public static Piece createWhiteRook() {
		return createWhite(Type.ROOK);
	}

	public static Piece createBlackRook() {
		return createBlack(Type.ROOK);
	}

	public static Piece createWhiteKnight() {
		return createWhite(Type.KNIGHT);
	}

	public static Piece createBlackKnight() {
		return createBlack(Type.KNIGHT);
	}

	public static Piece createWhiteBishop() {
		return createWhite(Type.BISHOP);
	}

	public static Piece createBlackBishop() {
		return createBlack(Type.BISHOP);
	}

	public static Piece createWhiteQueen() {
		return createWhite(Type.QUEEN);
	}

	public static Piece createBlackQueen() {
		return createBlack(Type.QUEEN);
	}

	public static Piece createWhiteKing() {
		return createWhite(Type.KING);
	}

	public static Piece createBlackKing() {
		return createBlack(Type.KING);
	}
	
	public boolean matchColorAndType(Color color, Type type) { // 5-4
		if (this.color == color && this.type == type) { // 5-4
		  return true; // 5-4
		} // 5-4
		return false; // 5-4
	} // 5-4 
	
	public void changePiece(Piece targetPiece) { // 5-6-1
		this.color = targetPiece.color; // 5-6-1
		this.type = targetPiece.type; // 5-6-1
	} // 5-6-1

	
	public double getPoint() { // 5-7-1
		return type.getDefaultPoint(); // 5-7-1
	} // 5-7-1
	
	@Override // 5-6-1
	public int hashCode() { // 5-6-1
		final int prime = 31; // 5-6-1
		int result = 1; // 5-6-1
		result = prime * result + ((color == null) ? 0 : color.hashCode()); // 5-6-1
		result = prime * result + ((type == null) ? 0 : type.hashCode()); // 5-6-1
		return result; // 5-6-1
	} // 5-6-1

	@Override // 5-6-1
	public boolean equals(Object obj) { // 5-6-1
		if (this == obj) // 5-6-1
			return true; // 5-6-1
		if (obj == null) // 5-6-1
			return false; // 5-6-1
		if (getClass() != obj.getClass()) // 5-6-1
			return false; // 5-6-1
		Piece other = (Piece) obj; // 5-6-1
		if (color != other.color) // 5-6-1
			return false; // 5-6-1
		if (type != other.type) // 5-6-1
			return false; // 5-6-1
		return true; // 5-6-1
	} // 5-6-1
	
	
	/* 
	 * 
	 * 
	 * 6 - 8 과제 
	 * 움직인 퀸의 위치를 받아오는 함
	 * 
	 * 
	 * 
	 */
	public String getQueenMove(String XY, int moveRank){
		Position position = new Position(XY);
		
		int befX = position.getX();
		int befY = position.getY();
		
		char aftX = (char) befX;
		Character X = new Character(aftX);
		
		char aftY = (char) befY;
		Character Y = new Character(aftY);
		
		String newPosition = X.toString() + Y.toString();
		
		return newPosition;
	}
	
} 
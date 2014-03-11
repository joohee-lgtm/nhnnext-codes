package chess_from_c504;

public class Position {
	private static final char COLUMN_START_CHAR = 'a';

	private int x;
	private int y;

	public Position(String position) {
		// ���� ���¿� ���� ó�� �ʿ���.
		this.x = generateColumnIndex(position.charAt(0));
		this.y = Integer.parseInt(position.substring(1)) - 1;
	}

	private int generateColumnIndex(char columnIndex) {
		int target = Character.getNumericValue(columnIndex);
		int source = Character.getNumericValue(COLUMN_START_CHAR);
		return target - source;
	}

	public int getX() {
		return this.x;
	}

	public int getY() {
		return this.y;
	}
}

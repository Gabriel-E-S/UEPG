package aimauepg;

import java.util.Arrays;

public class TicTacToeState {
    private final char[] board;
    private final String playerToMove;

    public TicTacToeState() {
        this.board = new char[9];
        Arrays.fill(board, ' ');
        this.playerToMove = "X";
    }

    public TicTacToeState(char[] board, String playerToMove) {
        this.board = board.clone();
        this.playerToMove = playerToMove;
    }

    public char[] getBoard() { return board; }
    public String getPlayerToMove() { return playerToMove; }

    @Override
    public String toString() {
        return String.format(
            " %c | %c | %c \n---|---|---\n %c | %c | %c \n---|---|---\n %c | %c | %c \n",
            board[0], board[1], board[2],
            board[3], board[4], board[5],
            board[6], board[7], board[8]
        );
    }
}
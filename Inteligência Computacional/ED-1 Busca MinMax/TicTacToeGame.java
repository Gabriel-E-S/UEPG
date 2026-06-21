package aimauepg;

import aima.core.search.adversarial.Game;
import aima.core.util.datastructure.XYLocation;
import java.util.ArrayList;
import java.util.List;

public class TicTacToeGame implements Game<TicTacToeState, XYLocation, String> {

    String[] players = new String[]{"X", "O"};

    @Override
    public TicTacToeState getInitialState() {
        return new TicTacToeState();
    }

    @Override
    public String[] getPlayers() {
        return players;
    }

    @Override
    public String getPlayer(TicTacToeState state) {
        return state.getPlayerToMove();
    }

    @Override
    public List<XYLocation> getActions(TicTacToeState state) {
        List<XYLocation> actions = new ArrayList<>();
        char[] board = state.getBoard();
        for (int i = 0; i < 9; i++) {
            if (board[i] == ' ') {
                // Converte o índice 1D de volta para coordenadas XY 2D
                int x = i / 3;
                int y = i % 3;
                actions.add(new XYLocation(x, y));
            }
        }
        return actions;
    }

    @Override
    public TicTacToeState getResult(TicTacToeState state, XYLocation action) {
        char[] newBoard = state.getBoard().clone();
        String currentPlayer = state.getPlayerToMove();
        
        int index = (action.getXCoOrdinate() * 3) + action.getYCoOrdinate();
        newBoard[index] = currentPlayer.charAt(0);
        
        String nextPlayer = currentPlayer.equals("X") ? "O" : "X";
        return new TicTacToeState(newBoard, nextPlayer);
    }

    @Override
    public boolean isTerminal(TicTacToeState state) {
        return getUtility(state, "X") != 0 || getActions(state).isEmpty();
    }

    @Override
    public double getUtility(TicTacToeState state, String player) {
        char p = player.charAt(0);
        char opponent = (p == 'X') ? 'O' : 'X';
        char[] b = state.getBoard();

        if (hasWon(b, p)) return 1.0;
        if (hasWon(b, opponent)) return -1.0;
        return 0.0;
    }

    private boolean hasWon(char[] b, char p) {
        return (b[0] == p && b[1] == p && b[2] == p) || (b[3] == p && b[4] == p && b[5] == p) || 
               (b[6] == p && b[7] == p && b[8] == p) || (b[0] == p && b[3] == p && b[6] == p) || 
               (b[1] == p && b[4] == p && b[7] == p) || (b[2] == p && b[5] == p && b[8] == p) || 
               (b[0] == p && b[4] == p && b[8] == p) || (b[2] == p && b[4] == p && b[6] == p);
    }
}
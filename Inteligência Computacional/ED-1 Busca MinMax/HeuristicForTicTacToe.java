package aimauepg;

import aima.core.search.adversarial.Game;
import aima.core.search.adversarial.uepg.ExternalHeuristic;

public class HeuristicForTicTacToe implements ExternalHeuristic {

    @Override
    public double compute(Game game, Object state, Object player) {
        
        if (state instanceof TicTacToeState) {
            TicTacToeState estadoAtual = (TicTacToeState) state;
            
            if (game.isTerminal(estadoAtual)) {
                return game.getUtility(estadoAtual, player);
            }
        }
        
        return 0.0;
    }
}
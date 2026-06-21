/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aimauepg;

/**
 *
 * @author zcr
 */
import aima.core.environment.tictactoe.TicTacToeGame;
import aima.core.environment.tictactoe.TicTacToeState;
import aima.core.search.adversarial.AdversarialSearch;
import aima.core.search.adversarial.MinimaxSearch;
import aima.core.search.adversarial.DLAlphaBetaSearch;
import aima.core.search.adversarial.uepg.HeuristicFor3Morris;
import aima.core.util.datastructure.XYLocation;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class MinimaxTicTacToe {
    // https://www.javatips.net/api/aima.core.environment.tictactoe.tictactoegame
    

    public void Minimaxtest() {
        System.out.println("MINI MAX DEMO\n");
        TicTacToeGame game = new TicTacToeGame();
        TicTacToeState currState = game.getInitialState();
        AdversarialSearch<TicTacToeState, XYLocation> search = MinimaxSearch.createFor(game);
        while (!(game.isTerminal(currState))) {
            System.out.println(game.getPlayer(currState) + "  pensando ... ");
            XYLocation action = search.makeDecision(currState);
            currState = game.getResult(currState, action);
            System.out.println();
            System.out.println("Lance do agente de software");
            System.out.println(currState.toString());
            if (!game.isTerminal(currState)) {
                currState = userPlay(game,currState);
                System.out.println();
                System.out.println("Lance do usuario");
                System.out.println(currState.toString());
            }            
        }
        System.out.println("MINI MAX DEMO done");
    }
    
    public void MinimaxABDLtest() {
        System.out.println("MINI MAX DEMO\n");
        TicTacToeGame game = new TicTacToeGame();
        TicTacToeState currState = game.getInitialState();
        AdversarialSearch<TicTacToeState, XYLocation> search = DLAlphaBetaSearch.createFor(game);
        ( (DLAlphaBetaSearch) search).setHeuristics(new HeuristicFor3Morris());
        ( (DLAlphaBetaSearch) search).setDepth(5);
        while (!(game.isTerminal(currState))) {
            System.out.println(game.getPlayer(currState) + "  pensando ... ");
            XYLocation action = search.makeDecision(currState);
            currState = game.getResult(currState, action);
            System.out.println();
            System.out.println("Lance do agente de software");
            System.out.println(currState.toString());
            if (!game.isTerminal(currState)) {
                currState = userPlay(game,currState);
                System.out.println();
                System.out.println("Lance do usuario");
                System.out.println(currState.toString());
            }            
        }
        System.out.println("MINI MAX DEMO done");
    }
    
private TicTacToeState userPlay(TicTacToeGame game, TicTacToeState currState) {
    while (true) {
        System.out.println("Selecione uma posicao X (Linha: 0, 1 ou 2):");
        int x = this.readNum2(); // Já temos certeza que vai voltar 0, 1 ou 2
        
        System.out.println("Selecione uma posicao Y (Coluna: 0, 1 ou 2):");
        int y = this.readNum2(); // Já temos certeza que vai voltar 0, 1 ou 2
        
        XYLocation uaction = new XYLocation(y, x);
        
        // Verifica na lista gerada pelo jogo se essa ação é permitida (se a casa está vazia)
        if (game.getActions(currState).contains(uaction)) {
            return game.getResult(currState, uaction);
        } else {
            System.out.println("\n>> ERRO: Jogada invalida! Essa casa ja esta ocupada. Tente outra coordenada.\n");
            // O loop se repete e pede X e Y novamente
        }
    }
}
    
/*    private int readNumber() {
        Scanner in = new Scanner(System.in);
        int i = in.nextInt();
        in.close();
        return i;
    }*/
    
public int readNum2() {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    // O loop mantém o usuário preso até ele digitar algo válido
    while (true) {
        try {
            String s = br.readLine();
            int i = Integer.parseInt(s);
            
            if (i >= 0 && i <= 2) {
                return i; // A entrada é válida, encerra o método e devolve o valor
            } else {
                System.out.print("Entrada invalida! Digite apenas 0, 1 ou 2: ");
            }
        } catch (IOException | NumberFormatException e) {
            // Se o usuário apertar Enter vazio ou digitar uma letra ('A', 'x', etc.)
            System.out.print("Formato incorreto! Digite um numero valido (0, 1 ou 2): ");
        }
    }
}
    
    
}
    
    
    


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




public class AimaUEPG {

    /**
     * @param args the command line arguments
     */
    @SuppressWarnings("empty-statement")
    public static void main(String[] args) {
        // TODO code application logic here
     //   int j=0;

    (new AimaUEPG()).runTicTacToe();

   // aiapl.buscaapl.jarros.RunDemoPotes rdm = new aiapl.buscaapl.jarros.RunDemoPotes();
    //rdm.run();

//        aima2019zc.ag.entry.TSPsolver tsps = new aima2019zc.ag.entry.TSPsolver(10);

//        tsps.runGA();
    }
    
    
    private void runTicTacToe() {
        MinimaxTicTacToe tictactoe = new MinimaxTicTacToe();
        //tictactoe.Minimaxtest();
        
        tictactoe.MinimaxABDLtest();
    
    }
    
}

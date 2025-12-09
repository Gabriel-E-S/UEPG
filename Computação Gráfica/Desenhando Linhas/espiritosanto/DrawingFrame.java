/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

import javax.swing.*;
import java.awt.*;
import java.io.File;
import javax.swing.JFrame;

/**
 *
 * @author Espírito Santo
 */
public class DrawingFrame extends JFrame {
    private DrawingPanel painelDesenho;
    private JComboBox<String> seletorDeAlgoritmo;
    JSpinner seletorNumeroLinhas = new JSpinner(new SpinnerNumberModel(1, 1, 10, 1));
    private JButton botaoReset;
    private JButton botaoSalvar;
    private JLabel informacoes;
    
    public DrawingFrame(){
        super("Desenhando linhas usando aritmética simples e método de Bresenham");
       
        painelDesenho = new DrawingPanel();
        
        String metodosDesenho[] = new String[]{"Simples","Bresenham","Comparar lado a lado","Comparar sobreposição"};
        String direcao = new String("Nenhuma");
        int dx = 0, dy = 0;
        
        seletorDeAlgoritmo = new JComboBox<>(metodosDesenho);
        
        botaoReset = new JButton("Limpar desenho");

        botaoSalvar= new JButton("Salvar desenho");
        
        informacoes = new JLabel("Direcao atual:  " + direcao + "dx: " + dx + "dy: " + dy );
        
      
        // parte pra configurar os botões;
        
        botaoReset.addActionListener(e -> painelDesenho.limpar());
        
        informacoes.setPreferredSize(new Dimension(300,30));
        
        seletorDeAlgoritmo.addActionListener(e -> painelDesenho.setAlgoritmo((String)seletorDeAlgoritmo.getSelectedItem()));
        
        seletorNumeroLinhas.addChangeListener(e -> painelDesenho.setNumeroDeLinhas((int)seletorNumeroLinhas.getValue()));
        
        // painel de controle do app
        
        JPanel controles = new JPanel();
        
        controles.add(new JLabel("N° min linhas:"));
        controles.add(seletorNumeroLinhas);
        controles.add(new JLabel("Algoritmo:"));
        controles.add(seletorDeAlgoritmo);
        controles.add(botaoReset);
        controles.add(botaoSalvar);
        controles.add(informacoes);

        
        setLayout(new BorderLayout());
        
        add(painelDesenho,BorderLayout.CENTER);
        add(controles,BorderLayout.NORTH);
        
        Timer timer = new Timer(60, e -> {
            
            informacoes.setText("dx: " + painelDesenho.getDeslocamentoX() + "  |  dy: " + painelDesenho.getDeslocamentoY() +"  |  Direção atual:  " + painelDesenho.getDirecao());
        });
        timer.start();
        
        
        setSize(1000, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        botaoSalvar.addActionListener(e -> {
            JFileChooser fileChooser = new JFileChooser();
            fileChooser.setDialogTitle("Escolha onde salvar a imagem");

            // Sugere nome padrão
            fileChooser.setSelectedFile(new File("linha.png"));

            int userSelection = fileChooser.showSaveDialog(painelDesenho);
            if (userSelection == JFileChooser.APPROVE_OPTION) {
                File fileToSave = fileChooser.getSelectedFile();
                
                // Garante que a extensão seja .png
                if (!fileToSave.getName().toLowerCase().endsWith(".png")) {
                    fileToSave = new File(fileToSave.getAbsolutePath() + ".png");
                }

                painelDesenho.saveJFrame(painelDesenho, fileToSave);
            }
        });
        
        
        setVisible(true);
        
              
    }
}

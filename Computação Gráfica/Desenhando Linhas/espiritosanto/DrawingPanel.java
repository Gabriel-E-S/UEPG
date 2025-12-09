

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.util.ArrayList;
import java.util.List;
import javax.imageio.ImageIO;

/**
 *
 * @author Espírito Santo
 */
public class DrawingPanel extends JPanel implements MouseListener {
    
    List<Point> pontos = new ArrayList<>();
    private String algoritmoSelecionado = "Simples";
    private String direcao = "Nenhuma";
    int deslocamentoX = 0;
    int deslocamentoY = 0;
    int numeroDeLinhas = 1;
    
    private final List<Pixel> pixels = new ArrayList<>();
    
    private boolean estaDesenhando = false;
        
    public DrawingPanel(){
        setBackground(Color.DARK_GRAY);
        
        addMouseListener(this);
    }
    
    public void setAlgoritmo(String nome){
       this.algoritmoSelecionado = nome; 
    }
    public void setNumeroDeLinhas(int numeroDeLinhas){
        this.numeroDeLinhas = numeroDeLinhas;
    }
    public void setDeslocamentoX(int deslocamentoX){
        this.deslocamentoX = deslocamentoX;
    }
    public void setDeslocamentoY(int deslocamentoY){
        this.deslocamentoY = deslocamentoY;
    }
    public int getDeslocamentoX(){
        return deslocamentoX;
    }
    public int getDeslocamentoY(){
        return deslocamentoY;
    }
    
    public void setDirecao(String direcao){
        this.direcao = direcao;
    }
    public String getDirecao(){
        return direcao;
    }    
    public void limpar(){
        pixels.clear();
        pontos.clear();
        repaint();
    }
    
    @Override
    protected void paintComponent(Graphics g){
        super.paintComponent(g);
        synchronized(pixels){
            for(Pixel p: pixels){
                g.setColor(p.cor);
                g.fillRect(p.x, p.y, 1, 1); // usando a função que o professor pediu <3
            }
        }
    }
    
    @Override
    public void mouseClicked(MouseEvent e) {
        
        if(estaDesenhando){
            JOptionPane.showMessageDialog(this,"Por favor, aguarde a linha atual terminar de ser desenhada.","Aguarde",JOptionPane.WARNING_MESSAGE);
            return;
        }
        //System.out.println("size ="+pontos.size()+"\n");
       
        pontos.add(e.getPoint());
        
        //System.out.println(" dps -- size ="+pontos.size()+"\n");

        if(!estaDesenhando && pontos.size() == numeroDeLinhas+1){
        
            estaDesenhando = true;

            new Thread(() -> {

                synchronized(pixels){
                    pixels.clear();
                }
                repaint();

                for(int i = 0; i< pontos.size()-1;i++){ // pra desenhar as linhas múltiplas é preciso de n+1 pontos para desenhar n retas ligadas

                    int x0 = pontos.get(i).x;
                    int y0 = pontos.get(i).y;
                    int x1 = pontos.get(i+1).x;
                    int y1 = pontos.get(i+1).y;

                    if (algoritmoSelecionado.equals("Simples")) {
                        desenharLinhaSimples(x0, y0, x1, y1);
                    } else{
                        if (algoritmoSelecionado.equals("Bresenham")) {
                            desenharBresenham(x0, y0, x1, y1);
                        }
                        else{
                            if (algoritmoSelecionado.equals("Comparar lado a lado")){
                                desenharLinhaSimples(x0, y0, x1, y1);

                                int dx = Math.abs(x1 - x0);

                                int dy = Math.abs(y1 - y0);

                                sleep(20);

                                if (dx > dy){ // a ideia é ver se fica melhor desenhar a outra linha pra baixo ou do lado da primeira.
                                    desenharBresenham(x0, y0+30, x1, y1+30);
                                }
                                else{
                                    desenharBresenham(x0+30, y0, x1+30, y1);
                                }
                            }
                            else{
                                desenharLinhaSimples(x0, y0, x1, y1);
                                sleep(20);
                                desenharBresenham(x0, y0, x1, y1);  
                            }
                        }
                    }
                }
                synchronized (pontos) {
                    pontos.clear();
                }
            }).start();
        }
    }
    
    // algoritmo dos slides
    private void desenharLinhaSimples(int x0, int y0, int x1, int y1){
        int x;
        double dy = y1 - y0;
        double dx = x1 - x0;
        
        estaDesenhando = true;
        
        setDeslocamentoX((int)dx);
        setDeslocamentoY((int)dy);
        setDirecao("A. Linha Simples");
        
        if(dx == 0 && dy == 0){
            adicionarPixel(x0,(int)Math.round(y0),Color.RED);
            setDirecao("Ponto Unico");
            estaDesenhando = false;
            return;
        }
        
        
        double m = dy/dx; //coeficiente angular
        double y = y0;
        
        
        if(dx == 0){ // linha vertical
            int ycomeco = Math.min(y0, y1);
            int yfim = Math.max(y0, y1);
            
            for(int i = ycomeco;i<=yfim;i++){
                adicionarPixel(x0, i, Color.RED);
                sleep(10);
            }
            setDirecao("Nenhuma");
            estaDesenhando = false;
            return;
        }
        
        int incrementoX;
        
        if(dx>0){
            incrementoX = 1;
        }
        else{
            incrementoX = -1;
        }

        for (x=x0; x!=x1 + incrementoX; x = x + incrementoX){
            adicionarPixel(x,(int)Math.round(y),Color.RED);
            y = y + m*incrementoX; //ou: y = y0 + m*(x - x0);
            sleep(60);
        }
        
        setDirecao("Nenhuma");
        estaDesenhando = false;
    }
    
    
    // algoritmo de Bresenham
    
    private void desenharBresenham(int x0, int y0, int x1, int y1) {
        
        String[] opcoes = new String[2];
        
        estaDesenhando = true;
        
        //  arredondando as coordenadas
        int xi = (int) Math.round(x0);
        int yi = (int) Math.round(y0);
        int xf = (int) Math.round(x1);
        int yf = (int) Math.round(y1);

        // contas
        int dx = xf - xi;
        int dy = yf - yi;
        int ax = Math.abs(dx);
        int ay = Math.abs(dy);
        
        setDeslocamentoX(dx);
        setDeslocamentoY(dy);
        
        // seção para mostrar as coordenadas de um jeito certo
        
         if (dx >= 0 && dy >= 0) { 
            if (dx >= dy) { 
                opcoes[0] = "E";
                opcoes[1] = "SE";
            } else { 
                opcoes[0] = "S";
                opcoes[1] = "SE";
            }
        } else if (dx <= 0 && dy >= 0) {
            if (-dx >= dy) { 
                opcoes[0] = "W";
                opcoes[1] = "SW";
            } else { 
                opcoes[0] = "S";
                opcoes[1] = "SW";
            }
        } else if (dx <= 0 && dy <= 0) {
            if (-dx >= -dy) { 
                opcoes[0] = "W";
                opcoes[1] = "NW";
            } else { 
                opcoes[0] = "N";
                opcoes[1] = "NW";
            }
        } else if (dx >= 0 && dy <= 0) {
            if (dx >= -dy) { 
                opcoes[0] = "E";
                opcoes[1] = "NE";
            } else { 
                opcoes[0] = "N";
                opcoes[1] = "NE";
            }
        }
        
        // passos de direção
        int passoX = (dx >= 0) ? 1 : -1;
        int passoY = (dy >= 0) ? 1 : -1;

        // posição inicial
        int x = xi;
        int y = yi;

        // Caso um único ponto)
        if (ax == 0 && ay == 0) {
            setDirecao("Ponto Unico");
            adicionarPixel(x, y, Color.YELLOW);
            estaDesenhando = false;
            return;
        }

        if (ax >= ay) {
            // |m| <= 1  → eixo condutor é X 
            // p decide entre E (leste) e NE/SE 
            int pDecisao_NE_ou_E = 2 * ay - ax;    
            int incrementoE      = 2 * ay;         
            int incrementoNE     = 2 * (ay - ax);  

            for (int i = 0; i <= ax; i++) {
                adicionarPixel(x, y, Color.YELLOW);

                if (pDecisao_NE_ou_E >= 0) {
                    setDirecao(opcoes[1]);
                    // Escolha NE se passoY>0, ou SE se passoY<0
                    y += passoY;
                    pDecisao_NE_ou_E += incrementoNE;
                } else {
                    // Escolha E
                    setDirecao(opcoes[0]);
                    pDecisao_NE_ou_E += incrementoE;
                }

                x += passoX; 
                sleep(60);
            }
        } else {
            // |m| > 1  → inversão lógica: eixo condutor é Y 
            int pDecisao_NE_ou_E = 2 * ax - ay;    
            int incrementoE      = 2 * ax;        
            int incrementoNE     = 2 * (ax - ay); 

            for (int i = 0; i <= ay; i++) {
                adicionarPixel(x, y, Color.YELLOW);

                if (pDecisao_NE_ou_E >= 0) {
                    // Escolha NE se passoY>0, ou SE se passoY<0
                    setDirecao(opcoes[1]);
                    x += passoX;
                    pDecisao_NE_ou_E += incrementoNE;
                } else {
                    // Escolha E
                    setDirecao(opcoes[0]);
                    pDecisao_NE_ou_E += incrementoE;
                }

                y += passoY;
                sleep(60);
            }
        }
        setDirecao("Nenhuma");
        estaDesenhando = false;
     }
    private void adicionarPixel(int x, int y, Color cor) {
        synchronized(pixels){
            pixels.add(new Pixel(x, y, cor));
        }
        repaint();
    }

    private void sleep(int ms) {
        try { Thread.sleep(ms); } catch (InterruptedException ignored) {}
    }
    
    public static void saveJFrame(JPanel frame, File file) {
        try {
            frame.repaint();
            Thread.sleep(200);

            Point location = frame.getLocationOnScreen();
            Dimension size = frame.getSize();

            Robot robot = new Robot();
            Rectangle captureRect = new Rectangle(location.x, location.y, size.width, size.height);
            BufferedImage image = robot.createScreenCapture(captureRect);

            ImageIO.write(image, "png", file);
            System.out.println("Imagem salva em: " + file.getAbsolutePath());
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    // Métodos não usados mas e obrigatória implementação por causa da interface
    public void mouseEntered(MouseEvent e) {}
    public void mouseExited(MouseEvent e) {}
    public void mousePressed(MouseEvent e) {}
    public void mouseReleased(MouseEvent e){}  
}

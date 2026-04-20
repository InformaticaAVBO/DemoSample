import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class PallinaAnimata extends JPanel implements ActionListener {
    int x = 50, y = 50;
    int dx = 3, dy = 2;
    int raggio = 20;

    public PallinaAnimata() {
        // Timer: ogni 16ms (~60fps) chiama actionPerformed
        Timer timer = new Timer(16, this);
        timer.start();
    }

    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);

        // Sfondo
        g.setColor(Color.BLACK);
        g.fillRect(0, 0, getWidth(), getHeight());

        // Pallina
        g.setColor(Color.ORANGE);
        g.fillOval(x - raggio, y - raggio, raggio * 2, raggio * 2);

        // Testo
        g.setColor(Color.WHITE);
        g.setFont(new Font("Arial", Font.BOLD, 16));
        g.drawString("Pallina rimbalzante!", 10, 20);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        x += dx;
        y += dy;

        // Rimbalzo sui bordi
        if (x - raggio < 0 || x + raggio > getWidth())  dx = -dx;
        if (y - raggio < 0 || y + raggio > getHeight()) dy = -dy;

        repaint(); // ridisegna il pannello
    }

    public static void main(String[] args) {
        JFrame finestra = new JFrame("Demo Grafica Java");
        finestra.setSize(600, 400);
        finestra.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        finestra.add(new PallinaAnimata());
        finestra.setVisible(true);
    }
}

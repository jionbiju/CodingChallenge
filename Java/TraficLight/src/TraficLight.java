import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class TraficLight extends JFrame implements ActionListener {
    JRadioButton r,y,g;

    public TraficLight(){

        setLayout(null);
        setSize(600,600);
        setVisible(true);

        r=new JRadioButton("RED");
        y=new JRadioButton("YELLOW");
        g=new JRadioButton("GREEN");

        r.setBounds(50, 45, 100, 20);
        y.setBounds(50, 120, 100, 20);
        g.setBounds(50, 200, 100, 20);
        add(r);
        add(y);
        add(g);

        ButtonGroup bg =new ButtonGroup();
        bg.add(r);
        bg.add(y);
        bg.add(g);

        r.addActionListener(this);
        y.addActionListener(this);
        g.addActionListener(this);

        setDefaultCloseOperation(EXIT_ON_CLOSE);

    }
    public void paint(Graphics gr) {



        gr.setColor(Color.black);
        gr.drawRect(180, 50, 90, 240);
        gr.setColor(Color.DARK_GRAY);
        gr.fillRect(180, 50, 90, 240);


        gr.setColor(Color.black);
        gr.drawOval(200, 60, 50, 60);  // Red light position
        gr.drawOval(200, 140, 50, 60); // Yellow light position
        gr.drawOval(200, 220, 50, 60); // Green light position


        gr.setColor(Color.gray);
        gr.fillOval(200, 60, 50, 60);  // Red
        gr.fillOval(200, 140, 50, 60); // Yellow
        gr.fillOval(200, 220, 50, 60); // Green


        if (r.isSelected()) {
            gr.setColor(Color.red);
            gr.fillOval(200, 60, 50, 60);
        } else if (y.isSelected()) {
            gr.setColor(Color.yellow);
            gr.fillOval(200, 140, 50, 60);
        } else if (g.isSelected()) {
            gr.setColor(Color.green);
            gr.fillOval(200, 220, 50, 60);
        }
    }
    public void actionPerformed(ActionEvent e) {
        repaint();
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new TraficLight();
            }
        });

    }


}

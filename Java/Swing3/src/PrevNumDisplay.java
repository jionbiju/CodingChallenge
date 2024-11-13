/*
Write a Java program using Swing to create a frame having three text fields, three
labels and a button. The interface has to accept a number in the first text field. While
clicking the button, the second and third text fields have to display the previous number
and next number respectively, of the accepted input number
 */
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class PevNumDisplay extends JFrame implements ActionListener {
    JButton btn;
    JTextField field1,field2,field3;
    JLabel label1,label2,label3;
    public PevNumDisplay(){
        setSize(300,400);
        setVisible(true);
        setLayout(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        label1=new JLabel("Enter a number");
        label1.setBounds(10,20,100,20);
        add(label1);

        field1=new JTextField();
        field1.setBounds(120,20,60,30);
        add(field1);

        label2=new JLabel("Previous number");
        label2.setBounds(10,80,100,20);
        add(label2);

        field2=new JTextField();
        field2.setEditable(false);
        field2.setBounds(120,80,60,30);
        add(field2);

        label3=new JLabel("Next number");
        label3.setBounds(10,120,100,20);
        add(label3);

        field3=new JTextField();
        field3.setEditable(false);
        field3.setBounds(120,120,60,30);
        add(field3);

        btn=new JButton("Click Here");
        btn.setBounds(20,200,100,30);
        add(btn);
        btn.addActionListener(this);
    }
    public void actionPerformed(ActionEvent a){
        int n=Integer.parseInt(field1.getText());
        int n1=n-1;
        int n2=n+1;
        field2.setText(Integer.toString(n1));
        field3.setText(Integer.toString(n2));
    }


    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new PevNumDisplay();
            }
        });
    }
}
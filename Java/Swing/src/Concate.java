import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/*
Implement a Java program using swing to create 3 textboxes.
There should be two buttons called “Concatenate” and “Clear”.
The first textbox should be labeled as “Input1”, the second
textbox should be labeled as “Input2” and the third textbox should
be labeled as “ConcatOutput”. When the user clicks on the
Concatenate button, the contents of Input1 and Input2 textboxes
are concatenated and should be displayed in the ConcatOutput
textbox. When the user clicks Clear, all the textboxes should be
cleared.
 */
public class Concate extends JFrame implements ActionListener {
    JTextField field1,field2,field3;
    JLabel label1,label2,label3;
    JButton concat,clear;
    public Concate(){
        setSize(500,600);
        setTitle("Concatenation");
        setLayout(null);
        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        label1=new JLabel("Input1");
        label1.setBounds(20,10,40,20);
        add(label1);

        field1=new JTextField();
        field1.setBounds(80,10,50,20);
        add(field1);

        label2=new JLabel("Input2");
        label2.setBounds(20,40,40,20);
        add(label2);

        field2=new JTextField();
        field2.setBounds(80,40,50,20);
        add(field2);

        label3=new JLabel("ConcatOutput");
        label3.setBounds(20,70,90,20);
        add(label3);

        field3=new JTextField();
        field3.setBounds(100,70,50,20);
        add(field3);

        clear=new JButton("Clear");
        clear.setBounds(20,150,100,30);
        add(clear);
        clear.addActionListener(this);

        concat=new JButton("Concatenate");
        concat.setBounds(20,110,120,30);
        add(concat);
        concat.addActionListener(this);
    }
    public void actionPerformed(ActionEvent ae){
        if(ae.getSource()==concat){
            String text1=field1.getText();
            String text2=field2.getText();
            String concatText=text1+text2;
            field3.setText(concatText);
        } else if (ae.getSource()==clear) {
            field1.setText("");
            field2.setText("");
            field3.setText("");
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new Concate();
            }
        });
    }
}

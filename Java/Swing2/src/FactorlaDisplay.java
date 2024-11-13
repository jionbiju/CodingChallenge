/*
Create two text field and a button.Enter a number in the first text field and display its factorial
in the second text field when button is clicked
 */
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class FactorlaDisplay extends JFrame implements ActionListener {
    JButton btn;
    JTextField field1,field2;
    public FactorlaDisplay(){
        setSize(300,400);
        setVisible(true);
        setLayout(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        field1=new JTextField();
        field1.setBounds(20,20,60,30);
        add(field1);

        field2=new JTextField();
        field2.setEditable(false);
        field2.setBounds(20,80,60,30);
        add(field2);

        btn=new JButton("Click Here");
        btn.setBounds(20,120,100,30);
        add(btn);
        btn.addActionListener(this);
    }
    public void actionPerformed(ActionEvent a){
        int n=Integer.parseInt(field1.getText());
        int fact=factorial(n);
        field2.setText(Integer.toString(fact));
    }
    int factorial(int n){
        if(n==0){
            return 1;
        }
        else{
            int fact=1;
            for(int i=1; i<=n; i++){
                fact=fact*i;
            }
            return fact;
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new FactorlaDisplay();
            }
        });
    }
}

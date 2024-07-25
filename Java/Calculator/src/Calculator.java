import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Calculator implements ActionListener {
    JFrame jf;
    boolean isOperatorClicked=false;
    String operations="";
    double oldValue;
    double newValue;
    String result;
    String answer;
    JLabel displayLabel;
    JButton sevenButton;
    JButton eightButton;
    JButton nineButton;
    JButton fourButton;
    JButton fiveButton;
    JButton sixButton;
    JButton oneButton;
    JButton twoButton;
    JButton threeButton;
    JButton dotButton;
    JButton zeroButton;
    JButton equalButton;
    JButton divideButton;
    JButton multiplicationButton;
    JButton substractButton;
    JButton additionButton;
    JButton clearButton;




    Calculator(){
        jf=new JFrame("Calculator");
        jf.setLayout(null);
        jf.setSize(390,630);
        jf.setLocation(1000,100);
        jf.setBackground(Color.lightGray);

        displayLabel=new JLabel();
        displayLabel.setBounds(20,40,340,100);
        displayLabel.setBackground(Color.white);
        displayLabel.setOpaque(true);
        displayLabel.setFont(new Font("Serif",Font.BOLD,40));
        displayLabel.setHorizontalAlignment(SwingConstants.RIGHT);
        jf.add(displayLabel);

        sevenButton=new JButton("7");
        sevenButton.setBounds(20,150,70,70);
        sevenButton.setBackground(Color.white);
        sevenButton.setFont(new Font("Arial", Font.PLAIN, 40));
        sevenButton.addActionListener(this::actionPerformed);
        jf.add(sevenButton);

        eightButton=new JButton("8");
        eightButton.setBounds(110,150,70,70);
        eightButton.setBackground(Color.white);
        eightButton.setFont(new Font("Arial", Font.PLAIN, 40));
        eightButton.addActionListener(this::actionPerformed);
        jf.add(eightButton);

        nineButton=new JButton("9");
        nineButton.setBounds(200,150,70,70);
        nineButton.setBackground(Color.white);
        nineButton.setFont(new Font("Arial", Font.PLAIN, 40));
        nineButton.addActionListener(this::actionPerformed);
        jf.add(nineButton);

        fourButton=new JButton("4");
        fourButton.setBounds(20,240,70,70);
        fourButton.setBackground(Color.white);
        fourButton.setFont(new Font("Arial", Font.PLAIN, 40));
        fourButton.addActionListener(this::actionPerformed);
        jf.add(fourButton);

        fiveButton=new JButton("5");
        fiveButton.setBounds(110,240,70,70);
        fiveButton.setBackground(Color.white);
        fiveButton.setFont(new Font("Arial", Font.PLAIN, 40));
        fiveButton.addActionListener(this::actionPerformed);
        jf.add(fiveButton);

        sixButton=new JButton("6");
        sixButton.setBounds(200,240,70,70);
        sixButton.setBackground(Color.white);
        sixButton.setFont(new Font("Arial", Font.PLAIN, 40));
        sixButton.addActionListener(this::actionPerformed);
        jf.add(sixButton);

        oneButton=new JButton("1");
        oneButton.setBounds(20,330,70,70);
        oneButton.setBackground(Color.white);
        oneButton.setFont(new Font("Arial", Font.PLAIN, 40));
        oneButton.addActionListener(this::actionPerformed);
        jf.add(oneButton);

        twoButton=new JButton("2");
        twoButton.setBounds(110,330,70,70);
        twoButton.setBackground(Color.white);
        twoButton.setFont(new Font("Arial", Font.PLAIN, 40));
        twoButton.addActionListener(this::actionPerformed);
        jf.add(twoButton);

        threeButton=new JButton("3");
        threeButton.setBounds(200,330,70,70);
        threeButton.setBackground(Color.white);
        threeButton.setFont(new Font("Arial", Font.PLAIN, 40));
        threeButton.addActionListener(this::actionPerformed);
        jf.add(threeButton);

        dotButton=new JButton(".");
        dotButton.setBounds(20,420,70,70);
        dotButton.setBackground(Color.white);
        dotButton.setFont(new Font("Arial", Font.PLAIN, 40));
        dotButton.addActionListener(this::actionPerformed);
        jf.add(dotButton);

        zeroButton=new JButton("0");
        zeroButton.setBounds(110,420,70,70);
        zeroButton.setBackground(Color.white);
        zeroButton.setFont(new Font("Arial", Font.PLAIN, 40));
        zeroButton.addActionListener(this::actionPerformed);
        jf.add(zeroButton);

        equalButton=new JButton("=");
        equalButton.setBounds(200,420,70,70);
        equalButton.setBackground(Color.white);
        equalButton.setFont(new Font("Arial", Font.PLAIN, 40));
        equalButton.addActionListener(this::actionPerformed);
        jf.add(equalButton);

        divideButton=new JButton("/");
        divideButton.setBounds(290,150,70,70);
        divideButton.setBackground(Color.white);
        divideButton.setFont(new Font("Arial", Font.PLAIN, 40));
        divideButton.addActionListener(this::actionPerformed);
        jf.add(divideButton);

        multiplicationButton=new JButton("*");
        multiplicationButton.setBounds(290,240,70,70);
        multiplicationButton.setBackground(Color.white);
        multiplicationButton.setFont(new Font("Arial", Font.PLAIN, 40));
        multiplicationButton.addActionListener(this::actionPerformed);
        jf.add(multiplicationButton);

        substractButton=new JButton("-");
        substractButton.setBounds(290,330,70,70);
        substractButton.setBackground(Color.white);
        substractButton.setFont(new Font("Arial", Font.PLAIN, 40));
        substractButton.addActionListener(this::actionPerformed);
        jf.add(substractButton);

        additionButton=new JButton("+");
        additionButton.setBounds(290,420,70,70);
        additionButton.setBackground(Color.white);
        additionButton.setFont(new Font("Arial", Font.PLAIN, 40));
        additionButton.addActionListener(this::actionPerformed);
        jf.add(additionButton);

        clearButton=new JButton("Clear");
        clearButton.setBounds(200,510,160,70);
        clearButton.setBackground(Color.white);
        clearButton.setFont(new Font("Arial", Font.PLAIN, 40));
        clearButton.addActionListener(this::actionPerformed);
        jf.add(clearButton);


        jf.setVisible(true);
        jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);


    }

    public static void main(String[] args){

        Calculator cal=new Calculator();
    }


    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource()==sevenButton){
            if (isOperatorClicked){
                displayLabel.setText("7");
                isOperatorClicked=false;
            }else {
                displayLabel.setText(displayLabel.getText()+"7");
            }

        } else if (e.getSource()==eightButton) {
            if (isOperatorClicked){
                displayLabel.setText("8");
                isOperatorClicked=false;
            }
            else {
                displayLabel.setText(displayLabel.getText()+"8");
            }

        } else if (e.getSource()==nineButton) {
            if (isOperatorClicked){
                displayLabel.setText("9");
                isOperatorClicked=false;
            }
            else {
                displayLabel.setText(displayLabel.getText()+"9");
            }
        } else if (e.getSource()==fourButton) {
            if (isOperatorClicked){
                displayLabel.setText("4");
                isOperatorClicked=false;
            }
            else {
                displayLabel.setText(displayLabel.getText()+"4");
            }
        } else if (e.getSource()==fiveButton) {
            if (isOperatorClicked){
                displayLabel.setText("5");
                isOperatorClicked=false;
            }
            else {
                displayLabel.setText(displayLabel.getText()+"5");
            }
        } else if (e.getSource()==sixButton) {
            if (isOperatorClicked){
                displayLabel.setText("86");
                isOperatorClicked=false;
            }
            else {
                displayLabel.setText(displayLabel.getText()+"6");
            }
        } else if (e.getSource()==oneButton) {
            if (isOperatorClicked){
                displayLabel.setText("1");
                isOperatorClicked=false;
            }
            else {
                displayLabel.setText(displayLabel.getText()+"1");
            }
        } else if (e.getSource()==twoButton) {
            if (isOperatorClicked){
                displayLabel.setText("2");
                isOperatorClicked=false;
            }
            else {
                displayLabel.setText(displayLabel.getText()+"2");
            }
        } else if (e.getSource()==threeButton) {
            if (isOperatorClicked){
                displayLabel.setText("3");
                isOperatorClicked=false;
            }
            else {
                displayLabel.setText(displayLabel.getText()+"3");
            }
        }else if (e.getSource()==dotButton) {
            displayLabel.setText(displayLabel.getText()+".");
        }else if (e.getSource()==zeroButton) {
            if (isOperatorClicked){
                displayLabel.setText("0");
                isOperatorClicked=false;
            }
            else {
                displayLabel.setText(displayLabel.getText()+"0");
            }
        }else if (e.getSource()==equalButton) {
            newValue=Double.parseDouble(displayLabel.getText());

//
            if (operations=="+"){
                double result;
                result=oldValue+newValue;
                answer=String.valueOf(result);
                displayLabel.setText(answer);
            }
            if (operations=="-"){
                double result;
                result=oldValue-newValue;
                answer=String.valueOf(result);
                displayLabel.setText(answer);
            }
            if (operations=="*"){
                double result;
                result=oldValue*newValue;
                answer=String.valueOf(result);
                displayLabel.setText(answer);
            }
            if (operations=="/"){
                double result;
                result=oldValue/newValue;
                answer=String.valueOf(result);
                displayLabel.setText(answer);
            }

        }else if (e.getSource()==divideButton) {
            isOperatorClicked=true;
            oldValue=Double.parseDouble(displayLabel.getText());
            displayLabel.setText("");
            operations="/";
        }else if (e.getSource()==multiplicationButton) {
            isOperatorClicked=true;
            oldValue=Double.parseDouble(displayLabel.getText());
            displayLabel.setText("");
            operations="*";
        }else if (e.getSource()==substractButton) {
            isOperatorClicked=true;
            oldValue=Double.parseDouble(displayLabel.getText());
            displayLabel.setText("");
            operations="-";
        }else if (e.getSource()==additionButton) {
            isOperatorClicked=true;
            oldValue=Double.parseDouble(displayLabel.getText());
            displayLabel.setText("");
            operations="+";
        } else if (e.getSource()==clearButton) {
            displayLabel.setText("");
        }

    }
}

public class Complex {
    private double real;
    private double imaginary;
    public Complex(){
        this.real=0;
        this.imaginary=0;
    }
     public Complex(double real, double imaginary){
        this.real=real;
        this.imaginary=imaginary;
     }
     public void display(){
         System.out.println(this.real + "+" + this.imaginary + "i");
     }
}

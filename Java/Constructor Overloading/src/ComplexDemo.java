public class ComplexDemo {
public static void main(String args[]){
    Complex c1 = new Complex();
    System.out.print("Default constructor: ");
    c1.display();
    Complex c2 = new Complex(4,7);
    System.out.print("Two parameter constructor: ");
    c2.display();
}
}

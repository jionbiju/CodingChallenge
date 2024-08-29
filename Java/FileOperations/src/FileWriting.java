//Reading and writing to a file
import java.util.Scanner;
import java.io.*;
public class FileWriting {
    public static void main(String[] args) throws IOException{
        String content;
        int ch;
        System.out.println("Enter the String:");
        Scanner sc = new Scanner(System.in);
        content = sc.nextLine();
        try{
            FileWriter writer = new FileWriter("input.txt");
            writer.write(content);
            writer.close();
            System.out.println("File input.txt created and content added to the file successfully.");
        }
        catch (IOException e){
            System.out.println(e);
        }
        try {
            FileReader fr = new FileReader("input.txt");
            FileWriter fw = new FileWriter("output.txt");
            while ((ch=fr.read())!=-1){
                    fw.write(ch);
            }
            fr.close();
            fw.close();
        }
        catch (IOException e){
            System.out.println(e);
        }
        try{
            FileReader reading =new FileReader("output.txt");
            System.out.println("Content of output.txt:");
            while ((ch=reading.read())!=-1){
                System.out.print((char)ch);
            }
            System.out.println();
            reading.close();
        }
        catch (IOException e){
            System.out.println(e);
        }
        finally {
            System.out.println("Operation completed.");
        }
    }
}
/*
OUTPUT
Enter the String:
JION
File input.txt created and content added to the file successfully.
Content of output.txt:
JION
Operation completed.
 */
//Write a Java program to copy the contents of one file to another file using
//FileInputStream and FileOutputStrea
//Copy the content from one file to another file
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
public class File {
    public static void main(String[] args) {
        FileInputStream fi=null;
        FileOutputStream fo=null;
        try{
            fi = new FileInputStream("G:/Jion Coding/Java/File1/src/sample.txt");
            fo=new FileOutputStream("G:/Jion Coding/Java/File1/src/output.txt");
            byte [] store =new byte[1024];
            int readCount;
            while ((readCount=fi.read(store))!=-1){
                fo.write(store,0,readCount);
            }
            System.out.println("File copied successfully.");
            fi.close();
            fo.close();
        }
        catch (IOException e){
            System.out.println(e);
        }
        finally {
            System.out.println("Operation Completed");
        }
    }
}

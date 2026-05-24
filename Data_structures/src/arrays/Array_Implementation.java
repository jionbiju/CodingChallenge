package arrays;

public class Array_Implementation {
    int [] arr;
    int size;
    int capacity;
    Array_Implementation (int capacity){
        arr = new int[capacity];
        this.capacity = capacity;
        size = 0;
    }
    boolean insert(int index, int element){
        if (index < 0 || size >= capacity || index > size){
            System.out.println("Cannot insert an element:Invalid Index");
            return false;
        }
        for (int i=size; i>index; i--){
            arr[i] = arr[i-1];
        }
        arr[index] = element;
        size++;
        return true;
    }
    int get(int index){
        if(index <0 || index >= size){
            System.out.println("Cannot get an element:Invalid index");
            return  -9999;
        }
        return arr[index];
    }

    void set(int index,int element){
        if(index <0 || index >= size){
            System.out.println("Cannot set an element:Invalid index");
            return;
        }
        arr[index] = element;
    }
    int search(int element){
        for(int i=0; i<size; i++){
            if(arr[i] == element){
                return i;
            }
        }
        return  -1;
    }

    boolean delete(int index){
        if(index<0 || index >= size){
            System.out.println("Cannot delete:Invalid index");
            return false;
        }
        for(int i=index; i<size-1; i++){
            arr[i] = arr[i+1];
        }
        size--;
        return true;
    }
    void display(){
        System.out.println("Array elements are:");
        for (int i=0; i<size; i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
    public static void main(String[] args) {
        Array_Implementation arr1 = new Array_Implementation(6);
        arr1.insert(0,7);
        arr1.insert(0,2);
        arr1.insert(1,10);
        arr1.insert(2,90);
        arr1.insert(1,55);
        arr1.insert(10,44);
        arr1.display();
        arr1.set(2,76);
        arr1.set(5,22);
        System.out.println("Search element 100:"+arr1.search(100));
        System.out.println("Element at index 0 is "+arr1.get(0));
        System.out.println("Element at index 7 is ");
        arr1.get(7);
        arr1.display();
        System.out.println("Index of element 7 is "+arr1.search(7));
        System.out.println("Deleted element at index 3 ");
        arr1.delete(3);
        System.out.println("Deleted element at index 20 ");
        arr1.delete(20);
        arr1.display();
    }
}
/*
OUTPUT
Cannot insert an element:Invalid Index
Array elements are:
2 55 10 90 7
Cannot set an element:Invalid index
Search element 100:-1
Element at index 0 is 2
Element at index 7 is
Cannot get an element:Invalid index
Array elements are:
2 55 76 90 7
Index of element 7 is 4
Deleted element at index 3
Deleted element at index 20
Cannot delete:Invalid index
Array elements are:
2 55 76 7

Process finished with exit code 0
*/

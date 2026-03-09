#include <stdio.h>

int main(){
    int bucket_size,outgoing_rate,dropped,bucket_content=0,packet_size,n;
    printf("Enter  bucket size:\n");
    scanf("%d",&bucket_size);
    printf("Enter outgoing rate:\n");
    scanf("%d",&outgoing_rate);
    printf("Enter number of packets:\n");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        printf("Enter the size of packet %d:",i+1);
        scanf("%d",&packet_size);
        if(packet_size <= (bucket_size-bucket_content)){
            printf("Packet added to bucket\n");
            bucket_content += packet_size;
        }
        else{
            dropped=packet_size - (bucket_size-bucket_content);
            bucket_content = bucket_size;
            printf("Bucket is full! %d bytes dropped\n", dropped);
        }
        if(bucket_content < outgoing_rate){
            printf("Transmitted %d bytes\n",bucket_content);
            bucket_content=0;
        }
        else{
            printf("Transmitted %d bytes\n",outgoing_rate);
            bucket_content-=outgoing_rate;
        }
        printf("Remaining bytes in bucket:%d\n",bucket_content);
    }
    
    return 0;

}
/*
OUTPUT
Enter  bucket size:
5
Enter outgoing rate:
2
Enter number of packets:
4
Enter the size of packet 1:2
Packet added to bucket
Transmitted 2 bytes
Remaining bytes in bucket:0
Enter the size of packet 2:6
Bucket is full! 1 bytes dropped
Transmitted 2 bytes
Remaining bytes in bucket:3
Enter the size of packet 3:2
Packet added to bucket
Transmitted 2 bytes
Remaining bytes in bucket:3
Enter the size of packet 4:2
Packet added to bucket
Transmitted 2 bytes
Remaining bytes in bucket:3
*/
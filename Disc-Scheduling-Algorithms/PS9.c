#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#define HIGH 199
#define LOW 0
int choice,track,no_req,head,head1,distance;
int disc_req[100],finish[100];
void menu()
{
    printf("*******MENU*******");
    printf("\n\n1. SSTF \n2. SCAN \n3. C-LOOK \n4. FCFS \n5. C-SCAN \n6. LOOK \n7. Exit");
    printf("\n\nEnter your choice: ");
    scanf("%d",&choice);
}

void sstf()
{
    char user;
    int i, queue[100], queue2[100], q_size, head, seek=0, temp;
  float avg;

  printf("\n\n-----SSTF Disk Scheduling Algorithm-----");

  printf("\nEnter the size of the queue: ");
  scanf("%d", &q_size);

  printf("Enter queue elements\n");
 for( i = 0; i < q_size; i++)
{
printf("Value No. [%d]: ", i + 1);
scanf("%d", &queue[i]);
}
  printf( "Enter initial head position: ");
  scanf("%d", &head);

  //get distance from head of elems in queue
  for(int i=0; i<q_size; i++){
    queue2[i] = abs(head-queue[i]);
  }

  //swap elems based on their distance from each other
  for(int i=0; i<q_size; i++){
      for(int j=i+1; j<q_size;j++){

        if(queue2[i]>queue2[j]){
            temp = queue2[i];
            queue2[i]=queue[j];
            queue2[j]=temp;

            temp=queue[i];
            queue[i]=queue[j];
            queue[j]=temp;
        }
    }

  }

  for(int i=1; i<q_size; i++){
    seek = seek+abs(head-queue[i]);
    head = queue[i];
  }

  printf("\nTotal seek time is %d\t",seek);
  avg = seek/(float)q_size;
  printf("\nAverage seek time is %f\t", avg);
  getch();
  system("cls");
}
void scan()
{
   int queue[20];
  int head, max, q_size, temp, sum;
  int dloc; //location of disk (head) arr

printf("\n\n-----SCAN Disk Scheduling Algorithm-----\n");
  printf( "Input no of disk locations: ");
  scanf("%d", &q_size);

  printf( "Enter head position: ");
  scanf("%d", &head);

  printf(  "Input elements into disk queue\n");
  for(int i=0; i<q_size; i++)
    {
    printf("Value No. [%d]: ", i + 1);
    scanf("%d", &queue[i]);
  }

  queue[q_size] = head; //add RW head into queue
  q_size++;

  //sort the array
  for(int i=0; i<q_size;i++){
    for(int j=i; j<q_size; j++){
      if(queue[i]>queue[j]){
        temp = queue[i];
        queue[i] = queue[j];
        queue[j] = temp;
      }
    }
  }

  max = queue[q_size-1];

  //locate head in the queue
  for(int i=0; i<q_size; i++){
    if(head == queue[i]){
      dloc = i;
      break;
    }
  }

  if(abs(head-LOW) <= abs(head-HIGH)){

      for(int j=dloc; j>=0; j--){
        printf("%d --> ",queue[j]);
      }
      for(int j=dloc+1; j<q_size; j++){
        printf("%d --> ",queue[j]);
      }

      } else {

      for(int j=dloc+1; j<q_size; j++){
          printf("%d --> ",queue[j]);
      }
      for(int j=dloc; j>=0; j--){
          printf("%d --> ",queue[j]);
      }

  }
  sum  = head + max;
  printf("\nmovement of total cylinders %d", sum);
    getch();
  system("cls");
  }
void clook()
{
struct request;
    {
	int request_track_number;
	bool visited;
    }
    int n, i, j, head, item[20], dst[20];
    int cyl=0;
    printf("\n\n-----CLOOK Disk Scheduling Algorithm-----\n");
    printf("Enter no. of locations: ");
    scanf("%d",&n);
    printf("Enter position of head: ");
    scanf("%d",&head);
    printf("Enter elements of disk queue\n");
    for(i=0; i<n; i++)
    {
    printf("Value No. [%d]: ", i + 1);
    scanf("%d", &item[i]);
    dst[i]=(head-item[i]);
    }
    //Selection Sort
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(dst[j]>dst[i])
            {
                int temp=dst[j];
                dst[j]=dst[i];
                dst[i]=temp;

                temp=item[i];
                item[i]=item[j];
                item[j]=temp;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        if(item[i]>=head)
        {
            j=i;
            break;
        }
    }

    printf("j=%d", j);
    printf("\n\nOrder of disk allocation is as follows:\n");
    for(i=j;i<n;i++)
    {
        printf(" -> %d", item[i]);
        cyl+= abs(head-item[i]);
        head=item[i];

    }
    for(i=0;i<j;i++)
    {
        printf(" -> %d", item[i]);
        cyl+= abs(head-item[i]);
        head=item[i];
    }
    printf("\n\nCylinder movement: %d\n\n", cyl );
      getch();
  system("cls");
}

void fcfs()
{
            int queue[20],n,head,i,j,k,seek=0,max,diff;
            float avg;
            printf("\n\n-----FCFS Disk Scheduling Algorithm-----\n");
            printf("Enter the max range of disk: ");
            scanf("%d",&max);
            printf("Enter the size of queue request: ");
            scanf("%d",&n);
            printf("Enter the queue of disk positions to be read\n");
            for(i=0;i<=n;i++)
            {
            printf("Value No. [%d]: ", i + 1);
            scanf("%d",&queue[i]);
            }
            printf("Enter the initial head position\n");
            scanf("%d",&head);
            queue[0]=head;
            for(j=0;j<=n-1;j++)
            {
                        diff=abs(queue[j+1]-queue[j]);
                        seek+=diff;
                        printf("Disk head moves from %d to %d with seek                                                                                       %d\n",queue[j],queue[j+1],diff);
            }
            printf("Total seek time is %d\n",seek);
            avg=seek/(float)n;
            printf("Average seek time is %f\n",avg);

  getch();
  system("cls");
}
void cscan (){
  int queue[20], q_size, head, i,j, seek=0, diff, max, temp, queue1[20], queue2[20], temp1=0, temp2=0;
  float avg;
 printf("\n\n-----CSCAN Disk Scheduling Algorithm-----\n");
  printf( "Input no of disk locations: ");
  scanf("%d", &q_size);

  printf( "Enter initial head position: ");
  scanf("%d", &head);

  printf( "Enter disk positions to be read\n");
  for(i=0; i<q_size; i++) {
printf("Value No. [%d]: ", i + 1);
    scanf("%d", &temp);
      if(temp >= head){
          queue1[temp1] = temp;
          temp1++;
      } else {
          queue2[temp2] = temp;
          temp2++;
      }
  }
  for(i=0; i<temp1-1; i++){
    for(j=i+1; j<temp1; j++){
        if(queue1[i] > queue1[j]){
          temp = queue1[i];
          queue1[i] = queue1[j];
          queue1[j] = temp;
      }
    }
  }

  for(i=0; i<temp2-1; i++){
    for(j=i+1; j<temp2; j++){
      if(queue2[i]>queue2[j]){
          temp = queue2[i];
          queue2[i] = queue2[j];
          queue2[j] = temp;
      }
    }
  }
  if(abs(head-LOW) >= abs(head-HIGH)){

      for(i=1,j=0; j<temp1; i++,j++){
          queue[i] = queue1[j];
      }

          queue[i] = HIGH;
          queue[i+1] = 0;

      for(i=temp1+3, j=0; j<temp2; i++, j++){
          queue[i] = queue2[j];
      }

  } else {

      for(i=1,j=temp2-1; j>=0; i++,j--){
          queue[i] = queue2[j];
      }

          queue[i] = LOW;
          queue[i+1] = HIGH;

      for(i=temp2+3, j=temp1-1; j>=0; i++, j--){
          queue[i] = queue1[j];
      }
}

  queue[0] = head;

  for(j=0; j<=q_size+1; j++){
      diff=abs(queue[j+1] - queue[j]);
        seek += diff;
        printf("Disk head moves from %d to %d with seek %d\n",queue[j],queue[j+1],diff);

  }
  printf("Total seek time is %d\n", seek);
  avg = seek/(float)q_size;
  printf("Average seek time is %f\n", avg);
    getch();
  system("cls");
}
void look()
{
#define LOW 0
#define HIGH 199
 int queue[20], head, q_size, i,j, seek=0, diff, max, temp, queue1[20], queue2[20], temp1=0, temp2=0;
  float avg;
 printf("\n\n-----LOOK Disk Scheduling Algorithm-----\n");
  printf( "Input the number of disk locations: ");
  scanf("%d", &q_size);

  printf( "Enter initial head position: ");
  scanf("%d", &head);

  printf("Enter disk positions to read\n");

  for(i=0; i<q_size; i++){
    printf("Value No. [%d]: ", i + 1);
    scanf("%d", &temp);
    if(temp >= head){
        queue1[temp1] = temp;
        temp1++;
    } else {
        queue2[temp2] = temp;
        temp2++;
    }
  }
  for(i=0; i<temp1-1; i++){
   for(j=i+1; j<temp1; j++){
       if(queue1[i] > queue1[j]){
         temp = queue1[i];
         queue1[i] = queue1[j];
         queue1[j] = temp;
       }
    }
  }
  for(i=0; i<temp2-1; i++){
    for(j=i+1; j<temp2; j++){
      if(queue2[i] < queue2[j]){
          temp = queue2[i];
          queue2[i] = queue2[j];
          queue2[j] = temp;
      }
    }
  }

  if(abs(head-LOW) >= abs(head-HIGH)){

      for(i=1,j=0; j<temp1; i++,j++){
          queue[i] = queue1[j];
      }

      for(i=temp1+1, j=0; j<temp2; i++, j++){
          queue[i] = queue2[j];
      }

  } else {

      for(i=1,j=0; j<temp2; i++,j++){
          queue[i] = queue2[j];
      }

      for(i=temp2+1, j=0; j<temp1; i++, j++){
          queue[i] = queue1[j];
      }

  }

  queue[0] = head;

  for(j=0; j<q_size; j++){
      diff=abs(queue[j+1] - queue[j]);
        seek += diff;
        printf("Disk head moves from %d to %d with seek %d\n",queue[j],queue[j+1],diff);

  }

  printf("Total seek time is %d\n", seek);
  avg = seek/(float)q_size;
  printf("Average seek time is %f\n", avg);
    getch();
  system("cls");
}

int main()
{
    system("color 07");
    while(1)
    {
        menu();
        switch(choice)
        {

        case 1: sstf();
            break;
        case 2: scan();
            break;
        case 3: clook();
            break;
        case 4: fcfs();
            break;
        case 5: cscan();
            break;
        case 6: look();
            break;
        case 7: exit(0);
            break;
        default:
            printf("\n\nEnter valid choice");
            break;
        }
    }

    return 0;
}

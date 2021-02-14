#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <stdlib.h>

pthread_mutex_t lockSum;
pthread_mutex_t lockCreator;
int inpNum, matrix[20][20];

void * thread_matrix_sum() //Matris toplamı için thread çağırımı
{
  for (int a = 0; a < inpNum; a++) {
    pthread_mutex_lock( & lockSum);
    int t = sumOfMatrix();
    printf("Toplam : %d \n", t);
    pthread_mutex_unlock( & lockCreator);
  }
}

int sumOfMatrix() { // matris toplama işlemi
  int total = 0;
  unsigned short i, j;

  for (i = 0; i < 20; i++) {
    for (j = 0; j < 20; j++) {
      total = total + matrix[i][j];
    }
  }
  return total;
}

void * thread_matrix_creator() // Matrisin oluşturulma işlemi
{
  int sayac;

  srand(time(NULL)); // aynı değerlerin üretilmesi engellendi

  for (sayac = 0; sayac < inpNum; sayac++) {
    pthread_mutex_lock( & lockCreator);
    for (int i = 0; i < 20; i++) {
      for (int j = 0; j < 20; j++) {
        matrix[i][j] = rand() % 100; // 0-100 arası random deger 
      }
    }
    printMatrix();
    pthread_mutex_unlock( & lockSum);
  }
}

void printMatrix() { //Global matris degiskeninin  
  unsigned short i, j;

  for (i = 0; i < 20; i++) {
    for (j = 0; j < 20; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  printf("\n");
}

void ctrl_c(int x) //Ctrl+c yapıldığında çıkış yapılır.
{
  printf("Ctrl+c ile çıkış yapıldı \n");
  signal(SIGINT, ctrl_c);
  pthread_mutex_destroy( & lockCreator);
  pthread_mutex_destroy( & lockSum);
  exit(0);
}

int main() {
  signal(SIGINT, ctrl_c);
  while (1) {

    printf("Matris sayısı giriniz ? \n");
    scanf("%d", & inpNum);
    if (inpNum <= 0) {
      printf("Lütfen 0 dan büyük bir integer değer giriniz. \n");
      break;
    }
    pthread_mutex_init( & lockSum, NULL);
    pthread_mutex_init( & lockCreator, NULL);
    pthread_mutex_lock( & lockSum);
    pthread_t sum;
    pthread_t creator;

    pthread_create( & sum, NULL, thread_matrix_sum, NULL);
    pthread_create( & creator, NULL, thread_matrix_creator, NULL);
    pthread_join(sum, NULL);
    pthread_join(creator, NULL);
  }

  return 0;
}

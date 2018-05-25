/*
 * queue adalah sekumpulan dari banyak objek yang di tambahkan (Enqueue)
 * atau di di keluarkan (Dequeue) berdasarkan prinsip First-in-First-out (FIFO).
 *
 * contoh mudah dari sebuah queue adalah seperti sebuah antrian pembeli di depan toko.
 *
 * ada 2 operasi utama di dalam queue, yaitu enqueue dan dequeue.
 * enqueue adalah memasukkan sebuah element kedalam baris terakhir dari queue.
 * dequeue adalah mengeluarkan sebuah element didalam baris terdepan queue.
 *
 * dalam bahasa c kita bisa mengimplementasikan struktur data queue menggunakan sebuah array.
 * kita menginput sebuah data dari belakang queue dan mengeluarkannya dari barisan terdepan.
 * oleh karena itu kita membutuhkan 2 pointer yaitu : Head dan Tail untuk membedakan baris mana
 * yang di depan dan dibelakang.
 *
 *               head             tail
 *                ||               ||
 *                ||               ||
 * -- enqueue-- >  5 - 4 - 3 - 2 - 1 -- dequeue -->
 *
 * queue pertama adalah bernilai kosong karena belum ada antriannya, maka kita harus menginisialisasi pointer 'head' dan 'tail'
 * dengan membuat fungsi "init( head, tail);"
 *
 *
 *  created by Agung Nur Aprianto
 */

#include <stdio.h>
#include <stdlib.h>
 /*
  * dalam bahasa c kita harus mendeklarasikan fungsi - fungsi
  * yang akan dibuat terlebih dahulu, kecuali fungsi main.
  * karena fungsi main adalah fungsi default untuk bahasa c.
  */

void init(int *head, int *tail);
void enqueue(int *q, int *tail, int element);
int dequeue(int *q, int *head);
int empty(int head, int tail);
int full(int tail, const int size);
void display(int *q, int head, int tail);


int main()
{
    const int SIZE = 5;     //queue size atau maksimal jumlah antrian dalam queue
    int head, tail, element;
    int queue[SIZE];

    init(&head, &tail);

    printf("-- Enqueue Elements --\n");
    //push element into stack (Push adalah istilah yang digunakan untuk
    // memasukkan data kedalam queue)
    while(!full(tail, SIZE)){
        printf("Enter number to enqueue: ");
        scanf("%d", &element); //input data

        enqueue(queue, &tail, element);

        display(queue, head, tail);
    }
    printf("Queue is full \n\n");

    printf("-- Denqueue Elements --\n");
    while(!empty(head, tail)){
        element = dequeue(queue, &head);
        printf("Denqueue Elements %d \n", element);

        display(queue, head, tail);

    }
    printf("Queue is empty \n");


    return 0;
}

/*
 * inisialisasi pointer head dan tail.
 * dan memberi nilai 0 karena belum ada antrian yang masuk.
 */
void init (int *head, int *tail){
    *head = *tail = 0;
}

/*
 * queue dalam keadaan kosong ketika kedua pointer bernilai sama.
 */
int empty (int head, int tail){
    return head == tail;
}

/*
 * ketika kita menginput(Enqueue) data masuk ke dalam Queue,
 * maka kita harus menambahkan Tail pointer + 1 setiap data yang di masukkan
 */
void enqueue(int *q, int *tail, int element){
    q[(*tail)++] = element;
}

/*
 * ketika kita mengeluarkan(Denqueue) data masuk ke dalam Queue,
 * maka kita harus menambahkan Head pointer + 1 setiap data yang di keluarkan
 */
int dequeue(int *q, int *head){
    return q[ (*head)++ ];
}

/*
 * queue dalam keadaan kosong ketika kedua pointer bernilai sama
 */
int full(int tail, const int size){
    return tail == size;
}

/*
 * tampilkan data di dalam pointer
 */
void display(int *q, int head, int tail){
    int i = tail - 1;
    while(i >= head){
        printf(" %d ,", q[i--]);
    }
    printf("\n");
}

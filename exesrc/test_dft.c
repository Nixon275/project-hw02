#include <stdio.h>
#include "../src/io.c"
#include "../src/cmplx.c"
#include<fcntl.h>
#include<math.h>


int writeTest(){
    int Fs = 200;
    double T = 1.0/Fs;
    int N = 100;
    
    cmplx_t signal[N];
    cmplx_t DFT[N];

    //generiranje signala
    for(int i = 0; i < N; i++){
        float signal_read = sin(2*M_PI*i*T);
        signal[i][0] = signal_read;
        signal[i][1] = 0; //realan input signal; img = 0
    }
    
    //DFT(signal)
    cmplx_dft(signal, DFT, N);

    //DFT(signal) upisuje se u datoteku
    int fd = open("datoteka.bin", O_WRONLY | O_CREAT | O_TRUNC);
    if(fd == -1){
        perror("Error opening file.");
        return 1;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < 2; j++){
            float vrijednost = DFT[i][j];
            void *a = (void *) &vrijednost;
            int vrijednost_ieee = *((int *) a);
            int vrijednost_cijeli_broj = (int) vrijednost;
            write_word(fd, vrijednost_ieee);
        }
    }
    close(fd);
    return 0;
}

int main(){
    if(!writeTest())
        printf("Write success.\n");
    else
        printf("Write fail.\n");
    return 0;
}
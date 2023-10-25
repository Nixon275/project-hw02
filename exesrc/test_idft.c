#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <math.h>
#include "../src/cmplx.c"
#include "../src/io.c"

int readTest(){
    int Fs = 200;
    double T = 1.0/Fs;
    int N = 100;

    //čitanje DFT(signal) iz datoteke u DFT_read
    cmplx_t DFT_read[N];

    int fd = open("datoteka.bin", O_RDONLY);
    if(fd == -1){
        perror("Error opening file");
        return 1;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 2; j++){
            int vrijednost_ieee = read_word(fd);
            void *a = (void *) &vrijednost_ieee;
            float vrijednost = *((float *) a);
            DFT_read[i][j] = vrijednost;
        }
    }

    //generiranje originalnog signala
    cmplx_t signal[N];
    for(int i = 0; i < N; i++){
        float signal_read = sin(2*M_PI*i*T);
        signal[i][0] = signal_read;
        signal[i][1] = 0;
    }

    //provodi se IDFT na DFT_read
    cmplx_t signal_after[N];
    cmplx_idft(DFT_read, signal_after, N);

    //usporedba novog signala s orginalnim
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 2; j++){
            if(signal_after[i][j]-signal[i][j] > 1e-6){
                return 1;
            }
        }
    }
    close(fd);
    remove("datoteka.bin");
    return 0;
}
    
    //usporedba član po član
    /*for(int i = 0; i < N; i++){
       printf("%f - %f\n", signal[i][0], signal_after[i][0]);
       printf("%fj - %fj\n", signal[i][1], signal_after[i][1]);
    }
    return 0;
}*/

int main(){
    if(!readTest())
        printf("Read success.\n");
    else
        printf("Read fail.\n");
    return 0;
}
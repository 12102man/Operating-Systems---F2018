#include  <stdio.h>
#include  <signal.h>
#include  <stdlib.h>


void sig_handler(int sig) {
     char choice;

     // Ignoring process
     signal(sig, SIG_IGN);
     printf("Are you sure you want to exit? [y/n]");
     choice = getchar();
     if (choice=='y' || choice=='Y') {
          exit(0);
     } else {
          signal(SIGINT, sig_handler);
     }


}

int main() {

     signal(SIGINT, sig_handler);
     while(1) {
     }
     return 0;

}
#include  <stdio.h>
#include  <signal.h>
#include  <stdlib.h>


void sigkill_handler(int sig) {
     char choice;

     // Ignoring process
     signal(sig, SIG_IGN);
     printf("Ooops, I caught SIGKILL.\n");


}

void sigstop_handler(int sig) {
     char choice;

     // Ignoring process
     signal(sig, SIG_IGN);
     printf("Ooops, I caught SIGSTOP.\n");
     
}
void sigusr1_handler(int sig) {

     // Ignoring process
     printf("Ooops, I caught SIGUSR1.\n");

     /* 
     When I call command 'kill -SIGUSR1 <pid>',
     program handles SIGKILL, and doesn't die
     */
}

int main() {
     signal(SIGKILL, sigkill_handler);
     signal(SIGSTOP, sigstop_handler);
     signal(SIGUSR1, sigusr1_handler);
     while(1) {
     }
     return 0;

}
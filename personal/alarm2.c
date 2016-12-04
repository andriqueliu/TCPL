#include <sys/time.h>		/* for setitimer */
#include <unistd.h>		/* for pause */
#include <signal.h>		/* for signal */

#include <stdio.h>              // for perror...
#include <stdlib.h>             // for exit...

#define INTERVAL 500		/* number of milliseconds to go off */
#define TIMERINTERVAL 3333

#define TIMER ITIMER_REAL

void DoStuff(void);

// i is just for testing
static int i = 0;

static double values[300];   // Buffer storing ADC values
static double average;       // Running average 

// Interrupt at a frequency of 300 Hz (for now)
// Call interrupt handler
int main(int argc, char *argv[]) {
   
   // Enable ADC pins
   system("echo BB-ADC > /sys/devices/bone_capemgr.*/slots");

   // declare it_val of type struct itimerval
   struct itimerval it_val;	// for setting itimer
   
   /* Upon SIGALRM, call DoStuff().
   * Set interval timer.  We want frequency in ms,
   * but the setitimer call needs seconds and useconds. */
   if (signal(SIGALRM, (void (*)(int)) DoStuff) == SIG_ERR) {
      perror("Unable to catch SIGALRM");
      exit(1);
   }
   /*
   it_val.it_value.tv_sec =     INTERVAL/1000; // this takes into account ms conversion
   it_val.it_value.tv_usec =    (INTERVAL*1000) % 1000000;
   it_val.it_interval = it_val.it_value;
   */

   it_val.it_value.tv_sec = 0;
   it_val.it_value.tv_usec = TIMERINTERVAL;   // results in 300 samples/s
   
   it_val.it_interval.tv_sec = 0;
   it_val.it_interval.tv_usec = TIMERINTERVAL;   

   // ITIMER_REAL: real timer is used, process sent a SIGALARM signal
   // after the wall-clock time has passed
   if (setitimer(TIMER, &it_val, NULL) == -1) {
      perror("error calling setitimer()"); // sent to stderr stream
      exit(1);
   }
   
   // printf("lol\n"); // this does NOT loop

   // !!!  Removing infinite loop breaks code
   while (1) {
      // printf("lol\n"); this repeats
      
      pause(); // pause blocks until a signal arrives (to ex. handler
               // or terminate process
   }
}

// Handler function
// Every time the handler is called, handler samples ADC value
// At the 300th value, average is taken; if avg > thresh, 
// interrupt master. Otherwise, restart process
void DoStuff(void) {
   printf("Timer went off.\n");
   printf("%d\n", i++);
   
   // here's where you sample the ADC values, still trying to get that done
   // values[i++] = 
} 

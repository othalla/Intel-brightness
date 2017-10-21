#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getBrightness(char const * sys_fs_bright);
void howToUse();
int setBrightness();

int main(int argc,char *argv[]) {
	if (argc != 2) {
		printf("Only 1 args must be specified !\nLeaving...\n");
		howToUse();
		exit(1);
	}

int inc = strcmp(argv[1],"inc");
int dec = strcmp(argv[1],"dec");
int action = 0;

	if (inc == 0) {
	printf("Increasing Brightness !");
	action = 1;
	} else if (dec == 0) {
	printf("Deacreasing Brightness !");
	action = 2;
	} else {
		printf("Bad option supplied\nLeaving...\n");
		howToUse();
		exit(2);
	} 

char const * MaxBr = "/sys/class/backlight/intel_backlight/max_brightness";
char const * CurBr = "/sys/class/backlight/intel_backlight/brightness";

  int MnBr;
  int MxBr;
  MxBr = getBrightness(MaxBr);
  printf("%d\n", MxBr);

  int CrBr;
  CrBr = getBrightness(CurBr);
  printf("%d\n", CrBr);

   // We will change value by 10% for each setBrightness() call inc/dec
   int StepBr;
   StepBr = MxBr / 10;
   MnBr = MxBr % 10;
   printf("Incr/Decr unit is done by = %d\n",StepBr);
   printf("Incr/Decr min is  = %d\n",MnBr);

   int NwBr;

	switch (action)
	{
		case 1:
		printf("\n Increase\n");

		if (CrBr < MxBr )
			{	
				NwBr = CrBr + StepBr;			
				printf("%d\n",NwBr);
				setBrightness(CurBr,NwBr);
			} else {
				printf("Maximum brightness... Cant do more lighter\n");
				exit(11);
			}
		break;
		
		case 2:
		printf("\n Decrease\n");
			if (CrBr > MnBr )
			{	
				NwBr = CrBr - StepBr;			
				printf("%d\n",NwBr);
				setBrightness(CurBr,NwBr);
			} else {
				printf("Minimum brightness... Cant do nothing darker\n");
				exit(12);
			}
		break;
	}
}

int getBrightness(char const * sys_fs_bright) {
   FILE *fp;
   int buff;
   fp = fopen(sys_fs_bright, "r");
   fscanf(fp, "%d", &buff);
   printf("getBrightness() \n - File : %s \n - Content : %d\n", sys_fs_bright, buff );
   fclose(fp);
   return buff;
}

int setBrightness(char const * sys_fs_bright,int newval) {
   FILE *fp;
   fp = fopen(sys_fs_bright, "w");
   fprintf(fp,"%d\n",newval);
   fclose(fp);
}

void howToUse () {
   printf("\nUsage : \n"); 
   printf("brightnessctrl (inc|dec) \n"); 
   printf("   inc : +10\% brightness \n"); 
   printf("   dec : -10\% brightness \n"); 
}    

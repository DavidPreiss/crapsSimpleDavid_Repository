#include <stdio.h>
#include <string.h>
	//Always^^
#include <stdlib.h>
#include <time.h>
	//Windows^^
//#include <linux/random.h>
	//linux^^
//Craps by David Preiss



int twoDice()
{
	
	/*
	char *buf = " ";
	//wow
	read("/dev/dice", buf, 1);
	printf("%d\n", buf);
	read("dice_dev", buf, 1);
	printf("%d\n", buf);
	int roll1 = dice_dev.read+ 1;

	int roll2 = read("/dev/dice")+ 1;
	*/
	
	int roll1 = rand()%6+ 1;
	int roll2 = rand()%6+ 1;
	
	int rollsum = roll1 + roll2;
	
	printf("\nYou have rolled %d + %d = %d",roll1,roll2,rollsum);
	return rollsum;
}
//end of twoDice

int main()
{
	srand((unsigned int)time(NULL));
	int repeat = 1;
	char choice1;
	char playername[30] = "";
	
	printf("\nWhat is your name? ");
	scanf("%s",playername);
	printf("\nHello %s!\n", playername);
	while (repeat)
	{
		
		printf("\nWould you like to play Craps?(y/n) ");
		scanf(" %c",&choice1);
		if(choice1 == 'y')
		{
			int game = 1; //no one has won. 1 neutral, 2 win, 0 lose
			int firstroll = twoDice();
			if(firstroll == 7 || firstroll == 11) game = 2;
			if(firstroll < 4 || firstroll == 12) game = 0;
			
			while( game == 1) //point
			{
				int pointroll = twoDice();
				if(pointroll == firstroll) game = 2;
				if(pointroll == 7) game = 0;
				
			}//end of point
			
			
			switch(game)// finish game
			{
				case 0:	
					printf("\nYou lose.\n");
					break;
				
				case 2: 
					printf("\nYou win.\n");
					break;
			}
			
		}
		//end of choice1 == 'y'
		
		
		if(choice1 == 'n')
		{
			printf("\nGoodbye %s!\n", playername);
			repeat = 0;
		}
		//end of choice1 == 'n'
	}
	//end of repeat
	
	
	return 0;
}
//end of main


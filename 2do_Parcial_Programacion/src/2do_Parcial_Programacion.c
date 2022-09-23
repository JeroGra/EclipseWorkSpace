/*
 ============================================================================
 Name        : 2do_Parcial_Programacion.c
 Author      : Granadillo Jeronimo
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 2

typedef struct
{
	char usuario[25];
	char comentario[140];
	char hashtag[50];
}eTweet;

eTweet* NewTweet();
eTweet* TweetNewParametros( char* usuario,char* comentario,char* hashtag);
int SetterTweet(eTweet* tweet,char* usuario,char* comentario,char* hashtag);
int GetterTweet(eTweet* tweet,char* usuario,char* comentario,char* hashtag);
void PrintTweet(eTweet* tweet);

int main(void) {
    setbuf(stdout,NULL);
	eTweet* tweetUno = NULL;
	eTweet* tweetDos = NULL;
	char usuario[2][25]={{"Cosmoxs0"},{"ger"}};
	char comentario[2][140]={{"Se aprueba o no? que decis @ger."},{"Se re aprueba @Cosmoxs0, CONFIRMADO POR @gio."}};
	char hashtag[2][50]={{"#2doParcialProgramacion"},{"#2doParcialProgramacion"}};

	tweetUno = TweetNewParametros(usuario[0],comentario[0],hashtag[0]);
	tweetDos = TweetNewParametros(usuario[1],comentario[1],hashtag[1]);

    PrintTweet(tweetUno);
	PrintTweet(tweetDos);

	return EXIT_SUCCESS;
}

eTweet* NewTweet()
{
	eTweet* indice = (eTweet*) malloc(sizeof(eTweet)*1);
	if(indice != NULL)
	{
		strcpy(indice->usuario,"");
		strcpy(indice->comentario,"");
		strcpy(indice->hashtag,"");
	}
	return indice;
}
eTweet* TweetNewParametros(char* usuario,char* comentario,char* hashtag)
{
	eTweet* tweet = NULL;
	tweet = NewTweet();
	if(tweet != NULL)
	{
           SetterTweet(tweet,usuario,comentario,hashtag);
	}
	return tweet;
}

int SetterTweet(eTweet* tweet,char* usuario,char* comentario,char* hashtag)
{
	int isOk = -1;
	if(tweet != NULL && usuario != NULL && comentario != NULL)
	{
		strcpy(tweet->usuario,usuario);
		strcpy(tweet->comentario,comentario);
		strcpy(tweet->hashtag,hashtag);
		isOk = 0;
	}
	return isOk;
}

int GetterTweet(eTweet* tweet,char* usuario,char* comentario,char* hashtag)
{
	int isOk = -1;
	if(tweet != NULL)
	{
		strcpy(usuario,tweet->usuario);
		strcpy(comentario,tweet->comentario);
		strcpy(hashtag,tweet->hashtag);
		isOk = 0;
	}
	return isOk;
}

void PrintTweet(eTweet* tweet)
{
	char usuario[25];
	char comentario[140];
	char hashtag[50];
	GetterTweet(tweet,usuario,comentario,hashtag);
	printf("@%s\n %s\n %s\n\n",usuario,comentario,hashtag);
}

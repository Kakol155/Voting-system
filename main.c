#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <time.h>

char CategoryVote[100];
char Question[100];
int NumberQuestions;



void CreatVote()
{
    FILE *file;



    int i = 1;
    char result[100];
    char txt[20] = ".txt";



    int value3;
    int value4;
    int value5;

    char ForbiddenNames[3][50] = { {"AnswerTheQuestion.txt"}, {"CategoryVote.txt"}, {"NumberOfQuestions.txt"}};

    printf("Enter voting categories\n");
    scanf("%s",&CategoryVote);

    value3 = strcmp(ForbiddenNames[0],CategoryVote);
    value4 = strcmp(ForbiddenNames[1],CategoryVote);
    value5 = strcmp(ForbiddenNames[2],CategoryVote);



    if(value3 == 0)
    {
        printf("This is not a vote \n");
        return;
    }

    if(value4 == 0)
    {
        printf("This is not a vote \n");
        return;
    }

    if(value5 == 0)
    {
        printf("This is not a vote \n");
        return;
    }

    file = fopen("CategoryVote.txt","w");

    fprintf(file,"%s",CategoryVote);

    fclose(file);

    printf("Enter how many questions you want to create, remember to use '-' when creating a multi-word question, e.g. Intel-or-AMD \n");
    scanf("%d",&NumberQuestions);




    file = fopen("NumberOfQuestions.txt","w");

    fprintf(file,"%d",NumberQuestions);

    fclose(file);

    strcpy(result,CategoryVote);
    strcat(result,"");
    strcat(result,txt);

    file = fopen(result,"w");

    fprintf(file,"Category: %s \n \n",CategoryVote);

    fclose(file);

    for(i; i < NumberQuestions; i++)
    {

    file = fopen(result,"a");

    printf("Enter %d question \n",i);
    scanf("%s",&Question);
    fprintf(file,"Question %d: %s \n",i,Question);

    fclose(file);

    }

    file = fopen(result,"a");

    printf("Enter %d Question \n",i);
    scanf("%s",&Question);
    fprintf(file,"Question %d: %s \n",i,Question);

    fclose(file);


}

void AnswerTheQuestions()
{
    FILE *file;

    int i = 1;

    int TheNumberOfQuestionsHeWantsToAnswer;
    char SelectedVote[100];
    char InformationVote[200];
    char Answer[200];
    char InformationCategoryVote[200];
    char InformationNumber[50];
    int value1;
    char value2[100] = "";

    char ForbiddenNames[3][50] = { {"AnswerTheQuestion.txt"}, {"CategoryVote.txt"}, {"NumberOfQuestions.txt"}};

    int result;

    int value3;
    int value4;
    int value5;

    file = fopen("NumberOfQuestions.txt","r");

    while(fgets(InformationNumber, 200, file))
    {
    //printf("%s",InformationNumber);
    }

    fclose(file);

    value1 = strcmp(InformationNumber,value2);

    if(value1 == 0)
    {
    printf("There are no selectable votes \n");
    }

    else
    {

    printf("Remember you can't use names AnswerTheQuestion.txt, CategoryVote.txt and NumberOfQuestions.txt, All the vote you can take part in: \n\n");

    struct _finddata_t txt_file;
    intptr_t eFile;

    if( (eFile = _findfirst( "*.txt", &txt_file )) == -1L )
    {
    printf( "There is no vote you can take part in\n" );
    return;
    }


    else
    {

    do {
    char buffer[30];

    ctime_s( buffer, _countof(buffer), &txt_file.time_write );
    printf( "%s, ",txt_file.name );
    printf("\n\n");

    } while( _findnext( eFile, &txt_file ) == 0 );
        _findclose( eFile );

    puts("");
    printf("Enter the name of the vote you want to participate in:\n");
    scanf("%s",&SelectedVote);

    value3 = strcmp(ForbiddenNames[0],SelectedVote);
    value4 = strcmp(ForbiddenNames[1],SelectedVote);
    value5 = strcmp(ForbiddenNames[2],SelectedVote);



    if(value3 == 0)
    {
        printf("This is not a vote \n");
        return;
    }

    if(value4 == 0)
    {
        printf("This is not a vote \n");
        return;
    }

    if(value5 == 0)
    {
        printf("This is not a vote \n");
        return;
    }

    else
    {

    file = fopen(SelectedVote,"r");

    puts("");
    while(fgets(InformationVote, 200, file))
    {
    printf("%s",InformationVote);
    }

    fclose(file);

    printf("Enter how many questions you want to answer \n");
    scanf("%d",&TheNumberOfQuestionsHeWantsToAnswer);

    result = TheNumberOfQuestionsHeWantsToAnswer;

    file = fopen("CategoryVote.txt","r");

    while(fgets(InformationCategoryVote, 200, file))
    {
    //printf("%s",InformationVote);
    }

    fclose(file);

    file = fopen("AnswerTheQuestion.txt","a");

    fprintf(file,"\n");
    fprintf(file,"Answer the question: %s \n\n",InformationCategoryVote);

    fclose(file);

    for(i; i < result; i++)
    {

    printf("Enter the answer to the question %d: \n",i);
    scanf("%s",&Answer);

    file = fopen("AnswerTheQuestion.txt","a");

    fprintf(file,"Question %d: %s \n",i,Answer);

    fclose(file);

    }

    printf("Enter the answer to the question %d: \n",i);
    scanf("%s",&Answer);

    file = fopen("AnswerTheQuestion.txt","a");

    fprintf(file,"Question %d: %s",i,Answer);

    fclose(file);

    }

    }
    }
}

void SeeTheAnswers()
{
    FILE *file;

    char AnswerQuestion[200];


    file = fopen("AnswerTheQuestion.txt","r");

    while(fgets(AnswerQuestion, 200, file))
    {
    printf("%s", AnswerQuestion);
    }




    fclose(file);

}

void ResetAnswers()
{
    FILE *file;

    file = fopen("AnswerTheQuestion.txt","w");

    fprintf(file,"");

    printf("Responses reset \n");

    fclose(file);
}

void Exit()
{
    printf("You have left the program \n");
}

void DeleteVote()
{
    char NameFile[100];



     printf("All files: \n\n");

    struct _finddata_t txt_file;
    intptr_t eFile;

    if( (eFile = _findfirst( "*.txt", &txt_file )) == -1L )
    {
        printf( "No files\n" );
        return 0;
    }


    else
    {

    do {
    char buffer[30];

    ctime_s( buffer, _countof(buffer), &txt_file.time_write );
    printf( "%s, ",txt_file.name );

    } while( _findnext( eFile, &txt_file ) == 0 );
    _findclose( eFile );
    }

    printf("\n\n");
    printf("Enter the name of the file with questions \n");
    scanf("%s",&NameFile);

    puts("");
    remove("AnswerTheQuestion.txt");
    remove("CategoryVote.txt");
    remove(NameFile);
    remove("NumberOfQuestions.txt");

}

int main()
{
    int number;
    int i = 0;

    for(i; i < 1000; i++)
    {

    printf("\n\n");
    printf("|---------------------------------------------------------------|\n");
    printf("|1.Create a vote                                                |\n");
    printf("|2.Answer the questions of the vote of your choice              |\n");
    printf("|3.View voting responses                                        |\n");
    printf("|4.Reset the given answers                                      |\n");
    printf("|5.Delete vote                                                  |\n");
    printf("|6.Exit                                                         |\n");
    printf("|---------------------------------------------------------------|\n");
    printf("\n\n");

    printf("  \n");
    printf("Enter number:\n");
    scanf("%d",&number);


    if(number == 1)
    {
       CreatVote();
    }

    if(number == 2)
    {
        AnswerTheQuestions();
    }

    if(number == 3)
    {
        SeeTheAnswers();
    }

    if(number == 4)
    {
        ResetAnswers();
    }

    if(number == 5)
    {
        DeleteVote();
    }

    if(number == 6)
    {
        Exit();
        return 0;
    }
    }
}






// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    InitGame();
    
    
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    //ClearScreen();

    if (bGameOver)
    {
        ClearScreen();
        InitGame();
    }
    else
    {
        PrintLine(TEXT("Your input is " + Input));
        CheckInput(Input);
    }


}

void UBullCowCartridge::CheckInput(FString Input)
{
    PrintLine(Input + " " + HiddenWord);
    if (Input == HiddenWord)
    {
        EndGame();     
    }
    else {
        if (Input.Len() != HiddenWord.Len())
        {
            PrintLine(TEXT("You kinda wrong.\n The length of the word you are looking for is %i"), HiddenWord.Len());
        }
        Lives--;
        PrintLine(TEXT("Sry, you lost a life =( \nBut don't worry, you have %i more to go"), Lives);
        if (Lives <= 0) {
            EndGame();
        }
    }
}

void UBullCowCartridge::InitGame()
{
    
    HiddenWord = TEXT("isogram");
    Lives = HiddenWord.Len();
    bGameOver = false;
    PrintWelcome();
}

void UBullCowCartridge::PrintWelcome()
{
    PrintLine(TEXT("Hello there! \nYou are on the BullCow game.\nAnd you have %i lives\nPls press the Enter button!"), Lives);
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Game is over for better or for worse.\nIf you want to continue - press enter!\nOtherwise, enjoy your eternity here"));
}
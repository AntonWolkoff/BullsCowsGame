// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include <set>

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
        CheckInput(Input);
    }


}

void UBullCowCartridge::CheckInput(FString Input)
{
    int32 HiddenWordLength = HiddenWord.Len();
    if (Input == HiddenWord)
    {
        PrintLine(TEXT("Wow! You won!\nWho could've guessed that?"));
        EndGame();     
    }
    else {
        if (Input.Len() != HiddenWordLength)
        {
            PrintLine(TEXT("You kinda wrong.\nThe length of the word you are looking for is %i"), HiddenWordLength);
        }
        else if (!IsIsogram(Input))
        {
            PrintLine(TEXT("Sry, it was not isogram("));
        }

        Lives--;
        
        if (Lives <= 0) {
            EndGame();
        }
        else
        {
            PrintLine(TEXT("Sry, you lost a life =( \nBut don't worry, you have %i more to go"), Lives);
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

bool UBullCowCartridge::IsIsogram(FString Input)
{
    int32 InputLength = Input.Len();
    char* result = TCHAR_TO_ANSI(*Input);
    std::set<char> UniqueInputChars(result, result+InputLength);
    if (InputLength == UniqueInputChars.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}
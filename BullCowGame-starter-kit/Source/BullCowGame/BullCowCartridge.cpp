// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT(" Hello there! \n You are on the BullCow game. \n Pls press the Enter button!"));
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    FString HiddenWord = TEXT("isogram");
    PrintLine(TEXT("Your input is " + Input));
    PrintLine(CheckInput(Input, HiddenWord));


}

FString UBullCowCartridge::CheckInput(FString Input, FString Isogram)
{
    PrintLine(Input + " " + Isogram);
    if (Input == Isogram) {
        return TEXT("VICTORY!");
    }
    else {
        return TEXT("LOOSER!");
    }
}
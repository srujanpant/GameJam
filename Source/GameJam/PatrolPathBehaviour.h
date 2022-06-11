// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UENUM()
enum EPatrolPathBehaviour
{
	DoNothing		UMETA(DisplayName = "Do Nothing"),
	PatrolBack      UMETA(DisplayName = "Patrol Back"),
	Loop			UMETA(DisplayName = "Loop"),
};
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Containers/Array.h"
#include "Containers/Map.h"
#include "Containers/UnrealString.h"
#include "CoreTypes.h"
#include "HAL/PlatformCrt.h"
#include "Math/Color.h"
#include "Misc/Exec.h"

class FString;

ARK_API class FColorList
{
public:
	typedef TMap< FString, const FColor* > TColorsMap;
	typedef TArray< const FColor* > TColorsLookup;

	// Common colors.	
	ARK_API static const FColor White;
	ARK_API static const FColor Red;
	ARK_API static const FColor Green;
	ARK_API static const FColor Blue;
	ARK_API static const FColor Magenta;
	ARK_API static const FColor Cyan;
	ARK_API static const FColor Yellow;
	ARK_API static const FColor Black;
	ARK_API static const FColor Aquamarine;
	ARK_API static const FColor BakerChocolate;
	ARK_API static const FColor BlueViolet;
	ARK_API static const FColor Brass;
	ARK_API static const FColor BrightGold;
	ARK_API static const FColor Brown;
	ARK_API static const FColor Bronze;
	ARK_API static const FColor BronzeII;
	ARK_API static const FColor CadetBlue;
	ARK_API static const FColor CoolCopper;
	ARK_API static const FColor Copper;
	ARK_API static const FColor Coral;
	ARK_API static const FColor CornFlowerBlue;
	ARK_API static const FColor DarkBrown;
	ARK_API static const FColor DarkGreen;
	ARK_API static const FColor DarkGreenCopper;
	ARK_API static const FColor DarkOliveGreen;
	ARK_API static const FColor DarkOrchid;
	ARK_API static const FColor DarkPurple;
	ARK_API static const FColor DarkSlateBlue;
	ARK_API static const FColor DarkSlateGrey;
	ARK_API static const FColor DarkTan;
	ARK_API static const FColor DarkTurquoise;
	ARK_API static const FColor DarkWood;
	ARK_API static const FColor DimGrey;
	ARK_API static const FColor DustyRose;
	ARK_API static const FColor Feldspar;
	ARK_API static const FColor Firebrick;
	ARK_API static const FColor ForestGreen;
	ARK_API static const FColor Gold;
	ARK_API static const FColor Goldenrod;
	ARK_API static const FColor Grey;
	ARK_API static const FColor GreenCopper;
	ARK_API static const FColor GreenYellow;
	ARK_API static const FColor HunterGreen;
	ARK_API static const FColor IndianRed;
	ARK_API static const FColor Khaki;
	ARK_API static const FColor LightBlue;
	ARK_API static const FColor LightGrey;
	ARK_API static const FColor LightSteelBlue;
	ARK_API static const FColor LightWood;
	ARK_API static const FColor LimeGreen;
	ARK_API static const FColor MandarianOrange;
	ARK_API static const FColor Maroon;
	ARK_API static const FColor MediumAquamarine;
	ARK_API static const FColor MediumBlue;
	ARK_API static const FColor MediumForestGreen;
	ARK_API static const FColor MediumGoldenrod;
	ARK_API static const FColor MediumOrchid;
	ARK_API static const FColor MediumSeaGreen;
	ARK_API static const FColor MediumSlateBlue;
	ARK_API static const FColor MediumSpringGreen;
	ARK_API static const FColor MediumTurquoise;
	ARK_API static const FColor MediumVioletRed;
	ARK_API static const FColor MediumWood;
	ARK_API static const FColor MidnightBlue;
	ARK_API static const FColor NavyBlue;
	ARK_API static const FColor NeonBlue;
	ARK_API static const FColor NeonPink;
	ARK_API static const FColor NewMidnightBlue;
	ARK_API static const FColor NewTan;
	ARK_API static const FColor OldGold;
	ARK_API static const FColor Orange;
	ARK_API static const FColor OrangeRed;
	ARK_API static const FColor Orchid;
	ARK_API static const FColor PaleGreen;
	ARK_API static const FColor Pink;
	ARK_API static const FColor Plum;
	ARK_API static const FColor Quartz;
	ARK_API static const FColor RichBlue;
	ARK_API static const FColor Salmon;
	ARK_API static const FColor Scarlet;
	ARK_API static const FColor SeaGreen;
	ARK_API static const FColor SemiSweetChocolate;
	ARK_API static const FColor Sienna;
	ARK_API static const FColor Silver;
	ARK_API static const FColor SkyBlue;
	ARK_API static const FColor SlateBlue;
	ARK_API static const FColor SpicyPink;
	ARK_API static const FColor SpringGreen;
	ARK_API static const FColor SteelBlue;
	ARK_API static const FColor SummerSky;
	ARK_API static const FColor Tan;
	ARK_API static const FColor Thistle;
	ARK_API static const FColor Turquoise;
	ARK_API static const FColor VeryDarkBrown;
	ARK_API static const FColor VeryLightGrey;
	ARK_API static const FColor Violet;
	ARK_API static const FColor VioletRed;
	ARK_API static const FColor Wheat;
	ARK_API static const FColor YellowGreen;

	/** Initializes list of common colors. */
	void CreateColorMap();

	/** Returns a color based on ColorName. If not found, returns White. */
	ARK_API const FColor& GetFColorByName( const TCHAR* ColorName ) const;

	/** Returns a linear color based on ColorName. If not found, returns White. */
	ARK_API const FLinearColor GetFLinearColorByName( const TCHAR* ColorName ) const;

	/** Returns true if color is valid common colors. If not found returns false. */
	bool IsValidColorName( const TCHAR* ColorName ) const;

	/** Returns index of color based on ColorName. If not found returns 0. */
	ARK_API int32 GetColorIndex( const TCHAR* ColorName ) const;

	/** Returns a color based on index. If index is invalid, returns White. */
	ARK_API const FColor& GetFColorByIndex( int32 ColorIndex ) const;

	/** Returns color's name based on index. If index is invalid, returns BadIndex. */
	ARK_API const FString& GetColorNameByIndex( int32 ColorIndex ) const;

	/** Returns the number of colors. */
	ARK_API int32 GetColorsNum() const
	{
		return ColorsMap.Num();
	}

	/** Prints to log all colors information. */
	void LogColors();

protected:
	void InitializeColor( const TCHAR* ColorName, const FColor* ColorPtr, int32& CurrentIndex );

	/** List of common colors. */
	TColorsMap ColorsMap;

	/** Array of colors for fast lookup when using index. */
	TColorsLookup ColorsLookup;
};


ARK_API extern FColorList GColorList;

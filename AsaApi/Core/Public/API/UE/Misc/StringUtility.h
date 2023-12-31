// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Containers/UnrealString.h"
#include "CoreTypes.h"

namespace StringUtility
{
	/**
	 * Unescapes a URI
	 *
	 * @param URLString an escaped string (e.g. File%20Name)
	 *
	 * @return un-escaped string (e.g. "File Name")
	 */
	FString UnescapeURI(const FString& URLString);
}


﻿// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

struct UScriptStruct;

/**
 * Describes a type with a StaticStruct (static) member.
 */
struct CStaticStructProvider
{
	template <typename T>
	auto Requires(UScriptStruct*& StructRef) -> decltype(
		StructRef = T::StaticStruct()
	);
};

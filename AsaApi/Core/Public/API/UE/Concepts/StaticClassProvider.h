﻿// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

struct UClass;

/**
 * Describes a type with a StaticClass (static) member.
 */
struct CStaticClassProvider
{
	template <typename T>
	auto Requires(UClass*& ClassRef) -> decltype(
		ClassRef = T::StaticClass()
	);
};

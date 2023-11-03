#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <string>

#ifdef ARK_EXPORTS
#define ARK_API __declspec(dllexport)
#else
#define ARK_API __declspec(dllimport)
#endif

struct BitField
{
	DWORD64 offset;
	DWORD bit_position;
	ULONGLONG num_bits;
	ULONGLONG length; //in bytes
};

// Address helpers

ARK_API DWORD64 GetAddress(const void* base, const std::string& name);
ARK_API LPVOID GetAddress(const std::string& name);

ARK_API LPVOID GetDataAddress(const std::string& name);

ARK_API BitField GetBitField(const void* base, const std::string& name);
ARK_API BitField GetBitField(LPVOID base, const std::string& name);

#define DECLARE_HOOK(name, returnType, ...) typedef returnType(__fastcall * name ## _Func)(__VA_ARGS__); \
inline name ## _Func name ## _original; \
returnType __fastcall Hook_ ## name(__VA_ARGS__)
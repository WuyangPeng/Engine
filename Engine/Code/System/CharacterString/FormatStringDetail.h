// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:11)

#ifndef SYSTEM_CHARACTER_STRING_FORMAT_STRING_DETAIL_H
#define SYSTEM_CHARACTER_STRING_FORMAT_STRING_DETAIL_H

#include "FormatString.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/EnumOperator/EnumCastDetail.h"

template <typename... T>
bool System
	::StringPrintfUseCharactersSize(TChar* dest, size_t destCharactersSize, const TChar* format, T... args)  
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (IsFailed(::StringCchPrintf(dest, destCharactersSize, format, args...)))
		return false;
	else
		return true;
#else // !SYSTEM_PLATFORM_WIN32
	va_list arguments{ nullptr };
	va_start(arguments, format); 
	va_end(arguments);

	SYSTEM_UNUSED_ARG(dest);
	SYSTEM_UNUSED_ARG(destCharactersSize);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

template <typename... T>
bool System
	::StringPrintfUseBytesSize(TChar* dest, size_t destBytesSize, const TChar* format, T... args) 
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (IsFailed(::StringCbPrintf(dest, destBytesSize, format, args...)))
		return false;
	else
		return true;
#else // !SYSTEM_PLATFORM_WIN32
	va_list arguments{ nullptr };
	va_start(arguments, format);
	va_end(arguments);

	SYSTEM_UNUSED_ARG(dest);
	SYSTEM_UNUSED_ARG(destBytesSize);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

template <typename... T>
bool System
	::StringPrintfUseCharactersSize(TChar* dest, size_t destCharactersSize, TChar** destEnd, size_t* remaining, StringSafe flag, const TChar* format, T... args)  
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (IsFailed(::StringCchPrintfEx(dest, destCharactersSize, destEnd, remaining, EnumCastUnderlying(flag), format, args...)))
		return false;
	else
		return true;
#else // !SYSTEM_PLATFORM_WIN32
	va_list arguments{ nullptr };
	va_start(arguments, format);
	va_end(arguments);

	SYSTEM_UNUSED_ARG(dest);
	SYSTEM_UNUSED_ARG(destCharactersSize);
	SYSTEM_UNUSED_ARG(destEnd);
	SYSTEM_UNUSED_ARG(remaining);
	SYSTEM_UNUSED_ARG(flag);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

template <typename... T>
bool System
	::StringPrintfUseBytesSize(TChar* dest, size_t destBytesSize, TChar** destEnd, size_t* remaining, StringSafe flag, const TChar* format, T... args)  
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (IsFailed(::StringCbPrintfEx(dest, destBytesSize, destEnd, remaining, EnumCastUnderlying(flag), format, args...)))
		return false;
	else
		return true;
#else // !SYSTEM_PLATFORM_WIN32
	va_list arguments{ nullptr };
	va_start(arguments, format);	   
	va_end(arguments);

	SYSTEM_UNUSED_ARG(dest);
	SYSTEM_UNUSED_ARG(destCharactersSize);
	SYSTEM_UNUSED_ARG(destEnd);
	SYSTEM_UNUSED_ARG(remaining);
	SYSTEM_UNUSED_ARG(flag);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

template <typename... Types>
int System
	::SNPrintf(char* const buffer, const size_t sizeInBytes, const size_t maxCount, char const* const format, const Types&... args)
{
#ifdef SYSTEM_PLATFORM_WIN32

	return	::_snprintf_s(buffer, sizeInBytes, maxCount, format, args...);

#else // !SYSTEM_PLATFORM_WIN32	

	SYSTEM_UNUSED_ARG(sizeInBytes);

	return	::snprintf(buffer, maxCount, format, args...);

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_CHARACTER_STRING_FORMAT_STRING_DETAIL_H

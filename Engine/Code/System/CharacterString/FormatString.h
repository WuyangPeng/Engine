// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 13:22)

#ifndef SYSTEM_CHARACTER_STRING_FORMAT_STRING_H
#define SYSTEM_CHARACTER_STRING_FORMAT_STRING_H

#include "System/SystemDll.h"

#include "Flags/FormatStringFlags.h"
#include "System/Helper/UnicodeUsing.h"

#include <cstdarg>

namespace System
{
	// 格式化字符串。

	int SYSTEM_DEFAULT_DECLARE VsnPrintf(char* buffer, size_t size, const char* format, va_list argList) noexcept;

	bool SYSTEM_DEFAULT_DECLARE Strcat(char* destination, size_t sizeInBytes, const char* source) noexcept;

	size_t SYSTEM_DEFAULT_DECLARE Strlen(const char* str) noexcept;
	bool SYSTEM_DEFAULT_DECLARE Strcpy(char* destination, size_t sizeInBytes, char const* source) noexcept;
	SYSTEM_DEFAULT_DECLARE char* Strtok(char* string, char const* delimiter, char** context) noexcept;
	SYSTEM_DEFAULT_DECLARE const char* Strstr(char const* str, char const* subStr) noexcept;

	constexpr StringSafe GetFillByteStringSafe(StringSafe flag) noexcept
	{
		return (flag & StringSafe::FillByte) | StringSafe::FillBehindNull;
	}

	constexpr StringSafe GetFailureByteStringSafe(StringSafe flag) noexcept
	{
		return (flag & StringSafe::FillByte) | StringSafe::FillOnFailure;
	}

	constexpr StringSafe GetFillPatternStringSafe(StringSafe flag) noexcept
	{
		return flag & StringSafe::FillByte;
	}

	bool SYSTEM_DEFAULT_DECLARE StringCopyUseCharactersSize(TChar* dest, size_t destCharactersSize, const TChar* src);
	bool SYSTEM_DEFAULT_DECLARE StringCopyUseBytesSize(TChar* dest, size_t destBytesSize, const TChar* src);
	bool SYSTEM_DEFAULT_DECLARE StringCopyUseCharactersSize(TChar* dest, size_t destCharactersSize, const TChar* src, TChar** destEnd, size_t* remaining, StringSafe flag);
	bool SYSTEM_DEFAULT_DECLARE StringCopyUseBytesSize(TChar* dest, size_t destBytesSize, const TChar* src, TChar** destEnd, size_t* remaining, StringSafe flag);
	bool SYSTEM_DEFAULT_DECLARE StringCopyUseCharactersSize(TChar* dest, size_t destCharactersSize, const TChar* src, size_t srcCharactersSize);
	bool SYSTEM_DEFAULT_DECLARE StringCopyUseBytesSize(TChar* dest, size_t destBytesSize, const TChar* src, size_t srcBytesSize);
	bool SYSTEM_DEFAULT_DECLARE StringCopyUseCharactersSize(TChar* dest, size_t destCharactersSize, const TChar* src, size_t srcCharactersSize,
															TChar** destEnd, size_t* remaining, StringSafe flag);
	bool SYSTEM_DEFAULT_DECLARE StringCopyUseBytesSize(TChar* dest, size_t destBytesSize, const TChar* src, size_t srcBytesSize,
													   TChar** destEnd, size_t* remaining, StringSafe flag);

	bool SYSTEM_DEFAULT_DECLARE StringCatUseCharactersSize(TChar* dest, size_t destCharactersSize, const TChar* src);
	bool SYSTEM_DEFAULT_DECLARE StringCatUseBytesSize(TChar* dest, size_t destBytesSize, const TChar* src);
	bool SYSTEM_DEFAULT_DECLARE StringCatUseCharactersSize(TChar* dest, size_t destCharactersSize, const TChar* src, TChar** destEnd, size_t* remaining, StringSafe flag);
	bool SYSTEM_DEFAULT_DECLARE StringCatUseBytesSize(TChar* dest, size_t destBytesSize, const TChar* src, TChar** destEnd, size_t* remaining, StringSafe flag);
	bool SYSTEM_DEFAULT_DECLARE StringCatUseCharactersSize(TChar* dest, size_t destCharactersSize, const TChar* src, size_t appendCharactersSize);
	bool SYSTEM_DEFAULT_DECLARE StringCatUseBytesSize(TChar* dest, size_t destBytesSize, const TChar* src, size_t appendBytesSize);
	bool SYSTEM_DEFAULT_DECLARE StringCatUseCharactersSize(TChar* dest, size_t destCharactersSize, const TChar* src, size_t appendCharactersSize,
														   TChar** destEnd, size_t* remaining, StringSafe flag);
	bool SYSTEM_DEFAULT_DECLARE StringCatUseBytesSize(TChar* dest, size_t destBytesSize, const TChar* src, size_t appendBytesSize,
													  TChar** destEnd, size_t* remaining, StringSafe flag);

	bool SYSTEM_DEFAULT_DECLARE StringGetsUseCharactersSize(TChar* dest, size_t destCharactersSize);
	bool SYSTEM_DEFAULT_DECLARE StringGetsUseBytesSize(TChar* dest, size_t destBytesSize);
	bool SYSTEM_DEFAULT_DECLARE StringGetsUseCharactersSize(TChar* dest, size_t destCharactersSize, TChar** destEnd, size_t* remaining, StringSafe flag);
	bool SYSTEM_DEFAULT_DECLARE StringGetsUseBytesSize(TChar* dest, size_t destBytesSize, TChar** destEnd, size_t* remaining, StringSafe flag);

	bool SYSTEM_DEFAULT_DECLARE StringLengthUseCharactersSize(const TChar* src, size_t maxCharactersSize, size_t* charactersLength);
	bool SYSTEM_DEFAULT_DECLARE StringLengthUseBytesSize(const TChar* src, size_t maxBytesSize, size_t* bytesLength);

	bool SYSTEM_DEFAULT_DECLARE StringVPrintfUseCharactersSize(TChar* dest, size_t destCharactersSize, const TChar* format, va_list argList);
	bool SYSTEM_DEFAULT_DECLARE StringVPrintfUseBytesSize(TChar* dest, size_t destBytesSize, const TChar* format, va_list argList);
	bool SYSTEM_DEFAULT_DECLARE StringVPrintfUseCharactersSize(TChar* dest, size_t destCharactersSize, TChar** destEnd, size_t* remaining,
															   StringSafe flag, const TChar* format, va_list argList);
	bool SYSTEM_DEFAULT_DECLARE StringVPrintfUseBytesSize(TChar* dest, size_t destBytesSize, TChar** destEnd, size_t* remaining,
														  StringSafe flag, const TChar* format, va_list argList);

	template <typename... T>
	bool StringPrintfUseCharactersSize(TChar* dest, size_t destCharactersSize, const TChar* format, T... args);
	template <typename... T>
	bool StringPrintfUseBytesSize(TChar* dest, size_t destBytesSize, const TChar* format, T... args);
	template <typename... T>
	bool StringPrintfUseCharactersSize(TChar* dest, size_t destCharactersSize, TChar** destEnd, size_t* remaining, StringSafe flag, const TChar* format, T... args);
	template <typename... T>
	bool StringPrintfUseBytesSize(TChar* dest, size_t destBytesSize, TChar** destEnd, size_t* remaining, StringSafe flag, const TChar* format, T... args);
	
	// 返回存储在buffer中的字符，不包括终止null字符。
	// 传入的sizeInBytes大小包括终止null字符，buffer的大小至少为sizeInBytes。错误返回-1。

	template <typename... Types>
	int SNPrintf(char* const buffer, const size_t sizeInBytes, const size_t maxCount, char const* const format, const Types&... args);
}

#endif // SYSTEM_CHARACTER_STRING_FORMAT_STRING_H

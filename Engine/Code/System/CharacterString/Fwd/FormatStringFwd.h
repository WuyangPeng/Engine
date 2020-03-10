// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:17)

#ifndef SYSTEM_CHARACTER_STRING_FORMAT_STRING_FWD_H
#define SYSTEM_CHARACTER_STRING_FORMAT_STRING_FWD_H 

#include "CharacterStringFlagsFwd.h"
#include "System/Helper/UnicodeUsing.h" 

namespace System
{
	int VsnPrintf(char* str, size_t size, const char* format, va_list argList) noexcept;
	bool Strcat(char* destination, size_t sizeInBytes, const char* source) noexcept;
	size_t Strlen(const char* str) noexcept;
	bool Strcpy(char* destination, size_t sizeInBytes, char const* source) noexcept;
	char* Strtok(char* string, char const* delimiter, char** context) noexcept;
	const char* Strstr(char const* str, char const* subStr) noexcept;

	bool StringCopyUseCharactersSize(TChar* dest, size_t destCharactersSize, const TChar* src);
	bool StringCopyUseBytesSize(TChar* dest, size_t destBytesSize, const TChar* src);
	bool StringCopyUseCharactersSize(TChar* dest, size_t destCharactersSize, const TChar* src, TChar** destEnd, size_t* remaining, StringSafe flag);
	bool StringCopyUseBytesSize(TChar* dest, size_t destBytesSize, const TChar* src, TChar** destEnd, size_t* remaining, StringSafe flag);
	bool StringCopyUseCharactersSize(TChar* dest, size_t destCharactersSize, const TChar* src, size_t srcCharactersSize);
	bool StringCopyUseBytesSize(TChar* dest, size_t destBytesSize, const TChar* src, size_t srcBytesSize);
	bool StringCopyUseCharactersSize(TChar* dest, size_t destCharactersSize, const TChar* src, size_t srcCharactersSize,
									 TChar** destEnd, size_t* remaining, StringSafe flag);
	bool StringCopyUseBytesSize(TChar* dest, size_t destBytesSize, const TChar* src, size_t srcBytesSize,
								TChar** destEnd, size_t* remaining, StringSafe flag);

	bool StringCatUseCharactersSize(TChar* dest, size_t destCharactersSize, const TChar* src);
	bool StringCatUseBytesSize(TChar* dest, size_t destBytesSize, const TChar* src);
	bool StringCatUseCharactersSize(TChar* dest, size_t destCharactersSize, const TChar* src, TChar** destEnd, size_t* remaining, StringSafe flag);
	bool StringCatUseBytesSize(TChar* dest, size_t destBytesSize, const TChar* src, TChar** destEnd, size_t* remaining, StringSafe flag);
	bool StringCatUseCharactersSize(TChar* dest, size_t destCharactersSize, const TChar* src, size_t appendCharactersSize);
	bool StringCatUseBytesSize(TChar* dest, size_t destBytesSize, const TChar* src, size_t appendBytesSize);
	bool StringCatUseCharactersSize(TChar* dest, size_t destCharactersSize, const TChar* src, size_t appendCharactersSize,
									TChar** destEnd, size_t* remaining, StringSafe flag);
	bool StringCatUseBytesSize(TChar* dest, size_t destBytesSize, const TChar* src, size_t appendBytesSize,
							   TChar** destEnd, size_t* remaining, StringSafe flag);

	bool StringGetsUseCharactersSize(TChar* dest, size_t destCharactersSize);
	bool StringGetsUseBytesSize(TChar* dest, size_t destBytesSize);
	bool StringGetsUseCharactersSize(TChar* dest, size_t destCharactersSize, TChar** destEnd, size_t* remaining, StringSafe flag);
	bool StringGetsUseBytesSize(TChar* dest, size_t destBytesSize, TChar** destEnd, size_t* remaining, StringSafe flag);

	bool StringLengthUseCharactersSize(const TChar* src, size_t maxCharactersSize, size_t* charactersLength);
	bool StringLengthUseBytesSize(const TChar* src, size_t maxBytesSize, size_t* bytesLength);

	bool StringVPrintfUseCharactersSize(TChar* dest, size_t destCharactersSize, const TChar* format, va_list argList);
	bool StringVPrintfUseBytesSize(TChar* dest, size_t destBytesSize, const TChar* format, va_list argList);
	bool StringVPrintfUseCharactersSize(TChar* dest, size_t destCharactersSize, TChar** destEnd, size_t* remaining,
										StringSafe flag, const TChar* format, va_list argList);
	bool StringVPrintfUseBytesSize(TChar* dest, size_t destBytesSize, TChar** destEnd, size_t* remaining,
								   StringSafe flag, const TChar* format, va_list argList);

	template <typename... T>
	bool StringPrintfUseCharactersSize(TChar* dest, size_t destCharactersSize, const TChar* format, T... args);
	template <typename... T>
	bool StringPrintfUseBytesSize(TChar* dest, size_t destBytesSize, const TChar* format, T... args);
	template <typename... T>
	bool StringPrintfUseCharactersSize(TChar* dest, size_t destCharactersSize, TChar** destEnd, size_t* remaining,
									   StringSafe flag, const TChar* format, T... args);
	template <typename... T>
	bool StringPrintfUseBytesSize(TChar* dest, size_t destBytesSize, TChar** destEnd, size_t* remaining,
								  StringSafe flag, const TChar* format, T... args);
}

#endif // SYSTEM_CHARACTER_STRING_FORMAT_STRING_FWD_H
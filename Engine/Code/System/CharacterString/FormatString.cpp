//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/22 13:23)

#include "System/SystemExport.h"

#include "FormatString.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

#include <cstdio>
#include <cstring>

int System::VsnPrintf(char* buffer, size_t size, const char* format, va_list argList) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    // 返回存储在buffer中的字符，不包括终止null字符。错误返回 -1。
    return ::_vsnprintf_s(buffer, size, _TRUNCATE, format, argList);
#else  // !SYSTEM_PLATFORM_WIN32
    return ::vsnprintf(buffer, size, format, argList);
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::Strcat(char* destination, [[maybe_unused]] size_t sizeInBytes, const char* source) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    // 如果成功，则为零；如果失败，则为错误代码。
    if (0 == ::strcat_s(destination, sizeInBytes, source))
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    // 返回一个目标字符串。
    ::strcat(destination, source);

    return true;
#endif  // SYSTEM_PLATFORM_WIN32
}

size_t System::Strlen(const char* str) noexcept
{
    if (str != nullptr)
        return ::strlen(str);
    else
        return 0;
}

bool System::StringCopyUseCharactersSize([[maybe_unused]] TChar* dest, [[maybe_unused]] size_t destCharactersSize, [[maybe_unused]] const TChar* src)
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (IsFailed(::StringCchCopy(dest, destCharactersSize, src)))
        return false;
    else
        return true;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::StringCopyUseCharactersSize([[maybe_unused]] TChar* dest, [[maybe_unused]] size_t destCharactersSize, [[maybe_unused]] const TChar* src, [[maybe_unused]] TChar** destEnd, [[maybe_unused]] size_t* remaining, [[maybe_unused]] StringSafe flag)
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (IsFailed(::StringCchCopyEx(dest, destCharactersSize, src, destEnd, remaining, EnumCastUnderlying(flag))))
        return false;
    else
        return true;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::StringCopyUseBytesSize([[maybe_unused]] TChar* dest, [[maybe_unused]] size_t destBytesSize, [[maybe_unused]] const TChar* src)
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (IsFailed(::StringCbCopy(dest, destBytesSize, src)))
        return false;
    else
        return true;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::StringCopyUseBytesSize([[maybe_unused]] TChar* dest, [[maybe_unused]] size_t destBytesSize, [[maybe_unused]] const TChar* src, [[maybe_unused]] TChar** destEnd, [[maybe_unused]] size_t* remaining, [[maybe_unused]] StringSafe flag)
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (IsFailed(::StringCbCopyEx(dest, destBytesSize, src, destEnd, remaining, EnumCastUnderlying(flag))))
        return false;
    else
        return true;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::StringCopyUseCharactersSize([[maybe_unused]] TChar* dest, [[maybe_unused]] size_t destCharactersSize, [[maybe_unused]] const TChar* src, [[maybe_unused]] size_t srcCharactersSize)
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (IsFailed(::StringCchCopyN(dest, destCharactersSize, src, srcCharactersSize)))
        return false;
    else
        return true;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::StringCopyUseBytesSize([[maybe_unused]] TChar* dest, [[maybe_unused]] size_t destBytesSize, [[maybe_unused]] const TChar* src, [[maybe_unused]] size_t srcBytesSize)
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (IsFailed(::StringCbCopyN(dest, destBytesSize, src, srcBytesSize)))
        return false;
    else
        return true;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::StringCopyUseCharactersSize([[maybe_unused]] TChar* dest, [[maybe_unused]] size_t destCharactersSize, [[maybe_unused]] const TChar* src, [[maybe_unused]] size_t srcCharactersSize,
                                         [[maybe_unused]] TChar** destEnd, [[maybe_unused]] size_t* remaining, [[maybe_unused]] StringSafe flag)
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (IsFailed(::StringCchCopyNEx(dest, destCharactersSize, src, srcCharactersSize, destEnd, remaining, EnumCastUnderlying(flag))))
        return false;
    else
        return true;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::StringCopyUseBytesSize([[maybe_unused]] TChar* dest, [[maybe_unused]] size_t destBytesSize, [[maybe_unused]] const TChar* src, [[maybe_unused]] size_t srcBytesSize, [[maybe_unused]] TChar** destEnd, [[maybe_unused]] size_t* remaining, [[maybe_unused]] StringSafe flag)
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (IsFailed(::StringCbCopyNEx(dest, destBytesSize, src, srcBytesSize, destEnd, remaining, EnumCastUnderlying(flag))))
        return false;
    else
        return true;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::StringCatUseCharactersSize([[maybe_unused]] TChar* dest, [[maybe_unused]] size_t destCharactersSize, [[maybe_unused]] const TChar* src)
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (IsFailed(::StringCchCat(dest, destCharactersSize, src)))
        return false;
    else
        return true;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::StringCatUseCharactersSize([[maybe_unused]] TChar* dest, [[maybe_unused]] size_t destCharactersSize, [[maybe_unused]] const TChar* src, [[maybe_unused]] TChar** destEnd, [[maybe_unused]] size_t* remaining, [[maybe_unused]] StringSafe flag)
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (IsFailed(::StringCchCatEx(dest, destCharactersSize, src, destEnd, remaining, EnumCastUnderlying(flag))))
        return false;
    else
        return true;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::StringCatUseCharactersSize([[maybe_unused]] TChar* dest, [[maybe_unused]] size_t destCharactersSize, [[maybe_unused]] const TChar* src, [[maybe_unused]] size_t appendCharactersSize)
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (IsFailed(::StringCchCatN(dest, destCharactersSize, src, appendCharactersSize)))
        return false;
    else
        return true;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::StringCatUseCharactersSize([[maybe_unused]] TChar* dest, [[maybe_unused]] size_t destCharactersSize, [[maybe_unused]] const TChar* src, [[maybe_unused]] size_t appendCharactersSize, [[maybe_unused]] TChar** destEnd, [[maybe_unused]] size_t* remaining, [[maybe_unused]] StringSafe flag)
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (IsFailed(::StringCchCatNEx(dest, destCharactersSize, src, appendCharactersSize, destEnd, remaining, EnumCastUnderlying(flag))))
        return false;
    else
        return true;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::StringCatUseBytesSize([[maybe_unused]] TChar* dest, [[maybe_unused]] size_t destBytesSize, [[maybe_unused]] const TChar* src)
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (IsFailed(::StringCbCat(dest, destBytesSize, src)))
        return false;
    else
        return true;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::StringCatUseBytesSize([[maybe_unused]] TChar* dest, [[maybe_unused]] size_t destBytesSize, [[maybe_unused]] const TChar* src, [[maybe_unused]] TChar** destEnd, [[maybe_unused]] size_t* remaining, [[maybe_unused]] StringSafe flag)
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (IsFailed(::StringCbCatEx(dest, destBytesSize, src, destEnd, remaining, EnumCastUnderlying(flag))))
        return false;
    else
        return true;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::StringCatUseBytesSize([[maybe_unused]] TChar* dest, [[maybe_unused]] size_t destBytesSize, [[maybe_unused]] const TChar* src, [[maybe_unused]] size_t appendBytesSize)
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (IsFailed(::StringCbCatN(dest, destBytesSize, src, appendBytesSize)))
        return false;
    else
        return true;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::StringCatUseBytesSize([[maybe_unused]] TChar* dest, [[maybe_unused]] size_t destBytesSize, [[maybe_unused]] const TChar* src, [[maybe_unused]] size_t appendBytesSize, [[maybe_unused]] TChar** destEnd, [[maybe_unused]] size_t* remaining, [[maybe_unused]] StringSafe flag)
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (IsFailed(::StringCbCatNEx(dest, destBytesSize, src, appendBytesSize, destEnd, remaining, EnumCastUnderlying(flag))))
        return false;
    else
        return true;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::StringGetsUseCharactersSize([[maybe_unused]] TChar* dest, [[maybe_unused]] size_t destCharactersSize)
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (IsFailed(::StringCchGets(dest, destCharactersSize)))
        return false;
    else
        return true;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::StringGetsUseCharactersSize([[maybe_unused]] TChar* dest, [[maybe_unused]] size_t destCharactersSize, [[maybe_unused]] TChar** destEnd, [[maybe_unused]] size_t* remaining, [[maybe_unused]] StringSafe flag)
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (IsFailed(::StringCchGetsEx(dest, destCharactersSize, destEnd, remaining, EnumCastUnderlying(flag))))
        return false;
    else
        return true;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::StringGetsUseBytesSize([[maybe_unused]] TChar* dest, [[maybe_unused]] size_t destBytesSize)
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (IsFailed(::StringCbGets(dest, destBytesSize)))
        return false;
    else
        return true;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::StringGetsUseBytesSize([[maybe_unused]] TChar* dest, [[maybe_unused]] size_t destBytesSize, [[maybe_unused]] TChar** destEnd, [[maybe_unused]] size_t* remaining, [[maybe_unused]] StringSafe flag)
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (IsFailed(::StringCbGetsEx(dest, destBytesSize, destEnd, remaining, EnumCastUnderlying(flag))))
        return false;
    else
        return true;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::StringLengthUseCharactersSize([[maybe_unused]] const TChar* src, [[maybe_unused]] size_t maxCharactersSize, [[maybe_unused]] size_t* charactersLength)
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (IsFailed(::StringCchLength(src, maxCharactersSize, charactersLength)))
        return false;
    else
        return true;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::StringLengthUseBytesSize([[maybe_unused]] const TChar* src, [[maybe_unused]] size_t maxBytesSize, [[maybe_unused]] size_t* bytesLength)
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (IsFailed(::StringCbLength(src, maxBytesSize, bytesLength)))
        return false;
    else
        return true;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::StringVPrintfUseCharactersSize([[maybe_unused]] TChar* dest, [[maybe_unused]] size_t destCharactersSize, [[maybe_unused]] const TChar* format, [[maybe_unused]] va_list argList)
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (IsFailed(::StringCchVPrintf(dest, destCharactersSize, format, argList)))
        return false;
    else
        return true;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::StringVPrintfUseBytesSize([[maybe_unused]] TChar* dest, [[maybe_unused]] size_t destBytesSize, [[maybe_unused]] const TChar* format, [[maybe_unused]] va_list argList)
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (IsFailed(::StringCbVPrintf(dest, destBytesSize, format, argList)))
        return false;
    else
        return true;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::StringVPrintfUseCharactersSize([[maybe_unused]] TChar* dest, [[maybe_unused]] size_t destCharactersSize, [[maybe_unused]] TChar** destEnd, [[maybe_unused]] size_t* remaining, [[maybe_unused]] StringSafe flag, [[maybe_unused]] const TChar* format, [[maybe_unused]] va_list argList)
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (IsFailed(::StringCchVPrintfEx(dest, destCharactersSize, destEnd, remaining, EnumCastUnderlying(flag), format, argList)))
        return false;
    else
        return true;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::StringVPrintfUseBytesSize([[maybe_unused]] TChar* dest, [[maybe_unused]] size_t destBytesSize, [[maybe_unused]] TChar** destEnd, [[maybe_unused]] size_t* remaining, [[maybe_unused]] StringSafe flag, [[maybe_unused]] const TChar* format, [[maybe_unused]] va_list argList)
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (IsFailed(::StringCbVPrintfEx(dest, destBytesSize, destEnd, remaining, EnumCastUnderlying(flag), format, argList)))
        return false;
    else
        return true;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::Strcpy(char* destination, size_t sizeInBytes, char const* source) noexcept
{
    if (::strcpy_s(destination, sizeInBytes, source) == 0)
        return true;
    else
        return false;
}

char* System::Strtok(char* string, char const* delimiter, char** context) noexcept
{
    return ::strtok_s(string, delimiter, context);
}

const char* System::Strstr(char const* str, char const* subStr) noexcept
{
    return ::strstr(str, subStr);
}

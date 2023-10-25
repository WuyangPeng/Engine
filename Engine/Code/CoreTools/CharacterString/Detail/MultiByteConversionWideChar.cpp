///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 10:29)

#include "CoreTools/CoreToolsExport.h"

#include "MultiByteConversionWideChar.h"
#include "System/CharacterString/StringConversion.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <gsl/narrow>

CoreTools::MultiByteConversionWideChar::MultiByteConversionWideChar(const std::string& character, bool isUtf8)
    : source{ character.begin(), character.end() },
      target{},
      lengthOfWideCharString{ 0 },
      isUtf8{ isUtf8 }
{
    Conversion();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

void CoreTools::MultiByteConversionWideChar::Conversion()
{
    FillNullChar();
    CreateTarget();
    FinishConversion();
}

void CoreTools::MultiByteConversionWideChar::FillNullChar()
{
    source.emplace_back('\0');
}

void CoreTools::MultiByteConversionWideChar::CreateTarget()
{
    if (const auto length = GetConversionLength(); 0 < length)
    {
        target.resize(length);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Multi Byte 转换为 Wide Char 失败！"s))
    }
}

int CoreTools::MultiByteConversionWideChar::GetConversionLength()
{
    const auto destSize = boost::numeric_cast<int>(source.size());
    const auto targetSize = boost::numeric_cast<int>(target.size());
    const auto wideChar = target.empty() ? nullptr : target.data();

    if (isUtf8)
    {
        return System::Utf8ConversionWideChar(source.data(), destSize, wideChar, targetSize);
    }
    else
    {
        return System::MultiByteConversionWideChar(source.data(), destSize, wideChar, targetSize);
    }
}

void CoreTools::MultiByteConversionWideChar::FinishConversion()
{
    lengthOfWideCharString = GetConversionLength();

    if (lengthOfWideCharString <= 0 || boost::numeric_cast<int>(target.size()) < lengthOfWideCharString)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Multi Byte 转换为 Wide Char 失败！"s))
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::MultiByteConversionWideChar::IsValid() const noexcept
{
    if (0 < lengthOfWideCharString && lengthOfWideCharString <= gsl::narrow_cast<int>(target.size()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

std::wstring CoreTools::MultiByteConversionWideChar::GetWideCharRepresentation() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    return std::wstring{ target.data(), target.data() + lengthOfWideCharString - 1 };

#include SYSTEM_WARNING_POP
}

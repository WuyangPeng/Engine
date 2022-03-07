///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/12 14:09)

#include "CoreTools/CoreToolsExport.h"

#include "MultiByteConversionWideChar.h"
#include "System/CharacterString/StringConversion.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <gsl/narrow>

using std::string;
using std::wstring;

CoreTools::MultiByteConversionWideChar::MultiByteConversionWideChar(const string& character, bool isUTF8)
    : source{ character.begin(), character.end() },
      target{},
      lengthOfWideCharString{ 0 },
      isUTF8{ isUTF8 }
{
    Conversion();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// private
void CoreTools::MultiByteConversionWideChar::Conversion()
{
    FillNullChar();
    CreateTarget();
    FinishConversion();
}

// private
void CoreTools::MultiByteConversionWideChar::FillNullChar()
{
    source.emplace_back('\0');
}

// private
void CoreTools::MultiByteConversionWideChar::CreateTarget()
{
    const auto length = GetConversionLength();

    if (0 < length)
    {
        target.resize(length);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Multi Byte 转换为 Wide Char 失败！"s));
    }
}

// private
int CoreTools::MultiByteConversionWideChar::GetConversionLength()
{
    const auto destSize = boost::numeric_cast<int>(source.size());
    const auto targetSize = boost::numeric_cast<int>(target.size());
    const auto wideChar = target.empty() ? nullptr : target.data();

    if (isUTF8)
    {
        return System::UTF8ConversionWideChar(source.data(), destSize, wideChar, targetSize);
    }
    else
    {
        return System::MultiByteConversionWideChar(source.data(), destSize, wideChar, targetSize);
    }
}

// private
void CoreTools::MultiByteConversionWideChar::FinishConversion()
{
    lengthOfWideCharString = GetConversionLength();

    if (lengthOfWideCharString <= 0 || boost::numeric_cast<int>(target.size()) < lengthOfWideCharString)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Multi Byte 转换为 Wide Char 失败！"s));
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

const wstring CoreTools::MultiByteConversionWideChar::GetWideCharRepresentation() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    return wstring{ target.data(), target.data() + lengthOfWideCharString - 1 };

#include STSTEM_WARNING_POP
}

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 10:31)

#include "CoreTools/CoreToolsExport.h"

#include "WideCharConversionMultiByte.h"
#include "System/CharacterString/StringConversion.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <gsl/narrow>

CoreTools::WideCharConversionMultiByte::WideCharConversionMultiByte(const std::wstring& character, bool isUtf8)
    : source{ character.begin(), character.end() },
      target{},
      lengthOfMultiByteString{ 0 },
      isUtf8{ isUtf8 }
{
    Conversion();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

void CoreTools::WideCharConversionMultiByte::Conversion()
{
    FillNullWChar();
    CreateTarget();
    FinishConversion();
}

void CoreTools::WideCharConversionMultiByte::FillNullWChar()
{
    source.emplace_back(L'\0');
}

int CoreTools::WideCharConversionMultiByte::GetConversionLength()
{
    const auto destSize = boost::numeric_cast<int>(source.size());
    const auto targetSize = boost::numeric_cast<int>(target.size());
    const auto multiByte = target.empty() ? nullptr : target.data();

    if (isUtf8)
    {
        return System::WideCharConversionUtf8(source.data(), destSize, multiByte, targetSize);
    }
    else
    {
        return System::WideCharConversionMultiByte(source.data(), destSize, multiByte, targetSize);
    }
}

void CoreTools::WideCharConversionMultiByte::CreateTarget()
{
    if (const auto length = GetConversionLength(); 0 < length)
    {
        target.resize(length);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Wide Char 转换为 Multi Byte 失败！"s));
    }
}

void CoreTools::WideCharConversionMultiByte::FinishConversion()
{
    lengthOfMultiByteString = GetConversionLength();

    if (lengthOfMultiByteString <= 0 || boost::numeric_cast<int>(target.size()) < lengthOfMultiByteString)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Wide Char 转换为 Multi Byte 失败！"s))
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::WideCharConversionMultiByte::IsValid() const noexcept
{
    if (0 < lengthOfMultiByteString && lengthOfMultiByteString <= gsl::narrow_cast<int>(target.size()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

std::string CoreTools::WideCharConversionMultiByte::GetMultiByteRepresentation() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    return std::string{ target.data(), target.data() + lengthOfMultiByteString - 1 };

#include SYSTEM_WARNING_POP
}

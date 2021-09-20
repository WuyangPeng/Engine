///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.2 (2021/08/29 20:20)

#include "CoreTools/CoreToolsExport.h"

#include "WideCharConversionMultiByte.h"
#include "System/CharacterString/StringConversion.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <gsl/narrow>

using std::make_shared;
using std::string;
using std::wstring;

CoreTools::WideCharConversionMultiByte::WideCharConversionMultiByte(const wstring& character, bool isUTF8)
    : source{ character.begin(), character.end() },
      target{},
      lengthOfMultiByteString{ 0 },
      isUTF8{ isUTF8 }
{
    Conversion();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// private
void CoreTools::WideCharConversionMultiByte::Conversion()
{
    FillNullWChar();
    CreateTarget();
    FinishConversion();
}

// private
void CoreTools::WideCharConversionMultiByte::FillNullWChar()
{
    source.emplace_back(L'\0');
}

// private
int CoreTools::WideCharConversionMultiByte::GetConversionLength()
{
    auto destSize = boost::numeric_cast<int>(source.size());
    auto targetSize = boost::numeric_cast<int>(target.size());
    auto multiByte = target.empty() ? nullptr : target.data();

    if (isUTF8)
    {
        return System::WideCharConversionUTF8(source.data(), destSize, multiByte, targetSize);
    }
    else
    {
        return System::WideCharConversionMultiByte(source.data(), destSize, multiByte, targetSize);
    }
}

// private
void CoreTools::WideCharConversionMultiByte::CreateTarget()
{
    const auto length = GetConversionLength();

    if (0 < length)
    {
        target.resize(length);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Wide Char 转换为 Multi Byte 失败！"s));
    }
}

// private
void CoreTools::WideCharConversionMultiByte::FinishConversion()
{
    lengthOfMultiByteString = GetConversionLength();

    if (lengthOfMultiByteString <= 0 || boost::numeric_cast<int>(target.size()) < lengthOfMultiByteString)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Wide Char 转换为 Multi Byte 失败！"s));
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

const string CoreTools::WideCharConversionMultiByte::GetMultiByteRepresentation() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
    return string{ target.data(), target.data() + lengthOfMultiByteString - 1 };
#include STSTEM_WARNING_POP
}

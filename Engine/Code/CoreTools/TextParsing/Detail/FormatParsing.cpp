///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 22:24)

#include "CoreTools/CoreToolsExport.h"

#include "FormatParsing.h"
#include "Parsing.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

using std::vector;
using namespace std::literals;

CoreTools::FormatParsing::FormatParsing(const FileContent& fileContent)
    : key{},
      mapping{},
      scope{},
      defaultValue{}
{
    Parsing(fileContent);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

void CoreTools::FormatParsing::Parsing(const FileContent& fileContent)
{
    constexpr auto index = System::EnumCastUnderlying(CSVType::Format) - 1;
    const auto& formatContent = fileContent.at(index);

    if (!formatContent.empty())
    {
        Parsing(formatContent);
    }
}

void CoreTools::FormatParsing::Parsing(const String& formatContent)
{
    const auto column = Parsing::GetSplitComma(formatContent);

    bool firstIndex = true;
    for (const auto& value : column)
    {
        ParsingColumn(value, firstIndex);
        firstIndex = false;
    }
}

void CoreTools::FormatParsing::EmplaceBackEmpty(bool isScope, bool isMapping, bool isDefaultValue)
{
    if (!isScope)
    {
        scope.emplace_back(SYSTEM_TEXT(""s));
    }

    if (!isMapping)
    {
        mapping.emplace_back(SYSTEM_TEXT(""s));
    }

    if (!isDefaultValue)
    {
        defaultValue.emplace_back(SYSTEM_TEXT(""s));
    }
}

CoreTools::FormatParsing::Element CoreTools::FormatParsing::GetElement(const String& column) const
{
    Element element{};
    boost::algorithm::split(element, column, boost::is_any_of(TextParsing::g_Or), boost::token_compress_off);

    return element;
}

bool CoreTools::FormatParsing::IsInterval(const String& single) const noexcept
{
    if (single.find(TextParsing::g_LeftSquareBrackets) != String::npos ||
        single.find(TextParsing::g_RightSquareBrackets) != String::npos ||
        single.find(TextParsing::g_LeftBrackets) != String::npos ||
        single.find(TextParsing::g_RightBrackets) != String::npos ||
        single.find(TextParsing::g_LeftAngleBracket) != String::npos ||
        single.find(TextParsing::g_RightAngleBracket) != String::npos ||
        single.find(TextParsing::g_LeftBigParantheses) != String::npos ||
        single.find(TextParsing::g_RightBigParantheses) != String::npos)
    {
        return true;
    }

    return false;
}

void CoreTools::FormatParsing::ParsingColumn(const String& column, bool firstIndex)
{
    const auto element = GetElement(column);

    auto isScope = false;
    auto isMapping = false;
    auto isDefaultValue = false;

    for (const auto& single : element)
    {
        if (IsInterval(single))
        {
            ParsingScope(isScope, single);
            isScope = true;
        }
        else if (single.find(TextParsing::g_equalSign) != String::npos)
        {
            ParsingDefaultValue(isDefaultValue, firstIndex, single);
            isDefaultValue = true;
        }
        else
        {
            ParsingMapping(isMapping, firstIndex, single);
            isMapping = true;
        }
    }

    EmplaceBackEmpty(isScope, isMapping, isDefaultValue);
}

void CoreTools::FormatParsing::ParsingScope(bool isScope, const String& single)
{
    if (!isScope)
    {
        scope.emplace_back(single);
    }
}

CoreTools::FormatParsing::Element CoreTools::FormatParsing::SplitEqualSign(const String& single) const
{
    Element element{};
    boost::algorithm::split(element, single, boost::is_any_of(TextParsing::g_equalSign), boost::token_compress_off);

    return element;
}

void CoreTools::FormatParsing::ParsingDefaultValue(bool isDefaultValue, bool firstIndex, const String& single)
{
    if (!isDefaultValue)
    {
        const auto element = SplitEqualSign(single);

        if (1 < element.size())
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

            defaultValue.emplace_back(element[1]);

#include STSTEM_WARNING_POP
        }
    }

    if (firstIndex)
    {
        ParsingKey(single);
    }
}

void CoreTools::FormatParsing::ParsingMapping(bool isMapping, bool firstIndex, const String& single)
{
    if (!isMapping)
    {
        if (firstIndex)
        {
            ParsingKey(single);

            mapping.emplace_back(SYSTEM_TEXT(""s));
        }
        else
        {
            mapping.emplace_back(single);
        }
    }
}

void CoreTools::FormatParsing::ParsingKey(const String& single)
{
    const auto firstKey = SplitEqualSign(single);

    if (1 < firstKey.size())
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        key = firstKey[1];

#include STSTEM_WARNING_POP
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::FormatParsing::IsValid() const noexcept
{
    if (scope.size() == mapping.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

System::String CoreTools::FormatParsing::GetKey() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return key;
}

System::String CoreTools::FormatParsing::GetMapping(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (0 <= index && index < boost::numeric_cast<int>(mapping.size()))
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        return mapping[index];

#include STSTEM_WARNING_POP
    }

    return String{};
}

bool CoreTools::FormatParsing::HasMapping() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    for (const auto& value : mapping)
    {
        if (!value.empty())
        {
            return true;
        }
    }

    return false;
}

System::String CoreTools::FormatParsing::GetScope(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (0 <= index && index < boost::numeric_cast<int>(scope.size()))
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        return scope[index];

#include STSTEM_WARNING_POP
    }

    return String{};
}

bool CoreTools::FormatParsing::HasScope() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    for (const auto& value : scope)
    {
        if (!value.empty())
        {
            return true;
        }
    }

    return false;
}

System::String CoreTools::FormatParsing::GetDefaultValue(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (0 <= index && index < boost::numeric_cast<int>(defaultValue.size()))
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        return defaultValue[index];

#include STSTEM_WARNING_POP
    }

    return String{};
}

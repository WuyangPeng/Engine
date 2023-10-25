///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 14:03)

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

    if (const auto& formatContent = fileContent.at(index); !formatContent.empty())
    {
        Parsing(formatContent);
    }
}

void CoreTools::FormatParsing::Parsing(const String& formatContent)
{
    const auto column = Parsing::GetSplitComma(formatContent);

    auto firstIndex = true;
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
        scope.emplace_back();
    }

    if (!isMapping)
    {
        mapping.emplace_back();
    }

    if (!isDefaultValue)
    {
        defaultValue.emplace_back();
    }
}

CoreTools::FormatParsing::Element CoreTools::FormatParsing::GetElement(const String& column)
{
    Element element{};
    split(element, column, boost::is_any_of(TextParsing::gOr), boost::token_compress_off);

    return element;
}

bool CoreTools::FormatParsing::IsInterval(const String& single) noexcept
{
    if (single.find(TextParsing::gLeftSquareBrackets) != String::npos ||
        single.find(TextParsing::gRightSquareBrackets) != String::npos ||
        single.find(TextParsing::gLeftBrackets) != String::npos ||
        single.find(TextParsing::gRightBrackets) != String::npos ||
        single.find(TextParsing::gLeftAngleBracket) != String::npos ||
        single.find(TextParsing::gRightAngleBracket) != String::npos ||
        single.find(TextParsing::gLeftBrace) != String::npos ||
        single.find(TextParsing::gRightBrace) != String::npos)
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
        else if (single.find(TextParsing::gEqualSign) != String::npos)
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

CoreTools::FormatParsing::Element CoreTools::FormatParsing::SplitEqualSign(const String& single)
{
    Element element{};
    split(element, single, boost::is_any_of(TextParsing::gEqualSign), boost::token_compress_off);

    return element;
}

void CoreTools::FormatParsing::ParsingDefaultValue(bool isDefaultValue, bool firstIndex, const String& single)
{
    if (!isDefaultValue)
    {
        if (const auto element = SplitEqualSign(single); 1 < element.size())
        {
            defaultValue.emplace_back(element.at(1));
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

            mapping.emplace_back();
        }
        else
        {
            mapping.emplace_back(single);
        }
    }
}

void CoreTools::FormatParsing::ParsingKey(const String& single)
{
    if (const auto firstKey = SplitEqualSign(single); 1 < firstKey.size())
    {
        key = firstKey.at(1);
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
        return mapping.at(index);
    }

    return String{};
}

bool CoreTools::FormatParsing::HasMapping() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return std::ranges::any_of(mapping, [](const auto& value) {
        return !value.empty();
    });
}

System::String CoreTools::FormatParsing::GetScope(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (0 <= index && index < boost::numeric_cast<int>(scope.size()))
    {
        return scope.at(index);
    }

    return String{};
}

bool CoreTools::FormatParsing::HasScope() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return std::ranges::any_of(scope, [](const auto& value) {
        return !value.empty();
    });
}

System::String CoreTools::FormatParsing::GetDefaultValue(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (0 <= index && index < boost::numeric_cast<int>(defaultValue.size()))
    {
        return defaultValue.at(index);
    }

    return String{};
}

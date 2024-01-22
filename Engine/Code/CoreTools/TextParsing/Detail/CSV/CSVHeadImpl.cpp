/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:57)

#include "CoreTools/CoreToolsExport.h"

#include "CSVHeadImpl.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Detail/FormatTypeParsing.h"
#include "CoreTools/TextParsing/Detail/Parsing.h"
#include "CoreTools/TextParsing/Detail/ScopeExpressionParsing.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVHeadImpl::CSVHeadImpl(const String& path, const FileContent& fileContent)
    : pathSplitParsing{ path },
      fileContent{ fileContent },
      formatType{ CSVFormatType::Default },
      formatParsing{ fileContent },
      annotation{},
      dataType{},
      enumTypeName{},
      variableName{}
{
    Init();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

void CoreTools::CSVHeadImpl::Init()
{
    Parsing();

    if (dataType.size() != variableName.size())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("变量名和数据类型长度不一致。"s))
    }
}

void CoreTools::CSVHeadImpl::Parsing()
{
    ParsingFormatType();
    ParsingAnnotation();
    ParsingDataType();
    ParsingVariableName();
}

void CoreTools::CSVHeadImpl::ParsingFormatType()
{
    constexpr auto index = System::EnumCastUnderlying(CSVType::Format) - 1;

    if (const auto content = fileContent.at(index); !content.empty())
    {
        const FormatTypeParsing formatTypeParsing{ content };
        formatType = formatTypeParsing.GetCSVFormatType();
    }
}

void CoreTools::CSVHeadImpl::ParsingAnnotation()
{
    constexpr auto index = System::EnumCastUnderlying(CSVType::Annotation) - 1;
    auto content = fileContent.at(index);

    split(annotation, content, boost::is_any_of(TextParsing::gComma), boost::token_compress_off);
}

void CoreTools::CSVHeadImpl::ParsingDataType()
{
    constexpr auto index = System::EnumCastUnderlying(CSVType::DataType) - 1;
    const auto content = fileContent.at(index);

    for (const auto column = Parsing::GetSplitComma(content); const auto& element : column)
    {
        const auto type = ParsingDataType(element);

        ParsingEnumTypeName(type, element);
    }
}

CoreTools::CSVDataType CoreTools::CSVHeadImpl::ParsingDataType(const String& element)
{
    auto type = CSVTypeConversion::GetDataType(element);
    if (type == CSVDataType::Bit || type == CSVDataType::BitArray)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("bit类型不应该存在于csv中。"s))
    }
    dataType.emplace_back(type);

    return type;
}

void CoreTools::CSVHeadImpl::ParsingEnumTypeName(CSVDataType type, const String& element)
{
    if (type == CSVDataType::Enum || type == CSVDataType::EnumArray)
    {
        EnumTypeName enumType{};
        split(enumType, element, boost::is_any_of(TextParsing::gOr), boost::token_compress_off);

        if (1 < enumType.size())
        {
            enumTypeName.emplace_back(StringUtility::ToFirstLetterUpper(enumType.at(1)));
        }
        else
        {
            THROW_EXCEPTION(SYSTEM_TEXT("enum类型定义错误。"s))
        }
    }
    else
    {
        enumTypeName.emplace_back(String{});
    }
}

void CoreTools::CSVHeadImpl::ParsingVariableName()
{
    constexpr auto index = System::EnumCastUnderlying(CSVType::VariableName) - 1;
    const auto content = fileContent.at(index);

    for (const auto column = Parsing::GetSplitComma(content); const auto& value : column)
    {
        variableName.emplace_back(StringUtility::ToFirstLetterLower(value));
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::CSVHeadImpl::IsValid() const noexcept
{
    if (!fileContent.empty() && dataType.size() == variableName.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

CoreTools::CSVFormatType CoreTools::CSVHeadImpl::GetCSVFormatType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return formatType;
}

System::String CoreTools::CSVHeadImpl::GetNameSpace() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return pathSplitParsing.GetNameSpace();
}

System::String CoreTools::CSVHeadImpl::GetCSVClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return pathSplitParsing.GetCSVClassName();
}

System::String CoreTools::CSVHeadImpl::GetKey() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return formatParsing.GetKey();
}

int CoreTools::CSVHeadImpl::GetCount() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(dataType.size());
}

System::String CoreTools::CSVHeadImpl::GetMapping(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return formatParsing.GetMapping(index);
}

bool CoreTools::CSVHeadImpl::HasMapping() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return formatParsing.HasMapping();
}

System::String CoreTools::CSVHeadImpl::GetScope(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return formatParsing.GetScope(index);
}

bool CoreTools::CSVHeadImpl::HasScope() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return formatParsing.HasScope();
}

System::String CoreTools::CSVHeadImpl::GetDefaultValue(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return formatParsing.GetDefaultValue(index);
}

System::String CoreTools::CSVHeadImpl::GetAnnotation(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (0 <= index && index < boost::numeric_cast<int>(annotation.size()))
    {
        return annotation.at(index);
    }

    return String{};
}

CoreTools::CSVDataType CoreTools::CSVHeadImpl::GetDataType(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return dataType.at(index);
}

CoreTools::CSVDataType CoreTools::CSVHeadImpl::GetDataType(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    auto index = 0;
    for (const auto& value : variableName)
    {
        if (value == field)
        {
            return GetDataType(index);
        }

        ++index;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("未找到指定字段名。"s))
}

int CoreTools::CSVHeadImpl::GetDataIndex(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (const auto iter = std::ranges::find(variableName, field); iter != variableName.cend())
    {
        return boost::numeric_cast<int>(iter - variableName.begin());
    }

    THROW_EXCEPTION(SYSTEM_TEXT("未找到指定字段名。"s))
}

int CoreTools::CSVHeadImpl::GetDataIndex(const StringView& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (const auto iter = std::ranges::find(variableName, field); iter != variableName.cend())
    {
        return boost::numeric_cast<int>(iter - variableName.begin());
    }

    THROW_EXCEPTION(SYSTEM_TEXT("未找到指定字段名。"s))
}

bool CoreTools::CSVHeadImpl::HasDataField(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (const auto iter = std::ranges::find(variableName, field); iter != variableName.cend())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CoreTools::CSVHeadImpl::HasDataField(const StringView& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (const auto iter = std::ranges::find(variableName, field); iter != variableName.cend())
    {
        return true;
    }
    else
    {
        return false;
    }
}

System::String CoreTools::CSVHeadImpl::GetVariableName(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return variableName.at(index);
}

System::String CoreTools::CSVHeadImpl::GetEnumTypeName(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return enumTypeName.at(index);
}

bool CoreTools::CSVHeadImpl::HasDataType(CSVDataType csvDataType) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (const auto iter = std::ranges::find(dataType, csvDataType); iter != dataType.cend())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CoreTools::CSVHeadImpl::HasVectorArrayDataType() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (const auto iter = std::ranges::find_if(dataType, [](auto value) {
            if (CSVDataType::CharArray <= value && value <= CSVDataType::IntVector4Array)
                return true;
            else
                return false;
        });
        iter != dataType.cend())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CoreTools::CSVHeadImpl::HasArrayDataType() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (const auto iter = std::ranges::find_if(dataType, [](auto value) {
            if (CSVDataType::BoolArray <= value && value <= CSVDataType::IntVector4Array)
                return true;
            else
                return false;
        });
        iter != dataType.cend())
    {
        return true;
    }
    else
    {
        return false;
    }
}

System::String CoreTools::CSVHeadImpl::GetCompleteClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    auto completeClassName = pathSplitParsing.GetNameSpace();

    completeClassName += TextParsing::gDoubleColon;
    completeClassName += pathSplitParsing.GetCSVClassName();

    return completeClassName;
}

System::String CoreTools::CSVHeadImpl::GetActualType(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (const auto type = GetDataType(index); type == CSVDataType::Enum || type == CSVDataType::EnumArray)
    {
        return GetEnumTypeName(index);
    }
    else
    {
        return CSVTypeConversion::GetActualType(type);
    }
}

System::String CoreTools::CSVHeadImpl::GetValueType(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (const auto type = GetDataType(index); type == CSVDataType::Enum || type == CSVDataType::EnumArray)
    {
        return GetEnumTypeName(index);
    }
    else
    {
        return CSVTypeConversion::GetValueType(type);
    }
}

System::String CoreTools::CSVHeadImpl::GetActualTypeByNameSpace(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (const auto type = GetDataType(index);
        type == CSVDataType::Enum || type == CSVDataType::EnumArray)
    {
        return pathSplitParsing.GetNameSpace() + TextParsing::gDoubleColon.data() + GetEnumTypeName(index);
    }
    else
    {
        return CSVTypeConversion::GetActualType(type);
    }
}

System::String CoreTools::CSVHeadImpl::GetUpperVariableName(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const auto upperVariableName = GetVariableName(index);
    if (upperVariableName == TextParsing::gIdSmall)
    {
        return TextParsing::gIdCapital.data();
    }

    return StringUtility::ToFirstLetterUpper(upperVariableName);
}

System::String CoreTools::CSVHeadImpl::GetFunctionVariableName(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    auto upperVariableName = GetUpperVariableName(index);

    if (const auto type = GetDataType(index); type == CSVDataType::Bool)
    {
        if (upperVariableName.find(TextParsing::gIs) != 0u)
        {
            return TextParsing::gIs.data() + upperVariableName;
        }
        else
        {
            return upperVariableName;
        }
    }
    else
    {
        return TextParsing::gGet.data() + upperVariableName;
    }
}

CoreTools::CSVHeadImpl::KeyName CoreTools::CSVHeadImpl::GetKeyName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    KeyName result{};
    split(result, GetKey(), boost::is_any_of(TextParsing::gKeySplit), boost::token_compress_on);

    std::locale locale{};
    const auto iter = std::ranges::remove_if(result, [&locale](const auto& value) {
        if (value.empty() || std::isdigit(value.at(0), locale))
        {
            return true;
        }
        else
        {
            return false;
        }
    });

    result.erase(iter.begin(), iter.end());

    return result;
}

System::String CoreTools::CSVHeadImpl::GetFunctionName(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (const auto type = GetDataType(index); type == CSVDataType::Enum || type == CSVDataType::EnumArray)
    {
        String result{ TextParsing::gGetEnum };

        result += TextParsing::gLeftAngleBracket;
        result += GetEnumTypeName(index);
        result += TextParsing::gRightAngleBracket;

        return result;
    }
    else
    {
        return CSVTypeConversion::GetFunctionName(type);
    }
}

System::String CoreTools::CSVHeadImpl::GetScopeExpression(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const auto scopeExpression = GetScope(index);
    if (scopeExpression.empty())
    {
        return String{};
    }

    const auto variableNameExpression = GetVariableName(index);

    const ScopeExpressionParsing scopeExpressionParsing{ scopeExpression, variableNameExpression };

    return scopeExpressionParsing.Parsing();
}

System::String CoreTools::CSVHeadImpl::GetAbbreviation(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (const auto type = GetDataType(index); type == CSVDataType::Enum || type == CSVDataType::EnumArray)
    {
        return GetEnumTypeName(index);
    }
    else
    {
        return CSVTypeConversion::GetAbbreviation(type);
    }
}

System::String CoreTools::CSVHeadImpl::GetAbbreviationByNameSpace(int index, const String& className) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (const auto type = GetDataType(index);
        type == CSVDataType::Enum || type == CSVDataType::EnumArray)
    {
        return pathSplitParsing.GetNameSpace() + TextParsing::gDoubleColon.data() + GetEnumTypeName(index);
    }
    else if (type < CSVDataType::BoolArray)
    {
        return CSVTypeConversion::GetActualType(type);
    }
    else
    {
        return pathSplitParsing.GetNameSpace() +
               TextParsing::gDoubleColon.data() +
               className +
               TextParsing::gDoubleColon.data() +
               CSVTypeConversion::GetAbbreviation(type);
    }
}

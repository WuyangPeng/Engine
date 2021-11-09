///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/10/15 20:46)

#include "CoreTools/CoreToolsExport.h"

#include "CSVHeadImpl.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVConstant.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"

using std::vector;
using namespace std::literals;
using namespace CoreTools::TextParsing;

CoreTools::CSVHeadImpl::CSVHeadImpl(const String& path, const FileContent& fileContent)
    : path{ path },
      fileContent{ fileContent },
      formatType{ CSVFormatType::Default },
      nameSpace{},
      className{},
      key{},
      mapping{},
      scope{},
      defaultValue{},
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
    if (path.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("文件名为空。"s));
    }

    Parsing();

    if (dataType.size() != variableName.size())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("变量名和数据类型长度不一致。"s));
    }
}

void CoreTools::CSVHeadImpl::Parsing()
{
    ParsingNameSpace();
    ParsingFormatType();
    ParsingFormat();
    ParsingAnnotation();
    ParsingDataType();
    ParsingVariableName();
}

void CoreTools::CSVHeadImpl::ParsingNameSpace()
{
    vector<String> pathSplit{};
    boost::algorithm::split(pathSplit, path, boost::is_any_of(g_FileSplit), boost::token_compress_on);

    if (1 < pathSplit.size())
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        nameSpace = StringConversion::ToFirstLetterUpper(pathSplit[pathSplit.size() - 2]);

#include STSTEM_WARNING_POP
    }

    auto lastName = pathSplit.at(pathSplit.size() - 1);
    const auto poistion = lastName.find(g_Dot);

    className = StringConversion::ToFirstLetterUpper(lastName.substr(0, poistion));
}

void CoreTools::CSVHeadImpl::ParsingFormatType()
{
    constexpr auto index = System::EnumCastUnderlying(CSVType::Format) - 1;
    auto content = fileContent.at(index);

    if (content.empty())
    {
        return;
    }

    auto poistion = content.find(g_Comma);
    auto column = content.substr(0, poistion);

    poistion = column.find(g_equalSign);
    auto columnFormat = column.substr(0, poistion);
    boost::algorithm::trim(columnFormat);

    if (columnFormat.empty())
    {
        return;
    }

    formatType = CSVTypeConversion::GetFormatType(columnFormat);

    if (formatType == CSVFormatType::Ignore)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("CSV格式类型不能为Ignore。"s));
    }
}

void CoreTools::CSVHeadImpl::ParsingFormat()
{
    constexpr auto index = System::EnumCastUnderlying(CSVType::Format) - 1;
    auto content = fileContent.at(index);

    if (content.empty())
    {
        return;
    }

    vector<String> column{};
    boost::algorithm::split(column, content, boost::is_any_of(g_Comma), boost::token_compress_off);

    bool firstIndex = true;
    for (const auto& value : column)
    {
        vector<String> element{};
        boost::algorithm::split(element, value, boost::is_any_of(g_Or), boost::token_compress_off);

        auto isScope = false;
        auto isMapping = false;
        auto isDefaultValue = false;

        for (const auto& single : element)
        {
            if (single.find(SYSTEM_TEXT("[")) != String::npos ||
                single.find(SYSTEM_TEXT("]")) != String::npos ||
                single.find(SYSTEM_TEXT("(")) != String::npos ||
                single.find(SYSTEM_TEXT(")")) != String::npos ||
                single.find(SYSTEM_TEXT(">")) != String::npos ||
                single.find(SYSTEM_TEXT("<")) != String::npos ||
                single.find(SYSTEM_TEXT("{")) != String::npos ||
                single.find(SYSTEM_TEXT("}")) != String::npos)
            {
                if (!isScope)
                {
                    scope.emplace_back(single);
                }

                isScope = true;
            }
            else if (single.find(SYSTEM_TEXT("=")) != String::npos)
            {
                if (!isDefaultValue)
                {
                    vector<String> equalSign{};
                    boost::algorithm::split(equalSign, single, boost::is_any_of(SYSTEM_TEXT("=")), boost::token_compress_off);
                    if (1 < equalSign.size())
                    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

                        defaultValue.emplace_back(equalSign[1]);

#include STSTEM_WARNING_POP
                    }
                }

                if (firstIndex)
                {
                    vector<String> firstKey{};
                    boost::algorithm::split(firstKey, single, boost::is_any_of(SYSTEM_TEXT("=")), boost::token_compress_off);
                    if (1 < firstKey.size())
                    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

                        key = firstKey[1];

#include STSTEM_WARNING_POP
                    }
                }

                isDefaultValue = true;
            }
            else
            {
                if (!isMapping)
                {
                    if (firstIndex)
                    {
                        vector<String> firstKey{};
                        boost::algorithm::split(firstKey, single, boost::is_any_of(SYSTEM_TEXT("=")), boost::token_compress_off);
                        if (1 < firstKey.size())
                        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

                            key = firstKey[1];

#include STSTEM_WARNING_POP
                        }

                        mapping.emplace_back(SYSTEM_TEXT(""s));
                    }
                    else
                    {
                        mapping.emplace_back(single);
                    }
                }

                isMapping = true;
            }
        }

        firstIndex = false;

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
}

void CoreTools::CSVHeadImpl::ParsingAnnotation()
{
    constexpr auto index = System::EnumCastUnderlying(CSVType::Annotation) - 1;
    auto content = fileContent.at(index);

    boost::algorithm::split(annotation, content, boost::is_any_of(g_Comma), boost::token_compress_off);
}

void CoreTools::CSVHeadImpl::ParsingDataType()
{
    constexpr auto index = System::EnumCastUnderlying(CSVType::DataType) - 1;
    auto content = fileContent.at(index);

    vector<String> column{};
    boost::algorithm::split(column, content, boost::is_any_of(g_Comma), boost::token_compress_off);

    for (const auto& value : column)
    {
        auto type = CSVTypeConversion::GetDataType(value);
        if (type == CSVDataType::Bit || type == CSVDataType::BitArray)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("bit类型不应该存在于csv中。"s));
        }
        dataType.emplace_back(type);

        if (type == CSVDataType::Enum || type == CSVDataType::EnumArray)
        {
            vector<String> enumType{};
            boost::algorithm::split(enumType, value, boost::is_any_of(SYSTEM_TEXT("|")), boost::token_compress_off);

            if (1 < enumType.size())
            {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

                enumTypeName.emplace_back(StringConversion::ToFirstLetterUpper(enumType[1]));

#include STSTEM_WARNING_POP
            }
            else
            {
                THROW_EXCEPTION(SYSTEM_TEXT("enum类型定义错误。"s));
            }
        }
        else
        {
            enumTypeName.emplace_back(SYSTEM_TEXT(""s));
        }
    }
}

void CoreTools::CSVHeadImpl::ParsingVariableName()
{
    constexpr auto index = System::EnumCastUnderlying(CSVType::VariableName) - 1;
    auto content = fileContent.at(index);

    vector<String> column{};
    boost::algorithm::split(column, content, boost::is_any_of(g_Comma), boost::token_compress_off);
    for (const auto& value : column)
    {
        variableName.emplace_back(StringConversion::ToFirstLetterLower(value));
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::CSVHeadImpl::IsValid() const noexcept
{
    if (!path.empty() &&
        !fileContent.empty() &&
        dataType.size() == variableName.size() &&
        scope.size() == mapping.size())
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

    return nameSpace;
}

System::String CoreTools::CSVHeadImpl::GetCSVClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return className;
}

System::String CoreTools::CSVHeadImpl::GetKey() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return key;
}

int CoreTools::CSVHeadImpl::GetCount() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(dataType.size());
}

System::String CoreTools::CSVHeadImpl::GetMapping(int index) const
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

bool CoreTools::CSVHeadImpl::HasMapping() const noexcept
{
    for (const auto& value : mapping)
    {
        if (!value.empty())
        {
            return true;
        }
    }

    return false;
}

System::String CoreTools::CSVHeadImpl::GetScope(int index) const
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

bool CoreTools::CSVHeadImpl::HasScope() const noexcept
{
    for (const auto& value : scope)
    {
        if (!value.empty())
        {
            return true;
        }
    }

    return false;
}

System::String CoreTools::CSVHeadImpl::GetScopeExpression(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    String result{};

    const auto scopeExpression = GetScope(index);
    if (scopeExpression.empty())
    {
        return result;
    }

    const auto variableNameExpression = GetVariableName(index);

    vector<String> scopeExpressionResult{};
    boost::algorithm::split(scopeExpressionResult, scopeExpression, boost::is_any_of(SYSTEM_TEXT("()[]<>=-  "s)), boost::token_compress_on);

    scopeExpressionResult.erase(std::remove(scopeExpressionResult.begin(), scopeExpressionResult.end(), SYSTEM_TEXT(""s)),
                                scopeExpressionResult.end());

    const auto firstChar = scopeExpression.front();

    switch (firstChar)
    {
        case SYSTEM_TEXT('['):
        {
            result += SYSTEM_TEXT("("s) + scopeExpressionResult.at(0) + SYSTEM_TEXT(" <= "s) + variableNameExpression + SYSTEM_TEXT(") && ("s);
            const auto lastChar = scopeExpression.back();
            if (lastChar == SYSTEM_TEXT(']'))
            {
                result += variableNameExpression + SYSTEM_TEXT(" <= "s) + scopeExpressionResult.at(1) + SYSTEM_TEXT(")"s);
            }
            else if (lastChar == SYSTEM_TEXT(')'))
            {
                result += variableNameExpression + SYSTEM_TEXT(" < "s) + scopeExpressionResult.at(1) + SYSTEM_TEXT(")"s);
            }
        }
        break;
        case SYSTEM_TEXT('('):
        {
            result += SYSTEM_TEXT("("s) + scopeExpressionResult.at(0) + SYSTEM_TEXT(" < "s) + variableNameExpression + SYSTEM_TEXT(") && ("s);
            const auto lastChar = scopeExpression.back();
            if (lastChar == SYSTEM_TEXT(']'))
            {
                result += variableNameExpression + SYSTEM_TEXT(" <= "s) + scopeExpressionResult.at(1) + SYSTEM_TEXT(")"s);
            }
            else if (lastChar == SYSTEM_TEXT(')'))
            {
                result += variableNameExpression + SYSTEM_TEXT(" < "s) + scopeExpressionResult.at(1) + SYSTEM_TEXT(")"s);
            }
        }
        break;
        case SYSTEM_TEXT('>'):
        {
            const auto nextChar = scopeExpression.at(1);
            if (nextChar == SYSTEM_TEXT('='))
            {
                result += scopeExpressionResult.at(0) + SYSTEM_TEXT(" <= "s) + variableNameExpression;
            }
            else
            {
                result += scopeExpressionResult.at(0) + SYSTEM_TEXT(" < "s) + variableNameExpression;
            }
        }
        break;
        case SYSTEM_TEXT('<'):
        {
            const auto nextChar = scopeExpression.at(1);
            if (nextChar == SYSTEM_TEXT('='))
            {
                result += variableNameExpression + SYSTEM_TEXT(" <= "s) + scopeExpressionResult.at(0);
            }
            else
            {
                result += variableNameExpression + SYSTEM_TEXT(" < "s) + scopeExpressionResult.at(0);
            }
        }
        break;
        default:
            break;
    }

    return result;
}

System::String CoreTools::CSVHeadImpl::GetDefaultValue(int index) const
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

System::String CoreTools::CSVHeadImpl::GetAnnotation(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (0 <= index && index < boost::numeric_cast<int>(annotation.size()))
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        return annotation[index];

#include STSTEM_WARNING_POP
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

    THROW_EXCEPTION(SYSTEM_TEXT("未找到指定字段名。"s));
}

int CoreTools::CSVHeadImpl::GetDataIndex(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    auto index = 0;
    for (const auto& value : variableName)
    {
        if (value == field)
        {
            return index;
        }

        ++index;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("未找到指定字段名。"s));
}

int CoreTools::CSVHeadImpl::GetDataIndex(const StringView& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const auto iter = find(variableName.cbegin(), variableName.cend(), field);

    if (iter != variableName.cend())
    {
        return boost::numeric_cast<int>(iter - variableName.begin());
    }

    THROW_EXCEPTION(SYSTEM_TEXT("未找到指定字段名。"s));
}

bool CoreTools::CSVHeadImpl::HasDataField(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const auto iter = find(variableName.cbegin(), variableName.cend(), field);

    if (iter != variableName.cend())
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

    const auto iter = find(variableName.cbegin(), variableName.cend(), field);

    if (iter != variableName.cend())
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

    const auto iter = find(dataType.cbegin(), dataType.cend(), csvDataType);
    if (iter != dataType.cend())
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

    const auto iter = find_if(dataType.cbegin(), dataType.cend(), [](auto value) {
        if (CSVDataType::CharArray <= value && value <= CSVDataType::IntVector4Array)
            return true;
        else
            return false;
    });

    if (iter != dataType.cend())
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

    const auto iter = find_if(dataType.cbegin(), dataType.cend(), [](auto value) {
        if (CSVDataType::BoolArray <= value && value <= CSVDataType::IntVector4Array)
            return true;
        else
            return false;
    });

    if (iter != dataType.cend())
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

    auto completeClassName = nameSpace;

    completeClassName += g_DoubleColon;
    completeClassName += className;

    return completeClassName;
}

System::String CoreTools::CSVHeadImpl::GetActualType(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const auto type = GetDataType(index);

    if (type == CSVDataType::Enum || type == CSVDataType::EnumArray)
    {
        return GetEnumTypeName(index);
    }
    else
    {
        return CSVTypeConversion::GetActualType(type);
    }
}

System::String CoreTools::CSVHeadImpl::GetActualTypeByNameSpace(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const auto type = GetDataType(index);

    if (type == CSVDataType::Enum || type == CSVDataType::EnumArray)
    {
        return nameSpace + g_DoubleColon.data() + GetEnumTypeName(index);
    }
    else
    {
        return CSVTypeConversion::GetActualType(type);
    }
}

System::String CoreTools::CSVHeadImpl::GetUpperVariableName(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    auto upperVariableName = GetVariableName(index);
    if (upperVariableName == SYSTEM_TEXT("id"s))
    {
        return SYSTEM_TEXT("ID"s);
    }

    return StringConversion::ToFirstLetterUpper(upperVariableName);
}

System::String CoreTools::CSVHeadImpl::GetFunctionVariableName(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const auto upperVariableName = GetUpperVariableName(index);

    const auto type = GetDataType(index);
    if (type == CSVDataType::Bool)
    {
        if (upperVariableName.find(SYSTEM_TEXT("Is"s)) != 0u)
        {
            return SYSTEM_TEXT("Is"s) + upperVariableName;
        }
        else
        {
            return upperVariableName;
        }
    }
    else
    {
        return SYSTEM_TEXT("Get"s) + upperVariableName;
    }
}

CoreTools::CSVHeadImpl::KeyName CoreTools::CSVHeadImpl::GetKeyName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    vector<String> result{};
    boost::algorithm::split(result, key, boost::is_any_of(g_KeySplit), boost::token_compress_on);

    std::locale locale{};
    const auto iter = std::remove_if(result.begin(), result.end(), [&locale](const auto& value) {
        if (value.empty() || std::isdigit(value.at(0), locale))
        {
            return true;
        }
        else
        {
            return false;
        }
    });

    result.erase(iter, result.end());

    return result;
}

///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/11/04 23:16)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateGetFunctionDefinition.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVConstant.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"

using std::vector;
using namespace std::literals;
using namespace CoreTools::TextParsing;

CoreTools::CSVGenerateGetFunctionDefinition::CSVGenerateGetFunctionDefinition(const CSVHead& csvHead, const String& suffix)
    : csvHead{ csvHead }, suffix{ suffix }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CSVGenerateGetFunctionDefinition)

System::String CoreTools::CSVGenerateGetFunctionDefinition::GenerateBaseGetFunctionDefinition(const String& keyTypeDescribe) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto nameSpace = csvHead.GetNameSpace();
    const auto className = csvHead.GetCSVClassName() + suffix;

    auto content = keyTypeDescribe;
    content += g_Space;
    content += nameSpace;
    content += g_DoubleColon;
    content += className;
    content += SYSTEM_TEXT("::GetKey() const noexcept\n"s);

    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += g_UserClassIsValidConst9;
    content += g_NewlineCharacter;
    content += g_Indentation;
    content += SYSTEM_TEXT("return key;\n"s);
    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    const auto size = csvHead.GetCount();
    for (auto index = 0; index < size; ++index)
    {
        content += GenerateBaseGetFunctionDefinition(index);
    }

    return content;
}

System::String CoreTools::CSVGenerateGetFunctionDefinition::GenerateBaseGetFunctionDefinition(int index) const
{
    const auto nameSpace = csvHead.GetNameSpace();
    const auto className = csvHead.GetCSVClassName() + suffix;

    String actualType = csvHead.GetActualTypeByNameSpace(index);
    auto functionVariableName = csvHead.GetFunctionVariableName(index);

    auto content = actualType;
    content += g_Space;
    content += nameSpace;
    content += g_DoubleColon;
    content += className;
    content += g_DoubleColon;
    content += functionVariableName;
    content += SYSTEM_TEXT("() const");

    const auto dataType = csvHead.GetDataType(index);
    if (CSVDataType::Bool <= dataType && dataType <= CSVDataType::IntVector4)
    {
        content += SYSTEM_TEXT(" noexcept"s);
    }

    content += g_NewlineCharacter;

    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += g_UserClassIsValidConst9;
    content += g_NewlineCharacter;

    content += GenerateBaseGetFunctionReturnDefinition(dataType, actualType);

    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    content += GenerateBaseGetFunctionArrayDefinition(index);
    content += GenerateBaseGetFunctionMappingDefinition(index);

    return content;
}

System::String CoreTools::CSVGenerateGetFunctionDefinition::GenerateBaseGetFunctionReturnDefinition(CSVDataType dataType, const String& actualType) const
{
    if (dataType == CSVDataType::String)
    {
        String content{ g_Indentation };
        content += SYSTEM_TEXT("THROW_EXCEPTION(SYSTEM_TEXT(\""s);
        content += StringConversion::ToFirstLetterLower(csvHead.GetCSVClassName());
        content += SYSTEM_TEXT("表基类不允许获取字符串。\"s));\n"s);

        return content;
    }
    else if (dataType == CSVDataType::Bool)
    {
        String content{ g_Indentation };
        content += SYSTEM_TEXT("return false;\n"s);

        return content;
    }
    else if (dataType == CSVDataType::Char)
    {
        String content{ g_Indentation };
        content += SYSTEM_TEXT("return SYSTEM_TEXT('\\0');\n"s);

        return content;
    }
    else if (dataType == CSVDataType::Int || dataType == CSVDataType::Int64)
    {
        String content{ g_Indentation };
        content += SYSTEM_TEXT("return 0;\n"s);

        return content;
    }
    else if (dataType == CSVDataType::Double)
    {
        String content{ g_Indentation };
        content += SYSTEM_TEXT("return 0.0;\n"s);

        return content;
    }
    else if (CSVDataType::Enum <= dataType && dataType <= CSVDataType::IntVector4)
    {
        String content{ g_Indentation };
        content += SYSTEM_TEXT("return "s);
        content += actualType;
        content += SYSTEM_TEXT("{};\n"s);

        return content;
    }
    else if (CSVDataType::BoolArray <= dataType)
    {
        String content{ g_Indentation };
        content += SYSTEM_TEXT("THROW_EXCEPTION(SYSTEM_TEXT(\""s);
        content += StringConversion::ToFirstLetterLower(csvHead.GetCSVClassName());
        content += SYSTEM_TEXT("表基类不允许获取数组。\"s));\n"s);

        return content;
    }

    return String{};
}

System::String CoreTools::CSVGenerateGetFunctionDefinition::GenerateBaseGetFunctionArrayDefinition(int index) const
{
    const auto dataType = csvHead.GetDataType(index);
    String content{};
    if (CSVDataType::BoolArray <= dataType)
    {
        const auto nameSpace = csvHead.GetNameSpace();
        const auto className = csvHead.GetCSVClassName() + suffix;

        String actualType = csvHead.GetActualTypeByNameSpace(index);
        auto functionVariableName = csvHead.GetFunctionVariableName(index);

        content += SYSTEM_TEXT("int "s);
        content += nameSpace;
        content += g_DoubleColon;
        content += className;
        content += g_DoubleColon;
        content += functionVariableName;
        content += SYSTEM_TEXT("Count() const\n"s);
        content += g_FunctionBeginBrackets;
        content += g_Indentation;
        content += g_UserClassIsValidConst9;
        content += g_NewlineCharacter;
        content += g_Indentation;
        content += SYSTEM_TEXT("THROW_EXCEPTION(SYSTEM_TEXT(\""s);
        content += StringConversion::ToFirstLetterLower(csvHead.GetCSVClassName());
        content += SYSTEM_TEXT("表基类不允许获取数组。\"s));\n"s);
        content += g_FunctionEndBrackets;
        content += g_NewlineCharacter;

        content += SYSTEM_TEXT("bool "s);
        content += nameSpace;
        content += g_DoubleColon;
        content += className;
        content += g_DoubleColon;
        content += functionVariableName;
        content += SYSTEM_TEXT("(MAYBE_UNUSED int index) const\n"s);
        content += g_FunctionBeginBrackets;
        content += g_Indentation;
        content += g_UserClassIsValidConst9;
        content += g_NewlineCharacter;
        content += g_Indentation;
        content += SYSTEM_TEXT("THROW_EXCEPTION(SYSTEM_TEXT(\""s);
        content += StringConversion::ToFirstLetterLower(csvHead.GetCSVClassName());
        content += SYSTEM_TEXT("表基类不允许获取数组。\"s));\n"s);
        content += g_FunctionEndBrackets;
        content += g_NewlineCharacter;

        content += actualType;
        content += SYSTEM_TEXT("::const_iterator "s);
        content += nameSpace;
        content += g_DoubleColon;
        content += className;
        content += g_DoubleColon;
        content += functionVariableName;
        content += SYSTEM_TEXT("Begin() const\n"s);
        content += g_FunctionBeginBrackets;
        content += g_Indentation;
        content += g_UserClassIsValidConst9;
        content += g_NewlineCharacter;
        content += g_Indentation;
        content += SYSTEM_TEXT("THROW_EXCEPTION(SYSTEM_TEXT(\""s);
        content += StringConversion::ToFirstLetterLower(csvHead.GetCSVClassName());
        content += SYSTEM_TEXT("表基类不允许获取数组。\"s));\n"s);
        content += g_FunctionEndBrackets;
        content += g_NewlineCharacter;

        content += actualType;
        content += SYSTEM_TEXT("::const_iterator "s);
        content += nameSpace;
        content += g_DoubleColon;
        content += className;
        content += g_DoubleColon;
        content += functionVariableName;
        content += SYSTEM_TEXT("End() const\n"s);
        content += g_FunctionBeginBrackets;
        content += g_Indentation;
        content += g_UserClassIsValidConst9;
        content += g_NewlineCharacter;
        content += g_Indentation;
        content += SYSTEM_TEXT("THROW_EXCEPTION(SYSTEM_TEXT(\""s);
        content += StringConversion::ToFirstLetterLower(csvHead.GetCSVClassName());
        content += SYSTEM_TEXT("表基类不允许获取数组。\"s));\n"s);
        content += g_FunctionEndBrackets;
        content += g_NewlineCharacter;
    }

    return content;
}

System::String CoreTools::CSVGenerateGetFunctionDefinition::GenerateBaseGetFunctionMappingDefinition(int index) const
{
    String content{};
    const auto mapping = csvHead.GetMapping(index);
    if (!mapping.empty())
    {
        const auto nameSpace = csvHead.GetNameSpace();
        const auto className = csvHead.GetCSVClassName() + suffix;
        auto upperVariableName = csvHead.GetUpperVariableName(index);

        content += SYSTEM_TEXT("std::shared_ptr<const "s);
        content += csvHead.GetNameSpace();
        content += g_DoubleColon;
        content += StringConversion::ToFirstLetterUpper(mapping);
        content += SYSTEM_TEXT("> ");
        content += nameSpace;
        content += g_DoubleColon;
        content += className;
        content += g_DoubleColon;
        content += SYSTEM_TEXT("Get"s);
        content += upperVariableName;
        content += SYSTEM_TEXT("(MAYBE_UNUSED const ");
        content += nameSpace;
        content += SYSTEM_TEXT("Container& csvContainer) const\n"s);

        content += g_FunctionBeginBrackets;
        content += g_Indentation;
        content += g_UserClassIsValidConst9;
        content += g_NewlineCharacter;
        content += g_Indentation;
        content += SYSTEM_TEXT("THROW_EXCEPTION(SYSTEM_TEXT(\""s);
        content += StringConversion::ToFirstLetterLower(csvHead.GetCSVClassName());
        content += SYSTEM_TEXT("表基类不允许获取映射值。\"s));\n"s);
        content += g_FunctionEndBrackets;
        content += g_NewlineCharacter;
    }

    return content;
}

System::String CoreTools::CSVGenerateGetFunctionDefinition::GenerateUserClassIsValidConst() const
{
    String content{};

    const auto scope = csvHead.HasScope();
    if (scope)
    {
        content += g_Indentation;
        content += g_UserClassIsValidConst1;
    }
    else
    {
        content += g_Indentation;
        content += g_UserClassIsValidConst9;
    }

    return content;
}

System::String CoreTools::CSVGenerateGetFunctionDefinition::GenerateGetFunctionDefinition(const String& keyTypeDescribe) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto nameSpace = csvHead.GetNameSpace();
    const auto className = csvHead.GetCSVClassName() + suffix;

    auto content = keyTypeDescribe;
    content += g_Space;
    content += nameSpace;
    content += g_DoubleColon;
    content += className;
    content += SYSTEM_TEXT("::GetKey() const noexcept\n"s);
    content += g_FunctionBeginBrackets;

    content += GenerateUserClassIsValidConst();

    content += g_NewlineCharacter;
    content += g_Indentation;
    content += SYSTEM_TEXT("return ");

    if (csvHead.GetCSVFormatType() == CSVFormatType::Key)
    {
        content += csvHead.GetKey();
    }
    else
    {
        content += csvHead.GetVariableName(0);
    }

    content += g_SemicolonNewline;

    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    const auto size = csvHead.GetCount();
    for (auto index = 0; index < size; ++index)
    {
        content += GenerateGetFunctionDefinition(index);
    }

    return content;
}

System::String CoreTools::CSVGenerateGetFunctionDefinition::GenerateGetFunctionDefinition(int index) const
{
    const auto nameSpace = csvHead.GetNameSpace();
    const auto className = csvHead.GetCSVClassName() + suffix;

    const auto actualType = csvHead.GetActualTypeByNameSpace(index);
    auto functionVariableName = csvHead.GetFunctionVariableName(index);

    String content = actualType;
    content += g_Space;
    content += nameSpace;
    content += g_DoubleColon;
    content += className;
    content += g_DoubleColon;
    content += functionVariableName;
    content += SYSTEM_TEXT("() const");

    const auto dataType = csvHead.GetDataType(index);
    if (CSVDataType::Bool <= dataType && dataType <= CSVDataType::IntVector4)
    {
        content += SYSTEM_TEXT(" noexcept"s);
    }

    content += g_NewlineCharacter;
    content += g_FunctionBeginBrackets;

    content += GenerateUserClassIsValidConst();
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += SYSTEM_TEXT("return ");
    content += csvHead.GetVariableName(index);
    content += g_SemicolonNewline;

    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    content += GenerateGetFunctionArrayDefinition(index);
    content += GenerateGetFunctionMappingDefinition(index);

    return content;
}

System::String CoreTools::CSVGenerateGetFunctionDefinition::GenerateGetFunctionArrayDefinition(int index) const
{
    const auto dataType = csvHead.GetDataType(index);
    String content{};
    if (CSVDataType::BoolArray <= dataType)
    {
        const auto nameSpace = csvHead.GetNameSpace();
        const auto className = csvHead.GetCSVClassName() + suffix;

        const auto actualType = csvHead.GetActualTypeByNameSpace(index);
        auto functionVariableName = csvHead.GetFunctionVariableName(index);

        content += SYSTEM_TEXT("int "s);
        content += nameSpace;
        content += g_DoubleColon;
        content += className;
        content += g_DoubleColon;
        content += functionVariableName;
        content += SYSTEM_TEXT("Count() const\n"s);
        content += g_FunctionBeginBrackets;

        content += GenerateUserClassIsValidConst();
        content += g_NewlineCharacter;
        content += g_Indentation;
        content += SYSTEM_TEXT("return boost::numeric_cast<int>("s);
        content += csvHead.GetVariableName(index);
        content += SYSTEM_TEXT(".size());\n"s);
        content += g_FunctionEndBrackets;
        content += g_NewlineCharacter;

        content += SYSTEM_TEXT("bool "s);
        content += nameSpace;
        content += g_DoubleColon;
        content += className;
        content += g_DoubleColon;
        content += functionVariableName;
        content += SYSTEM_TEXT("(int index) const\n"s);
        content += g_FunctionBeginBrackets;

        content += GenerateUserClassIsValidConst();
        content += g_NewlineCharacter;

        content += g_Indentation;
        content += SYSTEM_TEXT("return "s);
        content += csvHead.GetVariableName(index);
        content += SYSTEM_TEXT(".at(index);\n"s);
        content += g_FunctionEndBrackets;
        content += g_NewlineCharacter;

        content += actualType;
        content += SYSTEM_TEXT("::const_iterator "s);
        content += nameSpace;
        content += g_DoubleColon;
        content += className;
        content += g_DoubleColon;
        content += functionVariableName;
        content += SYSTEM_TEXT("Begin() const noexcept\n"s);
        content += g_FunctionBeginBrackets;

        content += GenerateUserClassIsValidConst();
        content += g_NewlineCharacter;

        content += g_Indentation;
        content += SYSTEM_TEXT("return "s);
        content += csvHead.GetVariableName(index);
        content += SYSTEM_TEXT(".cbegin();\n"s);
        content += g_FunctionEndBrackets;
        content += g_NewlineCharacter;

        content += actualType;
        content += SYSTEM_TEXT("::const_iterator "s);
        content += nameSpace;
        content += g_DoubleColon;
        content += className;
        content += g_DoubleColon;
        content += functionVariableName;
        content += SYSTEM_TEXT("End() const noexcept\n"s);
        content += g_FunctionBeginBrackets;

        content += GenerateUserClassIsValidConst();
        content += g_NewlineCharacter;

        content += g_Indentation;
        content += SYSTEM_TEXT("return "s);
        content += csvHead.GetVariableName(index);
        content += SYSTEM_TEXT(".cend();\n"s);
        content += g_FunctionEndBrackets;
        content += g_NewlineCharacter;
    }

    return content;
}

System::String CoreTools::CSVGenerateGetFunctionDefinition::GenerateGetFunctionMappingDefinition(int index) const
{
    String content{};
    const auto mapping = csvHead.GetMapping(index);
    if (!mapping.empty())
    {
        const auto nameSpace = csvHead.GetNameSpace();
        const auto className = csvHead.GetCSVClassName() + suffix;

        const auto actualType = csvHead.GetActualTypeByNameSpace(index);
        auto functionVariableName = csvHead.GetFunctionVariableName(index);
        auto upperVariableName = csvHead.GetUpperVariableName(index);

        content += SYSTEM_TEXT("std::shared_ptr<const "s);
        content += nameSpace;
        content += g_DoubleColon;
        content += StringConversion::ToFirstLetterUpper(mapping);
        content += SYSTEM_TEXT("> "s);
        content += nameSpace;
        content += g_DoubleColon;
        content += className;
        content += g_DoubleColon;
        content += SYSTEM_TEXT("Get"s);
        content += upperVariableName;
        content += SYSTEM_TEXT("(const ");
        content += nameSpace;
        content += SYSTEM_TEXT("Container& csvContainer) const\n "s);

        content += g_FunctionBeginBrackets;
        content += GenerateUserClassIsValidConst();
        content += g_NewlineCharacter;

        content += g_Indentation;
        content += SYSTEM_TEXT("return csvContainer.Get"s);
        content += StringConversion::ToFirstLetterUpper(csvHead.GetMapping(index));
        content += SYSTEM_TEXT("Container()->Get"s);
        content += StringConversion::ToFirstLetterUpper(csvHead.GetMapping(index));
        content += SYSTEM_TEXT("("s);
        content += csvHead.GetVariableName(index);
        content += SYSTEM_TEXT(");\n"s);
        content += g_FunctionEndBrackets;
        content += g_NewlineCharacter;
    }

    return content;
}

System::String CoreTools::CSVGenerateGetFunctionDefinition::GenerateContainerFunctionDefinition(const String& keyTypeDescribe) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const CSVFormatType csvFormatType = csvHead.GetCSVFormatType();

    switch (csvFormatType)
    {
        case CSVFormatType::Default:
        {
            return GenerateDefaultContainerFunctionDefinition(keyTypeDescribe);
        }
        break;
        case CSVFormatType::Vector:
        {
            return GenerateVectorContainerFunctionDefinition(keyTypeDescribe);
        }
        break;
        case CSVFormatType::TreeMap:
            FALLTHROUGH;
        case CSVFormatType::HashMap:
        {
            return GenerateMapContainerFunctionDefinition(keyTypeDescribe);
        }
        break;
        case CSVFormatType::Key:
        {
            return GenerateKeyContainerFunctionDefinition(keyTypeDescribe);
        }
        break;
        case CSVFormatType::Unique:
        {
            return GenerateUniqueContainerFunctionDefinition();
        }
        break;
        default:
            break;
    }

    return String{};
}

System::String CoreTools::CSVGenerateGetFunctionDefinition::GenerateDefaultContainerFunctionDefinition(const String& keyTypeDescribe) const
{
    const auto nameSpace = csvHead.GetNameSpace();
    const auto containerClassName = csvHead.GetCSVClassName() + suffix;
    const auto lowerClassName = StringConversion::ToFirstLetterLower(csvHead.GetCSVClassName());

    auto content = nameSpace;
    content += g_DoubleColon;
    content += containerClassName;
    content += SYSTEM_TEXT("::Const"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("BaseSharedPtr "s);
    content += nameSpace;
    content += g_DoubleColon;
    content += containerClassName;
    content += SYSTEM_TEXT("::GetFirst"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("() const\n"s);

    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += g_UserClassIsValidConst9;
    content += g_NewlineCharacter;
    content += g_Indentation;
    content += SYSTEM_TEXT("return "s);
    content += lowerClassName;
    content += SYSTEM_TEXT(".at(0);\n"s);
    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    content += nameSpace;
    content += g_DoubleColon;
    content += containerClassName;
    content += SYSTEM_TEXT("::Const"s);
    content += csvHead.GetCSVClassName();

    content += SYSTEM_TEXT("BaseSharedPtr "s);
    content += nameSpace;
    content += g_DoubleColon;
    content += containerClassName;
    content += SYSTEM_TEXT("::Get"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("(");
    content += keyTypeDescribe;
    content += SYSTEM_TEXT(" key) const\n");

    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += g_UserClassIsValidConst9;
    content += g_NewlineCharacter;
    content += g_Indentation;
    content += SYSTEM_TEXT("const auto function = [](const auto& lhs, const auto& rhs) noexcept {\n"s);
    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("return (*lhs).GetKey() < (*rhs).GetKey();\n"s);
    content += g_Indentation;
    content += SYSTEM_TEXT("};\n"s);
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += SYSTEM_TEXT("const auto iter = lower_bound("s);
    content += lowerClassName;
    content += SYSTEM_TEXT(".begin(), "s);
    content += lowerClassName;
    content += SYSTEM_TEXT(".end(), make_shared<"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("Base>(key), function);\n"s);
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += SYSTEM_TEXT("if (iter != "s);
    content += lowerClassName;
    content += SYSTEM_TEXT(".cend() && (*iter)->GetKey() == key)\n"s);
    content += g_Indentation;
    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("return *iter;\n"s);
    content += g_Indentation;
    content += g_FunctionEndBrackets;
    content += g_Indentation;
    content += SYSTEM_TEXT("else\n"s);
    content += g_Indentation;
    content += g_FunctionBeginBrackets;

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("THROW_EXCEPTION(SYSTEM_TEXT(\""s);
    content += lowerClassName;
    content += SYSTEM_TEXT("表未找到key = \"s) + System::ToString(key) + SYSTEM_TEXT(\"的配置信息。\"s));\n"s);

    content += g_Indentation;
    content += g_FunctionEndBrackets;
    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    content += nameSpace;
    content += g_DoubleColon;
    content += containerClassName;
    content += SYSTEM_TEXT("::Container "s);

    content += nameSpace;
    content += g_DoubleColon;
    content += containerClassName;
    content += SYSTEM_TEXT("::GetContainer() const\n"s);

    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += g_UserClassIsValidConst9;
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += SYSTEM_TEXT("return "s);
    content += lowerClassName;
    content += g_SemicolonNewline;
    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateGetFunctionDefinition::GenerateVectorContainerFunctionDefinition(const String& keyTypeDescribe) const
{
    const auto nameSpace = csvHead.GetNameSpace();
    const auto containerClassName = csvHead.GetCSVClassName() + suffix;
    const auto lowerClassName = StringConversion::ToFirstLetterLower(csvHead.GetCSVClassName());

    auto content = nameSpace;
    content += g_DoubleColon;
    content += containerClassName;
    content += SYSTEM_TEXT("::Const"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("BaseSharedPtr "s);
    content += nameSpace;
    content += g_DoubleColon;
    content += containerClassName;
    content += SYSTEM_TEXT("::GetFirst"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("(");
    content += keyTypeDescribe;
    content += SYSTEM_TEXT(" key) const\n");
    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += g_UserClassIsValidConst9;
    content += g_NewlineCharacter;
    content += g_Indentation;
    content += SYSTEM_TEXT("const auto function = [](const auto& lhs, const auto& rhs) noexcept {\n"s);
    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("return (*lhs).GetKey() < (*rhs).GetKey();\n"s);
    content += g_Indentation;
    content += SYSTEM_TEXT("};\n");
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += SYSTEM_TEXT("const auto range = equal_range("s);
    content += lowerClassName;
    content += SYSTEM_TEXT(".begin(), "s);
    content += lowerClassName;
    content += SYSTEM_TEXT(".end(), make_shared<"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("Base>(key), function);\n"s);
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += SYSTEM_TEXT("if (range.first != "s);
    content += lowerClassName;
    content += SYSTEM_TEXT(".cend())\n"s);
    content += g_Indentation;
    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("return *range.first;\n"s);
    content += g_Indentation;
    content += g_FunctionEndBrackets;
    content += g_Indentation;
    content += SYSTEM_TEXT("else\n"s);
    content += g_Indentation;
    content += g_FunctionBeginBrackets;

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("THROW_EXCEPTION(SYSTEM_TEXT(\""s);
    content += lowerClassName;
    content += SYSTEM_TEXT("表未找到key = \"s) + System::ToString(key) + SYSTEM_TEXT(\"的配置信息。\"s));\n"s);

    content += g_Indentation;
    content += g_FunctionEndBrackets;
    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    content += nameSpace;
    content += g_DoubleColon;
    content += containerClassName;
    content += SYSTEM_TEXT("::Container "s);
    content += nameSpace;
    content += g_DoubleColon;
    content += containerClassName;
    content += SYSTEM_TEXT("::Get"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("(");
    content += keyTypeDescribe;
    content += SYSTEM_TEXT(" key) const\n");
    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += g_UserClassIsValidConst9;
    content += g_NewlineCharacter;
    content += g_Indentation;
    content += SYSTEM_TEXT("const auto function = [](const auto& lhs, const auto& rhs) noexcept {\n"s);
    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("return (*lhs).GetKey() < (*rhs).GetKey();\n"s);
    content += g_Indentation;
    content += SYSTEM_TEXT("};\n"s);
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += SYSTEM_TEXT("const auto range = equal_range("s);
    content += lowerClassName;
    content += SYSTEM_TEXT(".begin(), "s);
    content += lowerClassName;
    content += SYSTEM_TEXT(".end(), make_shared<"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("Base>(key), function);\n"s);
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += SYSTEM_TEXT("return Container{ range.first, range.second };\n"s);

    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    content += nameSpace;
    content += g_DoubleColon;
    content += containerClassName;
    content += SYSTEM_TEXT("::Container "s);
    content += nameSpace;
    content += g_DoubleColon;
    content += containerClassName;
    content += SYSTEM_TEXT("::GetContainer() const\n"s);

    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += g_UserClassIsValidConst9;
    content += g_NewlineCharacter;
    content += g_Indentation;
    content += SYSTEM_TEXT("return "s);
    content += lowerClassName;
    content += g_SemicolonNewline;
    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateGetFunctionDefinition::GenerateMapContainerFunctionDefinition(const String& keyTypeDescribe) const
{
    const auto nameSpace = csvHead.GetNameSpace();
    const auto containerClassName = csvHead.GetCSVClassName() + suffix;
    const auto lowerClassName = StringConversion::ToFirstLetterLower(csvHead.GetCSVClassName());

    auto content = nameSpace;
    content += g_DoubleColon;
    content += containerClassName;
    content += SYSTEM_TEXT("::Const"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("SharedPtr "s);
    content += nameSpace;
    content += g_DoubleColon;
    content += containerClassName;
    content += SYSTEM_TEXT("::GetFirst"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("() const\n"s);
    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += g_UserClassIsValidConst9;
    content += g_NewlineCharacter;
    content += g_Indentation;
    content += SYSTEM_TEXT("if ("s);
    content += lowerClassName;
    content += SYSTEM_TEXT(".empty())\n"s);
    content += g_Indentation;
    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("THROW_EXCEPTION(SYSTEM_TEXT(\""s);
    content += lowerClassName;
    content += SYSTEM_TEXT("表为空。\"s));"s);
    content += g_Indentation;
    content += g_FunctionEndBrackets;
    content += g_Indentation;
    content += SYSTEM_TEXT("else\n"s);
    content += g_Indentation;
    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("return "s);
    content += lowerClassName;
    content += SYSTEM_TEXT(".begin()->second;\n"s);
    content += g_Indentation;
    content += g_FunctionEndBrackets;
    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    content += nameSpace;
    content += g_DoubleColon;
    content += containerClassName;
    content += SYSTEM_TEXT("::Const"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("SharedPtr "s);
    content += nameSpace;
    content += g_DoubleColon;
    content += containerClassName;
    content += SYSTEM_TEXT("::Get"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("(");
    content += keyTypeDescribe;
    content += SYSTEM_TEXT(" key) const\n");
    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += g_UserClassIsValidConst9;
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += SYSTEM_TEXT("const auto iter = ");
    content += lowerClassName;
    content += SYSTEM_TEXT(".find(key);\n");
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += SYSTEM_TEXT("if (iter != "s);
    content += lowerClassName;
    content += SYSTEM_TEXT(".cend())\n"s);
    content += g_Indentation;
    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("return iter->second;\n"s);
    content += g_Indentation;
    content += g_FunctionEndBrackets;
    content += g_Indentation;
    content += SYSTEM_TEXT("else\n"s);
    content += g_Indentation;
    content += g_FunctionBeginBrackets;

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("THROW_EXCEPTION(SYSTEM_TEXT(\""s);
    content += lowerClassName;
    content += SYSTEM_TEXT("表未找到key = \"s) + System::ToString(key) + SYSTEM_TEXT(\"的配置信息。\"s));\n"s);

    content += g_Indentation;
    content += g_FunctionEndBrackets;
    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    content += nameSpace;
    content += g_DoubleColon;
    content += containerClassName;
    content += SYSTEM_TEXT("::MappingContainer "s);
    content += nameSpace;
    content += g_DoubleColon;
    content += containerClassName;
    content += SYSTEM_TEXT("::GetContainer() const\n"s);

    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += g_UserClassIsValidConst9;
    content += g_NewlineCharacter;
    content += g_Indentation;
    content += SYSTEM_TEXT("return "s);
    content += lowerClassName;
    content += g_SemicolonNewline;
    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateGetFunctionDefinition::GenerateKeyContainerFunctionDefinition(const String& keyTypeDescribe) const
{
    const auto nameSpace = csvHead.GetNameSpace();
    const auto containerClassName = csvHead.GetCSVClassName() + suffix;
    const auto lowerClassName = StringConversion::ToFirstLetterLower(csvHead.GetCSVClassName());

    auto content = nameSpace;
    content += g_DoubleColon;
    content += containerClassName;
    content += SYSTEM_TEXT("::Const"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("BaseSharedPtr "s);
    content += nameSpace;
    content += g_DoubleColon;
    content += containerClassName;
    content += SYSTEM_TEXT("::GetFirst"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("() const\n"s);
    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += g_UserClassIsValidConst9;
    content += g_NewlineCharacter;
    content += g_Indentation;
    content += SYSTEM_TEXT("return "s);
    content += lowerClassName;
    content += SYSTEM_TEXT(".at(0);\n"s);
    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    content += nameSpace;
    content += g_DoubleColon;
    content += containerClassName;
    content += SYSTEM_TEXT("::Const"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("BaseSharedPtr "s);
    content += nameSpace;
    content += g_DoubleColon;
    content += containerClassName;
    content += SYSTEM_TEXT("::Get"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("(");

    const auto result = csvHead.GetKeyName();

    auto index = 0u;
    for (const auto& value : result)
    {
        content += CSVTypeConversion::GetActualType(csvHead.GetDataType(value));
        content += g_Space;
        content += value;

        ++index;
        if (index != result.size())
        {
            content += SYSTEM_TEXT(", "s);
        }
    }

    content += SYSTEM_TEXT(") const\n "s);

    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += g_UserClassIsValidConst9;
    content += g_NewlineCharacter;
    content += SYSTEM_TEXT("    return Get"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("("s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("::GenerateKey(");

    index = 0u;
    for (const auto& value : result)
    {
        content += value;

        ++index;
        if (index != result.size())
        {
            content += SYSTEM_TEXT(", "s);
        }
    }

    content += SYSTEM_TEXT("));\n"s);

    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    content += nameSpace;
    content += g_DoubleColon;
    content += containerClassName;
    content += SYSTEM_TEXT("::Const"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("BaseSharedPtr "s);
    content += nameSpace;
    content += g_DoubleColon;
    content += containerClassName;
    content += SYSTEM_TEXT("::Get"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("(");
    content += keyTypeDescribe;
    content += SYSTEM_TEXT(" key) const\n");
    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += g_UserClassIsValidConst9;
    content += g_NewlineCharacter;
    content += g_Indentation;
    content += SYSTEM_TEXT("const auto function = [](const auto& lhs, const auto& rhs) noexcept {\n"s);
    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("return (*lhs).GetKey() < (*rhs).GetKey();\n"s);
    content += g_Indentation;
    content += SYSTEM_TEXT("};\n"s);
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += SYSTEM_TEXT("const auto iter = lower_bound("s);
    content += lowerClassName;
    content += SYSTEM_TEXT(".begin(), "s);
    content += lowerClassName;
    content += SYSTEM_TEXT(".end(), make_shared<"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("Base>(key), function);\n"s);
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += SYSTEM_TEXT("if (iter != "s);
    content += lowerClassName;
    content += SYSTEM_TEXT(".cend() && (*iter)->GetKey() == key)\n"s);
    content += g_Indentation;
    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("return *iter;\n"s);
    content += g_Indentation;
    content += g_FunctionEndBrackets;
    content += g_Indentation;
    content += SYSTEM_TEXT("else\n"s);
    content += g_Indentation;
    content += g_FunctionBeginBrackets;

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("THROW_EXCEPTION(SYSTEM_TEXT(\""s);
    content += lowerClassName;
    content += SYSTEM_TEXT("表未找到key = \"s) + System::ToString(key) + SYSTEM_TEXT(\"的配置信息。\"s));\n"s);

    content += g_Indentation;
    content += g_FunctionEndBrackets;
    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    content += nameSpace;
    content += g_DoubleColon;
    content += containerClassName;
    content += SYSTEM_TEXT("::Container "s);
    content += nameSpace;
    content += g_DoubleColon;
    content += containerClassName;
    content += SYSTEM_TEXT("::GetContainer() const\n"s);

    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += g_UserClassIsValidConst9;
    content += g_NewlineCharacter;
    content += g_Indentation;
    content += SYSTEM_TEXT("return "s);
    content += lowerClassName;
    content += g_SemicolonNewline;
    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateGetFunctionDefinition::GenerateUniqueContainerFunctionDefinition() const
{
    const auto nameSpace = csvHead.GetNameSpace();
    const auto containerClassName = csvHead.GetCSVClassName() + suffix;
    const auto lowerClassName = StringConversion::ToFirstLetterLower(csvHead.GetCSVClassName());

    auto content = nameSpace;
    content += g_DoubleColon;
    content += containerClassName;
    content += SYSTEM_TEXT("::Const"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("SharedPtr "s);
    content += nameSpace;
    content += g_DoubleColon;
    content += containerClassName;
    content += SYSTEM_TEXT("::Get"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("() const noexcept\n"s);
    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += g_UserClassIsValidConst9;
    content += g_NewlineCharacter;
    content += g_Indentation;
    content += SYSTEM_TEXT("return "s);
    content += lowerClassName;
    content += g_SemicolonNewline;
    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateGetFunctionDefinition::GenerateContainerDetailDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvFormatType = csvHead.GetCSVFormatType();

    switch (csvFormatType)
    {
        case CSVFormatType::Default:
            FALLTHROUGH;
        case CSVFormatType::Vector:
            FALLTHROUGH;
        case CSVFormatType::Key:
        {
            return GenerateDefaultContainerDetailDefinition();
        }
        break;
        case CSVFormatType::TreeMap:
            FALLTHROUGH;
        case CSVFormatType::HashMap:
        {
            return GenerateMapContainerDetailDefinition();
        }
        break;
        default:
            break;
    }

    return String{};
}

System::String CoreTools::CSVGenerateGetFunctionDefinition::GenerateDefaultContainerDetailDefinition() const
{
    const auto nameSpace = csvHead.GetNameSpace();

    auto content = SYSTEM_TEXT("template <typename Function>\n"s);
    content += nameSpace;
    content += g_DoubleColon;
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("Container::Const");
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("BaseSharedPtr ");
    content += nameSpace;
    content += g_DoubleColon;
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("Container::GetFirst");
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("(Function function) const\n");
    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += g_UserClassIsValidConst9;
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += SYSTEM_TEXT("const auto iter = std::find_if("s);
    content += StringConversion::ToFirstLetterLower(csvHead.GetCSVClassName());
    content += SYSTEM_TEXT(".cbegin(), "s);
    content += StringConversion::ToFirstLetterLower(csvHead.GetCSVClassName());
    content += SYSTEM_TEXT(".cend(), function);\n"s);
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += SYSTEM_TEXT("if (iter != "s);
    content += StringConversion::ToFirstLetterLower(csvHead.GetCSVClassName());
    content += SYSTEM_TEXT(".cend())\n"s);
    content += g_Indentation;
    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("return *iter;\n"s);
    content += g_Indentation;
    content += g_FunctionEndBrackets;

    content += g_NewlineCharacter;
    content += g_Indentation;
    content += SYSTEM_TEXT("THROW_EXCEPTION(SYSTEM_TEXT(\""s);
    content += StringConversion::ToFirstLetterLower(csvHead.GetCSVClassName());
    content += SYSTEM_TEXT("表未找到满足条件的配置信息。\"s));\n"s);
    content += g_FunctionEndBrackets;

    content += g_NewlineCharacter;

    content += SYSTEM_TEXT("template <typename Function>\n"s);
    content += nameSpace;
    content += g_DoubleColon;
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("Container::Container ");
    content += nameSpace;
    content += g_DoubleColon;
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("Container::Get");
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("(Function function) const\n");
    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += g_UserClassIsValidConst9;
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += SYSTEM_TEXT("Container result{};\n"s);
    content += g_NewlineCharacter;
    content += g_Indentation;
    content += SYSTEM_TEXT("for (const auto& value : "s);
    content += StringConversion::ToFirstLetterLower(csvHead.GetCSVClassName());
    content += SYSTEM_TEXT(")\n"s);

    content += g_Indentation;
    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("if (function(value))\n"s);
    content += g_Indentation;
    content += g_Indentation;
    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("result.emplace_back(value);\n"s);
    content += g_Indentation;
    content += g_Indentation;
    content += g_FunctionEndBrackets;
    content += g_Indentation;
    content += g_FunctionEndBrackets;

    content += g_NewlineCharacter;
    content += g_Indentation;
    content += SYSTEM_TEXT("return result;\n"s);
    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateGetFunctionDefinition::GenerateMapContainerDetailDefinition() const
{
    const auto nameSpace = csvHead.GetNameSpace();

    auto content = SYSTEM_TEXT("template <typename Function>\n"s);
    content += nameSpace;
    content += g_DoubleColon;
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("Container::Const");
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("SharedPtr ");
    content += nameSpace;
    content += g_DoubleColon;
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("Container::GetFirst");
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("(Function function) const\n");
    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += g_UserClassIsValidConst9;
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += SYSTEM_TEXT("for (const auto& value : "s);
    content += StringConversion::ToFirstLetterLower(csvHead.GetCSVClassName());
    content += SYSTEM_TEXT(")\n"s);

    content += g_Indentation;
    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("if (function(value.second))\n"s);
    content += g_Indentation;
    content += g_Indentation;
    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("return value.second;\n"s);
    content += g_Indentation;
    content += g_Indentation;
    content += g_FunctionEndBrackets;
    content += g_Indentation;
    content += g_FunctionEndBrackets;

    content += g_NewlineCharacter;
    content += g_Indentation;
    content += SYSTEM_TEXT("THROW_EXCEPTION(SYSTEM_TEXT(\""s);
    content += StringConversion::ToFirstLetterLower(csvHead.GetCSVClassName());
    content += SYSTEM_TEXT("表未找到满足条件的配置信息。\"s));\n"s);
    content += g_FunctionEndBrackets;

    content += g_NewlineCharacter;

    content += SYSTEM_TEXT("template <typename Function>\n"s);
    content += nameSpace;
    content += g_DoubleColon;
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("Container::Container ");
    content += nameSpace;
    content += g_DoubleColon;
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("Container::Get");
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("(Function function) const\n");
    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += g_UserClassIsValidConst9;
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += SYSTEM_TEXT("Container result{};\n"s);
    content += g_Indentation;
    content += SYSTEM_TEXT("for (const auto& value : "s);
    content += StringConversion::ToFirstLetterLower(csvHead.GetCSVClassName());
    content += SYSTEM_TEXT(")\n"s);

    content += g_Indentation;
    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("if (function(value.second))\n"s);
    content += g_Indentation;
    content += g_Indentation;
    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("result.emplace_back(value.second);\n"s);
    content += g_Indentation;
    content += g_Indentation;
    content += g_FunctionEndBrackets;
    content += g_Indentation;
    content += g_FunctionEndBrackets;

    content += g_NewlineCharacter;
    content += g_Indentation;
    content += SYSTEM_TEXT("return result;\n"s);

    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateGetFunctionDefinition::GenerateStringCastEnumDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto nameSpace = csvHead.GetNameSpace();
    const auto className = csvHead.GetCSVClassName() + suffix;

    auto content = SYSTEM_TEXT("template <>\n"s);

    content += SYSTEM_TEXT("NODISCARD "s);
    content += nameSpace;
    content += g_DoubleColon;
    content += className;
    content += SYSTEM_TEXT(" CoreTools::CSVRow::StringCastEnum<"s);
    content += nameSpace;
    content += g_DoubleColon;
    content += className;
    content += SYSTEM_TEXT(">(const String& describe) const\n"s);

    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += SYSTEM_TEXT("CORE_TOOLS_CLASS_IS_VALID_CONST_9;\n"s);
    ;
    content += g_NewlineCharacter;
    content += g_Indentation;
    content += SYSTEM_TEXT("return CSVConfigure::StringCast");
    content += className;
    content += SYSTEM_TEXT("(describe);\n"s);
    content += g_FunctionEndBrackets;

    content += g_NewlineCharacter;

    return content;
}

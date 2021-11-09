///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/11/03 17:01)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateDefaultFunctionDefinition.h"
#include "CSVGenerateHelper.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVConstant.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"

using namespace std::literals;
using namespace CoreTools::TextParsing;

CoreTools::CSVGenerateDefaultFunctionDefinition::CSVGenerateDefaultFunctionDefinition(const CSVHead& csvHead, const String& suffix)
    : csvHead{ csvHead }, suffix{ suffix }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CSVGenerateDefaultFunctionDefinition)

System::String CoreTools::CSVGenerateDefaultFunctionDefinition::GenerateBaseDefaultFunctionDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto nameSpace = csvHead.GetNameSpace();
    const auto className = csvHead.GetCSVClassName() + suffix;

    auto content = nameSpace;
    content += g_DoubleColon;
    content += className;
    content += g_DoubleColon;
    content += className;
    content += SYSTEM_TEXT("(int key) noexcept\n"s);

    content += g_Indentation;
    content += SYSTEM_TEXT(": key{ key }\n"s);
    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += g_UserSelfClassIsValid9;
    content += g_FunctionEndBrackets;

    content += g_NewlineCharacter;

    content += SYSTEM_TEXT("CLASS_INVARIANT_STUB_DEFINE("s);
    content += nameSpace;
    content += SYSTEM_TEXT(", "s);
    content += className;
    content += SYSTEM_TEXT(")\n"s);
    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateDefaultFunctionDefinition::GenerateChildDefaultFunctionDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto nameSpace = csvHead.GetNameSpace();
    const auto className = csvHead.GetCSVClassName() + suffix;

    auto content = nameSpace;
    content += g_DoubleColon;
    content += className;
    content += g_DoubleColon;
    content += className;
    content += SYSTEM_TEXT("(const CoreTools::CSVRow& csvRow)\n"s);

    content += g_Indentation;
    content += SYSTEM_TEXT(": ParentType{},\n"s);

    const auto count = csvHead.GetCount();
    for (auto index = 0; index < count; ++index)
    {
        content += GenerateMemberDefinition(index, index == count - 1);
    }

    content += g_FunctionBeginBrackets;

    if (csvHead.HasScope())
    {
        content += g_Indentation;
        content += SYSTEM_TEXT("Checking();\n"s);
        content += g_NewlineCharacter;
        content += g_Indentation;
        content += g_UserSelfClassIsValid1;
    }
    else
    {
        content += g_Indentation;
        content += g_UserSelfClassIsValid9;
    }

    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    if (csvHead.HasScope())
    {
        content += GenerateCheckingFunctionDefinition();
    }
    else
    {
        content += GenerateNoCheckingFunctionDefinition();
    }

    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateDefaultFunctionDefinition::GenerateMemberDefinition(int index, bool isEnd) const
{
    const auto dataType = csvHead.GetDataType(index);

    String getFunctionName{};
    if (dataType == CSVDataType::Enum || dataType == CSVDataType::EnumArray)
    {
        getFunctionName = SYSTEM_TEXT("GetEnum<"s) + csvHead.GetEnumTypeName(index) + SYSTEM_TEXT(">"s);
    }
    else
    {
        getFunctionName = CSVTypeConversion::GetFunctionName(dataType);
    }

    auto variableName = csvHead.GetVariableName(index);
    auto lowerVariableName = StringConversion::ToFirstLetterLower(variableName);

    String content{ g_MemberIndentation };
    content += lowerVariableName;
    content += SYSTEM_TEXT("{ csvRow."s);
    content += getFunctionName;
    content += SYSTEM_TEXT("(SYSTEM_TEXT(\""s);
    content += lowerVariableName;
    content += SYSTEM_TEXT("\"s)) }"s);

    if (!isEnd)
    {
        content += g_Comma;
    }

    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateDefaultFunctionDefinition::GenerateCheckingFunctionDefinition() const
{
    const auto nameSpace = csvHead.GetNameSpace();
    const auto className = csvHead.GetCSVClassName() + suffix;

    auto content = SYSTEM_TEXT("void "s);

    content += nameSpace;
    content += g_DoubleColon;
    content += className;
    content += g_DoubleColon;
    content += SYSTEM_TEXT("Checking()\n"s);
    content += g_FunctionBeginBrackets;

    const auto count = csvHead.GetCount();
    for (auto index = 0; index < count; ++index)
    {
        content += GenerateCheckingMemberDefinition(index, index == 0);
    }

    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    content += SYSTEM_TEXT("#ifdef OPEN_CLASS_INVARIANT\n"s);
    content += g_NewlineCharacter;

    content += SYSTEM_TEXT("bool "s);
    content += nameSpace;
    content += g_DoubleColon;
    content += className;
    content += g_DoubleColon;
    content += SYSTEM_TEXT("IsValid() const noexcept\n"s);

    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += SYSTEM_TEXT("if (ParentType::IsValid() &&\n"s);

    for (auto index = 0; index < count; ++index)
    {
        content += GenerateIsValidMemberDefinition(index, index == 0);
    }

    content += g_RightBracket;

    content += g_Indentation;
    content += g_FunctionBeginBrackets;

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("return true;\n"s);

    content += g_Indentation;
    content += g_FunctionEndBrackets;

    content += g_Indentation;
    content += SYSTEM_TEXT("else\n"s);

    content += g_Indentation;
    content += g_FunctionBeginBrackets;

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("return false;\n"s);

    content += g_Indentation;
    content += g_FunctionEndBrackets;

    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    content += SYSTEM_TEXT("#endif  // OPEN_CLASS_INVARIANT\n"s);

    return content;
}

System::String CoreTools::CSVGenerateDefaultFunctionDefinition::GenerateCheckingMemberDefinition(int index, bool isBegin) const
{
    String content{};

    const auto scope = csvHead.GetScope(index);

    if (!scope.empty())
    {
        if (isBegin)
        {
            content += g_NewlineCharacter;
        }

        const auto variableName = csvHead.GetVariableName(index);

        content += g_Indentation;
        content += SYSTEM_TEXT("if (!(");
        content += csvHead.GetScopeExpression(index);
        content += SYSTEM_TEXT("))\n"s);

        content += g_Indentation;
        content += g_FunctionBeginBrackets;

        content += g_Indentation;
        content += g_Indentation;
        content += SYSTEM_TEXT("THROW_EXCEPTION(SYSTEM_TEXT(\""s);
        content += variableName;
        content += SYSTEM_TEXT(" 数据校验失败。\"s));\n"s);

        content += g_Indentation;
        content += g_FunctionEndBrackets;
    }

    return content;
}

System::String CoreTools::CSVGenerateDefaultFunctionDefinition::GenerateIsValidMemberDefinition(int index, bool isBegin) const
{
    String content{};

    const auto scope = csvHead.GetScope(index);

    if (!scope.empty())
    {
        if (isBegin)
        {
            content += SYSTEM_TEXT(" &&\n"s);
        }

        content += g_Indentation;
        content += g_Indentation;
        content += SYSTEM_TEXT("(");
        content += csvHead.GetScopeExpression(index);
        content += SYSTEM_TEXT(")"s);
    }

    return content;
}

System::String CoreTools::CSVGenerateDefaultFunctionDefinition::GenerateNoCheckingFunctionDefinition() const
{
    const auto nameSpace = csvHead.GetNameSpace();
    const auto className = csvHead.GetCSVClassName() + suffix;

    auto content = SYSTEM_TEXT("CLASS_INVARIANT_STUB_DEFINE("s);

    content += nameSpace;
    content += SYSTEM_TEXT(", "s);
    content += className;
    content += g_RightBracket;

    return content;
}

System::String CoreTools::CSVGenerateDefaultFunctionDefinition::GenerateDefaultFunctionDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto nameSpace = csvHead.GetNameSpace();
    const auto className = csvHead.GetCSVClassName() + suffix;

    auto content = nameSpace;
    content += g_DoubleColon;
    content += className;
    content += g_DoubleColon;
    content += className;
    content += SYSTEM_TEXT("(const CoreTools::CSVRow& csvRow)\n"s);

    content += g_Indentation;
    content += SYSTEM_TEXT(": "s);

    const auto count = csvHead.GetCount();
    for (auto index = 0; index < count; ++index)
    {
        content += GenerateCheckingMemberDefinition(index, GetPoistionType(index, count));
    }

    content += g_FunctionBeginBrackets;

    if (csvHead.HasScope())
    {
        content += g_Indentation;
        content += SYSTEM_TEXT("Checking();\n"s);
        content += g_NewlineCharacter;
        content += g_Indentation;
        content += g_UserSelfClassIsValid1;
    }
    else
    {
        content += g_Indentation;
        content += g_UserSelfClassIsValid9;
    }

    content += g_FunctionEndBrackets;

    content += g_NewlineCharacter;

    if (csvHead.HasScope())
    {
        content += GenerateCheckingFunctionDefinition();
    }
    else
    {
        content += GenerateNoCheckingFunctionDefinition();
    }

    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateDefaultFunctionDefinition::GenerateCheckingMemberDefinition(int index, CSVPoistionType csvPoistionType) const
{
    const auto dataType = csvHead.GetDataType(index);
    String getFunctionName{};
    if (dataType == CSVDataType::Enum || dataType == CSVDataType::EnumArray)
    {
        getFunctionName = SYSTEM_TEXT("GetEnum<"s) + csvHead.GetEnumTypeName(index) + SYSTEM_TEXT(">"s);
    }
    else
    {
        getFunctionName = CSVTypeConversion::GetFunctionName(dataType);
    }

    auto variableName = csvHead.GetVariableName(index);
    variableName = StringConversion::ToFirstLetterLower(variableName);

    String content{};
    if (csvPoistionType != CSVPoistionType::Begin)
    {
        content += g_MemberIndentation;
    }

    content += variableName;
    content += SYSTEM_TEXT("{ csvRow."s);
    content += getFunctionName;
    content += SYSTEM_TEXT("(SYSTEM_TEXT(\""s);
    content += variableName;
    content += SYSTEM_TEXT("\"s)) }"s);

    if (csvPoistionType != CSVPoistionType::End)
    {
        content += g_Comma;
    }

    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateDefaultFunctionDefinition::GenerateContainerDefaultFunctionDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto nameSpace = csvHead.GetNameSpace();
    const auto className = csvHead.GetCSVClassName() + suffix;
    const auto lowerClassName = StringConversion::ToFirstLetterLower(csvHead.GetCSVClassName());

    auto content = nameSpace;
    content += g_DoubleColon;
    content += className;
    content += g_DoubleColon;
    content += className;
    content += SYSTEM_TEXT("(const CoreTools::CSVContent& csvContent)\n"s);

    content += g_Indentation;
    content += SYSTEM_TEXT(": "s);
    content += lowerClassName;
    content += SYSTEM_TEXT("{}\n"s);
    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += SYSTEM_TEXT("Parsing(csvContent);\n"s);
    content += g_NewlineCharacter;
    content += g_Indentation;
    content += g_UserSelfClassIsValid9;
    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    content += SYSTEM_TEXT("void "s);
    content += nameSpace;
    content += g_DoubleColon;
    content += className;
    content += SYSTEM_TEXT("::Parsing(const CoreTools::CSVContent& csvContent)\n"s);

    content += g_FunctionBeginBrackets;
    content += g_Indentation;
    content += SYSTEM_TEXT("const auto size = csvContent.GetCount();\n"s);

    content += GenerateContainerAddDataDefinition();

    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    content += SYSTEM_TEXT("CLASS_INVARIANT_STUB_DEFINE(");
    content += nameSpace;
    content += SYSTEM_TEXT(", ");
    content += className;
    content += g_RightBracket;

    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateDefaultFunctionDefinition::GenerateContainerAddDataDefinition() const
{
    const auto lowerClassName = StringConversion::ToFirstLetterLower(csvHead.GetCSVClassName());

    String content{};
    const auto csvFormatType = csvHead.GetCSVFormatType();

    switch (csvFormatType)
    {
        case CSVFormatType::Default:
            FALLTHROUGH;
        case CSVFormatType::Key:
        {
            content += GenerateDefaultContainerAddDataDefinition();
        }
        break;
        case CSVFormatType::Vector:
        {
            content += GenerateVectorContainerAddDataDefinition();
        }
        break;
        case CSVFormatType::TreeMap:
            FALLTHROUGH;
        case CSVFormatType::HashMap:
        {
            content += GenerateMapContainerAddDataDefinition();
        }
        break;
        case CSVFormatType::Unique:
        {
            content += GenerateUniqueContainerAddDataDefinition();
        }
        break;
        default:
            break;
    }

    return content;
}

System::String CoreTools::CSVGenerateDefaultFunctionDefinition::GenerateDefaultContainerAddDataDefinition() const
{
    const auto lowerClassName = StringConversion::ToFirstLetterLower(csvHead.GetCSVClassName());

    String content{ g_Indentation };

    content += SYSTEM_TEXT("for (auto i = 0; i < size; ++i)\n");

    content += g_Indentation;
    content += g_FunctionBeginBrackets;

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("CoreTools::CSVRow csvRow{ csvContent.GetCSVHead(), csvContent.GetContent(i) };\n"s);
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += g_Indentation;
    content += lowerClassName;
    content += SYSTEM_TEXT(".emplace_back(make_shared<");
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT(">(csvRow));\n");

    content += g_Indentation;
    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += SYSTEM_TEXT("std::sort(");
    content += lowerClassName;
    content += SYSTEM_TEXT(".begin(), ");
    content += lowerClassName;
    content += SYSTEM_TEXT(".end(), [](const auto& lhs, const auto& rhs) noexcept {\n"s);

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("return (*lhs).GetKey() < (*rhs).GetKey();\n"s);

    content += g_Indentation;
    content += SYSTEM_TEXT("});\n");

    content += g_NewlineCharacter;
    content += g_Indentation;
    content += SYSTEM_TEXT("auto iter = unique(");
    content += lowerClassName;
    content += SYSTEM_TEXT(".begin(), ");
    content += lowerClassName;
    content += SYSTEM_TEXT(".end(), [](const auto& lhs, const auto& rhs) noexcept {\n"s);

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("return (*lhs).GetKey() == (*rhs).GetKey();\n"s);

    content += g_Indentation;
    content += SYSTEM_TEXT("});\n");
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += SYSTEM_TEXT("if (iter != ");
    content += lowerClassName;
    content += SYSTEM_TEXT(".cend())\n");

    content += g_Indentation;
    content += g_FunctionBeginBrackets;

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("LOG_SINGLETON_ENGINE_APPENDER(Warn, User)\n");

    content += g_Indentation;
    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("<< SYSTEM_TEXT(\"");
    content += lowerClassName;
    content += SYSTEM_TEXT("表存在重复主键。\")\n");

    content += g_Indentation;
    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("<< LOG_SINGLETON_TRIGGER_ASSERT;\n");
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += g_Indentation;
    content += lowerClassName;
    content += SYSTEM_TEXT(".erase(iter, ");
    content += lowerClassName;
    content += SYSTEM_TEXT(".end());\n");

    content += g_Indentation;
    content += g_FunctionEndBrackets;

    return content;
}

System::String CoreTools::CSVGenerateDefaultFunctionDefinition::GenerateVectorContainerAddDataDefinition() const
{
    const auto lowerClassName = StringConversion::ToFirstLetterLower(csvHead.GetCSVClassName());

    String content{ g_Indentation };

    content += SYSTEM_TEXT("for (auto i = 0; i < size; ++i)\n");

    content += g_Indentation;
    content += g_FunctionBeginBrackets;

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("CoreTools::CSVRow csvRow{ csvContent.GetCSVHead(), csvContent.GetContent(i) };\n"s);
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += g_Indentation;
    content += lowerClassName;
    content += SYSTEM_TEXT(".emplace_back(make_shared<");
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT(">(csvRow));\n");

    content += g_Indentation;
    content += g_FunctionEndBrackets;
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
    content += SYSTEM_TEXT("std::sort(");
    content += lowerClassName;
    content += SYSTEM_TEXT(".begin(), ");
    content += lowerClassName;
    content += SYSTEM_TEXT(".end(), function);\n");
    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateDefaultFunctionDefinition::GenerateMapContainerAddDataDefinition() const
{
    const auto lowerClassName = StringConversion::ToFirstLetterLower(csvHead.GetCSVClassName());

    String content{ g_Indentation };

    content += SYSTEM_TEXT("for (auto i = 0; i < size; ++i)\n");

    content += g_Indentation;
    content += g_FunctionBeginBrackets;

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("CoreTools::CSVRow csvRow{ csvContent.GetCSVHead(), csvContent.GetContent(i) };\n"s);
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("auto ");
    content += lowerClassName;
    content += SYSTEM_TEXT("Base = make_shared<");
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT(">(csvRow);\n");
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("if (!"s);
    content += lowerClassName;
    content += SYSTEM_TEXT(".emplace("s);
    content += lowerClassName;
    content += SYSTEM_TEXT("Base->GetKey(), "s);
    content += lowerClassName;
    content += SYSTEM_TEXT("Base).second)\n"s);

    content += g_Indentation;
    content += g_Indentation;
    content += g_FunctionBeginBrackets;
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("LOG_SINGLETON_ENGINE_APPENDER(Warn, User)\n");

    content += g_Indentation;
    content += g_Indentation;
    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("<< SYSTEM_TEXT(\"");
    content += lowerClassName;
    content += SYSTEM_TEXT("表存在重复主键：\")\n");

    content += g_Indentation;
    content += g_Indentation;
    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("<< ");
    content += lowerClassName;
    content += SYSTEM_TEXT("Base->GetKey()\n");

    content += g_Indentation;
    content += g_Indentation;
    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("<< LOG_SINGLETON_TRIGGER_ASSERT;\n");

    content += g_Indentation;
    content += g_Indentation;
    content += g_FunctionEndBrackets;

    content += g_Indentation;
    content += g_FunctionEndBrackets;

    return content;
}

System::String CoreTools::CSVGenerateDefaultFunctionDefinition::GenerateUniqueContainerAddDataDefinition() const
{
    const auto lowerClassName = StringConversion::ToFirstLetterLower(csvHead.GetCSVClassName());

    String content{ g_Indentation };

    content += SYSTEM_TEXT("if (size == 0)\n"s);

    content += g_Indentation;
    content += g_FunctionBeginBrackets;

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("THROW_EXCEPTION(SYSTEM_TEXT(\"");
    content += lowerClassName;
    content += SYSTEM_TEXT("表为空。\"s));\n"s);

    content += g_Indentation;
    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += SYSTEM_TEXT("if (1 < size)\n"s);

    content += g_Indentation;
    content += g_FunctionBeginBrackets;

    content += g_Indentation;
    content += g_Indentation; 
    content += SYSTEM_TEXT("LOG_SINGLETON_ENGINE_APPENDER(Warn, User)\n");

    content += g_Indentation;
    content += g_Indentation;
    content += g_Indentation; 
    content += SYSTEM_TEXT("<< SYSTEM_TEXT(\"");
    content += lowerClassName;
    content += SYSTEM_TEXT("表不是唯一的\")\n"s);

    content += g_Indentation;
    content += g_Indentation;
    content += g_Indentation; 
    content += SYSTEM_TEXT("<< LOG_SINGLETON_TRIGGER_ASSERT;\n");

    content += g_Indentation;
    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += SYSTEM_TEXT("CoreTools::CSVRow csvRow{ csvContent.GetCSVHead(), csvContent.GetContent(0) };\n"s);

    content += g_NewlineCharacter;

    content += g_Indentation;
    content += lowerClassName;
    content += SYSTEM_TEXT(" = make_shared<");
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT(">(csvRow);\n");

    return content;
}

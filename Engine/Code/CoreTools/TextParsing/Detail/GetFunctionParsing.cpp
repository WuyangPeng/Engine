///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 22:25)

#include "CoreTools/CoreToolsExport.h"

#include "GetFunctionParsing.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

using namespace std::literals;

CoreTools::GetFunctionParsing::GetFunctionParsing(const CSVHead& csvHead, const String& keyTypeDescribe)
    : ParentType{ 2 }, m_CSVHead{ csvHead }, keyTypeDescribe{ keyTypeDescribe }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, GetFunctionParsing)

System::String CoreTools::GetFunctionParsing::GetKeyTypeDescribe() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return keyTypeDescribe;
}

CoreTools::CSVHead CoreTools::GetFunctionParsing::GetCSVHead() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_CSVHead;
}

int CoreTools::GetFunctionParsing::GetCSVHeadCount() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_CSVHead.GetCount();
}

System::String CoreTools::GetFunctionParsing::GenerateGetKeyFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateKeyFunctionStatement();

    content += GenerateFunctionBeginBrackets();
    content += GenerateReturnKey();
    content += GenerateFunctionEndBrackets();
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::GetFunctionParsing::GenerateKeyFunctionStatement() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += TextParsing::g_Nodiscard;
    content += TextParsing::g_ConstexprStatic;
    content += GetKeyTypeDescribe();
    content += TextParsing::g_GenerateKey;

    content += GenerateKeyParameter();
    content += TextParsing::g_RightBrackets;
    content += TextParsing::g_Noexcept;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::GetFunctionParsing::GenerateReturnKey() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GenerateIndentation(1);

    content += TextParsing::g_Return;
    content += csvHead.GetKey();
    content += TextParsing::g_SemicolonNewline;

    return content;
}

System::String CoreTools::GetFunctionParsing::GenerateKeyParameter() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();
    const auto result = csvHead.GetKeyName();

    String content{};

    auto index = 0u;
    for (const auto& value : result)
    {
        content += CSVTypeConversion::GetActualType(csvHead.GetDataType(value));
        content += TextParsing::g_Space;
        content += value;

        ++index;
        if (index != result.size())
        {
            content += TextParsing::g_Comma;
            content += TextParsing::g_Space;
        }
    }

    return content;
}

System::String CoreTools::GetFunctionParsing::GenerateCountFunction(const String& functionVariableName, const StringView& beginDescribe, const StringView& endDescribe) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += beginDescribe;
    content += TextParsing::g_Int;
    content += functionVariableName;
    content += endDescribe;

    return content;
}

System::String CoreTools::GetFunctionParsing::GenerateGetValueFunction(const String& valueType, const String& functionVariableName, const StringView& beginDescribe, const StringView& endDescribe) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += beginDescribe;
    content += valueType;
    content += TextParsing::g_Space;
    content += functionVariableName;
    content += endDescribe;

    return content;
}

System::String CoreTools::GetFunctionParsing::GenerateBeginIterFunction(const String& actualType, const String& functionVariableName, const StringView& beginDescribe, const StringView& endDescribe) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += beginDescribe;
    content += actualType;
    content += TextParsing::g_ConstIterator;
    content += functionVariableName;
    content += endDescribe;

    return content;
}

System::String CoreTools::GetFunctionParsing::GenerateEndIterFunction(const String& actualType, const String& functionVariableName, const StringView& beginDescribe, const StringView& endDescribe) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += beginDescribe;
    content += actualType;
    content += TextParsing::g_ConstIterator;
    content += functionVariableName;
    content += endDescribe;

    return content;
}

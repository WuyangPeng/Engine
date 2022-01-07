///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 22:25)

#include "CoreTools/CoreToolsExport.h"

#include "GetFunctionDefinitionParsing.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::GetFunctionDefinitionParsing::GetFunctionDefinitionParsing(const CSVHead& csvHead, const String& className, const String& keyTypeDescribe)
    : ParentType{ 0 }, m_CSVHead{ csvHead }, className{ className }, keyTypeDescribe{ keyTypeDescribe }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, GetFunctionDefinitionParsing)

System::String CoreTools::GetFunctionDefinitionParsing::GetCSVClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return className;
}

System::String CoreTools::GetFunctionDefinitionParsing::GetKeyTypeDescribe() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return keyTypeDescribe;
}

CoreTools::CSVHead CoreTools::GetFunctionDefinitionParsing::GetCSVHead() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_CSVHead;
}

int CoreTools::GetFunctionDefinitionParsing::GetCSVHeadCount() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_CSVHead.GetCount();
}

System::String CoreTools::GetFunctionDefinitionParsing::GenerateReturnKey(int addIndentationCount) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(addIndentationCount);

    content += TextParsing::g_ReturnKey;

    return content;
}

System::String CoreTools::GetFunctionDefinitionParsing::GenerateGetFunctionArrayCount(const String& functionVariableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GenerateIndentation();

    content += TextParsing::g_Int;
    content += csvHead.GetNameSpace();
    content += TextParsing::g_DoubleColon;
    content += GetCSVClassName();
    content += TextParsing::g_DoubleColon;
    content += functionVariableName;
    content += TextParsing::g_CountConst;

    return content;
}

System::String CoreTools::GetFunctionDefinitionParsing::GenerateGetFunctionArrayConstIterator(const String& actualType, const String& functionVariableName, const StringView& endDescribe) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = actualType;
    content += TextParsing::g_ConstIterator;
    content += csvHead.GetNameSpace();
    content += TextParsing::g_DoubleColon;
    content += GetCSVClassName();
    content += TextParsing::g_DoubleColon;
    content += functionVariableName;
    content += endDescribe;

    return content;
}

System::String CoreTools::GetFunctionDefinitionParsing::GenerateLambdaFunctionReturnIter() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(2);

    content += TextParsing::g_ReturnIter;

    return content;
}

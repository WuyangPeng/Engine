///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 16:52)

#include "CoreTools/CoreToolsExport.h"

#include "GetFunctionDefinitionParsing.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::GetFunctionDefinitionParsing::GetFunctionDefinitionParsing(CSVHead csvHead, String className, String keyTypeDescribe) noexcept
    : ParentType{ 0 }, className{ std::move(className) }, keyTypeDescribe{ std::move(keyTypeDescribe) }, head{ std::move(csvHead) }
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

    return head;
}

int CoreTools::GetFunctionDefinitionParsing::GetCSVHeadCount() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return head.GetCount();
}

System::String CoreTools::GetFunctionDefinitionParsing::GenerateReturnKey(int addIndentationCount) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(addIndentationCount);

    content += TextParsing::gReturnKey;

    return content;
}

System::String CoreTools::GetFunctionDefinitionParsing::GenerateGetFunctionArrayCount(const String& functionVariableName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GenerateIndentation();

    content += TextParsing::gInt;
    content += TextParsing::gSpace;
    content += csvHead.GetNameSpace();
    content += TextParsing::gDoubleColon;
    content += GetCSVClassName();
    content += TextParsing::gDoubleColon;
    content += functionVariableName;
    content += TextParsing::gCountConst;

    return content;
}

System::String CoreTools::GetFunctionDefinitionParsing::GenerateGetFunctionArrayConstIterator(const String& actualType, const String& functionVariableName, const StringView& endDescribe) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = actualType;
    content += SYSTEM_TEXT("ConstIter");
    content += TextParsing::gSpace;
    content += csvHead.GetNameSpace();
    content += TextParsing::gDoubleColon;
    content += GetCSVClassName();
    content += TextParsing::gDoubleColon;
    content += functionVariableName;
    content += endDescribe;

    return content;
}

System::String CoreTools::GetFunctionDefinitionParsing::GenerateLambdaFunctionReturnIter() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(2);

    content += TextParsing::gReturnIter;

    return content;
}

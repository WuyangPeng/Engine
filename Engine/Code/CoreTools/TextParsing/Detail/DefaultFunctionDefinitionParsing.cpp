///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 16:54)

#include "CoreTools/CoreToolsExport.h"

#include "CSV/CSVGenerateHelper.h"
#include "DefaultFunctionDefinitionParsing.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::DefaultFunctionDefinitionParsing::DefaultFunctionDefinitionParsing(const CSVHead& csvHead, const String& className)
    : ParentType{ 0 }, head{ csvHead }, className{ className }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, DefaultFunctionDefinitionParsing)

System::String CoreTools::DefaultFunctionDefinitionParsing::GenerateConstructor(StringView parameter) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = head.GetNameSpace();

    content += TextParsing::gDoubleColon;
    content += className;
    content += TextParsing::gDoubleColon;
    content += className;
    content += parameter;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::DefaultFunctionDefinitionParsing::GenerateClassInvariantStubDefine() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::gClassInvariantStubDefine };

    content += head.GetNameSpace();
    content += TextParsing::gComma;
    content += TextParsing::gSpace;
    content += className;
    content += TextParsing::gRightBrackets;
    content += TextParsing::gNewlineCharacter;

    return content;
}

CoreTools::CSVHead CoreTools::DefaultFunctionDefinitionParsing::GetCSVHead() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return head;
}

int CoreTools::DefaultFunctionDefinitionParsing::GetCSVHeadCount() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return head.GetCount();
}

bool CoreTools::DefaultFunctionDefinitionParsing::HasCSVHeadScope() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return head.HasScope();
}

System::String CoreTools::DefaultFunctionDefinitionParsing::GetCSVClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return className;
}

System::String CoreTools::DefaultFunctionDefinitionParsing::GetNameSpace() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return head.GetNameSpace();
}

///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:58)

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
    : ParentType{ 0 }, m_CSVHead{ csvHead }, className{ className }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, DefaultFunctionDefinitionParsing)

System::String CoreTools::DefaultFunctionDefinitionParsing::GenerateConstructor(StringView parameter) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = m_CSVHead.GetNameSpace();

    content += TextParsing::g_DoubleColon;
    content += className;
    content += TextParsing::g_DoubleColon;
    content += className;
    content += parameter;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::DefaultFunctionDefinitionParsing::GenerateClassInvariantStubDefine() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::g_ClassInvariantStubDefine };

    content += m_CSVHead.GetNameSpace();
    content += TextParsing::g_Comma;
    content += TextParsing::g_Space;
    content += className;
    content += TextParsing::g_RightBracket;

    return content;
}

CoreTools::CSVHead CoreTools::DefaultFunctionDefinitionParsing::GetCSVHead() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_CSVHead;
}

int CoreTools::DefaultFunctionDefinitionParsing::GetCSVHeadCount() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_CSVHead.GetCount();
}

bool CoreTools::DefaultFunctionDefinitionParsing::HasCSVHeadScope() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_CSVHead.HasScope();
}

System::String CoreTools::DefaultFunctionDefinitionParsing::GetCSVClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return className;
}

System::String CoreTools::DefaultFunctionDefinitionParsing::GetNameSpace() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_CSVHead.GetNameSpace();
}

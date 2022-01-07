///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 22:28)

#include "CoreTools/CoreToolsExport.h"

#include "StringCastEnumDefinitionParsing.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::StringCastEnumDefinitionParsing::StringCastEnumDefinitionParsing(const CSVHead& csvHead, const String& className)
    : ParentType{ 0 }, m_CSVHead{ csvHead }, className{ className }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, StringCastEnumDefinitionParsing)

System::String CoreTools::StringCastEnumDefinitionParsing::GenerateStringCastEnumDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateStringCastEnum();

    content += GenerateFunctionBeginBrackets();

    content += GenerateIndentation(1);
    content += TextParsing::g_CoreToolsClassIsValidConst9;
    content += TextParsing::g_NewlineCharacter;
    content += GenerateDescribe();

    content += GenerateFunctionEndBrackets();
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::StringCastEnumDefinitionParsing::GenerateStringCastEnum() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto nameSpace = m_CSVHead.GetNameSpace();

    auto content = GenerateIndentation();

    content += TextParsing::g_TemplateSpecialization;
    content += TextParsing::g_Nodiscard;
    content += nameSpace;
    content += TextParsing::g_DoubleColon;
    content += className;
    content += TextParsing::g_CSVRowStringCastEnum;
    content += nameSpace;
    content += TextParsing::g_DoubleColon;
    content += className;
    content += TextParsing::g_DescribeConst;

    return content;
}

System::String CoreTools::StringCastEnumDefinitionParsing::GenerateDescribe() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto nameSpace = m_CSVHead.GetNameSpace();

    auto content = GenerateIndentation(1);

    content += TextParsing::g_Return;
    content += nameSpace;
    content += TextParsing::g_DoubleColon;
    content += TextParsing::g_StringCast;
    content += className;
    content += TextParsing::g_LeftBrackets;
    content += TextParsing::g_EnumDescribe;
    content += TextParsing::g_RightBrackets;
    content += TextParsing::g_SemicolonNewline;

    return content;
}

///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 22:27)

#include "CoreTools/CoreToolsExport.h"

#include "MapContainerMemberParsing.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::MapContainerMemberParsing::MapContainerMemberParsing(const CSVHead& csvHead) noexcept
    : ParentType{ csvHead }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, MapContainerMemberParsing)

System::String CoreTools::MapContainerMemberParsing::GenerateMember() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();
    content += TextParsing::g_Private;

    content += GenerateIndentation(1);
    content += TextParsing::g_MappingContainer;
    content += TextParsing::g_Space;
    content += StringConversion::ToFirstLetterLower(GetCSVClassName());
    content += TextParsing::g_SemicolonNewline;

    content += GenerateIndentation();
    content += TextParsing::g_ClassEndBrackets;
    content += TextParsing::g_FunctionEndBrackets;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

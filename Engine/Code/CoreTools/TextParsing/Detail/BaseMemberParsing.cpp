///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/04 17:09)

#include "CoreTools/CoreToolsExport.h"

#include "BaseMemberParsing.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::BaseMemberParsing::BaseMemberParsing() noexcept
    : ParentType{ 1 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, BaseMemberParsing)

System::String CoreTools::BaseMemberParsing::GenerateBaseMember() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += TextParsing::gPrivate;

    content += GenerateIndentation(1);
    content += TextParsing::gIntKey;

    content += GenerateIndentation();
    content += TextParsing::gClassEndBrackets;
    content += GenerateFunctionEndBrackets(-1);

    content += TextParsing::gNewlineCharacter;

    return content;
}

///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:53)

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

    content += TextParsing::g_Private;

    content += GenerateIndentation(1);
    content += TextParsing::g_IntKey;

    content += GenerateIndentation();
    content += TextParsing::g_ClassEndBrackets;
    content += GenerateFunctionEndBrackets(-1);

    content += TextParsing::g_NewlineCharacter;

    return content;
}

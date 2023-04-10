///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 16:36)

#include "CoreTools/CoreToolsExport.h"

#include "UniqueContainerMemberParsing.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::UniqueContainerMemberParsing::UniqueContainerMemberParsing(const CSVHead& csvHead) noexcept
    : ParentType{ csvHead }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, UniqueContainerMemberParsing)

System::String CoreTools::UniqueContainerMemberParsing::GenerateMember() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = GetCSVClassName();

    auto content = GenerateIndentation();
    content += TextParsing::gPrivate;

    content += GenerateIndentation(1);
    content += TextParsing::gCapitalConst;
    content += className;
    content += TextParsing::gSharedPtr;
    content += TextParsing::gSpace;
    content += StringUtility::ToFirstLetterLower(className);
    content += TextParsing::gSemicolonNewline;

    content += GenerateIndentation();
    content += TextParsing::gClassEndBrackets;
    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    return content;
}

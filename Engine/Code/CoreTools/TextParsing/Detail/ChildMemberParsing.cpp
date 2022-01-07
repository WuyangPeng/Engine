///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:54)

#include "CoreTools/CoreToolsExport.h"

#include "ChildMemberParsing.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::ChildMemberParsing::ChildMemberParsing(const CSVHead& csvHead) noexcept
    : ParentType{ 1 }, csvHead{ csvHead }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ChildMemberParsing)

System::String CoreTools::ChildMemberParsing::GenerateChildMember() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += TextParsing::g_Private;

    content += GenerateMember();

    content += GenerateIndentation();
    content += TextParsing::g_ClassEndBrackets;
    content += TextParsing::g_FunctionEndBrackets;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::ChildMemberParsing::GenerateMember() const
{
    String content{};

    const auto count = csvHead.GetCount();
    for (auto index = 0; index < count; ++index)
    {
        const auto actualType = csvHead.GetActualType(index);
        const auto variableName = csvHead.GetVariableName(index);
        const auto annotation = StringConversion::UTF8ConversionStandard(csvHead.GetAnnotation(index));

        content += GenerateIndentation(1);
        content += actualType;

        content += TextParsing::g_Space;
        content += variableName;
        content += TextParsing::g_SemicolonAnnotation;
        content += annotation;
        content += TextParsing::g_NewlineCharacter;
    }

    return content;
}

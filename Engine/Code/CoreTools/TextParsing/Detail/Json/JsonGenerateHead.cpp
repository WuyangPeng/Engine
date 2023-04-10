///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/08 17:05)

#include "CoreTools/CoreToolsExport.h"

#include "JsonGenerateHead.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::JsonGenerateHead::JsonGenerateHead(JsonHead jsonHead) noexcept
    : jsonHead{ std::move(jsonHead) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, JsonGenerateHead)

System::String CoreTools::JsonGenerateHead::GenerateCoreToolsHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::gCoreToolsHeadFile };
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIncludePrefix;
    content += jsonHead.GetNameSpace();
    content += TextParsing::gFwdHeadFileExtensionName;
    content += TextParsing::gQuotationMarks;
    content += TextParsing::gNewline;

    content += TextParsing::gUnicodeUsing;
    content += TextParsing::gNewlineCharacter;

    if (jsonHead.HasBoolArray())
    {
        content += TextParsing::gDequeInclude;
    }

    if (jsonHead.HasNested())
    {
        content += TextParsing::gMemoryInclude;
    }

    if (jsonHead.HasArray())
    {
        content += TextParsing::gVectorInclude;
    }

    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonGenerateHead::GenerateContainerDetailHead() const
{
    String content{ TextParsing::gIncludePrefix };

    content += jsonHead.GetJsonClassName();
    content += TextParsing::gHeadFileSuffix;

    content += TextParsing::gUserClassInvariantMacro;
    content += TextParsing::gExceptionMacro;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonGenerateHead::GenerateContainerSourceHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = jsonHead.GetJsonClassName();

    String content{ TextParsing::gIncludePrefix };

    content += className;
    content += TextParsing::gHeadFileSuffix;

    content += TextParsing::gNumericCast;
    content += TextParsing::gUserClassInvariantMacro;
    content += TextParsing::gExceptionMacro;
    content += TextParsing::gLogMacro;
    content += TextParsing::gIncludeJsonHead;
    content += TextParsing::gIncludeJsonRow;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gAlgorithmInclude;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gUsingNamespaceLiterals;
    content += TextParsing::gNewlineCharacter;

    return content;
}

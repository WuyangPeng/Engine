///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/10 14:00)

#include "CoreTools/CoreToolsExport.h"

#include "JsonGenerateHead.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

using namespace std::literals;

CoreTools::JsonGenerateHead::JsonGenerateHead(const JsonHead& jsonHead) noexcept
    : jsonHead{ jsonHead }
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
    content += SYSTEM_TEXT("Fwd.h\"\n"s);

    content += TextParsing::gUnicodeUsing;
    content += TextParsing::gNewlineCharacter;

    if (jsonHead.HasBoolArray())
    {
        content += TextParsing::gDeque;
    }

    if (jsonHead.HasNested())
    {
        content += TextParsing::gMemory;
    }

    if (jsonHead.HasArray())
    {
        content += TextParsing::gVector;
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

    auto content = TextParsing::gIncludePrefix.data() + className + TextParsing::gHeadFileSuffix.data();

    content += SYSTEM_TEXT("#include \"System/Helper/PragmaWarning/NumericCast.h\"\n"s);
    content += TextParsing::gUserClassInvariantMacro;
    content += TextParsing::gExceptionMacro;
    content += SYSTEM_TEXT("#include \"CoreTools/Helper/LogMacro.h\"\n"s);
    content += SYSTEM_TEXT("#include \"CoreTools/TextParsing/Json/JsonHead.h\"\n"s);
    content += SYSTEM_TEXT("#include \"CoreTools/TextParsing/Json/JsonRow.h\"\n"s);
    content += TextParsing::gNewlineCharacter;

    content += SYSTEM_TEXT("#include <algorithm>\n"s);
    content += TextParsing::gNewlineCharacter;

    content += SYSTEM_TEXT("using namespace std::literals;\n"s);
    content += TextParsing::gNewlineCharacter;

    return content;
}

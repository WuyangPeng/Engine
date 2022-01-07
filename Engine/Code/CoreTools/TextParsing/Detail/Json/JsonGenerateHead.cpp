///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:44)

#include "CoreTools/CoreToolsExport.h"

#include "JsonGenerateHead.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

using std::vector;
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

    String content{ TextParsing::g_CoreToolsHeadFile };
    content += TextParsing::g_NewlineCharacter;

    content += TextParsing::g_IncludePrefix;
    content += jsonHead.GetNameSpace();
    content += SYSTEM_TEXT("Fwd.h\"\n"s);

    content += TextParsing::g_UnicodeUsing;
    content += TextParsing::g_NewlineCharacter;

    if (jsonHead.HasBoolArray())
    {
        content += TextParsing::g_Deque;
    }

    if (jsonHead.HasNested())
    {
        content += TextParsing::g_Memory;
    }

    if (jsonHead.HasArray())
    {
        content += TextParsing::g_Vector;
    }

    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::JsonGenerateHead::GenerateContainerDetailHead() const
{
    String content{ TextParsing::g_IncludePrefix };

    content += jsonHead.GetJsonClassName();
    content += TextParsing::g_HeadFileSuffix;

    content += TextParsing::g_UserClassInvariantMacro;
    content += TextParsing::g_ExceptionMacro;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::JsonGenerateHead::GenerateContainerSourceHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = jsonHead.GetJsonClassName();

    auto content = TextParsing::g_IncludePrefix.data() + className + TextParsing::g_HeadFileSuffix.data();

    content += SYSTEM_TEXT("#include \"System/Helper/PragmaWarning/NumericCast.h\"\n"s);
    content += TextParsing::g_UserClassInvariantMacro;
    content += TextParsing::g_ExceptionMacro;
    content += SYSTEM_TEXT("#include \"CoreTools/Helper/LogMacro.h\"\n"s);
    content += SYSTEM_TEXT("#include \"CoreTools/TextParsing/Json/JsonHead.h\"\n"s);
    content += SYSTEM_TEXT("#include \"CoreTools/TextParsing/Json/JsonRow.h\"\n"s);
    content += TextParsing::g_NewlineCharacter;

    content += SYSTEM_TEXT("#include <algorithm>\n"s);
    content += TextParsing::g_NewlineCharacter;

    content += SYSTEM_TEXT("using std::make_shared;\n"s);
    content += SYSTEM_TEXT("using namespace std::literals;\n"s);
    content += TextParsing::g_NewlineCharacter;

    return content;
}

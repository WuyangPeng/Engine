///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 22:25)

#include "CoreTools/CoreToolsExport.h"

#include "KeyContainerFunctionParsing.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::KeyContainerFunctionParsing::KeyContainerFunctionParsing(const CSVHead& csvHead, const String& keyTypeDescribe)
    : ParentType{ csvHead, keyTypeDescribe }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, KeyContainerFunctionParsing)

System::String CoreTools::KeyContainerFunctionParsing::GenerateGetFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GenerateBaseGetFirst();

    content += GenerateGetKey();
    content += GenerateBaseGet();
    content += GenerateGetContainer();
    content += GenerateBaseGetFirstTemplate();
    content += GenerateBaseGetTemplate();

    return content;
}

System::String CoreTools::KeyContainerFunctionParsing::GenerateGetKey() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GenerateIndentation();

    content += TextParsing::g_NodiscardConst;
    content += csvHead.GetCSVClassName();
    content += TextParsing::g_Base;
    content += TextParsing::g_GetSharedPtr;
    content += csvHead.GetCSVClassName();
    content += TextParsing::g_LeftBrackets;

    content += GenerateGetKeyName();

    return content;
}

System::String CoreTools::KeyContainerFunctionParsing::GenerateGetKeyName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();
    auto result = csvHead.GetKeyName();

    String content{};

    auto index = 0u;
    for (const auto& value : result)
    {
        content += CSVTypeConversion::GetActualType(csvHead.GetDataType(value));
        content += TextParsing::g_Space;
        content += value;

        ++index;
        if (index != result.size())
        {
            content += TextParsing::g_Comma;
            content += TextParsing::g_Space;
        }
    }

    content += TextParsing::g_ConstSemicolonNewline;

    return content;
}

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/04 16:52)

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

    content += TextParsing::gNodiscardConst;
    content += csvHead.GetCSVClassName();
    content += TextParsing::gBase;
    content += TextParsing::gGetSharedPtr;
    content += csvHead.GetCSVClassName();
    content += TextParsing::gLeftBrackets;

    content += GenerateGetKeyName();

    return content;
}

System::String CoreTools::KeyContainerFunctionParsing::GenerateGetKeyName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();
    const auto result = csvHead.GetKeyName();

    String content{};

    auto index = 0u;
    for (const auto& value : result)
    {
        content += CSVTypeConversion::GetActualType(csvHead.GetDataType(value));
        content += TextParsing::gSpace;
        content += value;

        ++index;
        if (index != result.size())
        {
            content += TextParsing::gComma;
            content += TextParsing::gSpace;
        }
    }

    content += TextParsing::gConstSemicolonNewline;

    return content;
}

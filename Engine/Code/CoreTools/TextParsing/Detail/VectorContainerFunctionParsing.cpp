///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/04 16:36)

#include "CoreTools/CoreToolsExport.h"

#include "VectorContainerFunctionParsing.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::VectorContainerFunctionParsing::VectorContainerFunctionParsing(const CSVHead& csvHead, const String& keyTypeDescribe)
    : ParentType{ csvHead, keyTypeDescribe }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, VectorContainerFunctionParsing)

System::String CoreTools::VectorContainerFunctionParsing::GenerateGetFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GenerateGetFirstByKey();

    content += GenerateGetContainerByKey();
    content += GenerateGetContainer();
    content += GenerateBaseGetFirstTemplate();
    content += GenerateBaseGetTemplate();

    return content;
}

System::String CoreTools::VectorContainerFunctionParsing::GenerateGetFirstByKey() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GenerateIndentation();

    content += TextParsing::gNodiscardConst;
    content += csvHead.GetCSVClassName();
    content += TextParsing::gBase;
    content += TextParsing::gGetFirstSharedPtr;
    content += csvHead.GetCSVClassName();
    content += TextParsing::gLeftBrackets;
    content += GetKeyTypeDescribe();
    content += TextParsing::gKeyConst;

    return content;
}

System::String CoreTools::VectorContainerFunctionParsing::GenerateGetContainerByKey() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GenerateIndentation();

    content += TextParsing::gGetContainer;
    content += csvHead.GetCSVClassName();
    content += TextParsing::gLeftBrackets;
    content += GetKeyTypeDescribe();
    content += TextParsing::gKeyConst;

    return content;
}

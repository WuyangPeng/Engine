///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/04 16:51)

#include "CoreTools/CoreToolsExport.h"

#include "MapContainerFunctionParsing.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::MapContainerFunctionParsing::MapContainerFunctionParsing(const CSVHead& csvHead, const String& keyTypeDescribe)
    : ParentType{ csvHead, keyTypeDescribe }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, MapContainerFunctionParsing)

System::String CoreTools::MapContainerFunctionParsing::GenerateGetFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GenerateGetFirst();

    content += GenerateGet();
    content += GenerateGetMappingContainer();

    content += GenerateIndentation();
    content += SYSTEM_TEXT("NODISCARD int GetContainerSize() const;\n");
    content += TextParsing::gNewlineCharacter;

    content += GenerateGetFirstTemplate();
    content += GenerateGetTemplate();

    return content;
}

System::String CoreTools::MapContainerFunctionParsing::GenerateGetFirst() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GenerateIndentation();

    content += TextParsing::gNodiscardConst;
    content += csvHead.GetCSVClassName();
    content += TextParsing::gGetFirstSharedPtr;
    content += csvHead.GetCSVClassName();
    content += TextParsing::gFunctionConst;
    content += TextParsing::gSemicolonNewline;

    return content;
}

System::String CoreTools::MapContainerFunctionParsing::GenerateGet() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GenerateIndentation();

    content += TextParsing::gNodiscardConst;
    content += csvHead.GetCSVClassName();
    content += TextParsing::gGetSharedPtr;
    content += csvHead.GetCSVClassName();
    content += TextParsing::gLeftBrackets;
    content += GetKeyTypeDescribe();
    content += TextParsing::gKeyConst;

    return content;
}

System::String CoreTools::MapContainerFunctionParsing::GenerateGetFirstTemplate() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GenerateIndentation();

    content += TextParsing::gFunctionTemplate;

    content += GenerateIndentation();
    content += TextParsing::gNodiscardConst;
    content += csvHead.GetCSVClassName();
    content += TextParsing::gGetFirstSharedPtr;
    content += csvHead.GetCSVClassName();
    content += TextParsing::gFunctionParameter;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::MapContainerFunctionParsing::GenerateGetTemplate() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GenerateIndentation();

    content += TextParsing::gFunctionTemplate;

    content += GenerateIndentation();
    content += TextParsing::gGetContainer;
    content += csvHead.GetCSVClassName();
    content += TextParsing::gFunctionParameter;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::MapContainerFunctionParsing::GenerateGetMappingContainer() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GenerateIndentation();

    content += TextParsing::gGetMappingContainerConst;
    content += TextParsing::gNewlineCharacter;

    return content;
}

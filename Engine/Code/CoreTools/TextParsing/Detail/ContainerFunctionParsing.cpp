///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/09 09:36)

#include "CoreTools/CoreToolsExport.h"

#include "ContainerFunctionParsing.h"
#include "DefaultContainerFunctionParsing.h"
#include "KeyContainerFunctionParsing.h"
#include "MapContainerFunctionParsing.h"
#include "UniqueContainerFunctionParsing.h"
#include "VectorContainerFunctionParsing.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::ContainerFunctionParsing::ContainerFunctionParsingUniquePtr CoreTools::ContainerFunctionParsing::Create(const CSVHead& csvHead, const String& keyTypeDescribe)
{
    switch (const CSVFormatType csvFormatType = csvHead.GetCSVFormatType(); csvFormatType)
    {
        case CSVFormatType::Vector:
        {
            return std::make_unique<VectorContainerFunctionParsing>(csvHead, keyTypeDescribe);
        }
        case CSVFormatType::TreeMap:
            FALLTHROUGH;
        case CSVFormatType::HashMap:
        {
            return std::make_unique<MapContainerFunctionParsing>(csvHead, keyTypeDescribe);
        }
        case CSVFormatType::Key:
        {
            return std::make_unique<KeyContainerFunctionParsing>(csvHead, keyTypeDescribe);
        }
        case CSVFormatType::Unique:
        {
            return std::make_unique<UniqueContainerFunctionParsing>(csvHead, keyTypeDescribe);
        }
        default:
        {
            return std::make_unique<DefaultContainerFunctionParsing>(csvHead, keyTypeDescribe);
        }
    }
}

CoreTools::ContainerFunctionParsing::ContainerFunctionParsing(CSVHead csvHead, String keyTypeDescribe) noexcept
    : ParentType{ 2 }, keyTypeDescribe{ std::move(keyTypeDescribe) }, head{ std::move(csvHead) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ContainerFunctionParsing)

System::String CoreTools::ContainerFunctionParsing::GenerateParsing() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(-1);
    content += TextParsing::gPrivate;

    content += GenerateIndentation();
    content += TextParsing::gParsingFunction;
    content += TextParsing::gNewlineCharacter;

    return content;
}

CoreTools::CSVHead CoreTools::ContainerFunctionParsing::GetCSVHead() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return head;
}

System::String CoreTools::ContainerFunctionParsing::GetKeyTypeDescribe() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return keyTypeDescribe;
}

System::String CoreTools::ContainerFunctionParsing::GenerateBaseGetFirst() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += TextParsing::gNodiscardConst;
    content += head.GetCSVClassName();
    content += TextParsing::gBase;
    content += TextParsing::gGetFirstSharedPtr;
    content += head.GetCSVClassName();
    content += TextParsing::gFunctionConst;
    content += TextParsing::gSemicolonNewline;

    return content;
}

System::String CoreTools::ContainerFunctionParsing::GenerateGetContainer() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();
    content += TextParsing::gGetContainerConst;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::ContainerFunctionParsing::GenerateBaseGetFirstTemplate() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GenerateIndentation();
    content += TextParsing::gFunctionTemplate;

    content += GenerateIndentation();
    content += TextParsing::gNodiscardConst;
    content += csvHead.GetCSVClassName();
    content += TextParsing::gBase;
    content += TextParsing::gGetFirstSharedPtr;
    content += csvHead.GetCSVClassName();
    content += TextParsing::gFunctionParameter;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::ContainerFunctionParsing::GenerateBaseGetTemplate() const
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

System::String CoreTools::ContainerFunctionParsing::GenerateBaseGet() const
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
    content += GetKeyTypeDescribe();
    content += TextParsing::gKeyConst;

    return content;
}

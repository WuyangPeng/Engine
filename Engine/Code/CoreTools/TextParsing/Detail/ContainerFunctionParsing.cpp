///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:55)

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
    const CSVFormatType csvFormatType = csvHead.GetCSVFormatType();

    switch (csvFormatType)
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

CoreTools::ContainerFunctionParsing::ContainerFunctionParsing(const CSVHead& csvHead, const String& keyTypeDescribe)
    : ParentType{ 2 }, m_CSVHead{ csvHead }, keyTypeDescribe{ keyTypeDescribe }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ContainerFunctionParsing)

System::String CoreTools::ContainerFunctionParsing::GenerateParsing() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation(-1);
    content += TextParsing::g_Private;

    content += GenerateIndentation();
    content += TextParsing::g_ParsingFunction;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

CoreTools::CSVHead CoreTools::ContainerFunctionParsing::GetCSVHead() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_CSVHead;
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

    content += TextParsing::g_NodiscardConst;
    content += m_CSVHead.GetCSVClassName();
    content += TextParsing::g_Base;
    content += TextParsing::g_GetFirstSharedPtr;
    content += m_CSVHead.GetCSVClassName();
    content += TextParsing::g_FunctionConst;
    content += TextParsing::g_SemicolonNewline;

    return content;
}

System::String CoreTools::ContainerFunctionParsing::GenerateGetContainer() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();
    content += TextParsing::g_GetContainerConst;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::ContainerFunctionParsing::GenerateBaseGetFirstTemplate() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GenerateIndentation();
    content += TextParsing::g_FunctionTemplate;

    content += GenerateIndentation();
    content += TextParsing::g_NodiscardConst;
    content += csvHead.GetCSVClassName();
    content += TextParsing::g_Base;
    content += TextParsing::g_GetFirstSharedPtr;
    content += csvHead.GetCSVClassName();
    content += TextParsing::g_FunctionParameter;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::ContainerFunctionParsing::GenerateBaseGetTemplate() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GenerateIndentation();
    content += TextParsing::g_FunctionTemplate;

    content += GenerateIndentation();
    content += TextParsing::g_GetContainer;
    content += csvHead.GetCSVClassName();
    content += TextParsing::g_FunctionParameter;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::ContainerFunctionParsing::GenerateBaseGet() const
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
    content += GetKeyTypeDescribe();
    content += TextParsing::g_KeyConst;

    return content;
}

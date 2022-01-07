///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 20:15)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateContainerSourceFile.h"
#include "CSVGenerateDefaultFunctionDefinition.h"
#include "CSVGenerateGetFunctionDefinition.h"
#include "CSVGenerateHead.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVGenerateContainerSourceFile::CSVGenerateContainerSourceFile(const CSVHead& csvHead) noexcept
    : ParentType{ csvHead }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVGenerateContainerSourceFile)

System::String CoreTools::CSVGenerateContainerSourceFile::GetSuffix() const
{
    return String{ TextParsing::g_Container };
}

System::String CoreTools::CSVGenerateContainerSourceFile::GetFilePrefix() const
{
    return String{ TextParsing::g_ForwardSlash };
}

System::String CoreTools::CSVGenerateContainerSourceFile::GetFileSuffix() const
{
    auto result = GetSuffix();

    result += TextParsing::g_SourceFileExtensionName;

    return result;
}

System::String CoreTools::CSVGenerateContainerSourceFile::GetContent() const
{
    auto content = GenerateCopyright();

    content += TextParsing::g_NewlineCharacter;

    CSVGenerateHead csvGenerateHead{ GetCSVHead(), GetSuffix() };
    content += csvGenerateHead.GenerateContainerSourceHead();

    CSVGenerateDefaultFunctionDefinition csvGenerateDefaultFunctionDefinition{ GetCSVHead(), GetSuffix() };
    content += csvGenerateDefaultFunctionDefinition.GenerateContainerDefaultFunctionDefinition();

    CSVGenerateGetFunctionDefinition csvGenerateGetFunctionDefinition{ GetCSVHead(), GetSuffix() };
    content += csvGenerateGetFunctionDefinition.GenerateContainerFunctionDefinition(GetKeyTypeDescribe());

    return content;
}

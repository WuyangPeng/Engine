///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 17:20)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateContainerDetailHeadFile.h"
#include "CSVGenerateGetFunctionDefinition.h"
#include "CSVGenerateHead.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVGenerateContainerDetailHeadFile::CSVGenerateContainerDetailHeadFile(const CSVHead& csvHead) noexcept
    : ParentType{ csvHead }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVGenerateContainerDetailHeadFile)

System::String CoreTools::CSVGenerateContainerDetailHeadFile::GetSuffix() const
{
    return String{ TextParsing::gContainer };
}

System::String CoreTools::CSVGenerateContainerDetailHeadFile::GetFilePrefix() const
{
    return String{ TextParsing::gForwardSlash };
}

System::String CoreTools::CSVGenerateContainerDetailHeadFile::GetFileSuffix() const
{
    auto result = GetSuffix();

    result += TextParsing::gDetailHeadFileExtensionName;

    return result;
}

System::String CoreTools::CSVGenerateContainerDetailHeadFile::GetContent() const
{
    String content{ TextParsing::gCopyright };

    content += TextParsing::gNewlineCharacter;
    content += GenerateHeaderGuard();

    const CSVGenerateHead csvGenerateHead{ GetCSVHead(), GetSuffix() };
    content += csvGenerateHead.GenerateContainerDetailHead();

    const CSVGenerateGetFunctionDefinition csvGenerateGetFunctionDefinition{ GetCSVHead(), GetSuffix() };
    content += csvGenerateGetFunctionDefinition.GenerateContainerDetailDefinition();

    content += GenerateHeaderGuardEndif();

    return content;
}

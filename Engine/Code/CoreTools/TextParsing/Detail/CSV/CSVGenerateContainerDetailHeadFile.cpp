///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/09 17:28)

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
    auto content = GenerateCopyright();

    content += TextParsing::gNewlineCharacter;
    content += GenerateHeaderGuard();

    const CSVGenerateHead csvGenerateHead{ GetCSVHead(), GetSuffix() };
    content += csvGenerateHead.GenerateContainerDetailHead();

    const CSVGenerateGetFunctionDefinition csvGenerateGetFunctionDefinition{ GetCSVHead(), GetSuffix() };
    content += csvGenerateGetFunctionDefinition.GenerateContainerDetailDefinition();

    content += GenerateHeaderGuardEndif();

    return content;
}

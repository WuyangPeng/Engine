///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/04 17:19)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateBaseSourceFile.h"
#include "CSVGenerateDefaultFunctionDefinition.h"
#include "CSVGenerateGetFunctionDefinition.h"
#include "CSVGenerateHead.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVGenerateBaseSourceFile::CSVGenerateBaseSourceFile(const CSVHead& csvHead) noexcept
    : ParentType{ csvHead }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVGenerateBaseSourceFile)

System::String CoreTools::CSVGenerateBaseSourceFile::GetSuffix() const
{
    return String{ TextParsing::gBase };
}

System::String CoreTools::CSVGenerateBaseSourceFile::GetFilePrefix() const
{
    return String{ TextParsing::gForwardSlash };
}

System::String CoreTools::CSVGenerateBaseSourceFile::GetFileSuffix() const
{
    auto result = GetSuffix();

    result += TextParsing::gSourceFileExtensionName;

    return result;
}

System::String CoreTools::CSVGenerateBaseSourceFile::GetContent() const
{
    String content{ TextParsing::gCopyright };

    content += TextParsing::gNewlineCharacter;

    const CSVGenerateHead csvGenerateHead{ GetCSVHead(), GetSuffix() };
    content += csvGenerateHead.GenerateBaseSourceHead();

    const CSVGenerateDefaultFunctionDefinition csvGenerateDefaultFunctionDefinition{ GetCSVHead(), GetSuffix() };
    content += csvGenerateDefaultFunctionDefinition.GenerateBaseDefaultFunctionDefinition();

    const CSVGenerateGetFunctionDefinition csvGenerateGetFunctionDefinition{ GetCSVHead(), GetSuffix() };
    content += csvGenerateGetFunctionDefinition.GenerateBaseGetFunctionDefinition(GetKeyTypeDescribe());

    return content;
}

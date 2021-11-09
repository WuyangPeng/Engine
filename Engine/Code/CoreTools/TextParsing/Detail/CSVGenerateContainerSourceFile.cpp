///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.5 (2021/10/23 0:29)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateContainerSourceFile.h"
#include "CSVGenerateDefaultFunctionDefinition.h"
#include "CSVGenerateGetFunctionDefinition.h"
#include "CSVGenerateHead.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVConstant.h"

using namespace std::literals;
using namespace CoreTools::TextParsing;

CoreTools::CSVGenerateContainerSourceFile::CSVGenerateContainerSourceFile(const CSVHead& csvHead) noexcept
    : ParentType{ csvHead }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVGenerateContainerSourceFile)

System::String CoreTools::CSVGenerateContainerSourceFile::GetSuffix() const
{
    return SYSTEM_TEXT("Container"s);
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

    content += g_NewlineCharacter;

    CSVGenerateHead csvGenerateHead{ GetCSVHead(), GetSuffix() };
    content += csvGenerateHead.GenerateContainerSourceHead();

    CSVGenerateDefaultFunctionDefinition csvGenerateDefaultFunctionDefinition{ GetCSVHead(), GetSuffix() };
    content += csvGenerateDefaultFunctionDefinition.GenerateContainerDefaultFunctionDefinition();

    CSVGenerateGetFunctionDefinition csvGenerateGetFunctionDefinition{ GetCSVHead(), GetSuffix() };
    content += csvGenerateGetFunctionDefinition.GenerateContainerFunctionDefinition(GetKeyTypeDescribe());

    return content;
}

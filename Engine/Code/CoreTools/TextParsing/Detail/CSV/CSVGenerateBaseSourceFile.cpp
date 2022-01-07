///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 20:13)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateBaseSourceFile.h"
#include "CSVGenerateDefaultFunctionDefinition.h"
#include "CSVGenerateGetFunctionDefinition.h"
#include "CSVGenerateHead.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

using namespace std::literals;

CoreTools::CSVGenerateBaseSourceFile::CSVGenerateBaseSourceFile(const CSVHead& csvHead) noexcept
    : ParentType{ csvHead }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVGenerateBaseSourceFile)

System::String CoreTools::CSVGenerateBaseSourceFile::GetSuffix() const
{
    return String{ TextParsing::g_Base };
}

System::String CoreTools::CSVGenerateBaseSourceFile::GetFilePrefix() const
{
    return String{ TextParsing::g_ForwardSlash };
}

System::String CoreTools::CSVGenerateBaseSourceFile::GetFileSuffix() const
{
    auto result = GetSuffix();

    result += TextParsing::g_SourceFileExtensionName;

    return result;
}

System::String CoreTools::CSVGenerateBaseSourceFile::GetContent() const
{
    auto content = GenerateCopyright();

    content += TextParsing::g_NewlineCharacter;

    CSVGenerateHead csvGenerateHead{ GetCSVHead(), GetSuffix() };
    content += csvGenerateHead.GenerateBaseSourceHead();

    CSVGenerateDefaultFunctionDefinition csvGenerateDefaultFunctionDefinition{ GetCSVHead(), GetSuffix() };
    content += csvGenerateDefaultFunctionDefinition.GenerateBaseDefaultFunctionDefinition();

    CSVGenerateGetFunctionDefinition csvGenerateGetFunctionDefinition{ GetCSVHead(), GetSuffix() };
    content += csvGenerateGetFunctionDefinition.GenerateBaseGetFunctionDefinition(GetKeyTypeDescribe());

    return content;
}

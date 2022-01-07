///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 20:16)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateEnumSourceFile.h"
#include "CSVGenerateHead.h"
#include "CSVGenerateHelper.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/Detail/EnumHeadSourceParsing.h"
#include "CoreTools/TextParsing/Detail/Parsing.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

using namespace std::literals;

CoreTools::CSVGenerateEnumSourceFile::CSVGenerateEnumSourceFile(const CSVContent& csvContent)
    : ParentType{ csvContent.GetCSVHead() }, csvContent{ csvContent }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVGenerateEnumSourceFile)

System::String CoreTools::CSVGenerateEnumSourceFile::GetSuffix() const noexcept
{
    return String{};
}

System::String CoreTools::CSVGenerateEnumSourceFile::GetFilePrefix() const
{
    return String{ TextParsing::g_EnumFilePrefix };
}

System::String CoreTools::CSVGenerateEnumSourceFile::GetFileSuffix() const
{
    auto result = GetSuffix();

    result += TextParsing::g_SourceFileExtensionName;

    return result;
}

System::String CoreTools::CSVGenerateEnumSourceFile::GetContent() const
{
    auto content = GenerateCopyright();

    content += TextParsing::g_NewlineCharacter;

    CSVGenerateHead csvGenerateHead{ GetCSVHead(), GetSuffix() };
    content += csvGenerateHead.GenerateEnumSourceHead();

    EnumHeadSourceParsing enumHeadSourceParsing{ GetCSVHead(), csvContent, GetCSVClassName() + GetSuffix() };
    content += enumHeadSourceParsing.GenerateEnumFunctionDefinition();

    return content;
}

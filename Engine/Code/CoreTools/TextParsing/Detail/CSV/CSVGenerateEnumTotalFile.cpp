/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:56)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateEnumHeadFile.h"
#include "CSVGenerateEnumSourceFile.h"
#include "CSVGenerateEnumTotalFile.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"

#include <future>

CoreTools::CSVGenerateEnumTotalFile::CSVGenerateEnumTotalFile(const CSVContent& csvContent, const CodeMappingAnalysis& codeMappingAnalysis)
    : ParentType{ csvContent.GetCSVHead(), codeMappingAnalysis }, csvContent{ csvContent }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVGenerateEnumTotalFile)

System::String CoreTools::CSVGenerateEnumTotalFile::GetSuffix() const noexcept
{
    return String{};
}

System::String CoreTools::CSVGenerateEnumTotalFile::GetFilePrefix() const noexcept
{
    return String{};
}

System::String CoreTools::CSVGenerateEnumTotalFile::GetFileSuffix() const noexcept
{
    return GetSuffix();
}

System::String CoreTools::CSVGenerateEnumTotalFile::GetContent(const String& codeDirectory) const noexcept
{
    System::UnusedFunction(codeDirectory);

    return String{};
}

void CoreTools::CSVGenerateEnumTotalFile::GenerateFile(const String& codeDirectory, const String& directory) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    CSVGenerateEnumHeadFile csvGenerateEnumHeadFile{ csvContent, GetCodeMappingAnalysis() };

    const auto result = std::async(&CSVGenerateEnumHeadFile::GenerateFile, csvGenerateEnumHeadFile, codeDirectory, directory);

    const CSVGenerateEnumSourceFile csvGenerateEnumSourceFile{ csvContent, GetCodeMappingAnalysis() };
    csvGenerateEnumSourceFile.GenerateFile(codeDirectory, directory);

    result.wait();
}

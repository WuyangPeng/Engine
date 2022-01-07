///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 20:17)

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

CoreTools::CSVGenerateEnumTotalFile::CSVGenerateEnumTotalFile(const CSVContent& csvContent)
    : ParentType{ csvContent.GetCSVHead() }, csvContent{ csvContent }
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

System::String CoreTools::CSVGenerateEnumTotalFile::GetContent() const noexcept
{
    return String{};
}

void CoreTools::CSVGenerateEnumTotalFile::GenerateFile(const String& directory) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    CSVGenerateEnumHeadFile csvGenerateEnumHeadFile{ csvContent };

    auto result = std::async(&CSVGenerateEnumHeadFile::GenerateFile, csvGenerateEnumHeadFile, directory);

    CSVGenerateEnumSourceFile csvGenerateEnumSourceFile{ csvContent };
    csvGenerateEnumSourceFile.GenerateFile(directory);

    result.wait();
}

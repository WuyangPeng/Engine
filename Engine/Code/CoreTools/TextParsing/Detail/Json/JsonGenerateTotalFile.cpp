///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:47)

#include "CoreTools/CoreToolsExport.h"

#include "JsonGenerateDetailHeadFile.h"
#include "JsonGenerateHeadFile.h"
#include "JsonGenerateSourceFile.h"
#include "JsonGenerateTotalFile.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"

#include <future>

CoreTools::JsonGenerateTotalFile::JsonGenerateTotalFile(const JsonHead& jsonHead) noexcept
    : ParentType{ jsonHead }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, JsonGenerateTotalFile)

System::String CoreTools::JsonGenerateTotalFile::GetSuffix() const noexcept
{
    return String{};
}

System::String CoreTools::JsonGenerateTotalFile::GetFilePrefix() const noexcept
{
    return String{};
}

System::String CoreTools::JsonGenerateTotalFile::GetFileSuffix() const noexcept
{
    return GetSuffix();
}

System::String CoreTools::JsonGenerateTotalFile::GetContent() const noexcept
{
    return String{};
}

void CoreTools::JsonGenerateTotalFile::GenerateFile(const String& directory) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto head = GetJsonHead();

    const JsonGenerateHeadFile jsonGenerateHeadFile{ head };
    auto jsonGenerateHeadFileResult = std::async(&JsonGenerateHeadFile::GenerateFile, jsonGenerateHeadFile, directory);

    const JsonGenerateDetailHeadFile jsonGenerateDetailHeadFile{ head };
    auto jsonGenerateDetailHeadFileResult = std::async(&JsonGenerateDetailHeadFile::GenerateFile, jsonGenerateDetailHeadFile, directory);

    const JsonGenerateSourceFile jsonGenerateSourceFile{ head };
    jsonGenerateSourceFile.GenerateFile(directory);

    jsonGenerateHeadFileResult.wait();
    jsonGenerateDetailHeadFileResult.wait();
}

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.7 (2023/04/28 08:56)

#include "CoreTools/CoreToolsExport.h"

#include "BatchConversionCSV.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Detail/CSV/BatchConversionCSVImpl.h"

#include <filesystem>

CoreTools::BatchConversionCSV::BatchConversionCSV(const String& inputDirectory, const String& outputDirectory)
{
    Execution(inputDirectory, outputDirectory);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, BatchConversionCSV)

void CoreTools::BatchConversionCSV::Execution(const String& inputDirectory, const String& outputDirectory)
{
    for (const std::filesystem::path path{ StringConversion::StandardConversionWideChar(inputDirectory) };
         const auto& inputPath : std::filesystem::directory_iterator(path))
    {
        const auto& nativeFileName = StringConversion::WideCharConversionStandard(inputPath.path().native());

        const BatchConversionCSVImpl impl{ nativeFileName, outputDirectory };
    }
}

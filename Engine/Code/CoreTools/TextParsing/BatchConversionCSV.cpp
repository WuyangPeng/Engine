///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/10/28 18:07)

#include "CoreTools/CoreToolsExport.h"

#include "BatchConversionCSV.h"
#include "Detail/BatchConversionCSVImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <filesystem>

CoreTools::BatchConversionCSV::BatchConversionCSV(const String& inputDirectory, const String& outputDirectory)
{
    Execution(inputDirectory, outputDirectory);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, BatchConversionCSV)

void CoreTools::BatchConversionCSV::Execution(const String& inputDirectory, const String& outputDirectory)
{
    std::filesystem::path path{ inputDirectory };

    for (const auto& inputPath : std::filesystem::directory_iterator(path))
    {
        auto nativeFileName = inputPath.path().native();

        const BatchConversionCSVImpl impl{ nativeFileName, outputDirectory };
    }
}

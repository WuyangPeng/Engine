///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/05/29 22:23)

#include "CoreTools/CoreToolsExport.h"

#include "BatchConversionCSV.h"
#include "BatchConversionCode.h"
#include "CSVContent.h"
#include "CSVGenerate.h"
#include "CSVHead.h"
#include "CSVTotalGenerate.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"

#include <filesystem>

using System::operator++;

CoreTools::BatchConversionCode::BatchConversionCode(const String& inputDirectory, const String& outputDirectory)
{
    LoadConfigure(inputDirectory, outputDirectory);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, BatchConversionCode)

void CoreTools::BatchConversionCode::LoadConfigure(const String& inputDirectory, const String& outputDirectory)
{
    const std::filesystem::path path{ inputDirectory };

    CSVTotalGenerate::CSVHeadContainer container{};

    String nameSpace{};
    for (const auto& inputPath : std::filesystem::directory_iterator(path))
    {
        const auto nativeFileName = StringConversion::WideCharConversionStandard(inputPath.path().native());

        if (nativeFileName.find(SYSTEM_TEXT("csv")) != nativeFileName.size() - 3)
        {
            continue;
        }

        CSVContent csvContent{ nativeFileName };

        const auto csvHead = csvContent.GetCSVHead();

        container.emplace_back(csvHead);

        if (nameSpace.empty())
        {
            nameSpace = csvHead.GetNameSpace();
        }
    }

    for (auto i = CSVTotalGenerateType::Head; i <= CSVTotalGenerateType::ContainerSource; ++i)
    {
        const CSVTotalGenerate csvTotalGenerate{ nameSpace, container, i };

        csvTotalGenerate.GenerateFile(outputDirectory);
    }

    for (const auto& value : container)
    {
        const CSVGenerate csvGenerate{ value, CSVGenerateType::Total };

        csvGenerate.GenerateFile(outputDirectory);
    }
}

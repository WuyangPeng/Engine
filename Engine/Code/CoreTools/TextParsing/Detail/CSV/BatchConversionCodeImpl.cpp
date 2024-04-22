/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/03 09:14)

#include "CoreTools/CoreToolsExport.h"

#include "BatchConversionCodeImpl.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "CoreTools/CharacterString/CodeMappingAnalysis.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVGenerate.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

#include <filesystem>

using System::operator++;
using namespace std::literals;

CoreTools::BatchConversionCodeImpl::BatchConversionCodeImpl(const String& inputDirectory, const String& codeDirectory, const String& outputDirectory)
    : nameSpace{},
      container{},
      codeMappingAnalysis{ codeDirectory + SYSTEM_TEXT("/CSVEngineering.json") },
      codeDirectory{ codeDirectory },
      outputDirectory{ outputDirectory }
{
    LoadConfigure(inputDirectory);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, BatchConversionCodeImpl)

void CoreTools::BatchConversionCodeImpl::LoadConfigure(const String& inputDirectory)
{
    for (const std::filesystem::path path{ inputDirectory };
         const auto& inputPath : std::filesystem::directory_iterator(path))
    {
        LoadConfigure(inputPath);
    }

    GenerateFile();
}

void CoreTools::BatchConversionCodeImpl::LoadConfigure(const std::filesystem::directory_entry& inputPath)
{
    if (const auto nativeFileName = GetNativeFileName(inputPath);
        !nativeFileName.empty())
    {
        const CSVContent csvContent{ nativeFileName };

        const auto csvHead = csvContent.GetCSVHead();

        container.emplace_back(csvHead);

        if (nameSpace.empty())
        {
            nameSpace = csvHead.GetNameSpace();
        }
    }
}

System::String CoreTools::BatchConversionCodeImpl::GetNativeFileName(const std::filesystem::directory_entry& inputPath)
{
#ifdef SYSTEM_PLATFORM_LINUX

    auto nativeFileName = StringConversion::MultiByteConversionStandard(inputPath.path().native());

#else  // !SYSTEM_PLATFORM_LINUX

    auto nativeFileName = StringConversion::WideCharConversionStandard(inputPath.path().native());

#endif  // SYSTEM_PLATFORM_LINUX

    if (nativeFileName.find(TextParsing::gCsvExtension) != nativeFileName.size() - TextParsing::gCsvExtension.size())
    {
        return String{};
    }

    return nativeFileName;
}

void CoreTools::BatchConversionCodeImpl::GenerateFile() const
{
    TotalGenerateFile();

    for (const auto& element : container)
    {
        GenerateFile(element);
    }
}

void CoreTools::BatchConversionCodeImpl::TotalGenerateFile() const
{
    for (auto csvTotalGenerateType = CSVTotalGenerateType::Head; csvTotalGenerateType <= CSVTotalGenerateType::ContainerSource; ++csvTotalGenerateType)
    {
        TotalGenerateFile(csvTotalGenerateType);
    }
}

void CoreTools::BatchConversionCodeImpl::TotalGenerateFile(CSVTotalGenerateType csvTotalGenerateType) const
{
    const CSVTotalGenerate csvTotalGenerate{ nameSpace, container, codeMappingAnalysis, csvTotalGenerateType };

    csvTotalGenerate.GenerateFile(codeDirectory, outputDirectory);
}

void CoreTools::BatchConversionCodeImpl::GenerateFile(const CSVHead& csvHead) const
{
    const CSVGenerate csvGenerate{ csvHead, codeMappingAnalysis, CSVGenerateType::Total };

    csvGenerate.GenerateFile(codeDirectory, outputDirectory);
}

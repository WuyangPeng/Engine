/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:57)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateBaseHeadFile.h"
#include "CSVGenerateBaseSourceFile.h"
#include "CSVGenerateChildHeadFile.h"
#include "CSVGenerateChildSourceFile.h"
#include "CSVGenerateContainerDetailHeadFile.h"
#include "CSVGenerateContainerHeadFile.h"
#include "CSVGenerateContainerSourceFile.h"
#include "CSVGenerateDataHeadFile.h"
#include "CSVGenerateDataSourceFile.h"
#include "CSVGenerateTotalFile.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"

#include <future>

CoreTools::CSVGenerateTotalFile::CSVGenerateTotalFile(const CSVHead& csvHead, const CodeMappingAnalysis& codeMappingAnalysis) noexcept
    : ParentType{ csvHead, codeMappingAnalysis }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVGenerateTotalFile)

System::String CoreTools::CSVGenerateTotalFile::GetSuffix() const noexcept
{
    return String{};
}

System::String CoreTools::CSVGenerateTotalFile::GetFilePrefix() const noexcept
{
    return String{};
}

System::String CoreTools::CSVGenerateTotalFile::GetFileSuffix() const noexcept
{
    return GetSuffix();
}

System::String CoreTools::CSVGenerateTotalFile::GetContent(const String& codeDirectory) const noexcept
{
    System::UnusedFunction(codeDirectory);

    return String{};
}

void CoreTools::CSVGenerateTotalFile::GenerateFile(const String& codeDirectory, const String& directory) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    switch (const auto csvFormatType = GetCSVFormatType(); csvFormatType)
    {
        case CSVFormatType::TreeMap:
            FALLTHROUGH;
        case CSVFormatType::HashMap:
        {
            GenerateMapFile(codeDirectory, directory);
        }
        break;
        case CSVFormatType::Unique:
        {
            GenerateUniqueFile(codeDirectory, directory);
        }
        break;
        default:
        {
            GenerateDefaultFile(codeDirectory, directory);
        }
        break;
    }
}

void CoreTools::CSVGenerateTotalFile::GenerateFile(const Container& container, const String& codeDirectory, const String& directory) const
{
    using FutureContainer = std::vector<std::future<void>>;

    FutureContainer futureContainer{};
    for (const auto& value : container)
    {
        futureContainer.emplace_back(std::async(&CSVGenerateImpl::GenerateFile, std::ref(*value), codeDirectory, directory));
    }

    for (const auto& value : futureContainer)
    {
        value.wait();
    }
}

void CoreTools::CSVGenerateTotalFile::GenerateDefaultFile(const String& codeDirectory, const String& directory) const
{
    const Container container{ std::make_shared<CSVGenerateBaseHeadFile>(GetCSVHead(), GetCodeMappingAnalysis()),
                               std::make_shared<CSVGenerateBaseSourceFile>(GetCSVHead(), GetCodeMappingAnalysis()),
                               std::make_shared<CSVGenerateChildHeadFile>(GetCSVHead(), GetCodeMappingAnalysis()),
                               std::make_shared<CSVGenerateChildSourceFile>(GetCSVHead(), GetCodeMappingAnalysis()),
                               std::make_shared<CSVGenerateContainerHeadFile>(GetCSVHead(), GetCodeMappingAnalysis()),
                               std::make_shared<CSVGenerateContainerDetailHeadFile>(GetCSVHead(), GetCodeMappingAnalysis()),
                               std::make_shared<CSVGenerateContainerSourceFile>(GetCSVHead(), GetCodeMappingAnalysis()) };

    GenerateFile(container, codeDirectory, directory);
}

void CoreTools::CSVGenerateTotalFile::GenerateMapFile(const String& codeDirectory, const String& directory) const
{
    const Container container{ std::make_shared<CSVGenerateDataHeadFile>(GetCSVHead(), GetCodeMappingAnalysis()),
                               std::make_shared<CSVGenerateDataSourceFile>(GetCSVHead(), GetCodeMappingAnalysis()),
                               std::make_shared<CSVGenerateContainerHeadFile>(GetCSVHead(), GetCodeMappingAnalysis()),
                               std::make_shared<CSVGenerateContainerDetailHeadFile>(GetCSVHead(), GetCodeMappingAnalysis()),
                               std::make_shared<CSVGenerateContainerSourceFile>(GetCSVHead(), GetCodeMappingAnalysis()) };

    GenerateFile(container, codeDirectory, directory);
}

void CoreTools::CSVGenerateTotalFile::GenerateUniqueFile(const String& codeDirectory, const String& directory) const
{
    const Container container{ std::make_shared<CSVGenerateDataHeadFile>(GetCSVHead(), GetCodeMappingAnalysis()),
                               std::make_shared<CSVGenerateDataSourceFile>(GetCSVHead(), GetCodeMappingAnalysis()),
                               std::make_shared<CSVGenerateContainerHeadFile>(GetCSVHead(), GetCodeMappingAnalysis()),
                               std::make_shared<CSVGenerateContainerSourceFile>(GetCSVHead(), GetCodeMappingAnalysis()) };

    GenerateFile(container, codeDirectory, directory);
}

///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 20:20)

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

CoreTools::CSVGenerateTotalFile::CSVGenerateTotalFile(const CSVHead& csvHead) noexcept
    : ParentType{ csvHead }
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

System::String CoreTools::CSVGenerateTotalFile::GetContent() const noexcept
{
    return String{};
}

void CoreTools::CSVGenerateTotalFile::GenerateFile(const String& directory) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvFormatType = GetCSVFormatType();

    switch (csvFormatType)
    {
        case CSVFormatType::TreeMap:
            FALLTHROUGH;
        case CSVFormatType::HashMap:
        {
            GenerateMapFile(directory);
        }
        break;
        case CSVFormatType::Unique:
        {
            GenerateUniqueFile(directory);
        }
        break;
        default:
        {
            GenerateDefaultFile(directory);
        }
        break;
    }
}

void CoreTools::CSVGenerateTotalFile::GenerateFile(const Container& container, const String& directory) const
{
    using FutureContainer = std::vector<std::future<void>>;

    FutureContainer futureContainer{};
    for (const auto& value : container)
    {
        futureContainer.emplace_back(std::async(&CSVGenerateImpl::GenerateFile, std::ref(*value), directory));
    }

    for (const auto& value : futureContainer)
    {
        value.wait();
    }
}

void CoreTools::CSVGenerateTotalFile::GenerateDefaultFile(const String& directory) const
{
    Container container{ std::make_shared<CSVGenerateBaseHeadFile>(GetCSVHead()),
                         std::make_shared<CSVGenerateBaseSourceFile>(GetCSVHead()),
                         std::make_shared<CSVGenerateChildHeadFile>(GetCSVHead()),
                         std::make_shared<CSVGenerateChildSourceFile>(GetCSVHead()),
                         std::make_shared<CSVGenerateContainerHeadFile>(GetCSVHead()),
                         std::make_shared<CSVGenerateContainerDetailHeadFile>(GetCSVHead()),
                         std::make_shared<CSVGenerateContainerSourceFile>(GetCSVHead()) };

    GenerateFile(container, directory);
}

void CoreTools::CSVGenerateTotalFile::GenerateMapFile(const String& directory) const
{
    Container container{ std::make_shared<CSVGenerateDataHeadFile>(GetCSVHead()),
                         std::make_shared<CSVGenerateDataSourceFile>(GetCSVHead()),
                         std::make_shared<CSVGenerateContainerHeadFile>(GetCSVHead()),
                         std::make_shared<CSVGenerateContainerDetailHeadFile>(GetCSVHead()),
                         std::make_shared<CSVGenerateContainerSourceFile>(GetCSVHead()) };

    GenerateFile(container, directory);
}

void CoreTools::CSVGenerateTotalFile::GenerateUniqueFile(const String& directory) const
{
    Container container{ std::make_shared<CSVGenerateDataHeadFile>(GetCSVHead()),
                         std::make_shared<CSVGenerateDataSourceFile>(GetCSVHead()),
                         std::make_shared<CSVGenerateContainerHeadFile>(GetCSVHead()),
                         std::make_shared<CSVGenerateContainerSourceFile>(GetCSVHead()) };

    GenerateFile(container, directory);
}

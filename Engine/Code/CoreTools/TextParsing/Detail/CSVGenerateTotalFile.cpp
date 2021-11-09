///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/10/25 13:48)

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

using namespace std::literals;

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
        case CSVFormatType::Default:
            FALLTHROUGH;
        case CSVFormatType::Vector:
            FALLTHROUGH;
        case CSVFormatType::Key:
        {
            CSVGenerateBaseHeadFile csvGenerateBaseHeadFile{ GetCSVHead() };
            csvGenerateBaseHeadFile.GenerateFile(directory);

            CSVGenerateBaseSourceFile csvGenerateBaseSourceFile{ GetCSVHead() };
            csvGenerateBaseSourceFile.GenerateFile(directory);

            CSVGenerateChildHeadFile csvGenerateChildHeadFile{ GetCSVHead() };
            csvGenerateChildHeadFile.GenerateFile(directory);

            CSVGenerateChildSourceFile csvGenerateChildSourceFile{ GetCSVHead() };
            csvGenerateChildSourceFile.GenerateFile(directory);

            CSVGenerateContainerHeadFile csvGenerateContainerHeadFile{ GetCSVHead() };
            csvGenerateContainerHeadFile.GenerateFile(directory);

            CSVGenerateContainerDetailHeadFile csvGenerateContainerDetailHeadFile{ GetCSVHead() };
            csvGenerateContainerDetailHeadFile.GenerateFile(directory);

            CSVGenerateContainerSourceFile csvGenerateContainerSourceFile{ GetCSVHead() };
            csvGenerateContainerSourceFile.GenerateFile(directory);
        }
        break;
        case CSVFormatType::TreeMap:
            FALLTHROUGH;
        case CSVFormatType::HashMap:
        {
            CSVGenerateDataHeadFile csvGenerateDataHeadFile{ GetCSVHead() };
            csvGenerateDataHeadFile.GenerateFile(directory);

            CSVGenerateDataSourceFile csvGenerateDataSourceFile{ GetCSVHead() };
            csvGenerateDataSourceFile.GenerateFile(directory);

            CSVGenerateContainerHeadFile csvGenerateContainerHeadFile{ GetCSVHead() };
            csvGenerateContainerHeadFile.GenerateFile(directory);

            CSVGenerateContainerDetailHeadFile csvGenerateContainerDetailHeadFile{ GetCSVHead() };
            csvGenerateContainerDetailHeadFile.GenerateFile(directory);

            CSVGenerateContainerSourceFile csvGenerateContainerSourceFile{ GetCSVHead() };
            csvGenerateContainerSourceFile.GenerateFile(directory);
        }
        break;
        case CSVFormatType::Unique:
        {
            CSVGenerateDataHeadFile csvGenerateDataHeadFile{ GetCSVHead() };
            csvGenerateDataHeadFile.GenerateFile(directory);

            CSVGenerateDataSourceFile csvGenerateDataSourceFile{ GetCSVHead() };
            csvGenerateDataSourceFile.GenerateFile(directory);

            CSVGenerateContainerHeadFile csvGenerateContainerHeadFile{ GetCSVHead() };
            csvGenerateContainerHeadFile.GenerateFile(directory);

            CSVGenerateContainerSourceFile csvGenerateContainerSourceFile{ GetCSVHead() };
            csvGenerateContainerSourceFile.GenerateFile(directory);
        }
        break;
        default:
            break;
    }
}

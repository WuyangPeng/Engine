/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/10 18:11)

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
#include "CSVGenerateEnumHeadFile.h"
#include "CSVGenerateEnumSourceFile.h"
#include "CSVGenerateEnumTotalFile.h"
#include "CSVGenerateFactory.h"
#include "CSVGenerateImpl.h"
#include "CSVGenerateTotalFile.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"

CoreTools::CSVGenerateFactory::CSVGenerateSharedPtr CoreTools::CSVGenerateFactory::Create(const CSVHead& csvHead, const CodeMappingAnalysis& codeMappingAnalysis, CSVGenerateType csvGenerateType)
{
    switch (csvGenerateType)
    {
        case CSVGenerateType::BaseHead:
            return std::make_shared<CSVGenerateBaseHeadFile>(csvHead, codeMappingAnalysis);
        case CSVGenerateType::ChildHead:
            return std::make_shared<CSVGenerateChildHeadFile>(csvHead, codeMappingAnalysis);
        case CSVGenerateType::DataHead:
            return std::make_shared<CSVGenerateDataHeadFile>(csvHead, codeMappingAnalysis);
        case CSVGenerateType::ContainerHead:
            return std::make_shared<CSVGenerateContainerHeadFile>(csvHead, codeMappingAnalysis);
        case CSVGenerateType::ContainerDetailHead:
            return std::make_shared<CSVGenerateContainerDetailHeadFile>(csvHead, codeMappingAnalysis);
        case CSVGenerateType::BaseSource:
            return std::make_shared<CSVGenerateBaseSourceFile>(csvHead, codeMappingAnalysis);
        case CSVGenerateType::ChildSource:
            return std::make_shared<CSVGenerateChildSourceFile>(csvHead, codeMappingAnalysis);
        case CSVGenerateType::DataSource:
            return std::make_shared<CSVGenerateDataSourceFile>(csvHead, codeMappingAnalysis);
        case CSVGenerateType::ContainerSource:
            return std::make_shared<CSVGenerateContainerSourceFile>(csvHead, codeMappingAnalysis);
        case CSVGenerateType::Total:
            return std::make_shared<CSVGenerateTotalFile>(csvHead, codeMappingAnalysis);
        default:
            break;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("未找到指定类型"s))
}

CoreTools::CSVGenerateFactory::CSVGenerateSharedPtr CoreTools::CSVGenerateFactory::Create(const CSVContent& csvContent, const CodeMappingAnalysis& codeMappingAnalysis, CSVGenerateType csvGenerateType)
{
    switch (csvGenerateType)
    {
        case CSVGenerateType::EnumHead:
            return std::make_shared<CSVGenerateEnumHeadFile>(csvContent, codeMappingAnalysis);
        case CSVGenerateType::EnumSource:
            return std::make_shared<CSVGenerateEnumSourceFile>(csvContent, codeMappingAnalysis);
        case CSVGenerateType::EnumTotal:
            return std::make_shared<CSVGenerateEnumTotalFile>(csvContent, codeMappingAnalysis);
        default:
            return Create(csvContent.GetCSVHead(), codeMappingAnalysis, csvGenerateType);
    }
}
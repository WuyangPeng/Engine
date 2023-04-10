///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 17:20)

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

CoreTools::CSVGenerateFactory::CSVGenerateSharedPtr CoreTools::CSVGenerateFactory::Create(const CSVHead& csvHead, CSVGenerateType csvGenerateType)
{
    switch (csvGenerateType)
    {
        case CSVGenerateType::BaseHead:
            return std::make_shared<CSVGenerateBaseHeadFile>(csvHead);
        case CSVGenerateType::ChildHead:
            return std::make_shared<CSVGenerateChildHeadFile>(csvHead);
        case CSVGenerateType::DataHead:
            return std::make_shared<CSVGenerateDataHeadFile>(csvHead);
        case CSVGenerateType::ContainerHead:
            return std::make_shared<CSVGenerateContainerHeadFile>(csvHead);
        case CSVGenerateType::ContainerDetailHead:
            return std::make_shared<CSVGenerateContainerDetailHeadFile>(csvHead);
        case CSVGenerateType::BaseSource:
            return std::make_shared<CSVGenerateBaseSourceFile>(csvHead);
        case CSVGenerateType::ChildSource:
            return std::make_shared<CSVGenerateChildSourceFile>(csvHead);
        case CSVGenerateType::DataSource:
            return std::make_shared<CSVGenerateDataSourceFile>(csvHead);
        case CSVGenerateType::ContainerSource:
            return std::make_shared<CSVGenerateContainerSourceFile>(csvHead);
        case CSVGenerateType::Total:
            return std::make_shared<CSVGenerateTotalFile>(csvHead);
        default:
            break;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("未找到指定类型"s))
}

CoreTools::CSVGenerateFactory::CSVGenerateSharedPtr CoreTools::CSVGenerateFactory::Create(const CSVContent& csvContent, CSVGenerateType csvGenerateType)
{
    switch (csvGenerateType)
    {
        case CSVGenerateType::EnumHead:
            return std::make_shared<CSVGenerateEnumHeadFile>(csvContent);
        case CSVGenerateType::EnumSource:
            return std::make_shared<CSVGenerateEnumSourceFile>(csvContent);
        case CSVGenerateType::EnumTotal:
            return std::make_shared<CSVGenerateEnumTotalFile>(csvContent);
        default:
            return Create(csvContent.GetCSVHead(), csvGenerateType);
    }
}
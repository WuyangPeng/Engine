///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 20:17)

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

using std::make_shared;

CoreTools::CSVGenerateFactory::CSVGenerateSharedPtr CoreTools::CSVGenerateFactory::Create(const CSVHead& csvHead, CSVGenerateType csvGenerateType)
{
    switch (csvGenerateType)
    {
        case CSVGenerateType::BaseHead:
            return make_shared<CSVGenerateBaseHeadFile>(csvHead);
        case CSVGenerateType::ChildHead:
            return make_shared<CSVGenerateChildHeadFile>(csvHead);
        case CSVGenerateType::DataHead:
            return make_shared<CSVGenerateDataHeadFile>(csvHead);
        case CSVGenerateType::ContainerHead:
            return make_shared<CSVGenerateContainerHeadFile>(csvHead);
        case CSVGenerateType::ContainerDetailHead:
            return make_shared<CSVGenerateContainerDetailHeadFile>(csvHead);
        case CSVGenerateType::BaseSource:
            return make_shared<CSVGenerateBaseSourceFile>(csvHead);
        case CSVGenerateType::ChildSource:
            return make_shared<CSVGenerateChildSourceFile>(csvHead);
        case CSVGenerateType::DataSource:
            return make_shared<CSVGenerateDataSourceFile>(csvHead);
        case CSVGenerateType::ContainerSource:
            return make_shared<CSVGenerateContainerSourceFile>(csvHead);
        case CSVGenerateType::Total:
            return make_shared<CSVGenerateTotalFile>(csvHead);
        default:
            break;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("未找到指定类型"s));
}

CoreTools::CSVGenerateFactory::CSVGenerateSharedPtr CoreTools::CSVGenerateFactory::Create(const CSVContent& csvContent, CSVGenerateType csvGenerateType)
{
    switch (csvGenerateType)
    {
        case CSVGenerateType::EnumHead:
            return make_shared<CSVGenerateEnumHeadFile>(csvContent);
        case CSVGenerateType::EnumSource:
            return make_shared<CSVGenerateEnumSourceFile>(csvContent);
        case CSVGenerateType::EnumTotal:
            return make_shared<CSVGenerateEnumTotalFile>(csvContent);
        default:
            return Create(csvContent.GetCSVHead(), csvGenerateType);
    }
}
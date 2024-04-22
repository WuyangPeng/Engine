/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 09:38)

#include "CoreTools/CoreToolsExport.h"

#include "CSVTotalGenerateContainerHeadFile.h"
#include "CSVTotalGenerateContainerSourceFile.h"
#include "CSVTotalGenerateFactory.h"
#include "CSVTotalGenerateFwdHeadFile.h"
#include "CSVTotalGenerateHeadFile.h"
#include "CSVTotalGenerateImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"

CoreTools::CSVTotalGenerateFactory::CSVTotalGenerateSharedPtr CoreTools::CSVTotalGenerateFactory::Create(const String& nameSpace, const CSVHeadContainer& csvHeadContainer, const CodeMappingAnalysis& codeMappingAnalysis, CSVTotalGenerateType csvTotalGenerateType)
{
    switch (csvTotalGenerateType)
    {
        case CSVTotalGenerateType::Head:
            return make_shared<CSVTotalGenerateHeadFile>(nameSpace, csvHeadContainer, codeMappingAnalysis);
        case CSVTotalGenerateType::FwdHead:
            return make_shared<CSVTotalGenerateFwdHeadFile>(nameSpace, csvHeadContainer, codeMappingAnalysis);
        case CSVTotalGenerateType::ContainerHead:
            return make_shared<CSVTotalGenerateContainerHeadFile>(nameSpace, csvHeadContainer, codeMappingAnalysis);
        case CSVTotalGenerateType::ContainerSource:
            return make_shared<CSVTotalGenerateContainerSourceFile>(nameSpace, csvHeadContainer, codeMappingAnalysis);
        default:
            break;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("未找到指定类型"s))
}

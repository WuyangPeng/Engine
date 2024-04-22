/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/11 09:38)

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

    THROW_EXCEPTION(SYSTEM_TEXT("δ�ҵ�ָ������"s))
}

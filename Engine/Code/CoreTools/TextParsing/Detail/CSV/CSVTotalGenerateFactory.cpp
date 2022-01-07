///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 21:02)

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

using std::make_shared;

CoreTools::CSVTotalGenerateFactory::CSVTotalGenerateSharedPtr CoreTools::CSVTotalGenerateFactory::Create(const String& nameSpace, const CSVHeadContainer& csvHeadContainer, CSVTotalGenerateType csvTotalGenerateType)
{
    switch (csvTotalGenerateType)
    {
        case CSVTotalGenerateType::Head:
            return make_shared<CSVTotalGenerateHeadFile>(nameSpace, csvHeadContainer);
        case CSVTotalGenerateType::FwdHead:
            return make_shared<CSVTotalGenerateFwdHeadFile>(nameSpace, csvHeadContainer);
        case CSVTotalGenerateType::ContainerHead:
            return make_shared<CSVTotalGenerateContainerHeadFile>(nameSpace, csvHeadContainer);
        case CSVTotalGenerateType::ContainerSource:
            return make_shared<CSVTotalGenerateContainerSourceFile>(nameSpace, csvHeadContainer);
        default:
            break;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("δ�ҵ�ָ������"s));
}

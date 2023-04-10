///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/04 17:25)

#include "CoreTools/CoreToolsExport.h"

#include "JsonGenerateDetailHeadFile.h"
#include "JsonGenerateFactory.h"
#include "JsonGenerateHeadFile.h"
#include "JsonGenerateSourceFile.h"
#include "JsonGenerateTotalFile.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"

CoreTools::JsonGenerateFactory::JsonGenerateSharedPtr CoreTools::JsonGenerateFactory::Create(const JsonHead& jsonHead, JsonGenerateType csvGenerateType)
{
    switch (csvGenerateType)
    {
        case JsonGenerateType::Head:
            return std::make_shared<JsonGenerateHeadFile>(jsonHead);
        case JsonGenerateType::DetailHead:
            return std::make_shared<JsonGenerateDetailHeadFile>(jsonHead);
        case JsonGenerateType::Source:
            return std::make_shared<JsonGenerateSourceFile>(jsonHead);
        case JsonGenerateType::Total:
            return std::make_shared<JsonGenerateTotalFile>(jsonHead);
        case JsonGenerateType::EnumHead:
            break;
        case JsonGenerateType::EnumSource:
            break;
        case JsonGenerateType::EnumTotal:
            break;
        default:
            break;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("δ�ҵ�ָ������"s))
}

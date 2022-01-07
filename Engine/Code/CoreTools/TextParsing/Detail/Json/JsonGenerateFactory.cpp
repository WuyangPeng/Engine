///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:43)

#include "CoreTools/CoreToolsExport.h"

#include "JsonGenerateDetailHeadFile.h"
#include "JsonGenerateFactory.h"
#include "JsonGenerateHeadFile.h"
#include "JsonGenerateSourceFile.h"
#include "JsonGenerateTotalFile.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"

using std::make_shared;

CoreTools::JsonGenerateFactory::JsonGenerateSharedPtr CoreTools::JsonGenerateFactory::Create(const JsonHead& jsonHead, JsonGenerateType csvGenerateType)
{
    switch (csvGenerateType)
    {
        case CoreTools::JsonGenerateType::Head:
            return make_shared<JsonGenerateHeadFile>(jsonHead);
        case CoreTools::JsonGenerateType::DetailHead:
            return make_shared<JsonGenerateDetailHeadFile>(jsonHead);
        case CoreTools::JsonGenerateType::Source:
            return make_shared<JsonGenerateSourceFile>(jsonHead);
        case CoreTools::JsonGenerateType::Total:
            return make_shared<JsonGenerateTotalFile>(jsonHead);
        case CoreTools::JsonGenerateType::EnumHead:
            break;
        case CoreTools::JsonGenerateType::EnumSource:
            break;
        case CoreTools::JsonGenerateType::EnumTotal:
            break;
        default:
            break;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("未找到指定类型"s));
}

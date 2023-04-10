///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 17:27)

#include "CoreTools/CoreToolsExport.h"

#include "JsonTotalGenerateContainerHeadFile.h"
#include "JsonTotalGenerateContainerSourceFile.h"
#include "JsonTotalGenerateFactory.h"
#include "JsonTotalGenerateFwdHeadFile.h"
#include "JsonTotalGenerateHeadFile.h"
#include "JsonTotalGenerateImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"

CoreTools::JsonTotalGenerateFactory::JsonTotalGenerateSharedPtr CoreTools::JsonTotalGenerateFactory::Create(const String& nameSpace, const JsonHeadContainer& jsonHeadContainer, JsonTotalGenerateType jsonTotalGenerateType)
{
    switch (jsonTotalGenerateType)
    {
        case JsonTotalGenerateType::Head:
            return make_shared<JsonTotalGenerateHeadFile>(nameSpace, jsonHeadContainer);
        case JsonTotalGenerateType::FwdHead:
            return make_shared<JsonTotalGenerateFwdHeadFile>(nameSpace, jsonHeadContainer);
        case JsonTotalGenerateType::ContainerHead:
            return make_shared<JsonTotalGenerateContainerHeadFile>(nameSpace, jsonHeadContainer);
        case JsonTotalGenerateType::ContainerSource:
            return make_shared<JsonTotalGenerateContainerSourceFile>(nameSpace, jsonHeadContainer);
        default:
            break;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("未找到指定类型"s))
}

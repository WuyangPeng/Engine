///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/10 09:07)

#include "CoreTools/CoreToolsExport.h"

#include "JsonTotalGenerate.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/Detail/Json/JsonTotalGenerateFactory.h"
#include "CoreTools/TextParsing/Detail/Json/JsonTotalGenerateImpl.h"

CoreTools::JsonTotalGenerate::JsonTotalGenerate(const String& nameSpace, const JsonHeadContainer& jsonHeadContainer, JsonTotalGenerateType jsonTotalGenerateType)
    : impl{ ImplCreateUseFactory::Default, nameSpace, jsonHeadContainer, jsonTotalGenerateType }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, JsonTotalGenerate)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, JsonTotalGenerate, GenerateFile, String, void)

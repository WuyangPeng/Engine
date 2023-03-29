///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/10 09:07)

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

///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 22:35)

#include "CoreTools/CoreToolsExport.h"

#include "JsonGenerate.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/Detail/Json/JsonGenerateFactory.h"
#include "CoreTools/TextParsing/Detail/Json/JsonGenerateImpl.h"

CoreTools::JsonGenerate::JsonGenerate(const JsonHead& jsonHead, JsonGenerateType jsonGenerateType)
    : impl{ ImplCreateUseFactory::Default, jsonHead, jsonGenerateType }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, JsonGenerate)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, JsonGenerate, GenerateFile, String, void)
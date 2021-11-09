///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.5 (2021/10/25 12:51)

#include "CoreTools/CoreToolsExport.h"

#include "CSVTotalGenerate.h"
#include "Detail/CSVTotalGenerateFactory.h"
#include "Detail/CSVTotalGenerateImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::CSVTotalGenerate::CSVTotalGenerate(const String& nameSpace, const CSVHeadContainer& csvHeadContainer, CSVTotalGenerateType csvTotalGenerateType)
    : impl{ ImplCreateUseFactory::Default, nameSpace, csvHeadContainer, csvTotalGenerateType }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CSVTotalGenerate)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CSVTotalGenerate, GenerateFile, String, void)

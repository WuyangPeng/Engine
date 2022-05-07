///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 20:00)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerate.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/Detail/CSV/CSVGenerateFactory.h"
#include "CoreTools/TextParsing/Detail/CSV/CSVGenerateImpl.h"

CoreTools::CSVGenerate::CSVGenerate(const CSVHead& csvHead, CSVGenerateType csvGenerateType)
    : impl{ ImplCreateUseFactory::Default, csvHead, csvGenerateType }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::CSVGenerate::CSVGenerate(const CSVContent& csvContent, CSVGenerateType csvGenerateType)
    : impl{ ImplCreateUseFactory::Default, csvContent, csvGenerateType }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CSVGenerate)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CSVGenerate, GenerateFile, String, void)
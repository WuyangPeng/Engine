///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/10/21 14:24)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerate.h"
#include "Detail/CSVGenerateFactory.h"
#include "Detail/CSVGenerateImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

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

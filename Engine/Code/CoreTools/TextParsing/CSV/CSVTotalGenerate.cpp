///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 20:01)

#include "CoreTools/CoreToolsExport.h"

#include "CSVTotalGenerate.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/Detail/CSV/CSVTotalGenerateFactory.h"
#include "CoreTools/TextParsing/Detail/CSV/CSVTotalGenerateImpl.h"

CoreTools::CSVTotalGenerate::CSVTotalGenerate(const String& nameSpace, const CSVHeadContainer& csvHeadContainer, CSVTotalGenerateType csvTotalGenerateType)
    : impl{ ImplCreateUseFactory::Default, nameSpace, csvHeadContainer, csvTotalGenerateType }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CSVTotalGenerate)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CSVTotalGenerate, GenerateFile, String, void)

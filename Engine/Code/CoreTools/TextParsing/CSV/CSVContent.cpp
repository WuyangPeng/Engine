///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 15:01)

#include "CoreTools/CoreToolsExport.h"

#include "CSVContent.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/Detail/CSV/CSVContentImpl.h"

CoreTools::CSVContent::CSVContent(const String& fileName)
    : impl{ fileName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CSVContent)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CSVContent, GetCSVHead, CoreTools::CSVHead)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, CSVContent, GetContent, int, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CSVContent, GetCount, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CSVContent, GetCSVClassName, System::String)

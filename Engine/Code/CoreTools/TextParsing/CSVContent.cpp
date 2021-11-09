///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.5 (2021/10/19 11:37)

#include "CoreTools/CoreToolsExport.h"

#include "CSVContent.h"
#include "Detail/CSVContentImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

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

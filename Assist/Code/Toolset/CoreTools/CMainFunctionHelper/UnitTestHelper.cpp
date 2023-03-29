///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/14 16:01)

#include "UnitTestHelper.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CMainFunctionHelper::UnitTestHelper::UnitTestHelper(bool isCout)
    : ParentType{ OStreamShared{ isCout } }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CMainFunctionHelper, UnitTestHelper)

void CMainFunctionHelper::UnitTestHelper::DoRunUnitTest() noexcept
{
}

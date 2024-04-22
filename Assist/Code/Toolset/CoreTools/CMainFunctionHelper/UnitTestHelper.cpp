/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 17:36)

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

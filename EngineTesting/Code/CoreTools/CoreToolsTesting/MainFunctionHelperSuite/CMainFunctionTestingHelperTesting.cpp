///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 18:55)

#include "CMainFunctionTestingHelperTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CoreTools::CMainFunctionTestingHelperTesting::CMainFunctionTestingHelperTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CMainFunctionTestingHelperTesting)

void CoreTools::CMainFunctionTestingHelperTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CMainFunctionTestingHelperTesting::MainTest() noexcept
{
    // CMainFunctionTestingHelperʹ��Toolset�е�CMainFunctionHelper���ԡ�
}

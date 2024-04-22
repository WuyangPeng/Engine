/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/15 14:42)

#include "StaticSingletonTesting.h"
#include "Detail/StaticSingletonSubclass.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::StaticSingletonTesting::StaticSingletonTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, StaticSingletonTesting)

void CoreTools::StaticSingletonTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::StaticSingletonTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StaticSingletonTest);
}

void CoreTools::StaticSingletonTesting::StaticSingletonTest()
{
    ASSERT_UNEQUAL_NULL_PTR(StaticSingletonSubclass::GetSingletonPtr());

    StaticSingletonSubclass::GetSingleton().DoNothing();
}

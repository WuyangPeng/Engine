///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 14:43)

#include "SingletonTesting.h"
#include "Detail/SingletonSubclass.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::SingletonTesting::SingletonTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, SingletonTesting)

void CoreTools::SingletonTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::SingletonTesting::MainTest()
{
    SingletonSubclass::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(SingletonPtrTest);

    SingletonSubclass::Destroy();
}

void CoreTools::SingletonTesting::SingletonPtrTest()
{
    ASSERT_UNEQUAL_NULL_PTR(SingletonSubclass::GetSingletonPtr());

    SingletonSubclass::GetSingleton().DoNothing();
}

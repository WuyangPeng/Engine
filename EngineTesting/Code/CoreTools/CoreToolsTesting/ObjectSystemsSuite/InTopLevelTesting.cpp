///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 15:42)

#include "InTopLevelTesting.h"
#include "Detail/NullObject.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"

#include <vector>

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, InTopLevelTesting)

void CoreTools::InTopLevelTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BasisTest);
}

void CoreTools::InTopLevelTesting::BasisTest() noexcept
{
}

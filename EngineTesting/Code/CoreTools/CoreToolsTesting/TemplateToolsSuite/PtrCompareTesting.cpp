///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/17 19:05)

#include "PtrCompareTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/TemplateTools/PtrCompare.h"

using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, PtrCompareTesting)

void CoreTools::PtrCompareTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PtrCompareTest);
}

void CoreTools::PtrCompareTesting::PtrCompareTest()
{
    auto firstPtr = make_shared<int>(5);
    auto secondPtr = make_shared<int>(-5);

    PtrLess<std::shared_ptr<int>> less;
    PtrGreater<std::shared_ptr<int>> greater;

    ASSERT_TRUE(less(secondPtr, firstPtr));
    ASSERT_TRUE(greater(firstPtr, secondPtr));
}
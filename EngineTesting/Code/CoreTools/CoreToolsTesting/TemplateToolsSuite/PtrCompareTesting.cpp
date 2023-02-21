///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 19:05)

#include "PtrCompareTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/TemplateTools/PtrCompare.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::make_shared;

CoreTools::PtrCompareTesting::PtrCompareTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, PtrCompareTesting)

void CoreTools::PtrCompareTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

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
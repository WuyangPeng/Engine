///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/25 13:47)

#include "PtrCompareTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TemplateTools/PtrCompare.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

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
    const auto ptr0 = std::make_shared<int>(5);
    const auto ptr1 = std::make_shared<int>(-5);

    constexpr PtrLess<std::shared_ptr<int>> less{};
    constexpr PtrGreater<std::shared_ptr<int>> greater{};

    ASSERT_TRUE(less(ptr1, ptr0));
    ASSERT_TRUE(greater(ptr0, ptr1));
}
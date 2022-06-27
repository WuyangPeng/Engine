///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/16 20:41)

#include "ControllerKeyInfoTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/Controllers/ControllerKeyInfo.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, ControllerKeyInfoTesting)

void Rendering::ControllerKeyInfoTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
}

void Rendering::ControllerKeyInfoTesting::InitTest()
{
    const ControllerKeyInfo firstMorphControllerInfo(3.0f, 5, 16);

    ASSERT_APPROXIMATE(firstMorphControllerInfo.GetNormTime(), 3.0f, 1e-8f);
    ASSERT_EQUAL(firstMorphControllerInfo.GetFirstIndex(), 5);
    ASSERT_EQUAL(firstMorphControllerInfo.GetSecondIndex(), 16);
}

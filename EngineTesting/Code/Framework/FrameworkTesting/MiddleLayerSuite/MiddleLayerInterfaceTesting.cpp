///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 20:09)

#include "MiddleLayerInterfaceTesting.h"
#include "MiddleLayerInterfaceTestingBaseDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/MiddleLayer/MiddleLayerInterface.h"

Framework::MiddleLayerInterfaceTesting::MiddleLayerInterfaceTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, MiddleLayerInterfaceTesting)

void Framework::MiddleLayerInterfaceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::MiddleLayerInterfaceTesting::MainTest()
{
    using TestingType = MiddleLayerInterface;

    ASSERT_NOT_THROW_EXCEPTION_0(MiddleLayerMemberTest<TestingType>);
    ASSERT_NOT_THROW_EXCEPTION_0(MiddleLayerTest<TestingType>);
}

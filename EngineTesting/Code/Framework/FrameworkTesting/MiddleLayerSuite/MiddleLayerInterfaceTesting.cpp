///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/14 10:45)

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
    ASSERT_NOT_THROW_EXCEPTION_0(MiddleLayerMemberTest<MiddleLayerInterface>);
    ASSERT_NOT_THROW_EXCEPTION_0(MiddleLayerTest<MiddleLayerInterface>);
}

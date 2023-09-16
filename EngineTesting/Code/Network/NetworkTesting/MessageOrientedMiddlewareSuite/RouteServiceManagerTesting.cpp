///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:54)

#include "RouteServiceManagerTesting.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/MessageOrientedMiddleware/RouteServiceManager.h"

Network::RouteServiceManagerTesting::RouteServiceManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, RouteServiceManagerTesting)

void Network::RouteServiceManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::RouteServiceManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RouteServiceManagerTest);
}

void Network::RouteServiceManagerTesting::RouteServiceManagerTest()
{
    RouteServiceManager::Create(false);

    RouteServiceManager::Destroy();
}

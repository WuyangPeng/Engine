///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/19 09:27)

#include "ActiveMQRouteServiceManagerTesting.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/MessageOrientedMiddleware/RouteServiceManager.h"

Network::ActiveMQRouteServiceManagerTesting::ActiveMQRouteServiceManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, ActiveMQRouteServiceManagerTesting)

void Network::ActiveMQRouteServiceManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::ActiveMQRouteServiceManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RouteServiceManagerTest);
}

void Network::ActiveMQRouteServiceManagerTesting::RouteServiceManagerTest()
{
    RouteServiceManager::Create(true);

    RouteServiceManager::Destroy();
}

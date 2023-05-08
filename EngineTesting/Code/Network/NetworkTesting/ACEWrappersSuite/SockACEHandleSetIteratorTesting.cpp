///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/25 14:22)

#include "SockACEHandleSetIteratorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/HandleSet.h"
#include "Network/Interface/HandleSetIterator.h"
#include "Network/Interface/SockAcceptor.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
Network::SockACEHandleSetIteratorTesting::SockACEHandleSetIteratorTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, SockACEHandleSetIteratorTesting)

void Network::SockACEHandleSetIteratorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::SockACEHandleSetIteratorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::HandleSetTest);
}

void Network::SockACEHandleSetIteratorTesting::HandleSetTest()
{
    HandleSet handleSet{ GetACEServerConfigurationStrategy() };

    HandleSetIterator iterator{ GetACEServerConfigurationStrategy(), handleSet };

    MAYBE_UNUSED auto value = iterator();
}

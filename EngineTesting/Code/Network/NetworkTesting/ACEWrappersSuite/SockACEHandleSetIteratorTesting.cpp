///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 10:53)

#include "SockACEHandleSetIteratorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Interface/HandleSet.h"
#include "Network/Interface/HandleSetIterator.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

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
    const HandleSet handleSet{ GetACEServerConfigurationStrategy() };

    HandleSetIterator iterator{ GetACEServerConfigurationStrategy(), handleSet };

    MAYBE_UNUSED const auto result = iterator();
}

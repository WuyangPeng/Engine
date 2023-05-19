///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/18 10:17)

#include "SockACEHandleSetTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/HandleSet.h"
#include "Network/Interface/SockAcceptor.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

Network::SockACEHandleSetTesting::SockACEHandleSetTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, SockACEHandleSetTesting)

void Network::SockACEHandleSetTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::SockACEHandleSetTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::HandleSetTest);
}

void Network::SockACEHandleSetTesting::HandleSetTest()
{
    HandleSet handleSet{ GetACEServerConfigurationStrategy() };

    MAYBE_UNUSED const auto maxSet = handleSet.GetMaxSet();
    handleSet.SetBit(nullptr);
    handleSet.Sync(nullptr);
    MAYBE_UNUSED const auto isSet = handleSet.IsSet(nullptr);
    handleSet.ClearBit(nullptr);
    MAYBE_UNUSED const auto isFdSetFull = handleSet.IsFdSetFull();
    MAYBE_UNUSED const auto isFdSetCount = handleSet.IsFdSetCount();
    MAYBE_UNUSED const auto select = handleSet.Select(0);
}

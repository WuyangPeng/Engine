// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.2.4 (2020/03/13 16:12)

#include "SockACEHandleSetTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/HandleSet.h"
#include "Network/Interface/SockAcceptor.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, SockACEHandleSetTesting)

void Network::SockACEHandleSetTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::HandleSetTest);
}

void Network::SockACEHandleSetTesting ::HandleSetTest() noexcept
{
    // 	HandleSet handleSet{ GetACEServerConfigurationStrategy() };
    //
    // 	handleSet.GetMaxSet();
    // 	handleSet.SetBit(nullptr);
    // 	handleSet.Sync(nullptr);
    // 	handleSet.IsSet(nullptr);
    // 	handleSet.ClearBit(nullptr);
    // 	handleSet.IsFdSetFull();
    // 	handleSet.IsFdSetCount();
    // 	handleSet.Select(0);
}

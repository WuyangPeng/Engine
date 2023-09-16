///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/16 10:44)

#include "BoostSockAcceptorAsynchronousTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/Interface/SockAddress.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketEvent.h"

Network::BoostSockAcceptorAsynchronousTesting::BoostSockAcceptorAsynchronousTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostSockAcceptorAsynchronousTesting)

void Network::BoostSockAcceptorAsynchronousTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::BoostSockAcceptorAsynchronousTesting::MainTest() noexcept
{
}

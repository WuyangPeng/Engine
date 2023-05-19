///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/18 16:51)

#include "NetworkMainManagerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

Network::NetworkMainManagerTesting::NetworkMainManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NetworkMainManagerTesting)

void Network::NetworkMainManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::NetworkMainManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SingletonTest);
}

void Network::NetworkMainManagerTesting::SingletonTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(NetworkSingletonTest<ClassType>, this, &ClassType::RunTest);
}

void Network::NetworkMainManagerTesting::RunTest()
{
    BASE_MAIN_MANAGER_SINGLETON.Run();
}
///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 16:58)

#include "NetworkMainManagerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, NetworkMainManagerTesting)

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
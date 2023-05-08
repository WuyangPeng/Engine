///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/25 14:18)

#include "ACEMainManagerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
Network::ACEMainManagerTesting::ACEMainManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, ACEMainManagerTesting)

void Network::ACEMainManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::ACEMainManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SingletonTest);
}

void Network::ACEMainManagerTesting::SingletonTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::RunTest);
}

void Network::ACEMainManagerTesting::RunTest()
{
    BASE_MAIN_MANAGER_SINGLETON.Run();
}

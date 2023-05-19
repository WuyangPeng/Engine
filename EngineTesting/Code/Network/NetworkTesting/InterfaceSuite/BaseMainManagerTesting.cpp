///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/15 09:09)

#include "BaseMainManagerTesting.h"
#include "SingletonTestingDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Interface/BaseMainManager.h"

Network::BaseMainManagerTesting::BaseMainManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BaseMainManagerTesting)

void Network::BaseMainManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::BaseMainManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::ACETest);
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::BoostTest);
    ASSERT_NOT_THROW_EXCEPTION_2(ThreadsBoostSingletonTest<ClassType>, this, &ClassType::ThreadsBoostTest);
    ASSERT_NOT_THROW_EXCEPTION_2(MultiContextBoostSingletonTest<ClassType>, this, &ClassType::MultiContextBoostTest);
    ASSERT_NOT_THROW_EXCEPTION_2(NetworkSingletonTest<ClassType>, this, &ClassType::NetworkTest);
    ASSERT_NOT_THROW_EXCEPTION_2(NullSingletonTest<ClassType>, this, &ClassType::NullTest);
}

void Network::BaseMainManagerTesting::ACETest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ACERunTest);
    ASSERT_THROW_EXCEPTION_0(ACEGetIOContextExceptionTest);
    ASSERT_THROW_EXCEPTION_0(ACEStopContextExceptionTest);
    ASSERT_THROW_EXCEPTION_0(ACEIsContextStopExceptionTest);
    ASSERT_THROW_EXCEPTION_0(ACERestartContextExceptionTest);
}

void Network::BaseMainManagerTesting::BoostTest()
{
    MAYBE_UNUSED const auto& ioContext = BASE_MAIN_MANAGER_SINGLETON.GetContext();

    BASE_MAIN_MANAGER_SINGLETON.StopContext();
    ASSERT_FALSE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
    BASE_MAIN_MANAGER_SINGLETON.Run();
    ASSERT_TRUE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
    BASE_MAIN_MANAGER_SINGLETON.RestartContext();
    BASE_MAIN_MANAGER_SINGLETON.StopContext();
    ASSERT_FALSE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
    BASE_MAIN_MANAGER_SINGLETON.Run();
    ASSERT_TRUE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
}

void Network::BaseMainManagerTesting::ThreadsBoostTest()
{
    MAYBE_UNUSED const auto& ioContext = BASE_MAIN_MANAGER_SINGLETON.GetContext();

    BASE_MAIN_MANAGER_SINGLETON.Run();
    BASE_MAIN_MANAGER_SINGLETON.StopContext();
    ASSERT_TRUE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
    BASE_MAIN_MANAGER_SINGLETON.RestartContext();
    BASE_MAIN_MANAGER_SINGLETON.Run();
    BASE_MAIN_MANAGER_SINGLETON.StopContext();
    ASSERT_TRUE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
}

void Network::BaseMainManagerTesting::MultiContextBoostTest()
{
    MAYBE_UNUSED const auto& ioContext = BASE_MAIN_MANAGER_SINGLETON.GetContext();

    BASE_MAIN_MANAGER_SINGLETON.Run();
    BASE_MAIN_MANAGER_SINGLETON.StopContext();
    ASSERT_TRUE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
    BASE_MAIN_MANAGER_SINGLETON.RestartContext();
    BASE_MAIN_MANAGER_SINGLETON.Run();
    BASE_MAIN_MANAGER_SINGLETON.StopContext();
    ASSERT_TRUE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
}

void Network::BaseMainManagerTesting::NetworkTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NetworkRunTest);
    ASSERT_THROW_EXCEPTION_0(NetworkGetIoContextExceptionTest);
    ASSERT_THROW_EXCEPTION_0(NetworkStopContextExceptionTest);
    ASSERT_THROW_EXCEPTION_0(NetworkIsContextStopExceptionTest);
    ASSERT_THROW_EXCEPTION_0(NetworkRestartContextExceptionTest);
}

void Network::BaseMainManagerTesting::ACERunTest()
{
    BASE_MAIN_MANAGER_SINGLETON.Run();
}

void Network::BaseMainManagerTesting::ACEGetIOContextExceptionTest()
{
    MAYBE_UNUSED const auto& ioContext = BASE_MAIN_MANAGER_SINGLETON.GetContext();
}

void Network::BaseMainManagerTesting::ACEStopContextExceptionTest()
{
    BASE_MAIN_MANAGER_SINGLETON.StopContext();
}

void Network::BaseMainManagerTesting::ACEIsContextStopExceptionTest()
{
    MAYBE_UNUSED const auto result = BASE_MAIN_MANAGER_SINGLETON.IsContextStop();
}

void Network::BaseMainManagerTesting::ACERestartContextExceptionTest()
{
    BASE_MAIN_MANAGER_SINGLETON.RestartContext();
}

void Network::BaseMainManagerTesting::NetworkRunTest()
{
    BASE_MAIN_MANAGER_SINGLETON.Run();
}

void Network::BaseMainManagerTesting::NetworkGetIoContextExceptionTest()
{
    MAYBE_UNUSED const auto& ioContext = BASE_MAIN_MANAGER_SINGLETON.GetContext();
}

void Network::BaseMainManagerTesting::NetworkStopContextExceptionTest()
{
    BASE_MAIN_MANAGER_SINGLETON.StopContext();
}

void Network::BaseMainManagerTesting::NetworkIsContextStopExceptionTest()
{
    MAYBE_UNUSED const auto result = BASE_MAIN_MANAGER_SINGLETON.IsContextStop();
}

void Network::BaseMainManagerTesting::NetworkRestartContextExceptionTest()
{
    BASE_MAIN_MANAGER_SINGLETON.RestartContext();
}

void Network::BaseMainManagerTesting::NullTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NullRunTest);
    ASSERT_THROW_EXCEPTION_0(NullGetIoContextExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NullStopContextExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NullIsContextStopExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NullRestartContextExceptionTest);
}

void Network::BaseMainManagerTesting::NullRunTest()
{
    BASE_MAIN_MANAGER_SINGLETON.Run();
}

void Network::BaseMainManagerTesting::NullGetIoContextExceptionTest()
{
    MAYBE_UNUSED const auto& ioContext = BASE_MAIN_MANAGER_SINGLETON.GetContext();
}

void Network::BaseMainManagerTesting::NullStopContextExceptionTest()
{
    BASE_MAIN_MANAGER_SINGLETON.StopContext();
}

void Network::BaseMainManagerTesting::NullIsContextStopExceptionTest()
{
    MAYBE_UNUSED const auto result = BASE_MAIN_MANAGER_SINGLETON.IsContextStop();
}

void Network::BaseMainManagerTesting::NullRestartContextExceptionTest()
{
    BASE_MAIN_MANAGER_SINGLETON.RestartContext();
}

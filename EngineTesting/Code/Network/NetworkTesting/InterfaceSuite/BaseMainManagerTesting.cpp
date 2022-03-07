// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 13:13)

#include "BaseMainManagerTesting.h"
#include "SingletonTestingDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Interface/BaseMainManager.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(Network, BaseMainManager)

void Network::BaseMainManagerTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::ACETest);
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::BoostTest);
    ASSERT_NOT_THROW_EXCEPTION_2(ThreadsBoostSingletonTest<ClassType>, this, &ClassType::ThreadsBoostTest);
    ASSERT_NOT_THROW_EXCEPTION_2(MultiContextBoostSingletonTest<ClassType>, this, &ClassType::MultiContextBoostTest);
    ASSERT_NOT_THROW_EXCEPTION_2(NetworkSingletonTest<ClassType>, this, &ClassType::NetworkTest);
    ASSERT_NOT_THROW_EXCEPTION_2(NullSingletonTest<ClassType>, this, &ClassType::NullTest);
}

void Network::BaseMainManagerTesting ::ACETest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ACERunTest);
    ASSERT_THROW_EXCEPTION_0(ACEGetIOContextExceptionTest);
    ASSERT_THROW_EXCEPTION_0(ACEStopContextExceptionTest);
    ASSERT_THROW_EXCEPTION_0(ACEIsContextStopExceptionTest);
    ASSERT_THROW_EXCEPTION_0(ACERestartContextExceptionTest);
}

void Network::BaseMainManagerTesting ::BoostTest()
{
    [[maybe_unused]] const auto& ioContext = BASE_MAIN_MANAGER_SINGLETON.GetIOContext();

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

void Network::BaseMainManagerTesting ::NullTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NullRunTest);
    ASSERT_THROW_EXCEPTION_0(NullGetIOContextExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NullStopContextExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NullIsContextStopExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NullRestartContextExceptionTest);
}

void Network::BaseMainManagerTesting ::ThreadsBoostTest()
{
    [[maybe_unused]] const auto& ioContext = BASE_MAIN_MANAGER_SINGLETON.GetIOContext();

    BASE_MAIN_MANAGER_SINGLETON.Run();
    BASE_MAIN_MANAGER_SINGLETON.StopContext();
    ASSERT_TRUE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
    BASE_MAIN_MANAGER_SINGLETON.RestartContext();
    BASE_MAIN_MANAGER_SINGLETON.Run();
    BASE_MAIN_MANAGER_SINGLETON.StopContext();
    ASSERT_TRUE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
}

void Network::BaseMainManagerTesting ::MultiContextBoostTest()
{
    [[maybe_unused]] const auto& ioContext = BASE_MAIN_MANAGER_SINGLETON.GetIOContext();

    BASE_MAIN_MANAGER_SINGLETON.Run();
    BASE_MAIN_MANAGER_SINGLETON.StopContext();
    ASSERT_TRUE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
    BASE_MAIN_MANAGER_SINGLETON.RestartContext();
    BASE_MAIN_MANAGER_SINGLETON.Run();
    BASE_MAIN_MANAGER_SINGLETON.StopContext();
    ASSERT_TRUE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
}

void Network::BaseMainManagerTesting ::NetworkTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NetworkRunTest);
    ASSERT_THROW_EXCEPTION_0(NetworkGetIOContextExceptionTest);
    ASSERT_THROW_EXCEPTION_0(NetworkStopContextExceptionTest);
    ASSERT_THROW_EXCEPTION_0(NetworkIsContextStopExceptionTest);
    ASSERT_THROW_EXCEPTION_0(NetworkRestartContextExceptionTest);
}

void Network::BaseMainManagerTesting ::ACERunTest()
{
    BASE_MAIN_MANAGER_SINGLETON.Run();
}

void Network::BaseMainManagerTesting ::ACEGetIOContextExceptionTest()
{
    [[maybe_unused]] const auto& ioContext = BASE_MAIN_MANAGER_SINGLETON.GetIOContext();
}

void Network::BaseMainManagerTesting ::ACEStopContextExceptionTest()
{
    BASE_MAIN_MANAGER_SINGLETON.StopContext();
}

void Network::BaseMainManagerTesting ::ACEIsContextStopExceptionTest()
{
    [[maybe_unused]] const auto value = BASE_MAIN_MANAGER_SINGLETON.IsContextStop();
}

void Network::BaseMainManagerTesting ::ACERestartContextExceptionTest()
{
    BASE_MAIN_MANAGER_SINGLETON.RestartContext();
}

void Network::BaseMainManagerTesting ::NetworkRunTest()
{
    BASE_MAIN_MANAGER_SINGLETON.Run();
}

void Network::BaseMainManagerTesting ::NetworkGetIOContextExceptionTest()
{
    [[maybe_unused]] const auto& ioContext = BASE_MAIN_MANAGER_SINGLETON.GetIOContext();
}

void Network::BaseMainManagerTesting ::NetworkStopContextExceptionTest()
{
    BASE_MAIN_MANAGER_SINGLETON.StopContext();
}

void Network::BaseMainManagerTesting ::NetworkIsContextStopExceptionTest()
{
    [[maybe_unused]] const auto value = BASE_MAIN_MANAGER_SINGLETON.IsContextStop();
}

void Network::BaseMainManagerTesting ::NetworkRestartContextExceptionTest()
{
    BASE_MAIN_MANAGER_SINGLETON.RestartContext();
}

void Network::BaseMainManagerTesting ::NullRunTest()
{
    BASE_MAIN_MANAGER_SINGLETON.Run();
}

void Network::BaseMainManagerTesting ::NullGetIOContextExceptionTest()
{
    [[maybe_unused]] const auto& ioContext = BASE_MAIN_MANAGER_SINGLETON.GetIOContext();
}

void Network::BaseMainManagerTesting ::NullStopContextExceptionTest()
{
    BASE_MAIN_MANAGER_SINGLETON.StopContext();
}

void Network::BaseMainManagerTesting ::NullIsContextStopExceptionTest()
{
    [[maybe_unused]] const auto value = BASE_MAIN_MANAGER_SINGLETON.IsContextStop();
}

void Network::BaseMainManagerTesting ::NullRestartContextExceptionTest()
{
    BASE_MAIN_MANAGER_SINGLETON.RestartContext();
}

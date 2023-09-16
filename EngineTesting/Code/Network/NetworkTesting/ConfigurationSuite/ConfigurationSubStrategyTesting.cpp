///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 10:12)

#include "ConfigurationSubStrategyTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/ConfigurationSubStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

Network::ConfigurationSubStrategyTesting::ConfigurationSubStrategyTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, ConfigurationSubStrategyTesting)

void Network::ConfigurationSubStrategyTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::ConfigurationSubStrategyTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SubStrategyTest);
}

void Network::ConfigurationSubStrategyTesting::SubStrategyTest()
{
    auto configurationSubStrategy = ConfigurationSubStrategy::Create();

    ASSERT_FALSE(configurationSubStrategy.IsExist(WrappersSubStrategy::MultiContext));

    configurationSubStrategy.Insert(WrappersSubStrategy::MultiContext, 2);

    ASSERT_TRUE(configurationSubStrategy.IsExist(WrappersSubStrategy::MultiContext));
    ASSERT_EQUAL(configurationSubStrategy.GetValue(WrappersSubStrategy::MultiContext), 2);
}

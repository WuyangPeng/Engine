// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 10:39)

#include "ConfigurationSubStrategyTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Network/Configuration/ConfigurationSubStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(Network, ConfigurationSubStrategy)

void Network::ConfigurationSubStrategyTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SubStrategyTest);
}

void Network::ConfigurationSubStrategyTesting ::SubStrategyTest()
{
    TestingType configurationSubStrategy = TestingType::Create();

    ASSERT_FALSE(configurationSubStrategy.IsExist(WrappersSubStrategy::MultiContext));

    configurationSubStrategy.Insert(WrappersSubStrategy::MultiContext, 2);

    ASSERT_TRUE(configurationSubStrategy.IsExist(WrappersSubStrategy::MultiContext));
    ASSERT_EQUAL(configurationSubStrategy.GetValue(WrappersSubStrategy::MultiContext), 2);
}

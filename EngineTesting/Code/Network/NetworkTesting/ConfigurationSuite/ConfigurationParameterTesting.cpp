// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 10:39)

#include "ConfigurationParameterTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Network/Configuration/ConfigurationParameter.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(Network, ConfigurationParameter)

void Network::ConfigurationParameterTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ParameterTest);
}

void Network::ConfigurationParameterTesting ::ParameterTest()
{
    TestingType configurationParameter = TestingType::Create();

    configurationParameter.AddParameter(SYSTEM_TEXT("PlatformID"), SYSTEM_TEXT("3"));

    auto parameter = configurationParameter.GetParameter(SYSTEM_TEXT("PlatformID"));

    ASSERT_UNEQUAL(parameter.find(SYSTEM_TEXT("3")), parameter.end());

    ASSERT_TRUE(configurationParameter.IsParameterExist(SYSTEM_TEXT("PlatformID"), SYSTEM_TEXT("3")));
}

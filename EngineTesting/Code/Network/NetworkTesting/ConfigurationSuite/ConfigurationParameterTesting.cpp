///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 15:36)

#include "ConfigurationParameterTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Configuration/ConfigurationParameter.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
Network::ConfigurationParameterTesting::ConfigurationParameterTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, ConfigurationParameterTesting)

void Network::ConfigurationParameterTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::ConfigurationParameterTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ParameterTest);
}

void Network::ConfigurationParameterTesting::ParameterTest()
{
    ConfigurationParameter configurationParameter = ConfigurationParameter::Create();

    configurationParameter.AddParameter(SYSTEM_TEXT("PlatformID"), SYSTEM_TEXT("3"));

    auto parameter = configurationParameter.GetParameter(SYSTEM_TEXT("PlatformID"));

    ASSERT_UNEQUAL(parameter.find(SYSTEM_TEXT("3")), parameter.end());

    ASSERT_TRUE(configurationParameter.IsParameterExist(SYSTEM_TEXT("PlatformID"), SYSTEM_TEXT("3")));
}

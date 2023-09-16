///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 10:12)

#include "ConfigurationParameterTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/ConfigurationParameter.h"

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
    auto configurationParameter = ConfigurationParameter::Create();

    configurationParameter.AddParameter(SYSTEM_TEXT("PlatformId"), SYSTEM_TEXT("3"));

    const auto parameter = configurationParameter.GetParameter(SYSTEM_TEXT("PlatformId"));

    ASSERT_UNEQUAL(parameter.find(SYSTEM_TEXT("3")), parameter.end());

    ASSERT_TRUE(configurationParameter.IsParameterExist(SYSTEM_TEXT("PlatformId"), SYSTEM_TEXT("3")));

    ASSERT_EQUAL(configurationParameter.GetFirstParameter(SYSTEM_TEXT("PlatformId")), SYSTEM_TEXT("3"));
}

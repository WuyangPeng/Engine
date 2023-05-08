///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/24 15:36)

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

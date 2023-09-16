///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 10:13)

#include "ActiveMQProducerTesting.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/AnalysisNetworkConfiguration.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/MessageOrientedMiddleware/Producer.h"
#include "Network/MessageOrientedMiddleware/RouteService.h"
#include "Network/MessageOrientedMiddleware/RouteServiceManager.h"
#include "Network/NetworkMessage/NullMessage.h"

Network::ActiveMQProducerTesting::ActiveMQProducerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, ActiveMQProducerTesting)

void Network::ActiveMQProducerTesting::DoRunUnitTest()
{
    RouteServiceManager::Create(true);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    RouteServiceManager::Destroy();
}

void Network::ActiveMQProducerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ProducerTest);
}

void Network::ActiveMQProducerTesting::ProducerTest()
{
    const AnalysisNetworkConfiguration analysisNetworkConfiguration{ "Configuration/ActiveMQTest.json" };

    Producer producer{ analysisNetworkConfiguration.GetConfigurationStrategy(SYSTEM_TEXT("ActiveMQ")) };

    const auto message = std::make_shared<NullMessage>(MessageHeadStrategy::Default, 5);
    producer.SendServerMessage(SYSTEM_TEXT("Gateway"), message);
}

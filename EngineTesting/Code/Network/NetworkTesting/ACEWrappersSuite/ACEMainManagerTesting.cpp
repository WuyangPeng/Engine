// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 16:10)

#include "ACEMainManagerTesting.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, ACEMainManagerTesting)

void Network::ACEMainManagerTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(SingletonTest);
}

void Network::ACEMainManagerTesting
	::SingletonTest()
{
	ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::RunTest);
}

void Network::ACEMainManagerTesting
	::RunTest()
{
	BASE_MAIN_MANAGER_SINGLETON.Run();
}


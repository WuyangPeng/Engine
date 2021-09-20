// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 13:17)

#include "NetworkUniqueIDManagerTesting.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, NetworkUniqueIDManagerTesting)

void Network::NetworkUniqueIDManagerTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(GetNextUniqueIDTest);
}

void Network::NetworkUniqueIDManagerTesting
	::GetNextUniqueIDTest()
{

}


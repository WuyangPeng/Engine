// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 16:12)

#include "SockACEHandleSetIteratorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/HandleSet.h"
#include "Network/Interface/HandleSetIterator.h"
#include "Network/Interface/SockAcceptor.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, SockACEHandleSetIteratorTesting)

void Network::SockACEHandleSetIteratorTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::HandleSetTest);
}

void Network::SockACEHandleSetIteratorTesting ::HandleSetTest()
{
    HandleSet handleSet{ GetACEServerConfigurationStrategy() };

    HandleSetIterator iterator{ GetACEServerConfigurationStrategy(), handleSet };

    [[maybe_unused]] auto value = iterator();
}

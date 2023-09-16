///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/16 10:10)

#include "UserMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Helper/UserMacro.h"

Network::UserMacroTesting::UserMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, UserMacroTesting)

void Network::UserMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::UserMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CloseNetworkMaxTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MacroExistTest);
}

void Network::UserMacroTesting::CloseNetworkMaxTest()
{
    ASSERT_EQUAL(CLOSE_USE_ACE | CLOSE_USE_OPENSSL | CLOSE_USE_ACE_WCHAR | CLOSE_USE_PROTO_BUF | CLOSE_USE_ACTIVE_MQ | CLOSE_USE_NATS | CLOSE_USE_KAFKA, CLOSE_NETWORK_MAX);
}

void Network::UserMacroTesting::MacroExistTest() noexcept
{
#ifdef NETWORK_USES_ACE_WCHAR

    NETWORK_USE_ACE;

#endif  // NETWORK_USES_ACE_WCHAR

#ifdef NETWORK_USE_PROTO_BUF

    PROTOBUF_USE_DLLS;
    PROTO_BUF_PRAGMA_WARNING;

#endif  // NETWORK_USE_PROTO_BUF

#ifdef BUILDING_NETWORK_STATIC

    BUILDING_STATIC;

#endif  // BUILDING_NETWORK_STATIC

    BOOST_ASIO_NO_DEPRECATED;
}

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:12)

#include "WinSockHostTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Network/DatabasePrototypes.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::WinSockHostTesting::WinSockHostTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WinSockHostTesting)

void System::WinSockHostTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WinSockStartUpTest);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(WinSockCleanupTest);
}

void System::WinSockHostTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetHostByAddressTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetHostNameTest);
}

void System::WinSockHostTesting::GetHostByAddressTest()
{
#ifdef SYSTEM_PLATFORM_WIN32

    const auto serverHostname = "www.sina.com.cn"s;

    InternetAddress address{};
    address.s_addr = GetInternetAddress(serverHostname.c_str());

    const auto winSockHostEnt = GetHostByAddress(&address, ProtocolFamilies::Inet);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(winSockHostEnt, "获取Hostent失败。");

    ASSERT_NOT_THROW_EXCEPTION_1(WinSockHostEntTest, winSockHostEnt);

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::WinSockHostTesting::GetHostNameTest()
{
    CharBufferType buffer{};
    ASSERT_TRUE(GetHostName(buffer.data(), defaultBufferSize));
    const std::string hostName{ buffer.data() };

    ASSERT_FALSE(hostName.empty());

    const auto winSockHostEnt = GetHostByName(hostName.c_str());
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(winSockHostEnt, "获取Hostent失败。");

    ASSERT_NOT_THROW_EXCEPTION_1(WinSockHostEntTest, winSockHostEnt);
}

void System::WinSockHostTesting::WinSockHostEntTest(const WinSockHostEnt* winSockHostEnt)
{
    ASSERT_UNEQUAL_NULL_PTR(winSockHostEnt->h_name);
    ASSERT_UNEQUAL_NULL_PTR(winSockHostEnt->h_aliases);
    ASSERT_EQUAL(winSockHostEnt->h_addrtype, EnumCastUnderlying<uint16_t>(ProtocolFamilies::Inet));
    ASSERT_EQUAL(winSockHostEnt->h_length, boost::numeric_cast<uint16_t>(sizeof(InternetAddress)));
    ASSERT_UNEQUAL_NULL_PTR(winSockHostEnt->h_addr_list);
}

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/07 22:32)

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
    const auto serverHostname = "www.sina.com.cn"s;

    InternetAddress addr{};
    addr.s_addr = GetInternetAddress(serverHostname.c_str());

    const auto winSockHostent = GetHostByAddress(&addr, ProtocolFamilies::Inet);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(winSockHostent, "获取Hostent失败。");

    ASSERT_NOT_THROW_EXCEPTION_1(WinSockHostentTest, winSockHostent);
}

void System::WinSockHostTesting::GetHostNameTest()
{
    BufferType buffer{};
    ASSERT_TRUE(GetHostName(buffer.data(), bufferSize));
    std::string hostName{ buffer.data() };

    ASSERT_FALSE(hostName.empty());

    const auto winSockHostent = GetHostByName(hostName.c_str());
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(winSockHostent, "获取Hostent失败。");

    ASSERT_NOT_THROW_EXCEPTION_1(WinSockHostentTest, winSockHostent);
}

void System::WinSockHostTesting::WinSockHostentTest(const WinSockHostent* winSockHostent)
{
    ASSERT_UNEQUAL_NULL_PTR(winSockHostent->h_name);
    ASSERT_UNEQUAL_NULL_PTR(winSockHostent->h_aliases);
    ASSERT_EQUAL(winSockHostent->h_addrtype, EnumCastUnderlying<uint16_t>(ProtocolFamilies::Inet));
    ASSERT_EQUAL(winSockHostent->h_length, boost::numeric_cast<uint16_t>(sizeof(InternetAddress)));
    ASSERT_UNEQUAL_NULL_PTR(winSockHostent->h_addr_list);
}

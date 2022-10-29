///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/14 16:41)

#include "WinSockHostTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Network/DatabasePrototypes.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/Flags/WindowsExtensionPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "System/Network/WindowsExtensionPrototypes.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

using std::array;
using std::string;
using namespace std::literals;

System::WinSockHostTesting::WinSockHostTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WinSockHostTesting)

void System::WinSockHostTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Init);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(Cleanup);
}

void System::WinSockHostTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ByAddrTest);
}

void System::WinSockHostTesting::Init()
{
    WinSockData wsaData{};

    constexpr auto versionRequested = MakeWord(2, 2);
    const auto startUp = WinSockStartUp(versionRequested, &wsaData);

    ASSERT_ENUM_EQUAL(startUp, WinSockStartUpReturn::Successful);
}

void System::WinSockHostTesting::Cleanup()
{
    const auto cleanup = WinSockCleanup();
    ASSERT_ENUM_EQUAL(cleanup, WinSockCleanupReturn::Successful);
}

void System::WinSockHostTesting::ByAddrTest()
{
    const auto serverHostname = "www.sina.com.cn"s;

    WinSockInAddr addr{};
    addr.s_addr = GetInternetAddress(serverHostname.c_str());

    auto winSockHostent0 = GetHostByAddr(&addr, ProtocolFamilies::Inet);
    ASSERT_UNEQUAL_NULL_PTR(winSockHostent0);

    ASSERT_UNEQUAL_NULL_PTR(winSockHostent0->h_name);
    ASSERT_UNEQUAL_NULL_PTR(winSockHostent0->h_aliases);
    ASSERT_EQUAL(winSockHostent0->h_addrtype, EnumCastUnderlying<uint16_t>(ProtocolFamilies::Inet));
    ASSERT_EQUAL(winSockHostent0->h_length, boost::numeric_cast<uint16_t>(sizeof(WinSockInAddr)));
    ASSERT_UNEQUAL_NULL_PTR(winSockHostent0->h_addr_list);

    constexpr auto bufferSize = 256;
    array<char, bufferSize> buffer{};
    ASSERT_TRUE(GetHostName(buffer.data(), bufferSize));

    ASSERT_FALSE(string{ buffer.data() }.empty());

    auto winSockHostent1 = GetHostByName(buffer.data());
    ASSERT_UNEQUAL_NULL_PTR(winSockHostent1);

    ASSERT_UNEQUAL_NULL_PTR(winSockHostent1->h_name);
    ASSERT_UNEQUAL_NULL_PTR(winSockHostent1->h_aliases);
    ASSERT_EQUAL(winSockHostent1->h_addrtype, EnumCastUnderlying<uint16_t>(ProtocolFamilies::Inet));
    ASSERT_EQUAL(winSockHostent1->h_length, boost::numeric_cast<uint16_t>(sizeof(WinSockInAddr)));
    ASSERT_UNEQUAL_NULL_PTR(winSockHostent1->h_addr_list);
}

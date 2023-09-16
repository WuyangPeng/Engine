///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 11:18)

#include "WinSocketRecvFromTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "System/Network/Using/WindowsSockExUsing.h"
#include "System/Network/WindowsSockEx.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WinSocketRecvFromTesting::WinSocketRecvFromTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WinSocketRecvFromTesting)

void System::WinSocketRecvFromTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WinSockStartUpTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateUdpClientProcessTest);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(WinSockCleanupTest);
}

void System::WinSocketRecvFromTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RecvFromTest);
}

void System::WinSocketRecvFromTesting::RecvFromTest()
{
    const auto socketHandle = GetWinSocket(ProtocolFamilies::Inet, SocketTypes::Dgram, SocketProtocols::Udp, nullptr, 0, 0);
    ASSERT_TRUE_FAILURE_THROW(IsSocketValid(socketHandle), "创建Udp Socket失败。");

    ASSERT_NOT_THROW_EXCEPTION_1(DoRecvFromTest, socketHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSocketTest, socketHandle);
}

void System::WinSocketRecvFromTesting::DoRecvFromTest(WinSocket socketHandle)
{
    const auto address = GetAddress(GetUdpPort(), GetAddress());

    ASSERT_TRUE_FAILURE_THROW(Bind(socketHandle, &address), "Bind Error");

    BufferType buffer{};

    auto index = 0;
    auto remain = bufferSize;

    while (0 < remain)
    {
        WindowsDWord numberOfBytesRecvd{ 0 };

        const auto recvCount = WinSocketRecvFromTest(buffer, index, remain, address, socketHandle, numberOfBytesRecvd);

        if (recvCount == socketError)
        {
            break;
        }

        remain -= boost::numeric_cast<int>(numberOfBytesRecvd);
        index += boost::numeric_cast<int>(numberOfBytesRecvd);
    }

    const std::string result{ buffer.data() };

    ASSERT_EQUAL(result, "Hello");
}

int System::WinSocketRecvFromTesting::WinSocketRecvFromTest(BufferType& buffer, int index, int remain, WinSockInternetAddress address, WinSocket socketHandle, WindowsDWord& numberOfBytesRecvd)
{
    WinSockBuf winSockBuf{};
    winSockBuf.buf = &buffer.at(index);
    winSockBuf.len = remain;

    WindowsDWord flags{ 0 };
    int length{ sizeof(address) };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    const auto recvCount = WinSocketRecvFrom(socketHandle, &winSockBuf, 1, &numberOfBytesRecvd, &flags, reinterpret_cast<WinSockAddress*>(&address), &length, nullptr, nullptr);

#include SYSTEM_WARNING_POP

    ASSERT_UNEQUAL(recvCount, socketError);

    return recvCount;
}

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 10:58)

#include "RecvFromTesting.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::RecvFromTesting::RecvFromTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, RecvFromTesting)

void System::RecvFromTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WinSockStartUpTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateUdpClientProcessTest);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(WinSockCleanupTest);
}

void System::RecvFromTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RecvFromTest);
}

void System::RecvFromTesting::RecvFromTest()
{
    const auto socketHandle = CreateUdpSocket();
    ASSERT_TRUE_FAILURE_THROW(IsSocketValid(socketHandle), "创建Udp Socket失败。");

    ASSERT_NOT_THROW_EXCEPTION_1(DoRecvFromTest, socketHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSocketTest, socketHandle);
}

void System::RecvFromTesting::DoRecvFromTest(WinSocket socketHandle)
{
    auto address = BindInit(socketHandle);

    BufferType buffer{};
    auto index = 0;
    auto remain = bufferSize;
    int length{ sizeof(address) };

    while (0 < remain)
    {
        const auto recvCount = RecvFrom(socketHandle, &buffer.at(index), remain, SocketRecv::Default, &address, &length);

        ASSERT_UNEQUAL(recvCount, socketError);

        if (recvCount == socketError)
        {
            break;
        }

        remain -= recvCount;
        index += recvCount;
    }

    const std::string result{ buffer.data() };

    ASSERT_EQUAL(result, "Hello");
}

System::WinSockInternetAddress System::RecvFromTesting::BindInit(WinSocket socketHandle)
{
    const auto address = GetAddress(GetUdpPort(), GetAddress());

    ASSERT_TRUE_FAILURE_THROW(Bind(socketHandle, &address), "Bind Error");

    return address;
}

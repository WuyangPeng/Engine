/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 16:14)

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
    ASSERT_TRUE_FAILURE_THROW(IsSocketValid(socketHandle), "����Udp Socketʧ�ܡ�");

    ASSERT_NOT_THROW_EXCEPTION_1(DoRecvFromTest, socketHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSocketTest, socketHandle);
}

void System::RecvFromTesting::DoRecvFromTest(WinSocket socketHandle)
{
    auto address = BindInit(socketHandle);

    CharBufferType buffer{};
    auto index = 0;
    auto remain = defaultBufferSize;
    int length{ sizeof(address) };

    while (0 < remain)
    {
        const auto recvCount = RecvFrom(socketHandle, &buffer.at(index), remain, SocketReceive::Default, &address, &length);

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

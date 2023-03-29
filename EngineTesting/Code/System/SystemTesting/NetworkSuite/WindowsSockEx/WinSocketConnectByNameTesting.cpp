///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/11 23:54)

#include "WinSocketConnectByNameTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "System/Network/WindowsSockEx.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WinSocketConnectByNameTesting::WinSocketConnectByNameTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WinSocketConnectByNameTesting)

void System::WinSocketConnectByNameTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WinSockStartUpTest);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(WinSockCleanupTest);
}

void System::WinSocketConnectByNameTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConnectTest);
}

void System::WinSocketConnectByNameTesting::ConnectTest()
{
    const auto socketHandle = GetWinSocket(ProtocolFamilies::Inet, SocketTypes::Stream, SocketProtocols::Tcp, nullptr, 0, 0);

    ASSERT_TRUE_FAILURE_THROW(IsSocketValid(socketHandle), "创建Tcp Socket失败。");

    ASSERT_NOT_THROW_EXCEPTION_1(DoConnectTest, socketHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSocketTest, socketHandle);
}

void System::WinSocketConnectByNameTesting::DoConnectTest(WinSocket socketHandle)
{
    const auto serverHostname = GetConnectHostname();

    ASSERT_TRUE(WinSocketConnectByName(socketHandle,
                                       const_cast<TChar*>(serverHostname.c_str()),
                                       const_cast<TChar*>(SYSTEM_TEXT("80")),
                                       nullptr,
                                       nullptr,
                                       nullptr,
                                       nullptr,
                                       nullptr));

    ASSERT_NOT_THROW_EXCEPTION_1(SendTest, socketHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(RecvTest, socketHandle);
}

void System::WinSocketConnectByNameTesting::SendTest(WinSocket socketHandle)
{
    std::string sendMessage{ "GET /index.html HTTP/1.0\r\n\r\n" };

    std::vector<char> iov{ sendMessage.begin(), sendMessage.end() };

    uint32_t sendNum{ 0 };

    WinSockBuf winSockBuf{};

    do
    {
        winSockBuf.buf = &iov.at(sendNum);
        winSockBuf.len = boost::numeric_cast<uint32_t>(iov.size() - sendNum);

        WindowsDWord numberOfBytesSent{};
        const auto sendResult = WinSocketSend(socketHandle, &winSockBuf, 1, &numberOfBytesSent, 0, nullptr, nullptr);
        if (sendResult == 0)
        {
            sendNum += numberOfBytesSent;
        }
        else
        {
            break;
        }

    } while (sendNum < iov.size());
}

void System::WinSocketConnectByNameTesting::RecvTest(WinSocket socketHandle)
{
    BufferType buffer{};

    auto result = 0;
    std::string data{};

    do
    {
        result = Recv(socketHandle, buffer.data(), bufferSize - 1, SocketRecv::Default);
        ASSERT_LESS_EQUAL(result, bufferSize - 1);

        data += buffer.data();

    } while (0 < result);

    GetStream() << "收到的数据为：" << CoreTools::StringConversion::Utf8ConversionMultiByte(data) << "\n";
    ASSERT_FALSE(data.empty());
}

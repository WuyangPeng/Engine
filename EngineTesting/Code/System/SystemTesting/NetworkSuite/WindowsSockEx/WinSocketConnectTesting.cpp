///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/12 1:39)

#include "WinSocketConnectTesting.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "System/Network/WindowsSockEx.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WinSocketConnectTesting::WinSocketConnectTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WinSocketConnectTesting)

void System::WinSocketConnectTesting::DoConnectTest(WinSocket socketHandle)
{
    const auto serverHostname = CoreTools::StringConversion::StandardConversionMultiByte(GetConnectHostname());

    const auto address = GetAddress(80, serverHostname);

    ASSERT_TRUE(WinSocketConnect(socketHandle, reinterpret_cast<const WinSockAddress*>(&address), sizeof(WinSockAddress), nullptr, nullptr, nullptr, nullptr));

    ASSERT_NOT_THROW_EXCEPTION_1(SendTest, socketHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(RecvTest, socketHandle);
}

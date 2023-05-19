///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/18 10:37)

#include "BoostSockTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Interface/BaseMainManager.h"

Network::BoostSockTesting::BoostSockTesting(const OStreamShared& stream, int increase)
    : ParentType{ stream }, increase{ increase }, messageId{ 5 }, offset{ 0 }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostSockTesting)

void Network::BoostSockTesting::BoostServerThread()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DoBoostServerThread);
}

void Network::BoostSockTesting::DoBoostServerThread()
{
    BASE_MAIN_MANAGER_SINGLETON.Run();
}

void Network::BoostSockTesting::AddOffset() noexcept
{
    constexpr auto engineeringCount = 8;

    offset += engineeringCount;
}

void Network::BoostSockTesting::ClearOffset() noexcept
{
    offset = 0;
}

int Network::BoostSockTesting::GetOffset() const noexcept
{
    return offset;
}

int Network::BoostSockTesting::GetIncrease() const noexcept
{
    return increase;
}

int Network::BoostSockTesting::GetMessageId() const noexcept
{
    return messageId;
}

int Network::BoostSockTesting::GetRealOffset() const noexcept
{
    return increase + offset;
}

int Network::BoostSockTesting::GetRealPort() const noexcept
{
    return GetPort() + GetRealOffset();
}
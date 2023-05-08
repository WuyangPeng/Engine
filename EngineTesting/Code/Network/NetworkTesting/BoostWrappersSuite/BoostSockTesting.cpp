///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/25 14:01)

#include "BoostSockTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/BaseMainManager.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::make_shared;
using std::ostream;

Network::BoostSockTesting::BoostSockTesting(const OStreamShared& stream)
    : ParentType{ stream }, increase{ -1000 }, messageID{ 5 }, offset{ 0 }
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

int Network::BoostSockTesting::GetMessageID() const noexcept
{
    return messageID;
}

int Network::BoostSockTesting::GetRealOffset() const noexcept
{
    return increase + offset;
}

int Network::BoostSockTesting::GetRealPort() const noexcept
{
    return GetPort() + GetRealOffset();
}
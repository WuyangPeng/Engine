// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 16:40)

#include "BoostSockTesting.h" 
#include "CoreTools/Helper/AssertMacro.h" 
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/BaseMainManager.h"

using std::ostream;
using std::make_shared;

Network::BoostSockTesting
	::BoostSockTesting(const OStreamShared& osPtr)
	:ParentType{ osPtr }, m_Increase{ -1000 }, m_MessageID{ 5 }, m_Offset{ 0 }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

 
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostSockTesting)

void Network::BoostSockTesting
	::BoostServerThread()
{
	ASSERT_NOT_THROW_EXCEPTION_0(DoBoostServerThread);
}

void Network::BoostSockTesting
	::DoBoostServerThread()
{
	BASE_MAIN_MANAGER_SINGLETON.Run();
}

void Network::BoostSockTesting
	::AddOffset() noexcept
{
	constexpr auto engineeringCount = 8;

	m_Offset += engineeringCount;
}

void Network::BoostSockTesting
	::ClearOffset() noexcept
{
	m_Offset = 0;
}

int Network::BoostSockTesting
	::GetOffset() const noexcept
{
	return m_Offset;
}

int Network::BoostSockTesting
	::GetIncrease() const noexcept
{
	return m_Increase;
}

int Network::BoostSockTesting
	::GetMessageID() const noexcept
{
	return m_MessageID;
}

int Network::BoostSockTesting
	::GetRealOffset() const noexcept
{
	return m_Increase + m_Offset;
}

int Network::BoostSockTesting
	::GetRealPort() const noexcept
{
	return GetPort() + GetRealOffset();
} 
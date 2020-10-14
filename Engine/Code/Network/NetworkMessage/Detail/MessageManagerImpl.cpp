// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.4 (2020/03/10 16:24)

#include "Network/NetworkExport.h"

#include "MessageManagerImpl.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

using std::string;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26487)
Network::MessageManagerImpl
	::MessageManagerImpl() noexcept
	:m_Factories{}, m_FullVersion{ CoreTools::Version::GetTCREFullVersion() }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, MessageManagerImpl)

Network::MessageManagerImpl::FactoryFunction Network::MessageManagerImpl
	::Find(int64_t messageID, int version) const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	const auto iter = m_Factories.find(messageID);
	if (iter != m_Factories.cend())
	{
		for (const auto& value : iter->second)
		{
			if (value.first.IsVersionsConform(version))
			{
				return value.second;
			}
		}
	}

	THROW_EXCEPTION(SYSTEM_TEXT("找不到指定的工厂函数！"s));
}

void Network::MessageManagerImpl
	::Insert(int64_t messageID, const MessageTypeCondition& messageTypeCondition, FactoryFunction function)
{
	NETWORK_CLASS_IS_VALID_9;

	m_Factories[messageID].insert({ messageTypeCondition, function });
}

void Network::MessageManagerImpl
	::Remove(int64_t messageID, const MessageTypeCondition& messageTypeCondition)
{
	NETWORK_CLASS_IS_VALID_9;

	m_Factories[messageID].erase(messageTypeCondition);

	if (m_Factories[messageID].empty())
	{
		m_Factories.erase(messageID);
	}
}

void Network::MessageManagerImpl
	::Remove(int64_t messageID)
{
	NETWORK_CLASS_IS_VALID_9;

	m_Factories.erase(messageID);
}

void Network::MessageManagerImpl
	::SetFullVersion(int fullVersion) noexcept
{
	NETWORK_CLASS_IS_VALID_9;

	m_FullVersion = fullVersion;
}

int Network::MessageManagerImpl
	::GetFullVersion() const noexcept
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_FullVersion;
}


#include STSTEM_WARNING_POP
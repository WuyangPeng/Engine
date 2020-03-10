// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:24)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_MANAGER_IMPL_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_MANAGER_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/NetworkMessage/MessageInterface.h"
#include "Network/NetworkMessage/MessageTypeCondition.h"
#include "Network/NetworkMessage/MessageTypeConditionOperating.h"

#include <map>
#include <string>

namespace Network
{
	class NETWORK_HIDDEN_DECLARE MessageManagerImpl
	{
	public:
		using ClassType = MessageManagerImpl;
		using FactoryFunction = MessageInterface::FactoryFunction;

	public:
		MessageManagerImpl();

		CLASS_INVARIANT_DECLARE;

	public:
		FactoryFunction Find(int64_t messageID, int version) const;
		void Insert(int64_t messageID, const MessageTypeCondition& messageTypeCondition, FactoryFunction function);
		void Remove(int64_t messageID, const MessageTypeCondition& messageTypeCondition);
		void Remove(int64_t messageID);

		void SetFullVersion(int fullVersion) noexcept;
		int GetFullVersion() const noexcept;

	private:
		using ConditionContainer = std::map<MessageTypeCondition, FactoryFunction, MessageTypeConditionOperating>;
		using FactoryContainer = std::map<int64_t, ConditionContainer>;

	private:
		FactoryContainer m_Factories;
		int m_FullVersion;
	};
}

#endif // NETWORK_NETWORK_MESSAGE_MESSAGE_MANAGER_IMPL_H

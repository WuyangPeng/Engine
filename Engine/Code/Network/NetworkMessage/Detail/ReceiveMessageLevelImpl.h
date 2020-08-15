// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.4 (2020/03/10 14:27)

#ifndef NETWORK_NETWORK_MESSAGE_RECEIVE_MESSAGE_LEVEL_IMPL_H
#define NETWORK_NETWORK_MESSAGE_RECEIVE_MESSAGE_LEVEL_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/NetworkMessage/MessageInterface.h"

#include <map>
#include <vector>

namespace Network
{
	class NETWORK_HIDDEN_DECLARE ReceiveMessageLevelImpl
	{
	public:
		using ClassType = ReceiveMessageLevelImpl;
		using MessageContainer = std::vector<MessageInterfaceSharedPtr>;
		using MessageContainerConstIter = MessageContainer::const_iterator;

	public:
		ReceiveMessageLevelImpl() noexcept;

		CLASS_INVARIANT_DECLARE;

		int GetTopLevelSize() const;
		const ConstMessageInterfaceSharedPtr operator [](int index) const;

		// �Զ���Ķ�����б��档
		void Insert(const MessageInterfaceSharedPtr& message);

		MessageContainerConstIter begin() const noexcept;
		MessageContainerConstIter end() const noexcept;

	private:
		// ������������
		MessageContainer m_TopLevel;
	};
}

#endif // NETWORK_NETWORK_MESSAGE_RECEIVE_MESSAGE_LEVEL_IMPL_H

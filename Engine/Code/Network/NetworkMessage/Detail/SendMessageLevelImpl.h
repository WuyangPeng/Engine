// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.4 (2020/03/10 14:27)

#ifndef NETWORK_NETWORK_MESSAGE_SEND_MESSAGE_LEVEL_IMPL_H
#define NETWORK_NETWORK_MESSAGE_SEND_MESSAGE_LEVEL_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/NetworkMessage/MessageInterface.h"

#include <set>
#include <vector>

namespace Network
{
	class NETWORK_HIDDEN_DECLARE SendMessageLevelImpl
	{
	public:
		using ClassType = SendMessageLevelImpl;

	public:
		explicit SendMessageLevelImpl(int messageMaxSize);

		CLASS_INVARIANT_DECLARE;

		int GetTopLevelSize() const;
		const ConstMessageInterfaceSharedPtr operator [](int index) const;
		MessageInterfaceSharedPtr operator [](int index);

		// �Զ���Ķ�����б��档
		void Insert(const MessageInterfaceSharedPtr& message);

		int GetRemainingSize() const;
		int GetCurrentSize() const;

		void Clear();

	private:
		using MessagePtrContainer = std::vector<MessageInterfaceSharedPtr>;

	private:
		// ������������
		MessagePtrContainer m_TopLevel;
		int m_MessageMaxSize;
		int m_CurrentSize;
	};
}

#endif // NETWORK_NETWORK_MESSAGE_SEND_MESSAGE_LEVEL_IMPL_H

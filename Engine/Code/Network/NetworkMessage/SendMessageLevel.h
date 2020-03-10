// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.4 (2020/03/10 14:38)

#ifndef NETWORK_NETWORK_MESSAGE_SEND_MESSAGE_LEVEL_H
#define NETWORK_NETWORK_MESSAGE_SEND_MESSAGE_LEVEL_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Network/NetworkMessage/MessageInterface.h"

NETWORK_EXPORT_SHARED_PTR(SendMessageLevelImpl);

namespace Network
{
	// �����صĶ������
	class NETWORK_DEFAULT_DECLARE SendMessageLevel
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(SendMessageLevel);

	public:
		explicit SendMessageLevel(int messageMaxSize);

		IMPL_MOVE_AND_COPY_OPERATOR_COMPLETE_DECLARE(SendMessageLevel);

		int GetTopLevelSize() const;
		const ConstMessageInterfaceSharedPtr operator [](int index) const;
		MessageInterfaceSharedPtr operator [](int index);

		// �Զ���Ķ�����б��档
		void Insert(const MessageInterfaceSharedPtr& messagePtr);

		int GetRemainingSize() const;
		int GetCurrentSize() const;

		void Clear();

	private:
		IMPL_TYPE_DECLARE(SendMessageLevel);
	};
}

#endif // NETWORK_NETWORK_MESSAGE_SEND_MESSAGE_LEVEL_H

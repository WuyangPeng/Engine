// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.4 (2020/03/10 14:38)

#ifndef NETWORK_NETWORK_MESSAGE_RECEIVE_MESSAGE_LEVEL_H
#define NETWORK_NETWORK_MESSAGE_RECEIVE_MESSAGE_LEVEL_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Network/NetworkMessage/NetworkMessageInternalFwd.h"

#include <vector>

NETWORK_EXPORT_SHARED_PTR(ReceiveMessageLevelImpl);

namespace Network
{
	class NETWORK_DEFAULT_DECLARE ReceiveMessageLevel
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(ReceiveMessageLevel);
		using MessageContainer = std::vector<MessageInterfaceSharedPtr>;
		using MessageContainerConstIter = MessageContainer::const_iterator;

	public:
		ReceiveMessageLevel();

		IMPL_MOVE_AND_COPY_OPERATOR_COMPLETE_DECLARE(ReceiveMessageLevel);

		int GetTopLevelSize() const;
		const ConstMessageInterfaceSharedPtr operator [](int index) const;

		// 对顶层的对象进行保存。
		void Insert(const MessageInterfaceSharedPtr& message);

		MessageContainerConstIter begin() const;
		MessageContainerConstIter end() const;

	private:
		IMPL_TYPE_DECLARE(ReceiveMessageLevel);
	};
}

#endif // NETWORK_NETWORK_MESSAGE_RECEIVE_MESSAGE_LEVEL_H

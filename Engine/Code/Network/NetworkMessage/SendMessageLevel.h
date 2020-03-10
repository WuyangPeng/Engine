// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.4 (2020/03/10 14:38)

#ifndef NETWORK_NETWORK_MESSAGE_SEND_MESSAGE_LEVEL_H
#define NETWORK_NETWORK_MESSAGE_SEND_MESSAGE_LEVEL_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Network/NetworkMessage/MessageInterface.h"

NETWORK_EXPORT_SHARED_PTR(SendMessageLevelImpl);

namespace Network
{
	// 被加载的顶层对象。
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

		// 对顶层的对象进行保存。
		void Insert(const MessageInterfaceSharedPtr& messagePtr);

		int GetRemainingSize() const;
		int GetCurrentSize() const;

		void Clear();

	private:
		IMPL_TYPE_DECLARE(SendMessageLevel);
	};
}

#endif // NETWORK_NETWORK_MESSAGE_SEND_MESSAGE_LEVEL_H

// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.4 (2020/03/10 14:24)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_ALL_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_ALL_H

#include "Network/NetworkDll.h" 

#include "MessageTypeConditionImpl.h"

namespace Network
{
	class NETWORK_HIDDEN_DECLARE MessageTypeConditionAll : public MessageTypeConditionImpl
	{
	public:
		using ClassType = MessageTypeConditionAll;
		using ParentType = MessageTypeConditionImpl;

	public:
		MessageTypeConditionAll();
		virtual ~MessageTypeConditionAll();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

	public:
		virtual bool IsVersionsConform(int version) const override;
		virtual int GetMinVersion() const override;
		virtual int GetMaxVersion() const override;
	};
}

#endif // NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_ALL_H

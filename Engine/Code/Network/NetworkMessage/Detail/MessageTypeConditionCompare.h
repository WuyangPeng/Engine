// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.4 (2020/03/10 14:24)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_COMPARE_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_COMPARE_H

#include "Network/NetworkDll.h" 

#include "MessageTypeConditionImpl.h" 
#include "Network/NetworkMessage/NetworkMessageInternalFwd.h"

namespace Network
{
	class NETWORK_HIDDEN_DECLARE MessageTypeConditionCompare : public MessageTypeConditionImpl
	{
	public:
		using ClassType = MessageTypeConditionCompare;
		using ParentType = MessageTypeConditionImpl;

	public:
		MessageTypeConditionCompare(VersionsCondition condition, int version);
		virtual ~MessageTypeConditionCompare();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

	public:
		virtual bool IsVersionsConform(int version) const override;
		virtual int GetMinVersion() const override;
		virtual int GetMaxVersion() const override;

	private:
		VersionsCondition m_Condition;
		int m_Version;
	};
}

#endif // NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_COMPARE_H

// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:32)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_OPERATING_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_OPERATING_H

#include "Network/NetworkDll.h" 

#include "CoreTools/Helper/ExportMacro.h" 

namespace Network
{
	class MessageTypeCondition;

	class NETWORK_DEFAULT_DECLARE MessageTypeConditionOperating
	{
	public:
		using ClassType = MessageTypeConditionOperating;

	public:
		MessageTypeConditionOperating();

		CLASS_INVARIANT_DECLARE;

		bool operator()(const MessageTypeCondition& lhs, const MessageTypeCondition& rhs) const;
	};
}

#endif // NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_OPERATING_H

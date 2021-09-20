// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.4 (2020/03/12 13:24)

#include "TestDoubleNullMessage.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Helper/StreamMacro.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"
#include "Network/NetworkMessage/MessageSourceDetail.h"

Network::TestDoubleNullMessage
	::TestDoubleNullMessage(int64_t messageID)
	:ParentType{ messageID }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::TestDoubleNullMessage
	::~TestDoubleNullMessage()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, TestDoubleNullMessage);

CORE_TOOLS_RTTI_DEFINE(Network, TestDoubleNullMessage);
NETWORK_DEFAULT_STREAM_DEFINE(Network, TestDoubleNullMessage);
NETWORK_FACTORY_DEFINE(Network, TestDoubleNullMessage);

int Network::TestDoubleNullMessage
	::GetValue() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return GetMessageID();
}
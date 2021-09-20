// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ²âÊÔ°æ±¾£º0.0.2.4 (2020/03/12 13:24)

#include "TestDoubleIntMessage.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Helper/StreamMacro.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"
#include "Network/NetworkMessage/MessageSourceDetail.h" 

Network::TestDoubleIntMessage
	::TestDoubleIntMessage(int64_t messageID)
	:ParentType{ messageID }, m_IntValue{ 0 }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::TestDoubleIntMessage
	::~TestDoubleIntMessage()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, TestDoubleIntMessage);

CORE_TOOLS_RTTI_DEFINE(Network, TestDoubleIntMessage);
NETWORK_FACTORY_DEFINE(Network, TestDoubleIntMessage);

Network::TestDoubleIntMessage
	::TestDoubleIntMessage(LoadConstructor value, int64_t messageID) noexcept
	: ParentType{ value,messageID }, m_IntValue{ 0 }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

void Network::TestDoubleIntMessage
	::Load(const MessageSourceSharedPtr& source)
{
	NETWORK_CLASS_IS_VALID_9;

	NETWORK_BEGIN_STREAM_LOAD(source);

	ParentType::Load(source);

	source->Read(m_IntValue);

	NETWORK_END_STREAM_LOAD(source);
}

void Network::TestDoubleIntMessage
	::Save(const MessageTargetSharedPtr& target) const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	NETWORK_BEGIN_STREAM_SAVE(target);

	ParentType::Save(target);

	target->Write(m_IntValue);

	NETWORK_END_STREAM_SAVE(target);
}

int Network::TestDoubleIntMessage
	::GetStreamingSize() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return ParentType::GetStreamingSize() + CORE_TOOLS_STREAM_SIZE(m_IntValue);
}

int Network::TestDoubleIntMessage
	::GetIntValue() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_IntValue;
}

void Network::TestDoubleIntMessage
	::SetIntValue(int intValue)
{
	NETWORK_CLASS_IS_VALID_9;

	m_IntValue = intValue;
}

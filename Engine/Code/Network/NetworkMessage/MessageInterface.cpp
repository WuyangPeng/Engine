// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.4 (2020/03/10 16:34)

#include "Network/NetworkExport.h"

#include "MessageInterface.h"
#include "MessageSourceDetail.h"
#include "MessageTargetDetail.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Helper/StreamMacro.h" 
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h" 
#include "CoreTools/ObjectSystems/StreamSize.h"

Network::MessageInterface
	::MessageInterface(int64_t messageID)
	:m_MessageID{ messageID }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::MessageInterface
	::MessageInterface(LoadConstructor value, int64_t messageID)
	:m_MessageID{ messageID }
{
	SYSTEM_UNUSED_ARG(value);

	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::MessageInterface
	::~MessageInterface()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, MessageInterface);
CORE_TOOLS_RTTI_BASE_DEFINE(Network, MessageInterface);
NETWORK_ABSTRACT_FACTORY_DEFINE(Network, MessageInterface);

bool Network::MessageInterface
	::IsExactly(const Rtti& type) const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return GetRttiType().IsExactly(type);
}

bool Network::MessageInterface
	::IsDerived(const Rtti& type) const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return GetRttiType().IsDerived(type);
}

bool Network::MessageInterface
	::IsExactlyTypeOf(const ConstMessageInterfaceSharedPtr& message) const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return message && GetRttiType().IsExactly(message->GetRttiType());
}

bool Network::MessageInterface
	::IsDerivedTypeOf(const ConstMessageInterfaceSharedPtr& message) const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return message && GetRttiType().IsDerived(message->GetRttiType());
}

int Network::MessageInterface
	::GetStreamingSize() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	// 消息号
	auto size = CORE_TOOLS_STREAM_SIZE(m_MessageID);

	return size;
}

void Network::MessageInterface
	::Save(const MessageTargetSharedPtr& target) const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	NETWORK_BEGIN_STREAM_SAVE(target);

	// 写入消息号
	target->Write(m_MessageID);

	NETWORK_END_STREAM_SAVE(target);
}

void Network::MessageInterface
	::Load(const MessageSourceSharedPtr& source)
{
	NETWORK_CLASS_IS_VALID_9;

	NETWORK_BEGIN_STREAM_LOAD(source);

	// 消息号已经在外层读取。

	NETWORK_END_STREAM_LOAD(source);
}

int Network::MessageInterface
	::GetMessageID() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return boost::numeric_cast<int>(m_MessageID);
}

int Network::MessageInterface
	::GetSubMessageID() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return 0;
}

int64_t Network::MessageInterface
	::GetFullMessageID() const noexcept
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_MessageID;
}



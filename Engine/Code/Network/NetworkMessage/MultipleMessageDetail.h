// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 15:56)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_DETAIL_H

#include "MultipleMessage.h" 
#include "MessageManager.h"
#include "MessageSourceDetail.h"
#include "MessageTargetDetail.h"
#include "MessageContainerDetail.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h" 

#include "System/Helper/PragmaWarning/NumericCast.h"

template<typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
Network::MultipleMessage<E, ByteType, Types...>
	::MultipleMessage(int64_t messageID, const MessageType& messageType)
	:ParentType{ messageID }, m_Message{ messageType }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

template<typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
template<typename T, typename... OtherTypes>
Network::MultipleMessage<E, ByteType, Types...>
	::MultipleMessage(int64_t messageID, T value, OtherTypes... otherValue)
	:ParentType{ messageID }, m_Message{ value,otherValue... }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

template<typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
Network::MultipleMessage<E, ByteType, Types...>
	::~MultipleMessage()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template<typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
bool Network::MultipleMessage<E, ByteType, Types...>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template<typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
const CoreTools::Rtti& Network::MultipleMessage<E, ByteType, Types...>
	::GetRttiType() const noexcept
{
	return sm_Type;
}

template<typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
const CoreTools::Rtti Network::MultipleMessage<E, ByteType, Types...>
	::sm_Type
{
	typeid(ClassType).name(),&ParentType::sm_Type
};

template<typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
Network::MessageInterfaceSharedPtr Network::MultipleMessage<E, ByteType, Types...>
	::Factory(const MessageSourceSharedPtr& source, int64_t messageID)
{
	MessageInterfaceSharedPtr object{ std::make_shared<ClassType>(LoadConstructor::ConstructorLoader, messageID) };

	object->Load(source);

	return object;
}

template<typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
Network::MultipleMessage<E, ByteType, Types...>::MultipleMessage(LoadConstructor value, int64_t messageID) noexcept
    : ParentType{ value, messageID }, m_Message{}
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

template<typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
void Network::MultipleMessage<E, ByteType, Types...>
	::Load(const MessageSourceSharedPtr& source)
{
	NETWORK_CLASS_IS_VALID_9;

	NETWORK_BEGIN_STREAM_LOAD(source);

	ParentType::Load(source);

	m_Message.Load(source);

	NETWORK_END_STREAM_LOAD(source);
}

template<typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
void Network::MultipleMessage<E, ByteType, Types...>
	::Save(const MessageTargetSharedPtr& target) const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	NETWORK_BEGIN_STREAM_SAVE(target);

	ParentType::Save(target);

	m_Message.Save(target);

	NETWORK_END_STREAM_SAVE(target);
}

template<typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
int Network::MultipleMessage<E, ByteType, Types...>
	::GetStreamingSize() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return ParentType::GetStreamingSize() + m_Message.GetStreamingSize();
}

template<typename E, Network::MultipleMessageByteType ByteType, Network::MultipleMessageByteType... Types>
int Network::MultipleMessage<E, ByteType, Types...>
	::GetSize() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_Message.GetSize();
}

#endif // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_DETAIL_H
// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.4 (2020/03/10 15:58)

#ifndef NETWORK_NETWORK_MESSAGE_STRING_MESSAGE_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_STRING_MESSAGE_DETAIL_H

#include "StringMessage.h" 
#include "MessageManager.h"
#include "MessageSourceDetail.h"
#include "MessageTargetDetail.h" 
#include "MessageContainerDetail.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h" 

#include "System/Helper/PragmaWarning/NumericCast.h"

template<typename E>
Network::StringMessage<E>
	::StringMessage(int64_t messageID, const StringType& stringType)
	:ParentType{ messageID }, m_String{ stringType }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

template<typename E>
Network::StringMessage<E>
	::~StringMessage()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template<typename E>
bool Network::StringMessage<E>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename E>
const CoreTools::Rtti& Network::StringMessage<E>::GetRttiType() const noexcept
{
    return GetCurrentRttiType();
}

template <typename E>
const CoreTools::Rtti& Network::StringMessage<E>::GetCurrentRttiType() noexcept
{
    static const auto rtti = CoreTools::Rtti{ typeid(ClassType).name(), &ParentType::GetCurrentRttiType() };

    return rtti;
}
template<typename E>
Network::MessageInterfaceSharedPtr Network::StringMessage<E>
	::Factory(const MessageSourceSharedPtr& source, int64_t messageID)
{
	MessageInterfaceSharedPtr object{ std::make_shared<ClassType>(LoadConstructor::ConstructorLoader, messageID) };

	object->Load(source);

	return object;
}

template<typename E>
Network::StringMessage<E>::StringMessage(LoadConstructor value, int64_t messageID) noexcept
    : ParentType{ value, messageID }, m_String{}
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

template<typename E>
void Network::StringMessage<E>
	::Load(const MessageSourceSharedPtr& source)
{
	NETWORK_CLASS_IS_VALID_9;

	NETWORK_BEGIN_STREAM_LOAD(source);

	ParentType::Load(source);

	m_String.Load(source);

	NETWORK_END_STREAM_LOAD(source);
}

template<typename E>
void Network::StringMessage<E>
	::Save(const MessageTargetSharedPtr& target) const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	NETWORK_BEGIN_STREAM_SAVE(target);

	ParentType::Save(target);

	m_String.Save(target);

	NETWORK_END_STREAM_SAVE(target);
}

template<typename E>
int Network::StringMessage<E>
	::GetStreamingSize() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return ParentType::GetStreamingSize() + m_String.GetStreamingSize();
}

template<typename E>
std::string Network::StringMessage<E>
	::GetValue(E index) const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_String.GetValue(index);
}

template<typename E>
int Network::StringMessage<E>
	::GetSize() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_String.GetSize();
}

#endif // NETWORK_NETWORK_MESSAGE_STRING_MESSAGE_DETAIL_H
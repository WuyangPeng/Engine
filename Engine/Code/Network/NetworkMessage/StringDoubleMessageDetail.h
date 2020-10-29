//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 11:40)

#ifndef NETWORK_NETWORK_MESSAGE_STRING_DOUBLE_MESSAGE_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_STRING_DOUBLE_MESSAGE_DETAIL_H

#include "MessageContainerDetail.h"
#include "MessageManager.h"
#include "MessageSourceDetail.h"
#include "MessageTargetDetail.h"
#include "StringDoubleMessage.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

template <typename E>
Network::StringDoubleMessage<E>::StringDoubleMessage(int64_t messageID, const StringType& stringType)
    : ParentType{ messageID }, m_String{ stringType }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename E>
bool Network::StringDoubleMessage<E>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename E>
const CoreTools::Rtti& Network::StringDoubleMessage<E>::GetRttiType() const noexcept
{
    return GetCurrentRttiType();
}

template <typename E>
const CoreTools::Rtti& Network::StringDoubleMessage<E>::GetCurrentRttiType() noexcept
{
    static const auto rtti = CoreTools::Rtti{ typeid(ClassType).name(), &ParentType::GetCurrentRttiType() };

    return rtti;
}

template <typename E>
Network::MessageInterfaceSharedPtr Network::StringDoubleMessage<E>::Factory(const MessageSourceSharedPtr& source, int64_t messageID)
{
    MessageInterfaceSharedPtr object{ std::make_shared<ClassType>(LoadConstructor::ConstructorLoader, messageID) };

    object->Load(source);

    return object;
}

template <typename E>
Network::StringDoubleMessage<E>::StringDoubleMessage(LoadConstructor value, int64_t messageID) noexcept
    : ParentType{ value, messageID }, m_String{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

template <typename E>
void Network::StringDoubleMessage<E>::Load(const MessageSourceSharedPtr& source)
{
    NETWORK_CLASS_IS_VALID_9;

    NETWORK_BEGIN_STREAM_LOAD(source);

    ParentType::Load(source);

    m_String.Load(source);

    NETWORK_END_STREAM_LOAD(source);
}

template <typename E>
void Network::StringDoubleMessage<E>::Save(const MessageTargetSharedPtr& target) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    NETWORK_BEGIN_STREAM_SAVE(target);

    ParentType::Save(target);

    m_String.Save(target);

    NETWORK_END_STREAM_SAVE(target);
}

template <typename E>
int Network::StringDoubleMessage<E>::GetStreamingSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetStreamingSize() + m_String.GetStreamingSize();
}

template <typename E>
std::string Network::StringDoubleMessage<E>::GetValue(E index) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_String.GetValue(index);
}

template <typename E>
int Network::StringDoubleMessage<E>::GetSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_String.GetSize();
}

#endif  // NETWORK_NETWORK_MESSAGE_STRING_DOUBLE_MESSAGE_DETAIL_H
// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 15:43)

#ifndef NETWORK_NETWORK_MESSAGE_INTEGER_MESSAGE_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_INTEGER_MESSAGE_DETAIL_H

#include "IntegerMessage.h"
#include "MessageContainerDetail.h"
#include "MessageManager.h"
#include "MessageSourceDetail.h"
#include "MessageTargetDetail.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

template <typename E>
Network::IntegerMessage<E>::IntegerMessage(int64_t messageID, const IntegerType& integerType)
    : ParentType{ messageID }, m_Integer{ integerType }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

template <typename E>
Network::IntegerMessage<E>::~IntegerMessage()
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename E>
bool Network::IntegerMessage<E>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename E>
const CoreTools::Rtti& Network::IntegerMessage<E>::GetRttiType() const noexcept
{
    return GetCurrentRttiType();
}

template <typename E>
const CoreTools::Rtti& Network::IntegerMessage<E>::GetCurrentRttiType() noexcept
{
    static const auto rtti = CoreTools::Rtti{ typeid(ClassType).name(), &ParentType::GetCurrentRttiType() };

    return rtti;
}

 

template <typename E>
Network::MessageInterfaceSharedPtr Network::IntegerMessage<E>::Factory(const MessageSourceSharedPtr& source, int64_t messageID)
{
    MessageInterfaceSharedPtr object{ std::make_shared<ClassType>(LoadConstructor::ConstructorLoader, messageID) };

    object->Load(source);

    return object;
}

template <typename E>
Network::IntegerMessage<E>::IntegerMessage(LoadConstructor value, int64_t messageID) noexcept
    : ParentType{ value, messageID }, m_Integer{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

template <typename E>
void Network::IntegerMessage<E>::Load(const MessageSourceSharedPtr& source)
{
    NETWORK_CLASS_IS_VALID_9;

    NETWORK_BEGIN_STREAM_LOAD(source);

    ParentType::Load(source);

    m_Integer.Load(source);

    NETWORK_END_STREAM_LOAD(source);
}

template <typename E>
void Network::IntegerMessage<E>::Save(const MessageTargetSharedPtr& target) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    NETWORK_BEGIN_STREAM_SAVE(target);

    ParentType::Save(target);

    m_Integer.Save(target);

    NETWORK_END_STREAM_SAVE(target);
}

template <typename E>
int Network::IntegerMessage<E>::GetStreamingSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetStreamingSize() + m_Integer.GetStreamingSize();
}

template <typename E>
int32_t Network::IntegerMessage<E>::GetValue(E index) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_Integer.GetValue(index);
}

template <typename E>
int Network::IntegerMessage<E>::GetSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_Integer.GetSize();
}

#endif  // NETWORK_NETWORK_MESSAGE_INTEGER_MESSAGE_DETAIL_H
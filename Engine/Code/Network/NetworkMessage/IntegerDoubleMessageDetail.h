///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/18 18:26)

#ifndef NETWORK_NETWORK_MESSAGE_INTEGER_DOUBLE_MESSAGE_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_INTEGER_DOUBLE_MESSAGE_DETAIL_H

#include "IntegerDoubleMessage.h"
#include "MessageContainerDetail.h"
#include "MessageManager.h"
#include "MessageSourceDetail.h"
#include "MessageTargetDetail.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

template <typename E>
Network::IntegerDoubleMessage<E>::IntegerDoubleMessage(int64_t messageID, const IntegerType& integerType)
    : ParentType{ messageID }, integer{ integerType }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename E>
bool Network::IntegerDoubleMessage<E>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename E>
const CoreTools::Rtti& Network::IntegerDoubleMessage<E>::GetRttiType() const noexcept
{
    return GetCurrentRttiType();
}

template <typename E>
const CoreTools::Rtti& Network::IntegerDoubleMessage<E>::GetCurrentRttiType() noexcept
{
    static const auto rtti = CoreTools::Rtti{ typeid(ClassType).name(), &ParentType::GetCurrentRttiType() };

    return rtti;
}

template <typename E>
Network::MessageInterfaceSharedPtr Network::IntegerDoubleMessage<E>::Factory(MessageSource& source, int64_t messageID)
{
    auto object = std::make_shared<ClassType>(LoadConstructor::ConstructorLoader, messageID);

    object->Load(source);

    return object;
}

template <typename E>
Network::IntegerDoubleMessage<E>::IntegerDoubleMessage(LoadConstructor value, int64_t messageID) noexcept
    : ParentType{ value, messageID }, integer{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

template <typename E>
void Network::IntegerDoubleMessage<E>::Load(MessageSource& source)
{
    NETWORK_CLASS_IS_VALID_9;

    NETWORK_BEGIN_STREAM_LOAD(source);

    ParentType::Load(source);

    integer.Load(source);

    NETWORK_END_STREAM_LOAD(source);
}

template <typename E>
void Network::IntegerDoubleMessage<E>::Save(MessageTarget& target) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    NETWORK_BEGIN_STREAM_SAVE(target);

    ParentType::Save(target);

    integer.Save(target);

    NETWORK_END_STREAM_SAVE(target);
}

template <typename E>
int Network::IntegerDoubleMessage<E>::GetStreamingSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return ParentType::GetStreamingSize() + integer.GetStreamingSize();
}

template <typename E>
int32_t Network::IntegerDoubleMessage<E>::GetValue(E index) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return integer.GetValue(index);
}

template <typename E>
int Network::IntegerDoubleMessage<E>::GetSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return integer.GetSize();
}

#endif  // NETWORK_NETWORK_MESSAGE_INTEGER_DOUBLE_MESSAGE_DETAIL_H
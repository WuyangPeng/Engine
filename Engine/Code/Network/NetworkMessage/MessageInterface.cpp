///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.7 (2023/05/05 13:56)

#include "Network/NetworkExport.h"

#include "MessageInterface.h"
#include "MessageSourceDetail.h"
#include "MessageTargetDetail.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

Network::MessageInterface::MessageInterface(MessageHeadStrategy messageHeadStrategy, int64_t messageId) noexcept
    : messageHeadStrategy{ messageHeadStrategy }, messageId{ messageId }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::MessageInterface::~MessageInterface() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::MessageInterface::MessageInterface(LoadConstructor loadConstructor, MessageHeadStrategy messageHeadStrategy, int64_t messageId) noexcept
    : messageHeadStrategy{ messageHeadStrategy }, messageId{ messageId }
{
    System::UnusedFunction(loadConstructor);

    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, MessageInterface);
CORE_TOOLS_RTTI_BASE_DEFINE(Network, MessageInterface);
NETWORK_ABSTRACT_FACTORY_DEFINE(Network, MessageInterface);

bool Network::MessageInterface::IsExactly(const Rtti& type) const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return GetRttiType().IsExactly(type);
}

bool Network::MessageInterface::IsDerived(const Rtti& type) const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return GetRttiType().IsDerived(type);
}

bool Network::MessageInterface::IsExactlyTypeOf(const ConstMessageInterfaceSharedPtr& message) const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return (message != nullptr) && (GetRttiType().IsExactly(message->GetRttiType()));
}

bool Network::MessageInterface::IsDerivedTypeOf(const ConstMessageInterfaceSharedPtr& message) const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return (message != nullptr) && (GetRttiType().IsDerived(message->GetRttiType()));
}

int Network::MessageInterface::GetStreamingSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return GetBaseStreamingSize();
}

int Network::MessageInterface::GetBaseStreamingSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    const auto messageHeadStrategySize = CoreTools::GetStreamSize(messageHeadStrategy);

    if (IsUseSubId(messageHeadStrategy))
    {
        return messageHeadStrategySize + CoreTools::GetStreamSize(messageId);
    }
    else if (IsUseDescribe(messageHeadStrategy))
    {
        return messageHeadStrategySize + CoreTools::GetStreamSize(GetRttiType().GetName());
    }
    else
    {
        return messageHeadStrategySize + CoreTools::GetStreamSize(GetMessageId());
    }
}

void Network::MessageInterface::Save(MessageTarget& target) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    NETWORK_BEGIN_STREAM_SAVE(target);

    target.WriteEnum(messageHeadStrategy);

    if (IsUseSubId(messageHeadStrategy))
    {
        target.Write(messageId);
    }
    else if (IsUseDescribe(messageHeadStrategy))
    {
        target.WriteString(GetRttiType().GetName());
    }
    else
    {
        target.Write(GetMessageId());
    }

    NETWORK_END_STREAM_SAVE(target)
}

void Network::MessageInterface::Load(MessageSource& source)
{
    NETWORK_CLASS_IS_VALID_9;

    NETWORK_BEGIN_STREAM_LOAD(source);

    // 消息号已经在外层读取。

    NETWORK_END_STREAM_LOAD(source)
}

int32_t Network::MessageInterface::GetMessageId() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    if (IsUseSubId(messageHeadStrategy))
    {
        return boost::numeric_cast<int32_t>(GetFullMessageId() >> messageBytes);
    }
    else if (IsUseDescribe(messageHeadStrategy))
    {
        return 0;
    }
    else
    {
        return boost::numeric_cast<int32_t>(GetFullMessageId());
    }
}

int32_t Network::MessageInterface::GetSubMessageId() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    if (IsUseSubId(messageHeadStrategy))
    {
        return boost::numeric_cast<int32_t>(GetFullMessageId() & maxMessageId);
    }
    else
    {
        return 0;
    }
}

int64_t Network::MessageInterface::GetFullMessageId() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    if (IsUseDescribe(messageHeadStrategy))
    {
        return 0;
    }
    else
    {
        return messageId;
    }
}

Network::MessageHeadStrategy Network::MessageInterface::GetMessageHeadStrategy() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return messageHeadStrategy;
}

bool Network::MessageInterface::IsUseProtoBuf() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    using System::operator&;

    return (messageHeadStrategy & MessageHeadStrategy::UseProtoBuf) != MessageHeadStrategy::Default;
}

bool Network::MessageInterface::IsUseJson() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    using System::operator&;

    return (messageHeadStrategy & MessageHeadStrategy::UseJson) != MessageHeadStrategy::Default;
}

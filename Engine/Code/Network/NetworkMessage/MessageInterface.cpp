//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 14:02)

#include "Network/NetworkExport.h"

#include "MessageInterface.h"
#include "MessageSourceDetail.h"
#include "MessageTargetDetail.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
 
Network::MessageInterface::MessageInterface(int64_t messageID) noexcept
    : m_MessageID{ messageID }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::MessageInterface::MessageInterface([[maybe_unused]] LoadConstructor value, int64_t messageID) noexcept
    : m_MessageID{ messageID }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::MessageInterface::~MessageInterface()
{
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

    CoreTools::DisableNoexcept();

    // 消息号
    const auto size = CORE_TOOLS_STREAM_SIZE(m_MessageID);

    return size;
}

void Network::MessageInterface::Save(const MessageTargetSharedPtr& target) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    auto process = target;

    NETWORK_BEGIN_STREAM_SAVE(process);

    // 写入消息号
    process->Write(m_MessageID);

    NETWORK_END_STREAM_SAVE(process);
}

void Network::MessageInterface::Load(const MessageSourceSharedPtr& source)
{
    NETWORK_CLASS_IS_VALID_9;

     auto process = source;

    NETWORK_BEGIN_STREAM_LOAD(process);

    // 消息号已经在外层读取。

    NETWORK_END_STREAM_LOAD(process);
}

int Network::MessageInterface::GetMessageID() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(m_MessageID);
}

int Network::MessageInterface::GetSubMessageID() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    CoreTools::DisableNoexcept();

    return 0;
}

int64_t Network::MessageInterface::GetFullMessageID() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_MessageID;
}

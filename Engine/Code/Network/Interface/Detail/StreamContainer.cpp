//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 12:55)

#include "Network/NetworkExport.h"

#include "StreamContainer.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Configuration/ConfigurationStrategy.h"

using std::make_shared;

Network::StreamContainer::StreamContainer(const ConfigurationStrategy& configurationStrategy, const SockStreamSharedPtr& sockStream)
    : m_SockStream{ sockStream }, m_BufferSendStream{ boost::numeric_cast<uint32_t>(configurationStrategy.GetBufferSize()), configurationStrategy.GetParserStrategy() }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, StreamContainer)

void Network::StreamContainer::SetSockStream(const SockStreamSharedPtr& sockStream) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    m_SockStream = sockStream;
}

Network::SockStreamSharedPtr Network::StreamContainer::GetSockStream() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return m_SockStream;
}

Network::BufferSendStream& Network::StreamContainer::GetBufferSendStream() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return m_BufferSendStream;
}

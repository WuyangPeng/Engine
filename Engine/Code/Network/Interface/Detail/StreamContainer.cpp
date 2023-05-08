///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/21 16:57)

#include "Network/NetworkExport.h"

#include "StreamContainer.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

using std::make_shared;

Network::StreamContainer::StreamContainer(const ConfigurationStrategy& configurationStrategy, const SockStreamSharedPtr& sockStream)
    : m_SockStream{ sockStream }, bufferSendStream{ configurationStrategy.GetConfigurationSubStrategy().GetValue(WrappersSubStrategy::SendBufferSize), configurationStrategy.GetParserStrategy(), configurationStrategy.GetEncryptedCompressionStrategy() }
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

    return bufferSendStream;
}

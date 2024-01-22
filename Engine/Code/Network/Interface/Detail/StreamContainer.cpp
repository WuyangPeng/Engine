/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:28)

#include "Network/NetworkExport.h"

#include "StreamContainer.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

Network::StreamContainer::StreamContainer(const ConfigurationStrategy& configurationStrategy, const SockStreamSharedPtr& sockStream)
    : sockStream{ sockStream }, bufferSendStream{ configurationStrategy.GetConfigurationSubStrategy().GetValue(WrappersSubStrategy::SendBufferSize), configurationStrategy.GetParserStrategy(), configurationStrategy.GetEncryptedCompressionStrategy() }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, StreamContainer)

void Network::StreamContainer::SetSockStream(const SockStreamSharedPtr& aSockStream) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    sockStream = aSockStream;
}

Network::SockStreamSharedPtr Network::StreamContainer::GetSockStream() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return sockStream;
}

Network::BufferSendStream& Network::StreamContainer::GetBufferSendStream() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return bufferSendStream;
}

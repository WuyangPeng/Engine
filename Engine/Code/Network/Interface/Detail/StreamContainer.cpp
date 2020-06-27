// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 11:31)

#include "Network/NetworkExport.h" 

#include "StreamContainer.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"  
#include "Network/Configuration/ConfigurationStrategy.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

using std::make_shared;

Network::StreamContainer
	::StreamContainer(const ConfigurationStrategy& configurationStrategy, const SockStreamSharedPtr& sockStream)
	:m_SockStream{ sockStream }, m_BufferSendStream{ boost::numeric_cast<uint32_t>(configurationStrategy.GetBufferSize()),configurationStrategy.GetParserStrategy() }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, StreamContainer)

void Network::StreamContainer
	::SetSockStream(const SockStreamSharedPtr& sockStream)
{
	NETWORK_CLASS_IS_VALID_9;

	m_SockStream = sockStream;
}

Network::SockStreamSharedPtr Network::StreamContainer
	::GetSockStreamSharedPtr()
{
	NETWORK_CLASS_IS_VALID_9;

	return m_SockStream;
}

Network::BufferSendStream& Network::StreamContainer
	::GetBufferSendStream()
{
	NETWORK_CLASS_IS_VALID_9;

	return m_BufferSendStream;
}



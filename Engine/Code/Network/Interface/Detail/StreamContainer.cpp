// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/01 17:31)

#include "Network/NetworkExport.h" 

#include "StreamContainer.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"  
#include "Network/Configuration/ConfigurationStrategy.h"

#include <boost/numeric/conversion/cast.hpp>

using std::make_shared;

Network::StreamContainer
	::StreamContainer(const ConfigurationStrategy& configurationStrategy, const SockStreamSharedPtr& sockStream)
	:m_SockStream{ sockStream }, m_BufferSendStream{ boost::numeric_cast<uint32_t>(configurationStrategy.GetBufferSize()),configurationStrategy.GetParserStrategy()}
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

 

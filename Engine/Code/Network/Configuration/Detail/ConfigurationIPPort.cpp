// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 12:34)

#include "Network/NetworkExport.h" 

#include "ConfigurationIPPort.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

using std::string;

Network::ConfigurationIPPort
	::ConfigurationIPPort(const string& ip, int port)
	:m_IP{ ip }, m_Port{ port }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ConfigurationIPPort
	::ConfigurationIPPort()
	:m_IP{  }, m_Port{ 0 }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ConfigurationIPPort)

string Network::ConfigurationIPPort
	::GetIP() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_IP;
}

int Network::ConfigurationIPPort
	::GetPort() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_Port;
}


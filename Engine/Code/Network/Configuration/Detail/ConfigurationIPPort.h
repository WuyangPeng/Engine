// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 12:18)

#ifndef NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_PARAMETER_IMPL_H
#define NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_PARAMETER_IMPL_H

#include "Network/NetworkDll.h" 

#include <string>

namespace Network
{
	class NETWORK_HIDDEN_DECLARE ConfigurationIPPort
	{
	public:
		using ClassType = ConfigurationIPPort;

	public:
		ConfigurationIPPort(const std::string& ip, int port);
		ConfigurationIPPort() noexcept;

		CLASS_INVARIANT_DECLARE;

		std::string GetIP() const;
		int GetPort() const noexcept;

	private:
		std::string m_IP;
		int m_Port;
	};
}

#endif // NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_PARAMETER_IMPL_H

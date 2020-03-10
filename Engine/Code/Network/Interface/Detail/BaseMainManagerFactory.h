// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.1.0 (2019/11/29 10:47)


#ifndef NETWORK_NETWORK_INTERFACE_BASE_MAIN_MANAGER_FACTORY_H
#define NETWORK_NETWORK_INTERFACE_BASE_MAIN_MANAGER_FACTORY_H

#include "Network/NetworkDll.h"

#include <memory>

namespace Network
{
	class ConfigurationStrategy;
	class BaseMainManagerImpl;

	class NETWORK_HIDDEN_DECLARE BaseMainManagerFactory
	{
	public:
		using ClassType = BaseMainManagerFactory;
		using ImplType = BaseMainManagerImpl;
		using ImplTypePtr = std::shared_ptr<ImplType>;

	public:
		BaseMainManagerFactory();

		CLASS_INVARIANT_DECLARE;

		static const ImplTypePtr Create(const ConfigurationStrategy& configurationStrategy);
	};
}

#endif // NETWORK_NETWORK_INTERFACE_BASE_MAIN_MANAGER_FACTORY_H

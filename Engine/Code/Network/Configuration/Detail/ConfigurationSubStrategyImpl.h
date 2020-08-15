// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 12:22)

#ifndef NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_FACTORY_IMPL_H
#define NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_FACTORY_IMPL_H

#include "Network/NetworkDll.h" 

#include "Network/Configuration/ConfigurationFwd.h"

#include <map>

namespace Network
{
	class NETWORK_HIDDEN_DECLARE ConfigurationSubStrategyImpl
	{
	public:
		using ClassType = ConfigurationSubStrategyImpl;

	public:
		ConfigurationSubStrategyImpl() noexcept;

		CLASS_INVARIANT_DECLARE;

		bool IsExist(WrappersSubStrategy wrappersSubStrategy) const;
		int GetValue(WrappersSubStrategy wrappersSubStrategy) const;

		void Insert(WrappersSubStrategy wrappersSubStrategy, int value);

	private:
		using Container = std::map<WrappersSubStrategy, int>;

	private:
		Container m_Container;
	};
}

#endif // NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_FACTORY_IMPL_H

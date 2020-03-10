// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 12:31)

#ifndef NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_SUB_STRATEGY_H
#define NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_SUB_STRATEGY_H

#include "Network/NetworkDll.h"

#include "ConfigurationFwd.h"
#include "CoreTools/Helper/ExportMacro.h" 

NETWORK_EXPORT_SHARED_PTR(ConfigurationSubStrategyImpl);

namespace Network
{
	class NETWORK_DEFAULT_DECLARE ConfigurationSubStrategy
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(ConfigurationSubStrategy);

	public:
		ConfigurationSubStrategy();

		IMPL_MOVE_AND_COPY_OPERATOR_COMPLETE_DECLARE(ConfigurationSubStrategy);

		bool IsExist(WrappersSubStrategy wrappersSubStrategy) const;
		int GetValue(WrappersSubStrategy wrappersSubStrategy) const;

		void Insert(WrappersSubStrategy wrappersSubStrategy, int value);

	private:
		IMPL_TYPE_DECLARE(ConfigurationSubStrategy);
	};
}

#endif // NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_SUB_STRATEGY_H

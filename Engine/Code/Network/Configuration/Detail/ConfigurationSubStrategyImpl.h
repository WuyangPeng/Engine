//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/26 19:05)

#ifndef NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_FACTORY_IMPL_H
#define NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_FACTORY_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/Configuration/ConfigurationFwd.h"

#include <map>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ConfigurationSubStrategyImpl final
    {
    public:
        using ClassType = ConfigurationSubStrategyImpl;

    public:
        ConfigurationSubStrategyImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] bool IsExist(WrappersSubStrategy wrappersSubStrategy) const;
        [[nodiscard]] int GetValue(WrappersSubStrategy wrappersSubStrategy) const;

        void Insert(WrappersSubStrategy wrappersSubStrategy, int value);

    private:
        using Container = std::map<WrappersSubStrategy, int>;

    private:
        Container m_Container;
    };
}

#endif  // NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_FACTORY_IMPL_H

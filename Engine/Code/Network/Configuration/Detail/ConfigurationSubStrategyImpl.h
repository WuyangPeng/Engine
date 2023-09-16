///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/04 15:39)

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

        NODISCARD bool IsExist(WrappersSubStrategy wrappersSubStrategy) const;
        NODISCARD int GetValue(WrappersSubStrategy wrappersSubStrategy) const;

        void Insert(WrappersSubStrategy wrappersSubStrategy, int value);

    private:
        using Container = std::map<WrappersSubStrategy, int>;

    private:
        Container container;
    };
}

#endif  // NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_FACTORY_IMPL_H

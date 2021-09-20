//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/26 19:07)

#ifndef NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_SUB_STRATEGY_H
#define NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_SUB_STRATEGY_H

#include "Network/NetworkDll.h"

#include "ConfigurationFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
NETWORK_DELAY_COPY_UNSHARED_EXPORT_IMPL(ConfigurationSubStrategy,ConfigurationSubStrategyImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE ConfigurationSubStrategy final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(ConfigurationSubStrategy);

    public:
        ConfigurationSubStrategy();

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] bool IsExist(WrappersSubStrategy wrappersSubStrategy) const;
        [[nodiscard]] int GetValue(WrappersSubStrategy wrappersSubStrategy) const;

        void Insert(WrappersSubStrategy wrappersSubStrategy, int value);

    private:
        PackageType impl;
    };
}

#endif  // NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_SUB_STRATEGY_H

//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/26 19:06)

#ifndef NETWORK_NETWORK_CONFIGURATION_ANALYSIS_NETWORK_CONFIGURATION_H
#define NETWORK_NETWORK_CONFIGURATION_ANALYSIS_NETWORK_CONFIGURATION_H

#include "Network/NetworkDll.h"

#include "ConfigurationStrategy.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <map>
#include <string>

NETWORK_EXPORT_SHARED_PTR(AnalysisNetworkConfigurationImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE AnalysisNetworkConfiguration final
    {
    public:
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(AnalysisNetworkConfiguration);
        using String = System::String;
        using Container = std::map<String, ConfigurationStrategy>;
        using ContainerConstIter = Container::const_iterator;

    public:
        explicit AnalysisNetworkConfiguration(const std::string& fileName);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] ConfigurationStrategy GetConfigurationStrategy(const String& name) const;
        [[nodiscard]] ContainerConstIter begin() const noexcept;
        [[nodiscard]] ContainerConstIter end() const noexcept;
        [[nodiscard]] int GetSize() const;

    private:
        IMPL_TYPE_DECLARE(AnalysisNetworkConfiguration);
    };
}

#endif  // NETWORK_NETWORK_CONFIGURATION_ANALYSIS_NETWORK_CONFIGURATION_H

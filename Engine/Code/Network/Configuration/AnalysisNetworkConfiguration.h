///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/17 13:38)

#ifndef NETWORK_NETWORK_CONFIGURATION_ANALYSIS_NETWORK_CONFIGURATION_H
#define NETWORK_NETWORK_CONFIGURATION_ANALYSIS_NETWORK_CONFIGURATION_H

#include "Network/NetworkDll.h"

#include "ConfigurationStrategy.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <map>
#include <string>

NETWORK_PERFORMANCE_UNSHARED_EXPORT_IMPL(AnalysisNetworkConfigurationImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE AnalysisNetworkConfiguration final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(AnalysisNetworkConfiguration);
        using String = System::String;
        using Container = std::map<String, ConfigurationStrategy>;
        using ContainerConstIter = Container::const_iterator;

    public:
        explicit AnalysisNetworkConfiguration(const std::string& fileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConfigurationStrategy GetConfigurationStrategy(const String& name) const;
        NODISCARD ContainerConstIter begin() const noexcept;
        NODISCARD ContainerConstIter end() const noexcept;
        NODISCARD int GetSize() const;

    private:
        PackageType impl;
    };
}

#endif  // NETWORK_NETWORK_CONFIGURATION_ANALYSIS_NETWORK_CONFIGURATION_H

// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 12:29)

#ifndef NETWORK_NETWORK_CONFIGURATION_ANALYSIS_NETWORK_CONFIGURATION_H
#define NETWORK_NETWORK_CONFIGURATION_ANALYSIS_NETWORK_CONFIGURATION_H

#include "Network/NetworkDll.h"

#include "ConfigurationStrategy.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "System/Helper/UnicodeUsing.h"

#include <map>
#include <string>

NETWORK_EXPORT_SHARED_PTR(AnalysisNetworkConfigurationImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE AnalysisNetworkConfiguration
    {
    public:
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(AnalysisNetworkConfiguration);
        using String = System::String;
        using Container = std::map<String, ConfigurationStrategy>;
        using ContainerConstIter = Container::const_iterator;

    public:
        explicit AnalysisNetworkConfiguration(const std::string& fileName);        

        CLASS_INVARIANT_DECLARE;

        ConfigurationStrategy GetConfigurationStrategy(const String& name) const;
        ContainerConstIter GetBegin() const noexcept;
        ContainerConstIter GetEnd() const noexcept;
        int GetSize() const;

    private:
        IMPL_TYPE_DECLARE(AnalysisNetworkConfiguration);
    };
}

#endif  // NETWORK_NETWORK_CONFIGURATION_ANALYSIS_NETWORK_CONFIGURATION_H

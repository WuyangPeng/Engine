/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:21)

#ifndef NETWORK_NETWORK_CONFIGURATION_ANALYSIS_NETWORK_CONFIGURATION_IMPL_H
#define NETWORK_NETWORK_CONFIGURATION_ANALYSIS_NETWORK_CONFIGURATION_IMPL_H

#include "Network/NetworkDll.h"

#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Helper/UnicodeUsing.h"
#include "Network/Configuration/ConfigurationStrategy.h"

#include <map>
#include <string>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE AnalysisNetworkConfigurationImpl final
    {
    public:
        using ClassType = AnalysisNetworkConfigurationImpl;

        using String = System::String;
        using Container = std::map<String, ConfigurationStrategy>;
        using ContainerConstIter = Container::const_iterator;

    public:
        explicit AnalysisNetworkConfigurationImpl(std::string fileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConfigurationStrategy GetConfigurationStrategy(const String& name) const;
        NODISCARD ContainerConstIter begin() const noexcept;
        NODISCARD ContainerConstIter end() const noexcept;
        NODISCARD int GetSize() const;

    private:
        using BasicTree = boost::property_tree::basic_ptree<String, String>;

    private:
        void Analysis();
        void AnalysisJson();
        void AnalysisMain();
        void InsertStrategy(const String& name, const BasicTree& basicTree);
        NODISCARD static WrappersStrategy GetWrappersStrategy(const String& wrappers);
        NODISCARD static ConnectStrategy GetConnectStrategy(const String& connect);
        NODISCARD static ConfigurationSubStrategy GetConfigurationSubStrategy(const BasicTree& basicTree);
        NODISCARD static ConfigurationParameter GetConfigurationParameter(const BasicTree& basicTree);

    private:
        Container container;
        std::string fileName;
        BasicTree mainTree;
    };
}

#endif  // NETWORK_NETWORK_CONFIGURATION_ANALYSIS_NETWORK_CONFIGURATION_IMPL_H

//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/26 19:02)

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
        explicit AnalysisNetworkConfigurationImpl(const std::string& fileName);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] ConfigurationStrategy GetConfigurationStrategy(const String& name) const;
        [[nodiscard]] ContainerConstIter begin() const noexcept;
        [[nodiscard]] ContainerConstIter end() const noexcept;
        [[nodiscard]] int GetSize() const;

    private:
        using BasicTree = boost::property_tree::basic_ptree<String, String>;

    private:
        void Analysis();
        void AnalysisJson();
        void AnalysisMain();
        void InsertStrategy(const String& name, const BasicTree& basicTree);
        static WrappersStrategy GetWrappersStrategy(const String& wrappers);
        static ConnectStrategy GetConnectStrategy(const String& connect);
        static ConfigurationSubStrategy GetConfigurationSubStrategy(const BasicTree& basicTree);
        static ConfigurationParameter GetConfigurationParameter(const BasicTree& basicTree);

    private:
        Container m_Container;
        std::string m_FileName;
        BasicTree m_MainTree;
    };
}

#endif  // NETWORK_NETWORK_CONFIGURATION_ANALYSIS_NETWORK_CONFIGURATION_IMPL_H

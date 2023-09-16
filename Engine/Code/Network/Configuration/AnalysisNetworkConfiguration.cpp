///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/04 15:44)

#include "Network/NetworkExport.h"

#include "AnalysisNetworkConfiguration.h"
#include "Detail/AnalysisNetworkConfigurationImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::AnalysisNetworkConfiguration::AnalysisNetworkConfiguration(const std::string& fileName)
    : impl{ fileName }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, AnalysisNetworkConfiguration)

Network::ConfigurationStrategy Network::AnalysisNetworkConfiguration::GetConfigurationStrategy(const String& name) const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetConfigurationStrategy(name);
}

Network::AnalysisNetworkConfiguration::ContainerConstIter Network::AnalysisNetworkConfiguration::begin() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->begin();
}

Network::AnalysisNetworkConfiguration::ContainerConstIter Network::AnalysisNetworkConfiguration::end() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->end();
}

int Network::AnalysisNetworkConfiguration::GetSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetSize();
}

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.7 (2023/04/28 11:01)

#include "Network/NetworkExport.h"

#include "AnalysisNetworkConfiguration.h"
#include "Detail/AnalysisNetworkConfigurationImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Network::AnalysisNetworkConfiguration::AnalysisNetworkConfiguration(const std::string& fileName)
    : impl{ fileName }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, AnalysisNetworkConfiguration)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Network, AnalysisNetworkConfiguration, GetConfigurationStrategy, String, Network::ConfigurationStrategy)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, AnalysisNetworkConfiguration, begin, Network::AnalysisNetworkConfiguration::ContainerConstIter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, AnalysisNetworkConfiguration, end, Network::AnalysisNetworkConfiguration::ContainerConstIter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, AnalysisNetworkConfiguration, GetSize, int)

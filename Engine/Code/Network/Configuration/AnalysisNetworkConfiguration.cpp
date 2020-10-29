//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/26 19:15)

#include "Network/NetworkExport.h"

#include "AnalysisNetworkConfiguration.h"
#include "Detail/AnalysisNetworkConfigurationImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;
using std::string;

Network::AnalysisNetworkConfiguration::AnalysisNetworkConfiguration(const string& fileName)
    : m_Impl{ make_shared<ImplType>(fileName) }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Network, AnalysisNetworkConfiguration)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Network, AnalysisNetworkConfiguration, GetConfigurationStrategy, String, Network::ConfigurationStrategy)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, AnalysisNetworkConfiguration, begin, Network::AnalysisNetworkConfiguration::ContainerConstIter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Network, AnalysisNetworkConfiguration, end, Network::AnalysisNetworkConfiguration::ContainerConstIter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, AnalysisNetworkConfiguration, GetSize, int)

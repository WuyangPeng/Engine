// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 12:38)

#include "Network/NetworkExport.h" 

#include "AnalysisNetworkConfiguration.h"
#include "Detail/AnalysisNetworkConfigurationImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h" 

using std::string;
using std::make_shared;

Network::AnalysisNetworkConfiguration
	::AnalysisNetworkConfiguration(const string& fileName)
	:m_Impl{ make_shared<ImplType>(fileName) }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

PERFORMANCE_COPY_CONSTRUCTION_DEFINE(Network, AnalysisNetworkConfiguration)
IMPL_MOVE_OPERATOR_COMPLETE_DEFINE(Network, AnalysisNetworkConfiguration)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Network, AnalysisNetworkConfiguration, GetConfigurationStrategy, String, Network::ConfigurationStrategy)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, AnalysisNetworkConfiguration, GetBegin, Network::AnalysisNetworkConfiguration::ContainerConstIter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, AnalysisNetworkConfiguration, GetEnd, Network::AnalysisNetworkConfiguration::ContainerConstIter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, AnalysisNetworkConfiguration, GetSize, int)

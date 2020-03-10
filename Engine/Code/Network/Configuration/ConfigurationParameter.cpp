// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.4 (2020/03/10 12:38)

#include "Network/NetworkExport.h" 

#include "ConfigurationParameter.h"
#include "Detail/ConfigurationParameterImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h" 

using std::make_shared;
using std::string;

Network::ConfigurationParameter
	::ConfigurationParameter()
	:m_Impl{ make_shared<ImplType>() }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

IMPL_MOVE_OPERATOR_COMPLETE_DEFINE(Network, ConfigurationParameter)

DELAY_COPY_CONSTRUCTION_DEFINE(Network, ConfigurationParameter)
DELAY_COPY_CONSTRUCTION_SHALLOW_COPY_DEFINE(Network, ConfigurationParameter)

void Network::ConfigurationParameter
	::AddParameter(const String& key, const String& parameter)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->AddParameter(key, parameter);
}

bool Network::ConfigurationParameter
	::IsParameterExist(const String& key, const String& parameter) const
{
	NETWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->IsParameterExist(key, parameter);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Network, ConfigurationParameter, GetParameter, String, const Network::ConfigurationParameter::Parameter);



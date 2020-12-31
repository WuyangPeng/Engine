//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/26 19:15)

#include "Network/NetworkExport.h"

#include "ConfigurationParameter.h"
#include "Detail/ConfigurationParameterImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;
using std::string;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)

Network::ConfigurationParameter::ConfigurationParameter()
    : m_Impl{ make_shared<ImplType>() }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

#include STSTEM_WARNING_POP

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Network, ConfigurationParameter)

DELAY_COPY_CONSTRUCTION_DEFINE(Network, ConfigurationParameter)

void Network::ConfigurationParameter::AddParameter(const String& key, const String& parameter)
{
    IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->AddParameter(key, parameter);
}

bool Network::ConfigurationParameter::IsParameterExist(const String& key, const String& parameter) const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return m_Impl->IsParameterExist(key, parameter);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Network, ConfigurationParameter, GetParameter, String, const Network::ConfigurationParameter::Parameter);

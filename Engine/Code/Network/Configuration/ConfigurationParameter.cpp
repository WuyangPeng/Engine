///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/17 13:53)

#include "Network/NetworkExport.h"

#include "ConfigurationParameter.h"
#include "Detail/ConfigurationParameterImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;
using std::string;

Network::ConfigurationParameter Network::ConfigurationParameter::Create()
{
    return ConfigurationParameter{ CoreTools::DisableNotThrow::Disable };
}

Network::ConfigurationParameter::ConfigurationParameter(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ConfigurationParameter)

void Network::ConfigurationParameter::AddParameter(const String& key, const String& parameter)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->AddParameter(key, parameter);
}

bool Network::ConfigurationParameter::IsParameterExist(const String& key, const String& parameter) const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->IsParameterExist(key, parameter);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Network, ConfigurationParameter, GetParameter, String, Network::ConfigurationParameter::Parameter);
COPY_UNSHARED_CLONE_SELF_DEFINE(Network, ConfigurationParameter)

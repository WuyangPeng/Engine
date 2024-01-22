/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:19)

#include "Network/NetworkExport.h"

#include "ConfigurationParameter.h"
#include "Detail/ConfigurationParameterImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Network, ConfigurationParameter)

Network::ConfigurationParameter Network::ConfigurationParameter::Create()
{
    return ConfigurationParameter{ CoreTools::DisableNotThrow::Disable };
}

Network::ConfigurationParameter::ConfigurationParameter(CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(disableNotThrow);

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

Network::ConfigurationParameter::Parameter Network::ConfigurationParameter::GetParameter(const String& key) const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetParameter(key);
}

Network::ConfigurationParameter::String Network::ConfigurationParameter::GetFirstParameter(const String& key) const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetFirstParameter(key);
}

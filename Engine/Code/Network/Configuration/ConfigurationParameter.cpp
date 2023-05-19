///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.7 (2023/04/28 10:58)

#include "Network/NetworkExport.h"

#include "ConfigurationParameter.h"
#include "Detail/ConfigurationParameterImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

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

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Network, ConfigurationParameter, GetParameter, String, Network::ConfigurationParameter::Parameter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Network, ConfigurationParameter, GetFirstParameter, String, System::String)
COPY_UNSHARED_CLONE_SELF_DEFINE(Network, ConfigurationParameter)

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 17:20)

#include "Network/NetworkExport.h"

#include "ConfigurationParameterImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::ConfigurationParameterImpl::ConfigurationParameterImpl() noexcept
    : container{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ConfigurationParameterImpl)

void Network::ConfigurationParameterImpl::AddParameter(const String& key, const String& parameter)
{
    NETWORK_CLASS_IS_VALID_9;

    container[key].emplace(parameter);
}

bool Network::ConfigurationParameterImpl::IsParameterExist(const String& key, const String& parameter) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    if (const auto iter = container.find(key);
        iter != container.cend())
    {
        return iter->second.contains(parameter);
    }

    return false;
}

Network::ConfigurationParameterImpl::Parameter Network::ConfigurationParameterImpl::GetParameter(const String& key) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    if (const auto iter = container.find(key);
        iter != container.cend())
    {
        return iter->second;
    }

    return Parameter{};
}

Network::ConfigurationParameterImpl::String Network::ConfigurationParameterImpl::GetFirstParameter(const String& key) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    if (const auto parameter = GetParameter(key);
        !parameter.empty())
    {
        return *parameter.begin();
    }
    else
    {
        return String{};
    }
}

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.7 (2023/04/28 09:38)

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

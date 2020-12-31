//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/26 19:11)

#include "Network/NetworkExport.h"

#include "ConfigurationParameterImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::ConfigurationParameterImpl::ConfigurationParameterImpl() noexcept
    : m_Container{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ConfigurationParameterImpl)

void Network::ConfigurationParameterImpl::AddParameter(const String& key, const String& parameter)
{
    NETWORK_CLASS_IS_VALID_9;

    m_Container[key].insert(parameter);
}

bool Network::ConfigurationParameterImpl::IsParameterExist(const String& key, const String& parameter) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    const auto iter = m_Container.find(key);

    if (iter != m_Container.cend())
    {
        return iter->second.find(parameter) != iter->second.cend();
    }

    return false;
}

const Network::ConfigurationParameterImpl::Parameter Network::ConfigurationParameterImpl::GetParameter(const String& key) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    const auto iter = m_Container.find(key);

    if (iter != m_Container.cend())
    {
        return iter->second;
    }

    return Parameter{};
}

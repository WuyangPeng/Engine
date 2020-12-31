//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/26 19:15)

#include "Network/NetworkExport.h"

#include "ConfigurationSubStrategyImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Network::ConfigurationSubStrategyImpl::ConfigurationSubStrategyImpl() noexcept
    : m_Container{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ConfigurationSubStrategyImpl)

bool Network::ConfigurationSubStrategyImpl::IsExist(WrappersSubStrategy wrappersSubStrategy) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    const auto iter = m_Container.find(wrappersSubStrategy);

    return iter != m_Container.cend();
}

int Network::ConfigurationSubStrategyImpl::GetValue(WrappersSubStrategy wrappersSubStrategy) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    const auto iter = m_Container.find(wrappersSubStrategy);

    if (iter != m_Container.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�Ҳ���ָ�����Ӳ��ԡ�"s));
    }
}

void Network::ConfigurationSubStrategyImpl::Insert(WrappersSubStrategy wrappersSubStrategy, int value)
{
    NETWORK_CLASS_IS_VALID_9;

    m_Container.insert({ wrappersSubStrategy, value });
}

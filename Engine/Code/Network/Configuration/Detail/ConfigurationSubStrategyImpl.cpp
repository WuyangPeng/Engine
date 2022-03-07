///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/17 13:53)

#include "Network/NetworkExport.h"

#include "ConfigurationSubStrategyImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Network::ConfigurationSubStrategyImpl::ConfigurationSubStrategyImpl() noexcept
    : container{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ConfigurationSubStrategyImpl)

bool Network::ConfigurationSubStrategyImpl::IsExist(WrappersSubStrategy wrappersSubStrategy) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    const auto iter = container.find(wrappersSubStrategy);

    return iter != container.cend();
}

int Network::ConfigurationSubStrategyImpl::GetValue(WrappersSubStrategy wrappersSubStrategy) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    const auto iter = container.find(wrappersSubStrategy);

    if (iter != container.cend())
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

    container.insert({ wrappersSubStrategy, value });
}

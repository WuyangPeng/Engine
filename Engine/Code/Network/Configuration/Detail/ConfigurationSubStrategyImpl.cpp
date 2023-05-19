///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.7 (2023/04/28 10:01)

#include "Network/NetworkExport.h"

#include "ConfigurationSubStrategyImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

Network::ConfigurationSubStrategyImpl::ConfigurationSubStrategyImpl() noexcept
    : container{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ConfigurationSubStrategyImpl)

bool Network::ConfigurationSubStrategyImpl::IsExist(WrappersSubStrategy wrappersSubStrategy) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    if (const auto iter = container.find(wrappersSubStrategy);
        iter != container.cend())
    {
        return 0 < iter->second;
    }
    else
    {
        return false;
    }
}

int Network::ConfigurationSubStrategyImpl::GetValue(WrappersSubStrategy wrappersSubStrategy) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    if (const auto iter = container.find(wrappersSubStrategy);
        iter != container.cend())
    {
        return iter->second;
    }
    else
    {
        return -1;
    }
}

void Network::ConfigurationSubStrategyImpl::Insert(WrappersSubStrategy wrappersSubStrategy, int value)
{
    NETWORK_CLASS_IS_VALID_9;

    container.emplace(wrappersSubStrategy, value);
}

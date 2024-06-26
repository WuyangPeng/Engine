/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:19)

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

﻿/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:56)

#include "Network/NetworkExport.h"

#include "SessionImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::SessionImpl::SessionImpl(ConfigurationStrategy configurationStrategy) noexcept
    : configurationStrategy{ std::move(configurationStrategy) }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::SessionImpl::~SessionImpl() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::SessionImpl::SessionImpl(SessionImpl&& rhs) noexcept
    : configurationStrategy{ std::move(rhs.configurationStrategy) }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::SessionImpl& Network::SessionImpl::operator=(SessionImpl&& rhs) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    configurationStrategy = std::move(rhs.configurationStrategy);

    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SessionImpl)

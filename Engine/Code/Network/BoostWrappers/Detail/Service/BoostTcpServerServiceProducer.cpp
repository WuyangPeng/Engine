/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:24)

#include "Network/NetworkExport.h"

#include "BoostTcpServerServiceProducer.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/ServiceWrappers/ServiceSession.h"

Network::BoostTcpServerServiceProducer::BoostTcpServerServiceProducer(const ConfigurationStrategy& configurationStrategy) noexcept
    : ParentType{ configurationStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostTcpServerServiceProducer)

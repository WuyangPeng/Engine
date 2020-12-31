//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 15:09)
#include "Network/NetworkExport.h"

#ifdef NETWORK_USE_ACE

    #include "ACEMainManager.h"
    #include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::ACEMainManager::ACEMainManager() noexcept
    : ParentType{}, InterfaceType{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ACEMainManager)

void Network::ACEMainManager::Run() noexcept
{
    NETWORK_CLASS_IS_VALID_9;
}

int Network::ACEMainManager::run_i([[maybe_unused]] int argc, [[maybe_unused]] ACE_TCHAR** argv) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return 0;
}

#endif  // NETWORK_USE_ACE

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 14:01)

#include "Network/NetworkExport.h"

#include "ACEMainManager.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

#ifdef NETWORK_USE_ACE

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

int Network::ACEMainManager::run_i(int argc, ACE_TCHAR** argv) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(argc, argv);

    return 0;
}

#endif  // NETWORK_USE_ACE

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 17:30)

#include "Network/NetworkExport.h"

#include "AceMainManager.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

#ifdef NETWORK_USE_ACE

Network::AceMainManager::AceMainManager() noexcept
    : ParentType{}, InterfaceType{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, AceMainManager)

void Network::AceMainManager::Run() noexcept
{
    NETWORK_CLASS_IS_VALID_9;
}

int Network::AceMainManager::run_i(int argc, ACE_TCHAR** argv) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(argc, argv);

    return 0;
}

#endif  // NETWORK_USE_ACE

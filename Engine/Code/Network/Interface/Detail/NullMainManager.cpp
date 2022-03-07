///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/20 23:40)

#include "Network/NetworkExport.h"

#include "NullMainManager.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Network::NullMainManager::NullMainManager() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NullMainManager)

void Network::NullMainManager::Run() noexcept
{
    NETWORK_CLASS_IS_VALID_9;
}

void Network::NullMainManager::StopContext() noexcept
{
    NETWORK_CLASS_IS_VALID_9;
}

bool Network::NullMainManager::IsContextStop() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return false;
}

void Network::NullMainManager::RestartContext() noexcept
{
    NETWORK_CLASS_IS_VALID_9;
}

//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/28 11:30)

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

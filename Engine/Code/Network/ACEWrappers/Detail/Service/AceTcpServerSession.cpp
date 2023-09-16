///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/15 15:52)

#include "Network/NetworkExport.h"

#include "AceTcpServerSession.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::AceTcpServerSession::AceTcpServerSession(const ConfigurationStrategy& configurationStrategy) noexcept
    : ParentType{ configurationStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, AceTcpServerSession)

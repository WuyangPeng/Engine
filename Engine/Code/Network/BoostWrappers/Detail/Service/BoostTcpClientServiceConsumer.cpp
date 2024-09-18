/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 17:24)

#include "Network/NetworkExport.h"

#include "BoostTcpClientServiceConsumer.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/ServiceWrappers/ServiceSession.h"

Network::BoostTcpClientServiceConsumer::BoostTcpClientServiceConsumer(ServiceSession& serviceSession, const ConfigurationStrategy& configurationStrategy) noexcept
    : ParentType{ configurationStrategy }, serviceSession{ serviceSession }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostTcpClientServiceConsumer)

std::string Network::BoostTcpClientServiceConsumer::Response()
{
    NETWORK_CLASS_IS_VALID_9;

    return serviceSession.Response();
}

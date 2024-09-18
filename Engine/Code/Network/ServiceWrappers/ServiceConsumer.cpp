/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 15:54)

#include "Network/NetworkExport.h"

#include "ServiceConsumer.h"
#include "Detail/ServiceConsumerFactory.h"
#include "Detail/ServiceConsumerImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::ServiceConsumer::ServiceConsumer(ServiceSession& serviceSession, const ConfigurationStrategy& configurationStrategy)
    : impl{ CoreTools::ImplCreateUseFactory::Default, serviceSession, configurationStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ServiceConsumer)

std::string Network::ServiceConsumer::Response()
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->Response();
}

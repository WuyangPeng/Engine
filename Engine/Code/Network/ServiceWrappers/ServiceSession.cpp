/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:54)

#include "Network/NetworkExport.h"

#include "ServiceSession.h"
#include "Detail/ServiceSessionFactory.h"
#include "Detail/ServiceSessionImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::ServiceSession::ServiceSession(const ConfigurationStrategy& configurationStrategy)
    : impl{ CoreTools::ImplCreateUseFactory::Default, configurationStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ServiceSession)

void Network::ServiceSession::SendTextMessage(const std::string& message)
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->SendTextMessage(message);
}

void Network::ServiceSession::Response(const std::function<void(const std::string&)>& processDataCallback)
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->Response(processDataCallback);
}

void Network::ServiceSession::Run()
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->Run();
}

void Network::ServiceSession::Stop()
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->Stop();
}

void Network::ServiceSession::Close()
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->Close();
}

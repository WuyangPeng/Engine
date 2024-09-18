/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.1 (2024/09/18 09:36)

#include "Network/NetworkExport.h"

#include "BoostTcpClientServiceConsumer.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/ServiceWrappers/ServiceSession.h"

Network::BoostTcpClientServiceConsumer::BoostTcpClientServiceConsumer(ServiceSession& serviceSession, const ConfigurationStrategy& configurationStrategy) noexcept
    : ParentType{ configurationStrategy },
      serviceSession{ serviceSession },
      isStop{ false },
      thread{
          [this]() {
              this->Run();
          }
      }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::BoostTcpClientServiceConsumer::~BoostTcpClientServiceConsumer() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;

    EXCEPTION_TRY
    {
        Join();
    }
    EXCEPTION_ALL_CATCH(Network)
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostTcpClientServiceConsumer)

void Network::BoostTcpClientServiceConsumer::Response(const std::function<void(const std::string&)>& processDataCallback)
{
    NETWORK_CLASS_IS_VALID_9;

    return serviceSession.Response(processDataCallback);
}

void Network::BoostTcpClientServiceConsumer::Run()
{
    while (!isStop)
    {
        EXCEPTION_TRY
        {
            serviceSession.Run();
        }
        EXCEPTION_ALL_CATCH(Network)
    }
}

void Network::BoostTcpClientServiceConsumer::Join()
{
    isStop = true;

    serviceSession.Stop();

    thread.join();
}

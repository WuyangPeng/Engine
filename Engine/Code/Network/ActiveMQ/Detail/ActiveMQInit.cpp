///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/15 16:26)

#include "Network/NetworkExport.h"

#include "ActiveMQInit.h"
#include "System/Helper/PragmaWarning/ActiveMQ.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Network::ActiveMQInit::ActiveMQInit(CoreTools::DisableNotThrow disableNotThrow)
{
    System::UnusedFunction(disableNotThrow);

#ifdef NETWORK_USE_ACTIVE_MQ

    activemq::library::ActiveMQCPP::initializeLibrary();

#endif  // NETWORK_USE_ACTIVE_MQ

    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ActiveMQInit::~ActiveMQInit() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;

#ifdef NETWORK_USE_ACTIVE_MQ

    EXCEPTION_TRY
    {
        activemq::library::ActiveMQCPP::shutdownLibrary();
    }
    EXCEPTION_ALL_CATCH(Network)

#endif  // NETWORK_USE_ACTIVE_MQ
}

CLASS_INVARIANT_STUB_DEFINE(Network, ActiveMQInit)

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/15 17:34)

#ifndef NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_PRODUCER_H
#define NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_PRODUCER_H

#include "Network/NetworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "Network/Configuration/ConfigurationFwd.h"
#include "Network/NetworkMessage/MessageInterface.h"

NETWORK_NON_COPY_EXPORT_IMPL(ProducerImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE Producer
    {
    public:
        NON_COPY_TYPE_DECLARE(Producer);
        using String = System::String;

    public:
        explicit Producer(const ConfigurationStrategy& configurationStrategy);

        CLASS_INVARIANT_DECLARE;

        void SendServerMessage(const String& address, const MessageInterfaceSharedPtr& message);

    private:
        PackageType impl;
    };
}

#endif  // NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_PRODUCER_H

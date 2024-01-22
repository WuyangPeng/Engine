/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 16:27)

#ifndef NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_CONSUMER_H
#define NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_CONSUMER_H

#include "Network/NetworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "Network/Configuration/ConfigurationFwd.h"
#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/NetworkMessage/NetworkMessageFwd.h"

NETWORK_NON_COPY_EXPORT_IMPL(ConsumerImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE Consumer
    {
    public:
        NON_COPY_TYPE_DECLARE(Consumer);

        using String = System::String;

    public:
        Consumer(const ConfigurationStrategy& configurationStrategy, const String& address);

        CLASS_INVARIANT_DECLARE;

        NODISCARD MessageEventManager& GetMessageEventManager() noexcept;

        void Insert(int64_t messageId, const NetworkMessageEventSharedPtr& messageEvent);

    private:
        PackageType impl;
    };
}

#endif  // NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_CONSUMER_H

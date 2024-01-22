/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:01)

#ifndef NETWORK_SERVICE_WRAPPERS_SESSION_LISTENER_H
#define NETWORK_SERVICE_WRAPPERS_SESSION_LISTENER_H

#include "Network/NetworkDll.h"

#include "ServiceWrappersFwd.h"

#include <memory>

template class NETWORK_DEFAULT_DECLARE std::weak_ptr<Network::SessionListener>;
template class NETWORK_DEFAULT_DECLARE std::enable_shared_from_this<Network::SessionListener>;

namespace Network
{
    class NETWORK_DEFAULT_DECLARE SessionListener : public std::enable_shared_from_this<SessionListener>
    {
    public:
        using ClassType = SessionListener;

        using SessionSharedPtr = std::shared_ptr<Session>;

    public:
        SessionListener() noexcept = default;
        virtual ~SessionListener() noexcept = default;
        SessionListener(const SessionListener& rhs) noexcept = default;
        SessionListener& operator=(const SessionListener& rhs) noexcept = default;
        SessionListener(SessionListener&& rhs) noexcept = default;
        SessionListener& operator=(SessionListener&& rhs) noexcept = default;

        CLASS_INVARIANT_DECLARE;

        virtual void SessionCreate(const SessionSharedPtr& session) = 0;
        virtual void SessionRemove(const SessionSharedPtr& session) = 0;
        virtual void SessionReceive(const SessionSharedPtr& session) = 0;
    };
}

#endif  // NETWORK_SERVICE_WRAPPERS_SESSION_LISTENER_H

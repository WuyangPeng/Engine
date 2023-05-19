///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/10 10:52)

#ifndef NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_ROUTE_SERVICE_MANAGER_H
#define NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_ROUTE_SERVICE_MANAGER_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"

#include <memory>

NETWORK_EXPORT_UNIQUE_PTR(RouteServiceManager);
NETWORK_NON_COPY_EXPORT_IMPL(RouteServiceManagerImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE RouteServiceManager final : public CoreTools::Singleton<RouteServiceManager>
    {
    public:
        NON_COPY_TYPE_DECLARE(RouteServiceManager);
        using ParentType = Singleton<RouteServiceManager>;

    private:
        enum class RouteServiceManagerCreate
        {
            Init,
        };

    public:
        explicit RouteServiceManager(bool useActiveMQ, RouteServiceManagerCreate routeServiceManagerCreate);

        static void Create(bool useActiveMQ);
        static void Destroy() noexcept;

        SINGLETON_GET_PTR_DECLARE(RouteServiceManager)

        CLASS_INVARIANT_DECLARE;

    private:
        using RouteServiceManagerUniquePtr = std::unique_ptr<RouteServiceManager>;

    private:
        static RouteServiceManagerUniquePtr routeServiceManager;
        PackageType impl;
    };
}

#define ROUTE_SERVICE_MANAGER_SINGLETON Network::RouteServiceManager::GetSingleton()

#endif  // NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_ROUTE_SERVICE_MANAGER_H

//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 20:21)

#ifndef NETWORK_NETWORK_INTERFACE_BASE_MAIN_MANAGER_H
#define NETWORK_NETWORK_INTERFACE_BASE_MAIN_MANAGER_H

#include "Network/NetworkDll.h"

#include "NetworkInternalFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "CoreTools/Threading/ThreadingFwd.h"

NETWORK_EXPORT_UNIQUE_PTR(BaseMainManager);
NETWORK_EXPORT_SHARED_PTR(BaseMainManagerImpl);
EXPORT_NONCOPYABLE_CLASS(NETWORK);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE BaseMainManager final : public CoreTools::Singleton<BaseMainManager>
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(BaseMainManager);
        using ParentType = Singleton<BaseMainManager>;

    private:
        enum class BaseMainManagerCreate
        {
            Init,
        };

    public:
        explicit BaseMainManager(const ConfigurationStrategy& configurationStrategy, BaseMainManagerCreate baseMainManagerCreate);

        static void Create(const ConfigurationStrategy& configurationStrategy);
        static void Destroy() noexcept;

        SINGLETON_GET_PTR_DECLARE(BaseMainManager);

        CLASS_INVARIANT_DECLARE;

    public:
        // BoostMainManager调用Run会阻塞线程。
        void Run();

        [[nodiscard]] IOContextType& GetIOContext();
        void StopContext();
        [[nodiscard]] bool IsContextStop() const;
        void RestartContext();

    private:
        using BaseMainManagerUniquePtr = std::unique_ptr<BaseMainManager>;

    private:
        static BaseMainManagerUniquePtr sm_BaseMainManager;
        IMPL_TYPE_DECLARE(BaseMainManager);
    };
}

#define BASE_MAIN_MANAGER_SINGLETON Network::BaseMainManager::GetSingleton()

#endif  // NETWORK_NETWORK_INTERFACE_BASE_MAIN_MANAGER_H

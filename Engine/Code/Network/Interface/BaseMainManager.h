///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.8 (2023/05/08 17:24)

#ifndef NETWORK_NETWORK_INTERFACE_BASE_MAIN_MANAGER_H
#define NETWORK_NETWORK_INTERFACE_BASE_MAIN_MANAGER_H

#include "Network/NetworkDll.h"

#include "NetworkInternalFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "CoreTools/Threading/ThreadingFwd.h"

NETWORK_EXPORT_UNIQUE_PTR(BaseMainManager);
NETWORK_NON_COPY_EXPORT_IMPL(BaseMainManagerImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE BaseMainManager final : public CoreTools::Singleton<BaseMainManager>
    {
    public:
        NON_COPY_TYPE_DECLARE(BaseMainManager);
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

        SINGLETON_GET_PTR_DECLARE(BaseMainManager)

        CLASS_INVARIANT_DECLARE;

    public:
        // BoostMainManager����Run�������̡߳�
        void Run();

        NODISCARD IoContextType& GetContext();
        void StopContext();
        NODISCARD bool IsContextStop() const;
        void RestartContext();

    private:
        using BaseMainManagerUniquePtr = std::unique_ptr<BaseMainManager>;

    private:
        static BaseMainManagerUniquePtr baseMainManager;
        PackageType impl;
    };
}

#define BASE_MAIN_MANAGER_SINGLETON Network::BaseMainManager::GetSingleton()

#endif  // NETWORK_NETWORK_INTERFACE_BASE_MAIN_MANAGER_H

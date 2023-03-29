///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/17 19:47)

#ifndef CORE_TOOLS_BASE_UNIQUE_ID_MANAGER_H
#define CORE_TOOLS_BASE_UNIQUE_ID_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"

CORE_TOOLS_EXPORT_UNIQUE_PTR(UniqueIdManager);
CORE_TOOLS_NON_COPY_EXPORT_IMPL(UniqueIdManagerImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE UniqueIdManager final : public Singleton<UniqueIdManager>
    {
    public:
        NON_COPY_TYPE_DECLARE(UniqueIdManager);
        using ParentType = Singleton<UniqueIdManager>;

    private:
        enum class UniqueIdManagerCreate
        {
            Init,
        };

    public:
        explicit UniqueIdManager(int count, UniqueIdManagerCreate uniqueIdManagerCreate);

        static void Create(int count);
        static void Destroy() noexcept;

        SINGLETON_GET_PTR_DECLARE(WindowProcessManager)

        CLASS_INVARIANT_DECLARE;

    public:
        NODISCARD int64_t NextUniqueId(int index);
        NODISCARD int64_t NextDefaultUniqueId();

        template <typename E>
        static void Create(E count);

        template <typename E>
        NODISCARD int64_t NextUniqueId(E index);

        template <typename E>
        void SetUniqueId(E index, int64_t latestIndex);

        void SetUniqueId(int index, int64_t latestIndex);

    private:
        using UniqueIdManagerUniquePtr = std::unique_ptr<UniqueIdManager>;

    private:
        static UniqueIdManagerUniquePtr uniqueIdManager;
        PackageType impl;
    };
}

#define UNIQUE_ID_MANAGER_SINGLETON CoreTools::UniqueIdManager::GetSingleton()

#endif  // CORE_TOOLS_BASE_UNIQUE_ID_MANAGER_H

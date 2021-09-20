///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.2 (2021/08/26 19:09)

#ifndef CORE_TOOLS_BASE_UNIQUE_ID_MANAGER_H
#define CORE_TOOLS_BASE_UNIQUE_ID_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"

#include <string>

CORE_TOOLS_EXPORT_UNIQUE_PTR(UniqueIDManager);
CORE_TOOLS_NON_COPY_EXPORT_IMPL(UniqueIDManagerImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE UniqueIDManager final : public CoreTools::Singleton<UniqueIDManager>
    {
    public:
        NON_COPY_TYPE_DECLARE(UniqueIDManager);
        using ParentType = Singleton<UniqueIDManager>;

    private:
        enum class UniqueIDManagerCreate
        {
            Init,
        };

    public:
        explicit UniqueIDManager(int count, MAYBE_UNUSED UniqueIDManagerCreate uniqueIDManagerCreate);

        static void Create(int count);
        static void Destroy() noexcept;

        SINGLETON_GET_PTR_DECLARE(WindowProcessManager);

        CLASS_INVARIANT_DECLARE;

    public:
        NODISCARD uint64_t NextUniqueID(int index);
        NODISCARD uint64_t NextDefaultUniqueID();

        template <typename E>
        static void Create(E count);

        template <typename E>
        NODISCARD uint64_t NextUniqueID(E index);

    private:
        using UniqueIDManagerUniquePtr = std::unique_ptr<UniqueIDManager>;

    private:
        static UniqueIDManagerUniquePtr uniqueIDManager;
        PackageType impl;
    };
}

#define UNIQUE_ID_MANAGER_SINGLETON CoreTools::UniqueIDManager::GetSingleton()

#endif  // CORE_TOOLS_BASE_UNIQUE_ID_MANAGER_H

//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/22 10:44)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_MANAGER_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "ObjectInterface.h"
#include "CoreTools/Base/SingletonDetail.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "CoreTools/Threading/ThreadingFwd.h"

#include <string>

CORE_TOOLS_EXPORT_UNIQUE_PTR(ObjectManager);
CORE_TOOLS_EXPORT_SHARED_PTR(ObjectManagerImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE ObjectManager final : public CoreTools::Singleton<ObjectManager>
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(ObjectManager);
        using ParentType = Singleton<ObjectManager>;

    private:
        enum class ObjectManagerCreate
        {
            Init,
        };

    public:
        explicit ObjectManager(ObjectManagerCreate objectManagerCreate);

        static void Create();
        static void Destroy() noexcept;

        SINGLETON_GET_PTR_DECLARE(ObjectManager);

        CLASS_INVARIANT_DECLARE;

    public:
        using FactoryFunction = ObjectInterface::FactoryFunction;

    public:
        [[nodiscard]] FactoryFunction Find(const std::string& name) const;
        void Insert(const std::string& name, FactoryFunction function);
        void Remove(const std::string& name);

    private:
        using ObjectManagerUniquePtr = std::unique_ptr<ObjectManager>;

    private:
        static ObjectManagerUniquePtr sm_ObjectManager;
        IMPL_TYPE_DECLARE(ObjectManager);
    };
}

#define OBJECT_MANAGER_SINGLETON CoreTools::ObjectManager::GetSingleton()

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_MANAGER_H

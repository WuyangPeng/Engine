//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/22 10:44)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_MANAGER_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "ObjectInterface.h"
#include "CoreTools/Base/SingletonDetail.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "CoreTools/Threading/ThreadingFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include <string>

CORE_TOOLS_EXPORT_UNIQUE_PTR(ObjectManager);
CORE_TOOLS_NON_COPY_EXPORT_IMPL(ObjectManagerImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE ObjectManager final : public CoreTools::Singleton<ObjectManager>
    {
    public:
        NON_COPY_TYPE_DECLARE(ObjectManager);
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
        PackageType impl;
    };
}

#define OBJECT_MANAGER_SINGLETON CoreTools::ObjectManager::GetSingleton()

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_MANAGER_H

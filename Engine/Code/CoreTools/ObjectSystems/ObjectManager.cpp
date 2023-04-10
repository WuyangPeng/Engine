///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/03/30 17:16)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectManager.h"
#include "Detail/ObjectManagerImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

SINGLETON_GET_PTR_DEFINE(CoreTools, ObjectManager);

CoreTools::ObjectManager::ObjectManagerUniquePtr CoreTools::ObjectManager::objectManager{};

void CoreTools::ObjectManager::Create()
{
    objectManager = std::make_unique<ObjectManager>(ObjectManagerCreate::Init);
}

void CoreTools::ObjectManager::Destroy() noexcept
{
    objectManager.reset();
}

CoreTools::ObjectManager::ObjectManager(ObjectManagerCreate objectManagerCreate)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(objectManagerCreate);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ObjectManager)

CoreTools::ObjectManager::FactoryFunction CoreTools::ObjectManager::Find(const std::string& name) const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->Find(name);
}

void CoreTools::ObjectManager::Insert(const std::string& name, FactoryFunction function)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    return impl->Insert(name, function);
}

void CoreTools::ObjectManager::Remove(const std::string& name)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    return impl->Remove(name);
}

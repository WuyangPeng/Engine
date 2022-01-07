///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/24 23:11)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectManager.h"
#include "Detail/ObjectManagerImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"

using std::make_shared;
using std::make_unique;
using std::string;

SINGLETON_GET_PTR_DEFINE(CoreTools, ObjectManager);

CoreTools::ObjectManager::ObjectManagerUniquePtr CoreTools::ObjectManager::objectManager{};

void CoreTools::ObjectManager::Create()
{
    objectManager = make_unique<CoreTools::ObjectManager>(ObjectManagerCreate::Init);
}

void CoreTools::ObjectManager::Destroy() noexcept
{
    objectManager.reset();
}

CoreTools::ObjectManager::ObjectManager(MAYBE_UNUSED ObjectManagerCreate objectManagerCreate)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ObjectManager)

CoreTools::ObjectManager::FactoryFunction CoreTools::ObjectManager::Find(const string& name) const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->Find(name);
}

void CoreTools::ObjectManager::Insert(const string& name, FactoryFunction function)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    return impl->Insert(name, function);
}

void CoreTools::ObjectManager::Remove(const string& name)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    return impl->Remove(name);
}

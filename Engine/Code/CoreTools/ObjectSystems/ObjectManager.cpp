//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/22 16:39)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectManager.h"
#include "Detail/ObjectManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"

using std::string;

using std::make_shared;
using std::make_unique;

SINGLETON_GET_PTR_DEFINE(CoreTools, ObjectManager);

CoreTools::ObjectManager::ObjectManagerUniquePtr CoreTools::ObjectManager::sm_ObjectManager{};

void CoreTools::ObjectManager::Create()
{
    sm_ObjectManager = make_unique<CoreTools::ObjectManager>(ObjectManagerCreate::Init);
}

void CoreTools::ObjectManager::Destroy() noexcept
{
    sm_ObjectManager.reset();
}

CoreTools::ObjectManager::ObjectManager([[maybe_unused]] ObjectManagerCreate objectManagerCreate)
    : impl{  0 }
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

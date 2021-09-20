//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/20 10:28)

#include "CoreTools/CoreToolsExport.h"

#include "SmartPointerManager.h"
#include "Detail/SmartPointerManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"

using std::make_shared;
using std::make_unique;

SINGLETON_GET_PTR_DEFINE(CoreTools, SmartPointerManager);

CoreTools::SmartPointerManager::SmartPointerManagerUniquePtr CoreTools::SmartPointerManager ::sm_SmartPointerManager{};

void CoreTools::SmartPointerManager::Create()
{
    sm_SmartPointerManager = make_unique<CoreTools::SmartPointerManager>(SmartPointerManagerCreate::Init);
}

void CoreTools::SmartPointerManager::Destroy() noexcept
{
    sm_SmartPointerManager.reset();
}

CoreTools::SmartPointerManager::SmartPointerManager([[maybe_unused]] SmartPointerManagerCreate smartPointerManagerCreate)
    : impl{ 0  }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, SmartPointerManager)

int CoreTools::SmartPointerManager::CopyIncreaseReference(const void* data)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    

    return impl->CopyIncreaseReference(data);
}

int CoreTools::SmartPointerManager::IncreaseReference(const void* data)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    

    return impl->IncreaseReference(data);
}

int CoreTools::SmartPointerManager::DecreaseReference(const void* data)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    

    return impl->DecreaseReference(data);
}

bool CoreTools::SmartPointerManager::IsSmartPointer(const void* data) const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->IsSmartPointer(data);
}

///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.2 (2021/08/26 19:10)

#include "CoreTools/CoreToolsExport.h"

#include "UniqueIDManagerDetail.h"

#include "Flags/UniqueIDSelectFlags.h"
#include "Detail/UniqueIDManagerImpl.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#include <memory>

using std::make_shared;
using std::make_unique;
using std::string;

SINGLETON_GET_PTR_DEFINE(CoreTools, UniqueIDManager);

CoreTools::UniqueIDManager::UniqueIDManagerUniquePtr CoreTools::UniqueIDManager::uniqueIDManager{};

void CoreTools::UniqueIDManager::Create(int count)
{
    if (uniqueIDManager != nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�ظ���ʼ��UniqueIDManager��"));
    }

    uniqueIDManager = make_unique<CoreTools::UniqueIDManager>(count, UniqueIDManagerCreate::Init);
}

void CoreTools::UniqueIDManager::Destroy() noexcept
{
    uniqueIDManager.reset();
}

CoreTools::UniqueIDManager::UniqueIDManager(int count, MAYBE_UNUSED UniqueIDManagerCreate uniqueIDManagerCreate)
    : impl{ count }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, UniqueIDManager)

uint64_t CoreTools::UniqueIDManager::NextDefaultUniqueID()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_9;

    return NextUniqueID(UniqueIDSelect::Default);
}

uint64_t CoreTools::UniqueIDManager::NextUniqueID(int index)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->NextUniqueID(index);
}

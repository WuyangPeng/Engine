///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.3 (2023/02/23 16:36)

#include "SingletonSubclass.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::SingletonSubclass::SingletonSubclassUniquePtr CoreTools::SingletonSubclass::singletonSubclass{};

CoreTools::SingletonSubclass::SingletonSubclass(SingletonSubclassCreate singletonSubclassCreate) noexcept
    : ParentType{}
{
    System::UnusedFunction(singletonSubclassCreate);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, SingletonSubclass)

void CoreTools::SingletonSubclass::Create()
{
    if (singletonSubclass != nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�ظ���ʼ��SingletonSubclass��"));
    }

    singletonSubclass = std::make_unique<SingletonSubclass>(SingletonSubclassCreate::Init);
}

void CoreTools::SingletonSubclass::Destroy() noexcept
{
    singletonSubclass.reset();
}

void CoreTools::SingletonSubclass::DoNothing() const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_CONST_9;
}

///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.2 (2021/08/27 11:51)

#include "SingletonSubclass.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::make_unique;

CoreTools::SingletonSubclass::SingletonSubclassUniquePtr CoreTools::SingletonSubclass::singletonSubclass{};

CoreTools::SingletonSubclass::SingletonSubclass(MAYBE_UNUSED SingletonSubclassCreate singletonSubclassCreate) noexcept
    : ParentType{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, SingletonSubclass)

void CoreTools::SingletonSubclass::Create()
{
    if (singletonSubclass != nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�ظ���ʼ��SingletonSubclass��"));
    }

    singletonSubclass = make_unique<SingletonSubclass>(SingletonSubclassCreate::Init);
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
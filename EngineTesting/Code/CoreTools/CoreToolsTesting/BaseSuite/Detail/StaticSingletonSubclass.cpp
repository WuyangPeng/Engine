///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.3 (2023/02/23 16:37)

#include "StaticSingletonSubclass.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::StaticSingletonSubclass::StaticSingletonSubclass(SingletonCreate singletonCreate) noexcept
    : ParentType{ singletonCreate }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, StaticSingletonSubclass)

void CoreTools::StaticSingletonSubclass::DoNothing() const
{
    SINGLETON_SCOPED_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_CONST_9;
}

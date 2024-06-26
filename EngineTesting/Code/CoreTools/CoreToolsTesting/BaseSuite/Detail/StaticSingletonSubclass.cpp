/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/13 21:11)

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
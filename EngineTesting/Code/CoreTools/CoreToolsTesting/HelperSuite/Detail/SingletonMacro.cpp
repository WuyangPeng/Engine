///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/18 15:26)

#include "SingletonMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"

using std::make_unique;

CoreTools::SingletonMacro::SingletonMacroUniquePtr CoreTools::SingletonMacro::singletonMacro;

SINGLETON_GET_PTR_DEFINE(CoreTools, SingletonMacro)
CORE_TOOLS_MUTEX_EXTERN(CoreTools);

CoreTools::SingletonMacro::SingletonMacro(MAYBE_UNUSED SingletonMacroCreate singletonMacroCreate) noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, SingletonMacro)

void CoreTools::SingletonMacro::Create()
{
    SINGLETON_MUTEX_ENTER_GLOBAL(CoreTools);

    singletonMacro = make_unique<CoreTools::SingletonMacro>(SingletonMacroCreate::Init);
}

void CoreTools::SingletonMacro::Destroy() noexcept
{
    EXCEPTION_TRY
    {
        SINGLETON_MUTEX_ENTER_GLOBAL(CoreTools);
    }
    EXCEPTION_ALL_CATCH(CoreTools)

    singletonMacro.reset();
}

void CoreTools::SingletonMacro::DoNothing()
{
    SINGLETON_MUTEX_ENTER_MEMBER;
}

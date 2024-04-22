/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/13 21:09)

#include "SingletonMacro.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"

CoreTools::SingletonMacro::SingletonMacroUniquePtr CoreTools::SingletonMacro::singletonMacro;

SINGLETON_GET_PTR_DEFINE(CoreTools, SingletonMacro)
CORE_TOOLS_MUTEX_EXTERN(CoreTools);

CoreTools::SingletonMacro::SingletonMacro(SingletonMacroCreate singletonMacroCreate) noexcept
{
    System::UnusedFunction(singletonMacroCreate);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, SingletonMacro)

void CoreTools::SingletonMacro::Create()
{
    SINGLETON_MUTEX_ENTER_GLOBAL(CoreTools)

    singletonMacro = std::make_unique<SingletonMacro>(SingletonMacroCreate::Init);
}

void CoreTools::SingletonMacro::Destroy() noexcept
{
    SINGLETON_DESTROY_MUTEX_ENTER_GLOBAL(CoreTools, CoreTools)

    singletonMacro.reset();
}

void CoreTools::SingletonMacro::DoNothing()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    SINGLETON_MUTEX_ENTER_MEMBER;
}

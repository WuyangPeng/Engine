/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 22:21)

#include "CoreTools/CoreToolsExport.h"

#include "InitTerm.h"
#include "InitTermContainer.h"
#include "ObjectManager.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"

#include <array>

CORE_TOOLS_MUTEX_EXTERN(CoreTools);

void CoreTools::InitTerm::AddInitializer(Initializer function)
{
    GetInitializer().AddExecuteFunction(function);
}

void CoreTools::InitTerm::ExecuteInitializer()
{
    SINGLETON_MUTEX_ENTER_GLOBAL(CoreTools)

    ObjectManager::Create();

    GetInitializer().Execute();
}

void CoreTools::InitTerm::AddTerminator(Terminator function)
{
    GetTerminator().AddExecuteFunction(function);
}

void CoreTools::InitTerm::ExecuteTerminator()
{
    SINGLETON_MUTEX_ENTER_GLOBAL(CoreTools)

    GetTerminator().Execute();

    ObjectManager::Destroy();
}

CoreTools::InitTermContainer& CoreTools::InitTerm::GetInitializer() noexcept
{
    static InitTermContainer initializer{};

    return initializer;
}

CoreTools::InitTermContainer& CoreTools::InitTerm::GetTerminator() noexcept
{
    static InitTermContainer terminator{};

    return terminator;
}

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/03/30 17:12)

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
    SINGLETON_MUTEX_ENTER_GLOBAL(CoreTools);

    ObjectManager::Create();

    GetInitializer().Execute();
}

void CoreTools::InitTerm::AddTerminator(Terminator function)
{
    GetTerminator().AddExecuteFunction(function);
}

void CoreTools::InitTerm::ExecuteTerminator()
{
    SINGLETON_MUTEX_ENTER_GLOBAL(CoreTools);

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

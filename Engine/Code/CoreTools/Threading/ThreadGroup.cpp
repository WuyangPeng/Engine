/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 18:11)

#include "CoreTools/CoreToolsExport.h"

#include "ThreadGroup.h"
#include "Detail/ThreadGroupImpl.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::ThreadGroup::ThreadGroup(DisableNotThrow disableNotThrow)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(disableNotThrow);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ThreadGroup)

void CoreTools::ThreadGroup::AddThread(std::thread thread)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    impl->AddThread(std::move(thread));
}

CoreTools::ThreadGroup CoreTools::ThreadGroup::Create()
{
    return ThreadGroup{ DisableNotThrow::Disable };
}

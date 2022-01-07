///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/18 12:28)

#include "CoreTools/CoreToolsExport.h"

#include "ThreadGroup.h"
#include "Detail/ThreadGroupImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"

CoreTools::ThreadGroup::ThreadGroup(MAYBE_UNUSED DisableNotThrow disableNotThrow)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
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

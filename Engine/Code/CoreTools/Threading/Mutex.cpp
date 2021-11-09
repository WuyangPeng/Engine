///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.3 (2021/09/01 13:20)

#include "CoreTools/CoreToolsExport.h"

#include "Mutex.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::Mutex::Mutex(MutexCreate mutexCreate)
    : ParentType{ mutexCreate }
{
    ParentType::Initialize();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::Mutex::Mutex(Mutex&& rhs) noexcept
    : ParentType{ std::move(rhs) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::Mutex& CoreTools::Mutex::operator=(Mutex&& rhs) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    ParentType::operator=(std::move(rhs));

    return *this;
}

CoreTools::Mutex::~Mutex() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    ParentType::Delete();
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, Mutex)

void CoreTools::Mutex::Initialize() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;
}

void CoreTools::Mutex::Delete() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;
}

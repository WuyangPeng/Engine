/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/30 18:11)

#include "CoreTools/CoreToolsExport.h"

#include "Mutex.h"
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

    if (this != &rhs)
    {
        ParentType::operator=(std::move(rhs));
    }

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

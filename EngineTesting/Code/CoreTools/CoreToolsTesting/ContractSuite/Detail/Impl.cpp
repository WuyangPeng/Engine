///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/11 15:32)

#include "Impl.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::Impl::Impl() noexcept
    : Impl{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::Impl::Impl(int count) noexcept
    : count{ count }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, Impl)

int CoreTools::Impl::GetCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return count;
}

void CoreTools::Impl::SetCount(int aCount) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    count = aCount;
}

size_t CoreTools::Impl::GetAddress() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    return reinterpret_cast<size_t>(&count);

#include STSTEM_WARNING_POP
}

CoreTools::Impl::ImplSharedPtr CoreTools::Impl::Create(int count)
{
    return std::make_shared<ClassType>(count);
}

CoreTools::Impl::ImplSharedPtr CoreTools::Impl::Create()
{
    return std::make_shared<ClassType>();
}

///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.2 (2021/08/26 15:08)

#include "Impl.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;

CoreTools::Impl::Impl() noexcept
    : Impl{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::Impl::Impl(int count) noexcept
    : m_Count{ count }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, Impl)

int CoreTools::Impl::GetCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Count;
}

void CoreTools::Impl::SetCount(int count) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_Count = count;
}

size_t CoreTools::Impl::GetAddress() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    return reinterpret_cast<size_t>(&m_Count);

#include STSTEM_WARNING_POP
}

CoreTools::Impl::ImplSharedPtr CoreTools::Impl::Create(int count)
{
    return make_shared<ClassType>(count);
}

CoreTools::Impl::ImplSharedPtr CoreTools::Impl::Create()
{
    return make_shared<ClassType>();
}

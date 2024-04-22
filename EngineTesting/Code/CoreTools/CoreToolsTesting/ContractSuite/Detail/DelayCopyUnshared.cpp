/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/15 10:19)

#include "DelayCopyUnshared.h"
#include "CoreTools/Contract/DelayCopyUnsharedImplDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::DelayCopyUnshared::DelayCopyUnshared(int count)
    : impl{ count }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::DelayCopyUnshared::DelayCopyUnshared(ImplCreateUseFactory implCreateUseFactory, int count)
    : impl{ implCreateUseFactory, count }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::DelayCopyUnshared::DelayCopyUnshared(ImplCreateUseDefaultConstruction implCreateUseDefaultConstruction)
    : impl{ implCreateUseDefaultConstruction }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, DelayCopyUnshared)

int CoreTools::DelayCopyUnshared::GetCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void CoreTools::DelayCopyUnshared::SetCount(int count)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetCount(count);
}

size_t CoreTools::DelayCopyUnshared::GetAddress() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl.GetConstImpl()->GetAddress();
}

CoreTools::DelayCopyUnshared::ImplSharedPtr CoreTools::DelayCopyUnshared::Clone(const Impl& impl)
{
    return std::make_shared<Impl>(impl.GetCount());
}

int CoreTools::DelayCopyUnshared::GetDereferenceCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return (*impl).GetCount();
}

void CoreTools::DelayCopyUnshared::SetDereferenceCount(int count)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return (*impl).SetCount(count);
}

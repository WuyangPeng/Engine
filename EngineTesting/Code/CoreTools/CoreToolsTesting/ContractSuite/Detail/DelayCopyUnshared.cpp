///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.2 (2021/08/26 16:56)

#include "DelayCopyUnshared.h"
#include "CoreTools/Contract/DelayCopyUnsharedImplDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;

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
    return make_shared<Impl>(impl.GetCount());
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
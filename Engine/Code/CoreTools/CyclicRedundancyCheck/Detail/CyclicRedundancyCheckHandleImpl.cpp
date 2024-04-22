/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 15:14)

#include "CoreTools/CoreToolsExport.h"

#include "CyclicRedundancyCheckHandleImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::CyclicRedundancyCheckHandleImpl::CyclicRedundancyCheckHandleImpl() noexcept
    : ccitt{}, table16{}, table32{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CyclicRedundancyCheckHandleImpl)

uint16_t CoreTools::CyclicRedundancyCheckHandleImpl::GetCcitt(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return ccitt.GetCcitt(index);
}

uint16_t CoreTools::CyclicRedundancyCheckHandleImpl::Get16Table(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return table16.Get16Table(index);
}

uint32_t CoreTools::CyclicRedundancyCheckHandleImpl::Get32Table(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return table32.Get32Table(index);
}

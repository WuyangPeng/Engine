///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/22 19:21)

#include "CoreTools/CoreToolsExport.h"

#include "CyclicRedundancyCheckHandleImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::CyclicRedundancyCheckHandleImpl::CyclicRedundancyCheckHandleImpl() noexcept
    : ccitt{}, table16{}, table32{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CyclicRedundancyCheckHandleImpl)

uint16_t CoreTools::CyclicRedundancyCheckHandleImpl::GetCCITT(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return ccitt.GetCCITT(index);
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

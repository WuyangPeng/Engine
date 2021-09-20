//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/26 14:02)

#include "CoreTools/CoreToolsExport.h"

#include "CyclicRedundancyCheckHandleImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::CyclicRedundancyCheckHandleImpl::CyclicRedundancyCheckHandleImpl(MAYBE_UNUSED int count) noexcept
    : m_CCITT{}, m_Table16{}, m_Table32{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CyclicRedundancyCheckHandleImpl)

uint16_t CoreTools::CyclicRedundancyCheckHandleImpl::GetCCITT(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_CCITT.GetCCITT(index);
}

uint16_t CoreTools::CyclicRedundancyCheckHandleImpl::Get16Table(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Table16.Get16Table(index);
}

uint32_t CoreTools::CyclicRedundancyCheckHandleImpl::Get32Table(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Table32.Get32Table(index);
}

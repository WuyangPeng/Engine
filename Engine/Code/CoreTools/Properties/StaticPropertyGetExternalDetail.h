//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/26 13:40)

#ifndef CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_EXTERNAL_DETAIL_H
#define CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_EXTERNAL_DETAIL_H

#include "StaticPropertyGetExternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
#ifdef OPEN_CLASS_INVARIANT
template <typename ConstReference, ConstReference (*PF)()>
bool CoreTools::StaticPropertyGetExternal<ConstReference, PF>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26440)
template <typename ConstReference, ConstReference (*PF)()>
CoreTools::StaticPropertyGetExternal<ConstReference, PF>::operator ConstReferenceType() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return (*PF)();
}
#include STSTEM_WARNING_POP
#endif  // CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_EXTERNAL_DETAIL_H
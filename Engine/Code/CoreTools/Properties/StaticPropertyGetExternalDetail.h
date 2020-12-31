//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/26 13:40)

#ifndef CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_EXTERNAL_DETAIL_H
#define CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_EXTERNAL_DETAIL_H

#include "StaticPropertyGetExternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#ifdef OPEN_CLASS_INVARIANT
template <typename ConstReference, ConstReference (*PF)()>
bool CoreTools::StaticPropertyGetExternal<ConstReference, PF>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename ConstReference, ConstReference (*PF)()>
CoreTools::StaticPropertyGetExternal<ConstReference, PF>::operator ConstReferenceType() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return (*PF)();
}

#endif  // CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_EXTERNAL_DETAIL_H
/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 10:14)

#ifndef CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_EXTERNAL_DETAIL_H
#define CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_EXTERNAL_DETAIL_H

#include "StaticPropertyGetExternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#ifdef OPEN_CLASS_INVARIANT

template <typename ConstReference, ConstReference (*PropertyFunction)()>
bool CoreTools::StaticPropertyGetExternal<ConstReference, PropertyFunction>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename ConstReference, ConstReference (*PropertyFunction)()>
CoreTools::StaticPropertyGetExternal<ConstReference, PropertyFunction>::operator ConstReferenceType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return (*PropertyFunction)();
}

#endif  // CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_EXTERNAL_DETAIL_H
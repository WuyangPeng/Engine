///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/20 15:07)

#ifndef CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_SET_EXTERNAL_DETAIL_H
#define CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_SET_EXTERNAL_DETAIL_H

#include "StaticPropertySetExternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#ifdef OPEN_CLASS_INVARIANT

template <typename Reference, void (*PropertyFunction)(Reference)>
bool CoreTools::StaticPropertySetExternal<Reference, PropertyFunction>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Reference, void (*PropertyFunction)(Reference)>
CoreTools::StaticPropertySetExternal<Reference, PropertyFunction>& CoreTools::StaticPropertySetExternal<Reference, PropertyFunction>::operator=(ReferenceType value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    (*PropertyFunction)(value);

    return *this;
}

#endif  // CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_SET_EXTERNAL_DETAIL_H
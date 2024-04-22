/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 14:53)

#ifndef CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_SET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_SET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include <type_traits>

namespace CoreTools
{
    template <typename Reference, void (*PropertyFunction)(Reference)>
    requires(std::is_reference_v<Reference>)
    class StaticPropertySetExternal final
    {
    public:
        using ReferenceType = Reference;
        using ClassType = StaticPropertySetExternal<ReferenceType, PropertyFunction>;

    public:
        CLASS_INVARIANT_DECLARE;

        StaticPropertySetExternal& operator=(ReferenceType value);
    };
}

#endif  // CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_SET_EXTERNAL_H
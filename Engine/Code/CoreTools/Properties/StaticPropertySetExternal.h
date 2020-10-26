//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/26 13:15)

#ifndef CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_SET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_SET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include <type_traits>

namespace CoreTools
{
    template <typename Reference, void (*PF)(Reference)>
    class StaticPropertySetExternal final
    {
    public:
        static_assert(std::is_reference_v<Reference>, "Reference is not reference.");

        using ReferenceType = Reference;
        using ClassType = StaticPropertySetExternal<ReferenceType, PF>;

    public:
        CLASS_INVARIANT_DECLARE;

        StaticPropertySetExternal& operator=(ReferenceType value);
    };
}

#endif  // CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_SET_EXTERNAL_H
//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/26 13:15)

#ifndef CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <typename GetReference, typename SetReference, GetReference (*FG)(void), void (*FS)(SetReference)>
    class StaticPropertyGetSetExternal final
    {
    public:
        using GetReferenceType = GetReference;
        using SetReferenceType = SetReference;
        using ClassType = StaticPropertyGetSetExternal<GetReferenceType, SetReferenceType, FG, FS>;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        [[nodiscard]] operator GetReferenceType() const;
        StaticPropertyGetSetExternal& operator=(SetReferenceType value);
    };
}

#endif  // CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_EXTERNAL_H
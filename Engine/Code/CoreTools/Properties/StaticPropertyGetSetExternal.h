///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/23 18:07)

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
        NODISCARD operator GetReferenceType() const noexcept;
        StaticPropertyGetSetExternal& operator=(SetReferenceType value);
    };
}

#endif  // CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_EXTERNAL_H
/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 14:56)

#ifndef CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <typename GetReference, typename SetReference, GetReference (*PropertyGet)(), void (*PropertySet)(SetReference)>
    class StaticPropertyGetSetExternal final
    {
    public:
        using GetReferenceType = GetReference;
        using SetReferenceType = SetReference;
        using ClassType = StaticPropertyGetSetExternal<GetReferenceType, SetReferenceType, PropertyGet, PropertySet>;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        NODISCARD operator GetReferenceType() const noexcept;
        StaticPropertyGetSetExternal& operator=(SetReferenceType value);
    };
}

#endif  // CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_EXTERNAL_H
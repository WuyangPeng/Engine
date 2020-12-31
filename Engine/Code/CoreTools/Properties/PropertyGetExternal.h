//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/26 13:13)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include <type_traits>

namespace CoreTools
{
    template <typename T, typename ConstReference, ConstReference (T::*PF)() const>
    class PropertyGetExternal final
    {
    public:
        static_assert(std::is_const_v<std::remove_reference_t<ConstReference>>, "ConstReference is not const.");
        static_assert(std::is_reference_v<ConstReference>, "ConstReference is not reference.");

        using ConstReferenceType = ConstReference;
        using ClassType = PropertyGetExternal<T, ConstReferenceType, PF>;

    public:
        explicit PropertyGetExternal(const T& object);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] operator ConstReferenceType() const;

        PropertyGetExternal& operator=(const PropertyGetExternal& rhs) = delete;

    private:
        const T& m_Object;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_H
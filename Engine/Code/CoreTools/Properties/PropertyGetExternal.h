/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 15:02)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include <type_traits>

namespace CoreTools
{
    template <typename T, typename ConstReference, ConstReference (T::*PropertyFunction)() const>
    requires(std::is_const_v<std::remove_reference_t<ConstReference>> &&
             std::is_reference_v<ConstReference>)
    class PropertyGetExternal final
    {
    public:
        using ConstReferenceType = ConstReference;
        using ClassType = PropertyGetExternal<T, ConstReferenceType, PropertyFunction>;

    public:
        explicit PropertyGetExternal(const T& object) noexcept;

        ~PropertyGetExternal() noexcept = default;
        PropertyGetExternal(const PropertyGetExternal& rhs) = delete;
        PropertyGetExternal& operator=(const PropertyGetExternal& rhs) = delete;
        PropertyGetExternal(PropertyGetExternal&& rhs) noexcept = delete;
        PropertyGetExternal& operator=(PropertyGetExternal&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        NODISCARD operator ConstReferenceType() const noexcept;

    private:
        const T& object;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_H
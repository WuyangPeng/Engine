///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/23 18:03)

#ifndef CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_GET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_GET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include <type_traits>

namespace CoreTools
{
    template <typename Value, typename ConstReference>
    class SimplePropertyGetExternal final
    {
    public:
        static_assert(std::is_const_v<std::remove_reference_t<ConstReference>>, "ConstReference is not const.");
        static_assert(std::is_reference_v<ConstReference>, "ConstReference is not reference.");

        using ValueType = Value;
        using ConstReferenceType = ConstReference;
        using ClassType = SimplePropertyGetExternal<ValueType, ConstReferenceType>;

    public:
        explicit SimplePropertyGetExternal(const ValueType& value) noexcept;

        ~SimplePropertyGetExternal() noexcept = default;
        SimplePropertyGetExternal(const SimplePropertyGetExternal& rhs) noexcept = delete;
        SimplePropertyGetExternal& operator=(const SimplePropertyGetExternal& rhs) noexcept = delete;
        SimplePropertyGetExternal(SimplePropertyGetExternal&& rhs) noexcept = delete;
        SimplePropertyGetExternal& operator=(SimplePropertyGetExternal&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        NODISCARD operator ConstReferenceType() const noexcept;

    private:
        const ValueType& m_Value;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_GET_EXTERNAL_H
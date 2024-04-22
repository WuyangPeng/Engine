/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 15:00)

#ifndef CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_GET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_GET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include <type_traits>

namespace CoreTools
{
    template <typename Value, typename ConstReference>
    requires(std::is_const_v<std::remove_reference_t<ConstReference>> && std::is_reference_v<ConstReference>)
    class SimplePropertyGetExternal final
    {
    public:
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
        const ValueType& value;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_GET_EXTERNAL_H
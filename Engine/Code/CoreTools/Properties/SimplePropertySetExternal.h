/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 10:16)

#ifndef CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_SET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_SET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <typename Value, typename Reference>
    class SimplePropertySetExternal final
    {
    public:
        static_assert(std::is_reference_v<Reference>, "Reference is not reference.");

        using ValueType = Value;
        using ReferenceType = Reference;
        using ClassType = SimplePropertySetExternal<ValueType, ReferenceType>;

    public:
        explicit SimplePropertySetExternal(ValueType& value) noexcept;

        ~SimplePropertySetExternal() noexcept = default;
        SimplePropertySetExternal(const SimplePropertySetExternal& rhs) noexcept = delete;
        SimplePropertySetExternal& operator=(const SimplePropertySetExternal& rhs) noexcept = delete;
        SimplePropertySetExternal(SimplePropertySetExternal&& rhs) noexcept = delete;
        SimplePropertySetExternal& operator=(SimplePropertySetExternal&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        SimplePropertySetExternal& operator=(ReferenceType aValue);

    private:
        ValueType& value;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_SET_EXTERNAL_H
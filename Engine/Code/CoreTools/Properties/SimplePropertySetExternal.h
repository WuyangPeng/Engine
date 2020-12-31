//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/26 13:14)

#ifndef CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_SET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_SET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include <boost/noncopyable.hpp>

namespace CoreTools
{
    template <typename Value, typename Reference>
    class SimplePropertySetExternal final : private boost::noncopyable
    {
    public:
        static_assert(std::is_reference_v<Reference>, "Reference is not reference.");

        using ValueType = Value;
        using ReferenceType = Reference;
        using ClassType = SimplePropertySetExternal<ValueType, ReferenceType>;

    public:
        explicit SimplePropertySetExternal(ValueType& value);

        CLASS_INVARIANT_DECLARE;

        SimplePropertySetExternal& operator=(ReferenceType value);

    private:
        ValueType& m_Value;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_SET_EXTERNAL_H
/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 15:03)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_H

#include "CoreTools/CoreToolsDll.h"

#include "PropertyBase.h"

namespace CoreTools
{
    /// ��Ҫͨ����TCRE_DECLARE_PROPERTY����������
    template <typename Id, typename T, typename V, typename R, void (T::*FunctionSet)(R), R (T::*FunctionGet)() const>
    class Property final : PropertyBase<Id, T>
    {
    public:
        using ParentType = PropertyBase<Id, T>;
        using ClassType = Property<Id, T, V, R, FunctionSet, FunctionGet>;

    public:
        Property() noexcept;
        explicit Property(V value);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        Property& operator=(R aValue) noexcept;
        NODISCARD operator R() const noexcept;

    public:
        V value;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_H
/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 15:03)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_BASE_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/PropertiesMacro.h"

namespace CoreTools
{
    /// ��Ҫͨ����TCRE_DEFINE_PROPERTY����offset
    template <typename Id, typename T>
    class PropertyBase
    {
    public:
        using ClassType = PropertyBase<Id, T>;

    public:
        PropertyBase() = default;
        virtual ~PropertyBase() = default;

        PropertyBase(const PropertyBase& rhs) noexcept = default;
        PropertyBase& operator=(const PropertyBase& rhs) noexcept = default;
        PropertyBase(PropertyBase&& rhs) noexcept = default;
        PropertyBase& operator=(PropertyBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

    protected:
        T* Holder() noexcept;
        const T* Holder() const noexcept;

    private:
        static const ptrdiff_t offset;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_BASE_H
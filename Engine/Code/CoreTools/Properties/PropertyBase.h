//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/26 13:12)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_BASE_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/PropertiesMacro.h"

namespace CoreTools
{
    // ��Ҫͨ����TCRE_DEFINE_PROPERTY����m_Offset
    template <typename ID, typename T>
    class PropertyBase
    {
    public:
        using ClassType = PropertyBase<ID, T>;

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
        static const ptrdiff_t m_Offset;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_BASE_H
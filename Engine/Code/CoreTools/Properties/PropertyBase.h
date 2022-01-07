///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/23 17:27)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_BASE_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/PropertiesMacro.h"

namespace CoreTools
{
    // 需要通过宏TCRE_DEFINE_PROPERTY定义m_Offset
    template <typename ID, typename T>
    class PropertyBase
    {
    public:
        using ClassType = PropertyBase<ID, T>;

    public:
        PropertyBase() = default;
        virtual ~PropertyBase() = default;

        PropertyBase(const PropertyBase& rhs) noexcept = default;
        virtual PropertyBase& operator=(const PropertyBase& rhs) noexcept = default;
        PropertyBase(PropertyBase&& rhs) noexcept = default;
        virtual PropertyBase& operator=(PropertyBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

    protected:
        T* Holder() noexcept;
        const T* Holder() const noexcept;

    private:
        static const ptrdiff_t offset;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_BASE_H
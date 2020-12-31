//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 13:13)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_GET_INTERNAL_OFFSET_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_GET_INTERNAL_OFFSET_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/PropertiesMacro.h"

// 使用方式：
// 类必须是1字节对齐
// #pragma pack(push, 1)
// 需要定义一个类似下面的静态函数：
// static ptrdiff_t GetOffset()
// { enum { offset = offsetof(Class, Property) }; return offset; }

namespace CoreTools
{
    template <typename T, typename V, typename Reference, Reference (T::*PF)() const, ptrdiff_t (*FO)()>
    class PropertyGetInternalOffset final
    {
    public:
        using ReferenceType = Reference;
        using ClassType = PropertyGetInternalOffset<T, V, ReferenceType, PF, FO>;

    public:
        CLASS_INVARIANT_DECLARE;

    private:
        explicit PropertyGetInternalOffset(ReferenceType value);

        PropertyGetInternalOffset& operator=(ReferenceType value);
        void SetValue(ReferenceType value);
        [[nodiscard]] ReferenceType GetValue() const;

        TCRE_DECLARE_TEMPLATE_PARAM_AS_FRIEND(T);

    public:
        operator ReferenceType() const;

    private:
        V m_Value;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_GET_INTERNAL_OFFSET_H
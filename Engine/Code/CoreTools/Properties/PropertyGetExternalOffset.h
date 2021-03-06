//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 13:13)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_OFFSET_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_OFFSET_H

#include "CoreTools/CoreToolsDll.h"

// 使用方式：
// 类必须是1字节对齐
// #pragma pack(push, 1)
// 需要定义一个类似下面的静态函数：
// static ptrdiff_t GetOffset()
// { enum { offset = offsetof(Class, Property) }; return offset; }

namespace CoreTools
{
    template <typename T, typename ConstReference, ConstReference (T::*PF)() const, ptrdiff_t (*FO)()>
    class PropertyGetExternalOffset final
    {
    public:
        using ConstReferenceType = ConstReference;
        using ClassType = PropertyGetExternalOffset<T, ConstReferenceType, PF, FO>;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        [[nodiscard]] operator ConstReferenceType() const;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_OFFSET_H
/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 15:02)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_OFFSET_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_OFFSET_H

#include "CoreTools/CoreToolsDll.h"

/// 使用方式：
/// 类必须是1字节对齐
/// #pragma pack(push, 1)
/// 需要定义一个类似下面的静态函数：
/// static ptrdiff_t GetOffset()
/// { enum { offset = offsetof(Class, Property) }; return offset; }

namespace CoreTools
{
    template <typename T, typename ConstReference, ConstReference (T::*PropertyFunction)() const, ptrdiff_t (*FunctionOffset)()>
    class PropertyGetExternalOffset final
    {
    public:
        using ConstReferenceType = ConstReference;
        using ClassType = PropertyGetExternalOffset<T, ConstReferenceType, PropertyFunction, FunctionOffset>;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        NODISCARD operator ConstReferenceType() const noexcept;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_OFFSET_H
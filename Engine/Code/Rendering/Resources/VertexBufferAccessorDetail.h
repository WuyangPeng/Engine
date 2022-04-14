///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/31 19:05)

#ifndef RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_DETAIL_H
#define RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_DETAIL_H

#include "VertexBufferAccessor.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/Vector2.h"

template <>
RENDERING_DEFAULT_DECLARE Mathematics::APointF Rendering::VertexBufferAccessor::GetPosition(int index) const noexcept;

template <typename T>
T Rendering::VertexBufferAccessor::GetPosition(int index) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    return *(reinterpret_cast<const T*>(GetPosition(index)));

#include STSTEM_WARNING_POP
}

template <>
RENDERING_DEFAULT_DECLARE Mathematics::AVectorF Rendering::VertexBufferAccessor::GetNormal(int index) const noexcept;

template <typename T>
T Rendering::VertexBufferAccessor::GetNormal(int index) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    return *(reinterpret_cast<const T*>(GetNormal(index)));

#include STSTEM_WARNING_POP
}

template <>
RENDERING_DEFAULT_DECLARE Mathematics::AVectorF Rendering::VertexBufferAccessor::GetTangent(int index) const noexcept;

template <typename T>
T Rendering::VertexBufferAccessor::GetTangent(int index) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    return *(reinterpret_cast<const T*>(GetTangent(index)));

#include STSTEM_WARNING_POP
}

template <>
RENDERING_DEFAULT_DECLARE Mathematics::AVectorF Rendering::VertexBufferAccessor::GetBinormal(int index) const noexcept;

template <typename T>
T Rendering::VertexBufferAccessor::GetBinormal(int index) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    return *(reinterpret_cast<const T*>(GetBinormal(index)));

#include STSTEM_WARNING_POP
}

template <>
RENDERING_DEFAULT_DECLARE Mathematics::Vector2F Rendering::VertexBufferAccessor::GetTextureCoord(int unit, int index) const;

template <typename T>
T Rendering::VertexBufferAccessor::GetTextureCoord(int unit, int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    return *(reinterpret_cast<const T*>(GetTextureCoord(unit, index)));

#include STSTEM_WARNING_POP
}

template <typename T>
T Rendering::VertexBufferAccessor::GetColor(int unit, int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    return *(reinterpret_cast<const T*>(GetColor(unit, index)));

#include STSTEM_WARNING_POP
}

template <typename T>
T Rendering::VertexBufferAccessor::GetBlendIndices(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    return *(reinterpret_cast<const T*>(GetBlendIndices(index)));

#include STSTEM_WARNING_POP
}

template <typename T>
T Rendering::VertexBufferAccessor::GetBlendWeight(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    return *(reinterpret_cast<const T*>(GetBlendWeight(index)));

#include STSTEM_WARNING_POP
}

#endif  // RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_DETAIL_H
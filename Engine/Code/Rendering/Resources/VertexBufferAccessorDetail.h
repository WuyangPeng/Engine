// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/19 13:50)

#ifndef RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_DETAIL_H
#define RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_DETAIL_H

#include "VertexBufferAccessor.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/Vector2D.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
template <>
RENDERING_DEFAULT_DECLARE Mathematics::FloatAPoint Rendering::VertexBufferAccessor ::GetPosition(int index) const noexcept;

template <typename T>
T Rendering::VertexBufferAccessor
	::GetPosition(int index) const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return *(reinterpret_cast<const T*>(GetPosition(index)));
}

template <>
RENDERING_DEFAULT_DECLARE Mathematics::FloatAVector Rendering::VertexBufferAccessor ::GetNormal(int index) const noexcept;

template <typename T>
T Rendering::VertexBufferAccessor ::GetNormal(int index) const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return *(reinterpret_cast<const T*>(GetNormal(index)));
}

template <>
RENDERING_DEFAULT_DECLARE Mathematics::FloatAVector Rendering::VertexBufferAccessor ::GetTangent(int index) const noexcept;

template <typename T>
T Rendering::VertexBufferAccessor ::GetTangent(int index) const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return *(reinterpret_cast<const T*>(GetTangent(index)));
}

template <>
RENDERING_DEFAULT_DECLARE Mathematics::FloatAVector Rendering::VertexBufferAccessor ::GetBinormal(int index) const noexcept;

template <typename T>
T Rendering::VertexBufferAccessor ::GetBinormal(int index) const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return *(reinterpret_cast<const T*>(GetBinormal(index)));
}

template <>
RENDERING_DEFAULT_DECLARE Mathematics::FloatVector2D Rendering::VertexBufferAccessor
	::GetTextureCoord(int unit, int index) const;

template <typename T>
T Rendering::VertexBufferAccessor
	::GetTextureCoord(int unit, int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return *(reinterpret_cast<const T*>(GetTextureCoord(unit, index)));
}

template <typename T>
T Rendering::VertexBufferAccessor
	::GetColor(int unit, int index) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return *(reinterpret_cast<const T*>(GetColor(unit, index)));
}

template <typename T>
T Rendering::VertexBufferAccessor
	::GetBlendIndices(int index) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return *(reinterpret_cast<const T*>(GetBlendIndices(index)));
}

template <typename T>
T Rendering::VertexBufferAccessor
	::GetBlendWeight(int index) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return *(reinterpret_cast<const T*>(GetBlendWeight(index)));
}
#include STSTEM_WARNING_POP
#endif // RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_DETAIL_H
// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.3.0 (2020/03/27 10:01)

#include "Rendering/RenderingExport.h" 

#include "PickRayImpl.h"  
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::PickRayImpl
	::PickRayImpl(bool result, const Mathematics::APointf& origin, const Mathematics::AVectorf& direction) noexcept
	:m_Result{ result }, m_Origin{ origin }, m_Direction{ direction }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::PickRayImpl ::PickRayImpl() noexcept
    : m_Result{ false }, m_Origin{}, m_Direction{}
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PickRayImpl)

bool Rendering::PickRayImpl
	::IsResult() const noexcept
{
	RENDERING_CLASS_IS_VALID_9;

	return m_Result;
}

Mathematics::APointf Rendering::PickRayImpl ::GetOrigin() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Origin;
}

Mathematics::AVectorf Rendering::PickRayImpl ::GetDirection() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Direction;
}

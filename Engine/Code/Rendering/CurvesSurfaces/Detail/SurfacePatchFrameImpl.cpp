// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/25 16:08)

#include "Rendering/RenderingExport.h"

#include "SurfacePatchFrameImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::SurfacePatchFrameImpl
	::SurfacePatchFrameImpl(const APoint& position, const AVector& tangent0, const AVector& tangent1, const AVector& normal)
	:m_Position{ position }, m_Tangent0{ tangent0 },m_Tangent1{ tangent1 }, m_Normal{ normal }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::SurfacePatchFrameImpl
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

const Rendering::SurfacePatchFrameImpl::APoint Rendering::SurfacePatchFrameImpl
	::GetPosition() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Position;
}

const Rendering::SurfacePatchFrameImpl::AVector Rendering::SurfacePatchFrameImpl
	::GetTangent0() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Tangent0;
}

const Rendering::SurfacePatchFrameImpl::AVector Rendering::SurfacePatchFrameImpl
	::GetTangent1() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Tangent1;
}

const Rendering::SurfacePatchFrameImpl::AVector Rendering::SurfacePatchFrameImpl
	::GetNormal() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Normal;
}
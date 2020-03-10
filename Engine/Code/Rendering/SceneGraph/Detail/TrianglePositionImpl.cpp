// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/22 17:00)

#include "Rendering/RenderingExport.h"

#include "TrianglePositionImpl.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::TrianglePositionImpl
	::TrianglePositionImpl(const APoint& firstPosition,const APoint& secondPosition, const APoint& thirdPosition)
	:m_FirstPosition{ firstPosition }, m_SecondPosition{ secondPosition }, m_ThirdPosition{ thirdPosition }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, TrianglePositionImpl)

const Rendering::TrianglePositionImpl::APoint Rendering::TrianglePositionImpl
	::GetFirstPosition() const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_FirstPosition;
}

const Rendering::TrianglePositionImpl::APoint Rendering::TrianglePositionImpl
	::GetSecondPosition() const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_SecondPosition;
}

const Rendering::TrianglePositionImpl::APoint Rendering::TrianglePositionImpl
	::GetThirdPosition() const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_ThirdPosition;
}

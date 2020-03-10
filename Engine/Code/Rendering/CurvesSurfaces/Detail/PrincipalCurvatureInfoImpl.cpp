// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/25 16:08)

#include "Rendering/RenderingExport.h"

#include "PrincipalCurvatureInfoImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::PrincipalCurvatureInfoImpl
	::PrincipalCurvatureInfoImpl(float principalCurvature0, float principalCurvature1, const AVector& principalDirection0, const  AVector& principalDirection1)
	:m_PrincipalCurvature0{ principalCurvature0 }, m_PrincipalCurvature1{ principalCurvature1 },
	 m_PrincipalDirection0{ principalDirection0 }, m_PrincipalDirection1{ principalDirection1 }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::PrincipalCurvatureInfoImpl
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

float Rendering::PrincipalCurvatureInfoImpl
	::GetPrincipalCurvature0() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_PrincipalCurvature0;
}

float Rendering::PrincipalCurvatureInfoImpl
	::GetPrincipalCurvature1() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_PrincipalCurvature1;
}

const Rendering::PrincipalCurvatureInfoImpl::AVector Rendering::PrincipalCurvatureInfoImpl
	::GetPrincipalDirection0() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_PrincipalDirection0;
}

const Rendering::PrincipalCurvatureInfoImpl::AVector Rendering::PrincipalCurvatureInfoImpl
	::GetPrincipalDirection1() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_PrincipalDirection1;
}
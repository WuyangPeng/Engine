// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/25 15:50)

#ifndef RENDERING_CURVES_SURFACES_PRINCIPAL_CURVATURE_INFO_IMPL_H
#define RENDERING_CURVES_SURFACES_PRINCIPAL_CURVATURE_INFO_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/AVector.h"

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE PrincipalCurvatureInfoImpl
	{
	public:
		typedef PrincipalCurvatureInfoImpl ClassType;
		typedef Mathematics::AVectorf AVector; 

	public:
		PrincipalCurvatureInfoImpl(float principalCurvature0, float principalCurvature1, const AVector& principalDirection0, const  AVector& principalDirection1);

		CLASS_INVARIANT_DECLARE;

		float GetPrincipalCurvature0() const;
		float GetPrincipalCurvature1() const;
		const AVector GetPrincipalDirection0() const;
		const AVector GetPrincipalDirection1() const;
		 
	private:
		float m_PrincipalCurvature0;
		float m_PrincipalCurvature1;
		AVector m_PrincipalDirection0;
		AVector m_PrincipalDirection1;
	}; 
}

#endif // RENDERING_CURVES_SURFACES_PRINCIPAL_CURVATURE_INFO_IMPL_H

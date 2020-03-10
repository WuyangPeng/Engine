// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/25 15:55)

#ifndef RENDERING_CURVES_SURFACES_PRINCIPAL_CURVATURE_INFO_H
#define RENDERING_CURVES_SURFACES_PRINCIPAL_CURVATURE_INFO_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Mathematics/Algebra/AVector.h" 

RENDERING_EXPORT_SHARED_PTR(PrincipalCurvatureInfoImpl);

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE PrincipalCurvatureInfo
	{
	public:
		PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(PrincipalCurvatureInfo);
		using AVector = Mathematics::AVectorf;

	public:
		PrincipalCurvatureInfo(float principalCurvature0, float principalCurvature1, const AVector& principalDirection0,  const AVector& principalDirection1);

		CLASS_INVARIANT_DECLARE;

		float GetPrincipalCurvature0() const;
		float GetPrincipalCurvature1() const;
		const AVector GetPrincipalDirection0() const;
		const AVector GetPrincipalDirection1() const;

	private:
		IMPL_TYPE_DECLARE(PrincipalCurvatureInfo);
	};

}

#endif // RENDERING_CURVES_SURFACES_PRINCIPAL_CURVATURE_INFO_H

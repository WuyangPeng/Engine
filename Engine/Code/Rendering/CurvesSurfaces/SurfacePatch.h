// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/25 15:57)

#ifndef RENDERING_CURVES_SURFACES_SURFACE_PATCH_H
#define RENDERING_CURVES_SURFACES_SURFACE_PATCH_H

#include "Rendering/RenderingDll.h"

#include "SurfacePatchFrame.h"
#include "PrincipalCurvatureInfo.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SubclassSmartPointerMacro.h"

RENDERING_EXPORT_SHARED_PTR(SurfacePatchImpl);

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE SurfacePatch : public CoreTools::Object
	{
	public:
		COPY_UNSHARE_CLASSES_TYPE_DECLARE(SurfacePatch);
		using ParentType = Object;
		using AVector = Mathematics::AVectorf;
		using APoint = Mathematics::APointf;

	public:
		SurfacePatch(float uMin, float uMax, float vMin, float vMax, bool rectangular);
		virtual ~SurfacePatch();

#ifdef OPEN_CLASS_INVARIANT
		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		bool IsParameterValid(float u, float v) const noexcept;
#endif // OPEN_CLASS_INVARIANT
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(SurfacePatch); 

		// 参数域可以是矩形或三角形。
		// 对于矩形域有效的(u,v)值满足umin <= u <= umax,  vmin <= v <= vmax
		// 三角域有效的(u,v)值的满足 umin <= u <= umax,  vmin <= v <= vmax，
		//  (vmax - vmin) * (u - umin) + (umax - umin) * (v - vmax) <= 0
		float GetUMin() const;
		float GetUMax() const;
		float GetVMin() const;
		float GetVMax() const;
		bool IsRectangular() const;
		
		// 位置及二阶导数
		virtual const APoint GetPosition(float u, float v) const = 0;
		virtual const AVector GetDerivativesU(float u, float v) const = 0;
		virtual const AVector GetDerivativesV(float u, float v) const = 0;
		virtual const AVector GetDerivativesUU(float u, float v) const = 0;
		virtual const AVector GetDerivativesUV(float u, float v) const = 0;
		virtual const AVector GetDerivativesVV(float u, float v) const = 0;
		
		// 计算一个坐标系。集合{T0,T1,N}是一个右手正交坐标系。
		const AVector GetTangent0 (float u, float v) const;
		const AVector GetTangent1(float u, float v) const;
		const AVector GetNormal(float u, float v) const;
		const SurfacePatchFrame GetFrame(float u, float v) const;
		
		// 微分几何量。返回的标量是主曲率，并返回矢量的对应主方向。
		const PrincipalCurvatureInfo ComputePrincipalCurvatureInfo(float u, float v) const;
		
	private:
		IMPL_TYPE_DECLARE(SurfacePatch);
	};

	CORE_TOOLS_STREAM_REGISTER(SurfacePatch);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, SurfacePatch);
}

#endif // RENDERING_CURVES_SURFACES_SURFACE_PATCH_H

// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/25 15:54)

#ifndef RENDERING_CURVES_SURFACES_CURVE_SEGMENT_H
#define RENDERING_CURVES_SURFACES_CURVE_SEGMENT_H

#include "Rendering/RenderingDll.h"
 
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "CoreTools/ObjectSystems/Object.h"

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE CurveSegment : public CoreTools::Object
	{
	private:
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(CurveSegment); 

	public:
		using ClassType = CurveSegment;
		using ParentType = Object;
		using APoint = Mathematics::APointf;
		using AVector = Mathematics::AVectorf;

	protected:
		// Construction.
		CurveSegment(float umin, float umax);
	public:
		// Abstract base class.
		virtual ~CurveSegment();

		// The parametric domain is umin <= u <= umax.
		float GetUMin() const noexcept;
		float GetUMax() const noexcept;

		// Position and derivatives up to third order.
		virtual APoint P(float u) const = 0;
		virtual AVector PU(float u) const = 0;
		virtual AVector PUU(float u) const = 0;
		virtual AVector PUUU(float u) const = 0;

		// Differential geometric quantities.
		AVector Tangent(float u) const;
		AVector Normal(float u) const;
		AVector Binormal(float u) const;
		void GetFrame(float u, APoint& position, AVector& tangent, AVector& normal, AVector& binormal) const;
		float Curvature(float u) const;
		float Torsion(float u) const;

	protected:
		float mUMin, mUMax;
	};

	CORE_TOOLS_STREAM_REGISTER(CurveSegment);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, CurveSegment);

}

#endif // RENDERING_CURVES_SURFACES_CURVE_SEGMENT_H

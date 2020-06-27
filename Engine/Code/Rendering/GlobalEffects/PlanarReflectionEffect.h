// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/25 15:27)

#ifndef RENDERING_GLOBAL_EFFECTS_PLANAR_REFLECTION_EFFECT_H
#define RENDERING_GLOBAL_EFFECTS_PLANAR_REFLECTION_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "GlobalEffect.h"
#include "Mathematics/Algebra/Plane.h"
#include "Mathematics/Algebra/Matrix.h" 
#include "Rendering/SceneGraph/TrianglesMesh.h"

namespace Rendering
{
	class  PlanarReflectionEffect : public GlobalEffect
	{
	public:
		using ClassType = PlanarReflectionEffect;
		using ParentType = GlobalEffect;

	private:
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(PlanarReflectionEffect);
		CORE_TOOLS_NAMES_OVERRIDE_DECLARE;
		
	public:
		// Construction and destruction.  The number of planes supported depends
		// on the number of stencil bits (256 for an 8-bit stencil buffer).
		explicit PlanarReflectionEffect (int numPlanes);
		virtual ~PlanarReflectionEffect ();
		
		virtual void Draw (std::shared_ptr<Renderer> renderer, VisibleSet& visibleSet) override;
		
		// Member access.
		int GetNumPlanes () const;
		void SetPlane(int i, TrianglesMeshSmartPointer plane);
		ConstTrianglesMeshSmartPointer GetPlane(int i) const;
		void SetReflectance (int i, float reflectance);		
		float GetReflectance (int i) const;

	protected:
		void GetReflectionMatrixAndModelPlane(int i, Mathematics::Matrixf& reflection, Mathematics::Planef& modelPlane);
		
		int mNumPlanes;
		TrianglesMeshSmartPointer* mPlanes;
		float* mReflectances;
		
		// Global render state for drawing.
		AlphaStateSmartPointer mAlphaState;
		DepthStateSmartPointer mDepthState;
		StencilStateSmartPointer mStencilState;
	};
	
	CORE_TOOLS_STREAM_REGISTER(PlanarReflectionEffect);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fourth, PlanarReflectionEffect);
}

#endif // RENDERING_GLOBAL_EFFECTS_PLANAR_REFLECTION_EFFECT_H

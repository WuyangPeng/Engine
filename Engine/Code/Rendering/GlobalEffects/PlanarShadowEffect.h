// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/25 15:29)

#ifndef RENDERING_GLOBAL_EFFECTS_PLANAR_SHADOW_EFFECT_H
#define RENDERING_GLOBAL_EFFECTS_PLANAR_SHADOW_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "GlobalEffect.h"
#include "Mathematics/Base/Float4.h"
#include "Mathematics/Algebra/Matrix.h"   
#include "Rendering/SceneGraph/Node.h"
#include "Rendering/SceneGraph/Light.h"
#include "Rendering/SceneGraph/TrianglesMesh.h"
#include "Rendering/LocalEffects/MaterialEffect.h" 

namespace Rendering
{
	class  PlanarShadowEffect : public GlobalEffect
	{
	public:
		using ClassType = PlanarShadowEffect;
		using ParentType = GlobalEffect;

	private:
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(PlanarShadowEffect);
		CORE_TOOLS_NAMES_OVERRIDE_DECLARE;
 
	public:
		// Construction and destruction.  The number of planes supported depends
		// on the number of stencil bits (256 for an 8-bit stencil buffer).
		PlanarShadowEffect (int numPlanes, Node* shadowCaster);
		virtual ~PlanarShadowEffect ();

		virtual void Draw (Renderer* renderer, const VisibleSet& visibleSet);

		// Member access.
		  int GetNumPlanes () const;
		  void SetPlane (int i, TrianglesMeshSmartPointer plane);
		  TrianglesMeshSmartPointer GetPlane (int i) const;
		  void SetProjector (int i, Light* projector);
		  Light* GetProjector (int i) const;
		  void SetShadowColor (int i, const Mathematics::Float4& shadowColor);
		  const Mathematics::Float4& GetShadowColor (int i) const;

	protected:
		bool GetProjectionMatrix (int i,Mathematics::Matrixf& projection);

		int mNumPlanes;
		TrianglesMeshSmartPointer* mPlanes;
		LightSmartPointer* mProjectors;
		Mathematics::Float4* mShadowColors;
		NodeSmartPointer mShadowCaster;// 可能是数组

		// Global render state for drawing.
		AlphaStateSmartPointer mAlphaState;
		DepthStateSmartPointer mDepthState;
		StencilStateSmartPointer mStencilState;

		// Override effect for drawing the shadows.
		MaterialSmartPointer mMaterial;
		MaterialEffectSmartPointer mMaterialEffect;
		VisualEffectInstanceSmartPointer mMaterialEffectInstance;
	};

	CORE_TOOLS_STREAM_REGISTER(PlanarShadowEffect);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fourth, PlanarShadowEffect);


}

#endif // RENDERING_GLOBAL_EFFECTS_PLANAR_SHADOW_EFFECT_H

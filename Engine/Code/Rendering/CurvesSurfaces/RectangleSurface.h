// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/25 15:56)

#ifndef RENDERING_CURVES_SURFACES_RECTANGLE_SURFACE_H
#define RENDERING_CURVES_SURFACES_RECTANGLE_SURFACE_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Base/Float2.h"
#include "Mathematics/CurvesSurfacesVolumes/ParametricSurface.h"
#include "Rendering/SceneGraph/TrianglesMesh.h"

namespace Rendering
{
	class RectangleSurface : public TrianglesMesh
	{
	private:
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(RectangleSurface); 

	public:
		using ClassType = RectangleSurface;
		using ParentType = TrianglesMesh;

	public:
		// Construction and destruction.  The input surface must be rectangular,
		// not triangular.  RectangleSurface accepts responsibility for deleting
		// the input surface.  Any texture coordinates in the vertex format must
		// be 2D.  The minimum and maximum texture coordinates are specified in
		// the constructor.  If you have none, set tcoordMin and tcoordMax to
		// null.
		RectangleSurface(Mathematics::ParametricSurfacef* surface, int numUSamples, int numVSamples,
					     VertexFormatSmartPointer vformat, const Mathematics::Float2* tcoordMin, const Mathematics::Float2* tcoordMax);

		virtual ~RectangleSurface();

		// Member access.
		void SetSurface(Mathematics::ParametricSurfacef* surface);
		const Mathematics::ParametricSurfacef* GetSurface() const;
		int GetNumUSamples() const;
		int GetNumVSamples() const;

		// If the surface is modified, for example if it is control point
		// based and the control points are modified, then you should call this
		// update function to recompute the rectangle surface geometry.
		void UpdateSurface();

	protected:
		Mathematics::ParametricSurfacef* mSurface;
		int mNumUSamples, mNumVSamples;
	};

	CORE_TOOLS_STREAM_REGISTER(RectangleSurface);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Ninth, RectangleSurface);
}

#endif // RENDERING_CURVES_SURFACES_RECTANGLE_SURFACE_H

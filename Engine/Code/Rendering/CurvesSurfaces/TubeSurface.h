// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/25 16:00)

#ifndef RENDERING_CURVES_SURFACES_TUBE_SURFACE_H
#define RENDERING_CURVES_SURFACES_TUBE_SURFACE_H

#include "Rendering/RenderingDll.h"

#include "Rendering/SceneGraph/TrianglesMesh.h"
#include "Mathematics/Base/Float2.h"
#include "Mathematics/CurvesSurfacesVolumes/Curve3.h"

namespace Rendering
{
	class  TubeSurface : public TrianglesMesh
	{
	private:
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(TubeSurface); 

	public:
		using ClassType = TubeSurface;
		using ParentType = TrianglesMesh;

	public:
		using RadialFunction = float (*)(float);

		// Construction and destruction.  TubeSurface accepts responsibility
		// for deleting the input curve.  If upVector is not the zero vector,
		// it will be used as 'up' in the frame calculations.  If it is the zero
		// vector, the Frenet frame will be used.  If bWantColors is 'true',
		// the vertex colors are allocated and set to black.  The application
		// needs to assign colors as needed.  If either of tcoordMin or tcoordMax is
		// not null, both must be not null.  In this case, texture coordinates are
		// generated for the surface.
		TubeSurface (Mathematics::Curve3f* medial, RadialFunction radial, bool closed,
					 const Mathematics::Vector3Df& upVector, int numMedialSamples, int mNumSliceSamples,
					 bool sampleByArcLength, bool insideView, const Mathematics::Float2* tcoordMin,
					 const Mathematics::Float2* tcoordMax, VertexFormatSmartPointer vformat);

		  ~TubeSurface ();
		  
		  TubeSurface(const TubeSurface&) = default;
		  TubeSurface& operator=(const TubeSurface&) = default;
		  TubeSurface(TubeSurface&&) = default;
		  TubeSurface& operator=(TubeSurface&&) = default;

		// Member access.
		void SetMedial (Mathematics::Curve3f* medial) noexcept;
		const Mathematics::Curve3f* GetMedial () const noexcept;
		void SetRadial (RadialFunction radial) noexcept;
		RadialFunction GetRadial () const noexcept;
		void SetUpVector (const Mathematics::Vector3Df& upVector) noexcept;
		const Mathematics::Vector3Df& GetUpVector () const noexcept;
		int GetNumMedialSamples () const noexcept;
		int GetNumSliceSamples () const noexcept;

		// Generate vertices for the end slices.  These are useful when you build
		// an open tube and want to attach meshes at the ends to close the tube.
		// The input array must have size (at least) S+1 where S is the number
		// returned by GetSliceSamples.  Function GetTMinSlice is used to access
		// the slice corresponding to the medial curve evaluated at its domain
		// minimum, tmin.  Function GetTMaxSlice accesses the slice for the
		// domain maximum, tmax.  If the curve is closed, the slices are the same.
		void GetTMinSlice (Mathematics::Vector3Df* slice);
		void GetTMaxSlice (Mathematics::Vector3Df* slice);

		// If the medial curve is modified, for example if it is control point
		// based and the control points are modified, then you should call this
		// update function to recompute the tube surface geometry.
		void UpdateSurface ();

	protected:
		// Tessellation support.
            int Index(int s, int m) noexcept;
		void ComputeSinCos ();
		void ComputeVertices ();
		void ComputeNormals ();
		void ComputeUVs (const Mathematics::Float2& tcoordMin, const Mathematics::Float2& tcoordMax);
		void ComputeIndices (bool insideView);

		Mathematics::Curve3f* mMedial;
		RadialFunction mRadial;
		int mNumMedialSamples, mNumSliceSamples;
		Mathematics::Vector3Df mUpVector;
		float* mSin;
		float* mCos;
		bool mClosed, mSampleByArcLength;
	};
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
	CORE_TOOLS_STREAM_REGISTER(TubeSurface);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Ninth, TubeSurface); 
	#include STSTEM_WARNING_POP
}

#endif // RENDERING_CURVES_SURFACES_TUBE_SURFACE_H

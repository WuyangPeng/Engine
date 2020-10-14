// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/25 15:51)

#ifndef RENDERING_CURVES_SURFACES_BOX_SURFACE_H
#define RENDERING_CURVES_SURFACES_BOX_SURFACE_H

#include "Rendering/RenderingDll.h"

#include "Rendering/SceneGraph/Node.h"
#include "Mathematics/CurvesSurfacesVolumes/BSplineVolume.h"
#include "Rendering/SceneGraph/TrianglesMesh.h"

namespace Rendering
{
	class BoxSurface : public Node
	{
	private:
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(BoxSurface); 

	public:
		using ClassType = BoxSurface;
		using ParentType = Node;

	public:
		// Construction and destruction.  BoxSurface accepts responsibility for
		// deleting the input volume.
		//
		// The six TriMesh children of this object are initially stored in the
		// order: u=0 face, u=1 face, v=0 face, v=1 face, w=0 face, w=1 face.  The
		// texture coordinate ordering preserves the (u,v,w) ordering of the box
		// coordinate space.
		//   u=0 face:  (v,w) in [0,1]^2, origin at vertex (0,0,0)
		//   u=1 face:  (v,w) in [0,1]^2, origin at vertex (1,0,0)
		//   v=0 face:  (u,w) in [0,1]^2, origin at vertex (0,0,0)
		//   v=1 face:  (u,w) in [0,1]^2, origin at vertex (0,1,0)
		//   w=0 face:  (u,v) in [0,1]^2, origin at vertex (0,0,0)
		//   w=1 face:  (u,v) in [0,1]^2, origin at vertex (0,0,1)

		BoxSurface(Mathematics::BSplineVolumef* volume, int numUSamples, int numVSamples, int numWSamples, VertexFormatSharedPtr vformat[6]);

		  ~BoxSurface();
		  
		  BoxSurface(const BoxSurface&) = default;
		  BoxSurface& operator=(const BoxSurface&) = default;
		  BoxSurface(BoxSurface&&) = default;
		  BoxSurface& operator=(BoxSurface&&) = default;

		// Member access.
		const Mathematics::BSplineVolumef* GetVolume() const noexcept;
		int GetNumUSamples() const noexcept;
		int GetNumVSamples() const noexcept;
		int GetNumWSamples() const noexcept;

		// When the volume is modified, call this update function to recompute
		// the box surface geometry.
		void UpdateSurface();

		// The order of the faces can change by sorting.  Given a direction,
		// the faces are ordered so that the back-facing ones occur first in
		// the list followed by the front-facing ones.  This supports correct
		// alpha blending, at least when the faces are only moderately perturbed
		// by the B-spline volume.  The process of enabling and disabling
		// causes changes in the render state (cull state, zbuffer state).
		void EnableSorting();
		void DisableSorting();
		void SortFaces(const AVector& worldViewDirection);
                ObjectInterfaceSharedPtr CloneObject() const override;
	protected:
		TrianglesMeshSharedPtr CreateFace(int numRows, int numCols, VertexFormatSharedPtr vformat,bool ccw, float faceValue, int permute[3]);

		void UpdateFace(int numRows, int numCols, VertexFormatSharedPtr vformat,VertexBufferSharedPtr vbuffer, bool ccw, float faceValue, int permute[3]);

		Mathematics::BSplineVolumef* mVolume;
		int mNumUSamples, mNumVSamples, mNumWSamples;
		bool mDoSort;
	};
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(BoxSurface);
	CORE_TOOLS_SHARED_PTR_DECLARE( BoxSurface)
		#include STSTEM_WARNING_POP
}

#endif // RENDERING_CURVES_SURFACES_BOX_SURFACE_H

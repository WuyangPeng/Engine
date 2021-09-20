/////////////////////////////////////////////////////////////////////////////
//
// 3D Math Primer for Games and Graphics Development
//
// TriMesh.h - Triangle mesh class for real-time use (rendering and
// collision detection)
//
// Visit gamemath.com for the latest version of this file.
//
/////////////////////////////////////////////////////////////////////////////

#ifndef __TRIMESH_H_INCLUDED__
#define __TRIMESH_H_INCLUDED__

#ifndef __AABB3_H_INCLUDED__
	#include "AABB3.h"
#endif

namespace ThreeDMathPrimerForGraphicsAndGameDevelopment
{
	struct RenderVertex;
	struct RenderTri;
	class EditTriMesh;

	/////////////////////////////////////////////////////////////////////////////
	//
	// TriMesh
	//
	// Triangle mesh class that can be rendered and collided with
	//
	/////////////////////////////////////////////////////////////////////////////

	class TriMesh
	{
	public:
		TriMesh() noexcept;
		~TriMesh() noexcept;

		TriMesh(const TriMesh&) = delete;
		TriMesh& operator=(const TriMesh&) = delete;
		TriMesh(TriMesh&&) noexcept = delete;
		TriMesh& operator=(TriMesh&&) noexcept = delete;

		// Memory allocation

		void allocateMemory(int nVertexCount, int nTriCount);
		void freeMemory() noexcept;

		// Mesh accessesors

		int getVertexCount() const noexcept
		{
			return vertexCount;
		}
		RenderVertex* getVertexList() const noexcept
		{
			return vertexList;
		}
		int getTriCount() const noexcept
		{
			return triCount;
		}
		RenderTri* getTriList() const noexcept
		{
			return triList;
		}

		// Rendering.  This will use the current 3D context.

		void render() const noexcept;

		// Bounding box

		void computeBoundingBox() noexcept;
		const AABB3& getBoundingBox() const noexcept
		{
			return boundingBox;
		}

		// Conversion to/from an "edit" mesh.  Note that this class
		// doesn't know anything about parts or materials, so the
		// conversion is not an exact translation.

		void fromEditMesh(const EditTriMesh& mesh);
		void toEditMesh(const EditTriMesh& mesh) const noexcept;

	protected:

		// Mesh data

		int vertexCount;
		RenderVertex* vertexList;
		int triCount;
		RenderTri* triList;

		// Axially aligned bounding box.  You must call computeBoundingBox()
		// to update this if you modify the vertex list directly

		AABB3 boundingBox;
	};
}
/////////////////////////////////////////////////////////////////////////////
#endif // #ifndef __TRIMESH_H_INCLUDED__

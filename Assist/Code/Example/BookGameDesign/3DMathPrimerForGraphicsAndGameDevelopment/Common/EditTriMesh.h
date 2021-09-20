/////////////////////////////////////////////////////////////////////////////
//
// 3D Math Primer for Games and Graphics Development
//
// EditTriMesh.h - Declarations for class EditTriMesh
//
// Visit gamemath.com for the latest version of this file.
//
// For more details, see EditTriMesh.cpp
//
/////////////////////////////////////////////////////////////////////////////

#ifndef __EDITTRIMESH_H_INCLUDED__
#define __EDITTRIMESH_H_INCLUDED__

#ifndef __VECTOR3_H_INCLUDED__
	#include "Vector3.h"
#endif
#include <cstdio>

namespace ThreeDMathPrimerForGraphicsAndGameDevelopment
{
	class Matrix4x3;
	class AABB3;

	/////////////////////////////////////////////////////////////////////////////
	//
	// class EditTriMesh
	//
	// Store an indexed triangle mesh in a very flexible format that makes
	// editing and mesh manipulations easy.  (NOT optimized for rendering,
	// collision detection, or anything else.)
	//
	// This class supports texture mapping coordinates and vertex normals
	//
	/////////////////////////////////////////////////////////////////////////////

	class EditTriMesh
	{
	public:

		// Local types

			// class Vertex represents the information we keep track of for
			// one vertex

		class Vertex
		{
		public:
			Vertex() noexcept
			{
				setDefaults();
			}
			void setDefaults() noexcept;

			// 3D vertex position;

			Vector3	p;

			// Vertex-level texture mapping coordinates.  Notice that
			// these may be invalid at various times.  The "real" UVs
			// are in the triangles.  For rendering, we often need UV's
			// at the vertex level.  But for many other optimizations,
			// we may need to weld vertices for faces with different
			// UV's.

			float u = 0.0f;
			float v = 0.0f;

			// vertex-level surface normal.  Again, this is only
			// valid in certain circumstances

			Vector3	normal;

			// Utility "mark" variable, often handy

			int	mark = 0;
		};

		// class Tri represents the information we keep track of
		// for one triangle

		class Tri
		{
		public:
			Tri() noexcept
			{
				setDefaults();
			}
			void setDefaults() noexcept;

			// Face vertices.

			struct Vert
			{
				int	index = 0;	// index into the vertex list
				float u = 0.0f;
				float v = 0.0f;	// mapping coords
			};

			Vert v[3];

			// Surface normal

			Vector3	normal;

			// Which part does this tri belong to?

			int	part = 0;

			// Index into the material list

			int	material = 0;

			// Utility "mark" variable, often handy

			int	mark = 0;

			// Return true if the triangle is "degenerate" - it uses
			// the same vertex more than once

			bool isDegenerate() const noexcept;

			// Return index of vertex (0..2), or -1 if we
			// don't use that vertex

			int	findVertex(int vertexIndex) const noexcept;
		};

		// This is the information we store for a "material"
		// In our case, we're only going to store a simple
		// diffuse texture map.  However, more complex properties
		// are often associated with materials.

		class Material
		{
		public:
			Material() noexcept
			{
				setDefaults();
			}
			void setDefaults() noexcept;

			char diffuseTextureName[256]{ };

			// Utility "mark" variable, often handy

			int	mark = 0;
		};

		// This is the information we store for a "part"
		// We don't store much except the part name,
		// and a mark variable

		class Part
		{
		public:
			Part() noexcept
			{
				setDefaults();
			}
			void setDefaults() noexcept;

			char name[256]{ };

			// Utility "mark" variable, often handy

			int	mark = 0;
		};

		// This class contains options used to control
		// optimization

		class OptimizationParameters
		{
		public:
			OptimizationParameters() noexcept
			{
				setDefaults();
			}
			void setDefaults() noexcept;

			// A tolerance value which is used to
			// determine if two vertices are coincident.

			float coincidentVertexTolerance = 0.0f;

			// Triangle angle tolerance.  Vertices
			// are not welded if the are on an edge
			// and the angle between the nrmals of the
			// triangles on this edge are too
			// far apart.  We store the cosine of this
			// value since that's what's actually used.
			// Use the functions to set it

			float cosOfEdgeAngleTolerance = 0.0f;
			void setEdgeAngleToleranceInDegrees(float degrees) noexcept;
		};

		// Standard class object maintenance

		EditTriMesh() noexcept;
		EditTriMesh(const EditTriMesh& x) noexcept;
		~EditTriMesh() noexcept;

		// Operator = makes a copy of the mesh

		EditTriMesh& operator=(const EditTriMesh& src) noexcept;

		EditTriMesh(EditTriMesh&& x) noexcept = default;
		EditTriMesh& operator=(EditTriMesh&& x) noexcept = default;

		// Accessors to the mesh data:

		int	vertexCount() const noexcept
		{
			return vCount;
		}
		int	triCount() const noexcept
		{
			return tCount;
		}
		int	materialCount() const noexcept
		{
			return mCount;
		}
		int	partCount() const noexcept
		{
			return pCount;
		}

		Vertex& vertex(int vertexIndex) noexcept;
		const Vertex& vertex(int vertexIndex) const noexcept;

		Tri& tri(int triIndex) noexcept;
		const Tri& tri(int triIndex) const noexcept;

		Material& material(int materialIndex) noexcept;
		const Material& material(int materialIndex) const noexcept;

		Part& part(int partIndex) noexcept;
		const Part& part(int partIndex) const noexcept;

		// Basic mesh operations

		// Reset the mesh to empty state

		void empty() noexcept;

		// Set list counts.  If the lists are grown, the new
		// entries will be properly defaulted.  If the lists
		// are shrunk, no check is made to ensure that a valid
		// mesh remains.

		void setVertexCount(int vc) noexcept;
		void setTriCount(int tc) noexcept;
		void setMaterialCount(int mc) noexcept;
		void setPartCount(int pc) noexcept;

		// Add a triangle/vertex/material.  The index of the newly
		// added item is returned

		int	addTri() noexcept;
		int	addTri(const Tri& t) noexcept;
		int	addVertex() noexcept;
		int	addVertex(const Vertex& v) noexcept;
		int	dupVertex(int srcVertexIndex) noexcept;
		int	addMaterial(const Material& m) noexcept;
		int	addPart(const Part& p) noexcept;

		// Handy functions to reset all marks at once

		void markAllVertices(int mark) noexcept;
		void markAllTris(int mark) noexcept;
		void markAllMaterials(int mark) noexcept;
		void markAllParts(int mark) noexcept;

		// Deletion.

		void deleteVertex(int vertexIndex) noexcept;
		void deleteTri(int triIndex) noexcept;
		void deleteMarkedTris(int mark) noexcept;
		void deleteDegenerateTris() noexcept;
		void deleteMaterial(int materialIndex) noexcept;
		void deleteUnusedMaterials() noexcept;
		void deletePart(int partIndex) noexcept;
		void deleteEmptyParts() noexcept;

		// Extract parts

		void extractParts(EditTriMesh* meshes) noexcept;
		void extractOnePartOneMaterial(int partIndex, int materialIndex, EditTriMesh* result) noexcept;

		// Detach all the faces from one another.  This
		// creates a new vertex list, with each vertex
		// only used by one triangle.  Simultaneously,
		// unused vertices are removed.

		void detachAllFaces() noexcept;

		// Transform all the vertices

		void transformVertices(const Matrix4x3& m) noexcept;

		// Computations

		// Compute triangle-level surface normals

		void computeOneTriNormal(int triIndex) noexcept;
		void computeOneTriNormal(Tri& t) noexcept;
		void computeTriNormals() noexcept;

		// Compute vertex level surface normals.  This
		// automatically computes the triangle level
		// surface normals

		void computeVertexNormals() noexcept;

		// Compute the size of the mesh

		AABB3 computeBounds() const noexcept;

		// Optimization

		// Re-order the vertex list, in the order that they
		// are used by the faces.  This can improve cache
		// performace and vertex caching by increasing the
		// locality of reference.  This function can also remove
		// unused vertices simultaneously

		void optimizeVertexOrder(bool removeUnusedVertices = true) noexcept;

		// Sort triangles by material.  This is VERY important
		// for effecient rendering

		void sortTrisByMaterial() noexcept;

		// Weld coincident vertices

		void weldVertices(const OptimizationParameters& opt) noexcept;

		// Ensure that the vertex UVs are correct, possibly
		// duplicating vertices if necessary

		void copyUvsIntoVertices() noexcept;

		// Do all of the optimizations and prepare the model
		// for fast rendering under *most* rendering systems,
		// with proper lighting.

		void optimizeForRendering() noexcept;

		// Import/Export S3D format

		bool importS3d(const char* filename, char* returnErrMsg);	
			   
		void exportS3d(const char* filename) noexcept;

		// Debugging

		void validityCheck() noexcept;
		bool validityCheck(const char* returnErrMsg) noexcept;

		// Private representation

	private:

		// The mesh lists

		int vAlloc = 0;
		int vCount = 0;
		Vertex* vList = nullptr;

		int tAlloc = 0;
		int tCount = 0;
		Tri* tList = nullptr;

		int mCount = 0;
		Material* mList = nullptr;

		int pCount = 0;
		Part* pList = nullptr;

		// Implementation details:

		void construct() noexcept;

	private:
		bool failed(FILE* f) noexcept;
		bool corrupt(char* returnErrMsg, FILE* f) noexcept;
	};
}
/////////////////////////////////////////////////////////////////////////////
#endif // #ifndef __EDITTRIMESH_H_INCLUDED__


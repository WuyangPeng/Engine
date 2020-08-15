// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 11:12)

#ifndef MATHEMATICS_MESHES_BASIC_MESH_H
#define MATHEMATICS_MESHES_BASIC_MESH_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446) 
namespace Mathematics
{
	class MATHEMATICS_DEFAULT_DECLARE BasicMesh
	{
	public:
		// Construction and destruction.  The number of vertices in the input is
		// numVertices.  The vertex array is usually passed as points, but this
		// input can be any data type you prefer (points+attributes).  The number
		// of triangles is numTriangles.  The triangles are represented as triples
		// of indices into the vertex array.  These triples are stored in indices.
		// The caller is responsible for deleting the input arrays.
		BasicMesh (int numVertices, const void* points, int numTriangles, const int* indices);
		
		virtual ~BasicMesh ();
		
		BasicMesh(const BasicMesh&) = default;
		BasicMesh& operator=(const BasicMesh&) = default;
		BasicMesh(BasicMesh&&) = default;
		BasicMesh& operator=(BasicMesh&&) = default;
		
		// The input must correspond to a mesh whose edges are shared by no more
		// than two triangles.  If an edge with three (or more) edges is
		// encountered in the construction, IsValid returns 'false'.  Otherwise
		// it returns 'true'.
		bool IsValid () const noexcept;
		
		class MATHEMATICS_DEFAULT_DECLARE Vertex
		{
		public:
			Vertex () noexcept;
			~Vertex ();
			Vertex(const Vertex&) = default;
		Vertex& operator=(const Vertex&) = default;
		Vertex(Vertex&&) = default;
		Vertex& operator=(Vertex&&) = default;
		
			enum { MV_CHUNK = 8 };
			
			void InsertEdge (int v, int e);
			void InsertTriangle (int t);
			
			int NumVertices;
			int* V;
			int* E;
			int NumTriangles;
			int* T;
		};
		
		class MATHEMATICS_DEFAULT_DECLARE Edge
		{
		public:
			Edge () noexcept;
			
			int V[2];
			int T[2];
		};
		
		class MATHEMATICS_DEFAULT_DECLARE Triangle
		{
		public:
			Triangle () noexcept;
			
			int V[3];
			int E[3];
			int T[3];
		};
		
		// Member access.
		int GetNumVertices () const noexcept;
		int GetNumEdges () const noexcept;
		int GetNumTriangles () const noexcept;
		const void* GetPoints () const noexcept;
		const int* GetIndices () const noexcept;
		const Vertex* GetVertices () const noexcept;    
		const Edge* GetEdges () const noexcept ;
		const Triangle* GetTriangles () const noexcept;
		
	protected:
		int mNumVertices, mNumEdges, mNumTriangles;
		const void* mPoints;
		const int* mIndices;
		Vertex* mVertices;
		Edge* mEdges;
		Triangle* mTriangles;
		bool mIsValid;
	};
}
#include STSTEM_WARNING_POP
#endif // MATHEMATICS_MESHES_BASIC_MESH_H

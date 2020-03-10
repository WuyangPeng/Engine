// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 11:12)

#ifndef MATHEMATICS_MESHES_BASIC_MESH_H
#define MATHEMATICS_MESHES_BASIC_MESH_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"

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
		
		// The input must correspond to a mesh whose edges are shared by no more
		// than two triangles.  If an edge with three (or more) edges is
		// encountered in the construction, IsValid returns 'false'.  Otherwise
		// it returns 'true'.
		bool IsValid () const;
		
		class MATHEMATICS_DEFAULT_DECLARE Vertex
		{
		public:
			Vertex ();
			~Vertex ();
			
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
			Edge ();
			
			int V[2];
			int T[2];
		};
		
		class MATHEMATICS_DEFAULT_DECLARE Triangle
		{
		public:
			Triangle ();
			
			int V[3];
			int E[3];
			int T[3];
		};
		
		// Member access.
		int GetNumVertices () const;
		int GetNumEdges () const;
		int GetNumTriangles () const;
		const void* GetPoints () const;
		const int* GetIndices () const;
		const Vertex* GetVertices () const;    
		const Edge* GetEdges () const;
		const Triangle* GetTriangles () const;
		
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

#endif // MATHEMATICS_MESHES_BASIC_MESH_H

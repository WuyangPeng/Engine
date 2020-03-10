// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 11:16)

#ifndef MATHEMATICS_MESHES_VE_MANIFOLD_MESH_H
#define MATHEMATICS_MESHES_VE_MANIFOLD_MESH_H

#include "Mathematics/MathematicsDll.h"

#include <map>

namespace Mathematics
{
	class  VEManifoldMesh
	{
	public:
		// Vertex data types.
		class Vertex;
		typedef Vertex* VPtr;
		typedef const Vertex* VCPtr;
		typedef VPtr (*VCreator)(int);
		typedef std::map<int,Vertex*> VMap;
		typedef VMap::iterator VMapIterator;
		typedef VMap::const_iterator VMapCIterator;
		
		// Edge data types.
		class Edge;
		typedef Edge* EPtr;
		typedef const Edge* ECPtr;
		typedef EPtr (*ECreator)(int,int);
		typedef std::map<std::pair<int,int>,Edge*> EMap;
		typedef EMap::iterator EMapIterator;
		typedef EMap::const_iterator EMapCIterator;
		
		// Vertex object.
		class MATHEMATICS_DEFAULT_DECLARE Vertex
		{
		public:
			Vertex (int v);
			virtual ~Vertex ();
			
			int V;
			EPtr E[2];
		};
		
		// Edge object.
		class MATHEMATICS_DEFAULT_DECLARE Edge
		{
		public:
			Edge (int v0, int v1);
			virtual ~Edge ();
			
			// Vertices, listed as a directed edge <V[0],V[1]>.
			int V[2];

			// Adjacent edges:
			//   T[0] points to edge sharing V[0]
			//   T[1] points to edge sharing V[1]
			EPtr E[2];
		};

		
		// Construction and destruction.
		VEManifoldMesh (VCreator vCreator = 0, ECreator eCreator = 0);
		virtual ~VEManifoldMesh ();
		
		// Member access.
		const VMap& GetVertices () const;
		const EMap& GetEdges () const;
		
		// Mesh manipulation.
		EPtr InsertEdge (int v0, int v1);
		bool RemoveEdge (int v0, int v1);
		
		// Manifold mesh is closed if each vertex is shared twice.
		bool IsClosed () const;
		
		// For debugging.
		void Print (const char* filename);

	protected:
		// The vertex data.
		static VPtr CreateVertex (int v0);
		VCreator mVCreator;
		VMap mVMap;
		
		// The edge data.
		static EPtr CreateEdge (int v0, int v1);
		ECreator mECreator;
		EMap mEMap;
	};
}

#endif // MATHEMATICS_MESHES_VE_MANIFOLD_MESH_H

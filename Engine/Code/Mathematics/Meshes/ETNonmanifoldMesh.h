// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 11:14)

#ifndef MATHEMATICS_MESHES_ET_NONMANIFOLD_MESH_H
#define MATHEMATICS_MESHES_ET_NONMANIFOLD_MESH_H

#include "Mathematics/MathematicsDll.h"

#include "EdgeKey.h"
#include "TriangleKey.h"

#include <map>
#include <set>
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
namespace Mathematics
{
	class  ETNonmanifoldMesh
	{
	public:
		// Edge data types.
		class Edge;
		typedef Edge* EPtr;
		typedef const Edge* ECPtr;
		typedef EPtr (*ECreator)(int,int);
		typedef std::map<EdgeKey,Edge*> EMap;
		typedef EMap::iterator EMapIterator;
		typedef EMap::const_iterator EMapCIterator;

		// Triangle data types.
		class Triangle;
		typedef Triangle* TPtr;
		typedef const Triangle* TCPtr;
		typedef TPtr (*TCreator)(int,int,int);
		typedef std::map<TriangleKey,Triangle*> TMap;
		typedef TMap::iterator TMapIterator;
		typedef TMap::const_iterator TMapCIterator;

		// Edge object.
		class  Edge
		{
		public:
			Edge (int v0, int v1) noexcept;
			virtual ~Edge ();
			Edge(const Edge&) = default;
		Edge& operator=(const Edge&) = default;
		Edge(Edge&&) = default;
		Edge& operator=(Edge&&) = default;

			int V[2];
			std::set<Triangle*> T;
		};

		class MATHEMATICS_DEFAULT_DECLARE Triangle
		{
		public:
			Triangle (int v0, int v1, int v2) noexcept;
			virtual ~Triangle ();
			Triangle(const Triangle&) = default;
		Triangle& operator=(const Triangle&) = default;
		Triangle(Triangle&&) = default;
		Triangle& operator=(Triangle&&) = default;

			// vertices (V[0],V[1],V[2])
			int V[3];

			// adjacent edges
			// E[0] represents edge (V[0],V[1])
			// E[1] represents edge (V[1],V[2])
			// E[2] represents edge (V[2],V[0])
			EPtr E[3];
		};


		ETNonmanifoldMesh (ECreator eCreator = 0, TCreator tCreator = 0) noexcept;
		virtual ~ETNonmanifoldMesh ();
		ETNonmanifoldMesh(const ETNonmanifoldMesh&) = default;
		ETNonmanifoldMesh& operator=(const ETNonmanifoldMesh&) = default;
		ETNonmanifoldMesh(ETNonmanifoldMesh&&) = default;
		ETNonmanifoldMesh& operator=(ETNonmanifoldMesh&&) = default;

		// Member access.
		int GetNumEdges () const noexcept;
		const EMap& GetEdges () const noexcept;
		int GetNumTriangles () const noexcept;
		const TMap& GetTriangles () const noexcept;

		// Mesh manipulation.
		TPtr InsertTriangle (int v0, int v1, int v2);
		bool RemoveTriangle (int v0, int v1, int v2);

		// Topological operations.
		bool IsManifold () const;
		bool IsClosed () const;
		bool IsConnected () const;

		// Extract a connected component from the mesh and remove all the
		// triangles of the component from the mesh.  This is useful for computing
		// the components in a very large mesh that uses a lot of memory.  The
		// intention is that the function is called until all components are
		// found.  The typical code is
		//
		//     ETNonmanifoldMesh mesh = <some mesh>;
		//     int numTotalIndices = 3*mesh.GetNumTriangles();
		//     int* indices = NEW1<int>(numTotalIndices);
		//     for (int numIndices = 0; numIndices < numTotalIndices; /**/ )
		//     {
		//         int currNumIndices;
		//         int* currIndices = indices + numIndices;
		//         mesh.RemoveComponent(currNumIndices, currIndices);
		//         numIndices += currNumIndices;
		//     }
		void RemoveComponent (int& numIndices, int* indices);

		void Print (const char* filename);

	protected:
		static EPtr CreateEdge (int v0, int v1);
		ECreator mECreator;
		EMap mEMap;

		static TPtr CreateTriangle (int v0, int v1, int v2);
		TCreator mTCreator;
		TMap mTMap;
	};
}
#include STSTEM_WARNING_POP
#endif // MATHEMATICS_MESHES_ET_NONMANIFOLD_MESH_H

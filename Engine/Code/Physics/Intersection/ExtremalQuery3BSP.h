// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 17:29)

#ifndef PHYSICS_INTERSECTION_EXTREMAL_QUERY3BSP_H
#define PHYSICS_INTERSECTION_EXTREMAL_QUERY3BSP_H

#include "Physics/PhysicsDll.h"

#include "ExtremalQuery3.h"
#include "Mathematics/Meshes/BasicMesh.h"

namespace Physics
{
	template <typename Real>
	class PHYSICS_TEMPLATE_DEFAULT_DECLARE ExtremalQuery3BSP : public ExtremalQuery3<Real>
	{
	public:
		using BasicMesh = Mathematics::BasicMesh;
		using ConvexPolyhedron3 = Mathematics::ConvexPolyhedron3<Real>;

	public:
		ExtremalQuery3BSP (const ConvexPolyhedron3* polytope);
		virtual ~ExtremalQuery3BSP ();

		// Compute the extreme vertices in the specified direction and return the
		// indices of the vertices in the polyhedron vertex array.
		virtual void GetExtremeVertices (const  ExtremalQuery3<Real>::Vector3D& direction, int& positiveDirection, int& negativeDirection);

		// Tree statistics.
		int GetNumNodes () const;
		int GetTreeDepth () const;

	private:
		using ExtremalQuery3<Real>::mPolytope;
		using ExtremalQuery3<Real>::mFaceNormals;

		class SphericalArc
		{
		public:
			// Construction.
			SphericalArc ();

			// The arcs are stored in a multiset ordered by increasing separation.
			// The multiset will be traversed in reverse order.  This heuristic is
			// designed to create BSP trees whose top-most nodes can eliminate as
			// many arcs as possible during an extremal query.
			bool operator< (const SphericalArc& arc) const;

			// Indices N[] into the face normal array for the endpoints of the
			// arc.
			int NIndex[2];

			// The number of arcs in the path from normal N[0] to normal N[1].
			// For spherical polygon edges, the number is 1.  The number is 2 or
			// larger for bisector arcs of the spherical polygon.
			int Separation;

			// The normal is Cross(FaceNormal[N[0]],FaceNormal[N[1]]).
			ExtremalQuery3<Real>::Vector3D Normal;

			// Indices into the vertex array for the extremal points for the
			// two regions sharing the arc.  As the arc is traversed from normal
			// N[0] to normal N[1], PosVertex is the index for the extreme vertex
			// to the left of the arc and NegVertex is the index for the extreme
			// vertex to the right of the arc.
			int PosVertex, NegVertex;

			// Support for BSP trees stored as contiguous nodes in an array.
			int PosChild, NegChild;
		};

		void SortVertexAdjacents (BasicMesh& mesh);

		void CreateSphericalArcs (BasicMesh& mesh, std::multiset<SphericalArc>& arcs);

		void CreateSphericalBisectors (BasicMesh& mesh, std::multiset<SphericalArc>& arcs);

		void CreateBSPTree (std::multiset<SphericalArc>& arcs, std::vector<SphericalArc>& nodes);

		void InsertArc (const SphericalArc& arcs, std::vector<SphericalArc>& nodes);

		// Fixed-size storage for the BSP nodes.
		int mNumNodes;
		SphericalArc* mNodes;
		int mTreeDepth;
	};

	using ExtremalQuery3BSPf = ExtremalQuery3BSP<float>;
	using ExtremalQuery3BSPd = ExtremalQuery3BSP<double>;
}

#endif // PHYSICS_INTERSECTION_EXTREMAL_QUERY3BSP_H

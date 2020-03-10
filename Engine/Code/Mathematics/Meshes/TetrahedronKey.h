// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 11:15)

#ifndef MATHEMATICS_MESHES_TETRAHEDRON_KEY_H
#define MATHEMATICS_MESHES_TETRAHEDRON_KEY_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
	class MATHEMATICS_DEFAULT_DECLARE TetrahedronKey
	{
	public:
		// An ordered tetrahedron has V[0] = min(v0,v1,v2,v3).  Let {u1,u2,u3} be
		// the set of inputs excluding the one assigned to V[0] and define
		// V[1] = min(u1,u2,u3).  Choose (V[1],V[2],V[3]) to be a permutation of
		// (u1,u2,u3) so that the final storage is one of
		//   (v0,v1,v2,v3), (v0,v2,v3,v1), (v0,v3,v1,v2)
		//   (v1,v3,v2,v0), (v1,v2,v0,v3), (v1,v0,v3,v2)
		//   (v2,v3,v0,v1), (v2,v0,v1,v3), (v2,v1,v3,v0)
		//   (v3,v1,v0,v2), (v3,v0,v2,v1), (v3,v2,v1,v0)
		// The idea is that if v0 corresponds to (1,0,0,0), v1 corresponds to
		// (0,1,0,0), v2 corresponds to (0,0,1,0), and v3 corresponds to
		// (0,0,0,1), the ordering (v0,v1,v2,v3) corresponds to the 4x4 identity
		// matrix I; the rows are the specified 4-tuples.  The permutation
		// (V[0],V[1],V[2],V[3]) induces a permutation of the rows of the identity
		// matrix to form a permutation matrix P with det(P) = 1 = det(I).
		TetrahedronKey(int v0 = -1, int v1 = -1, int v2 = -1, int v3 = -1);

		bool operator< (const TetrahedronKey& key) const;

		int V[4];

		// Indexing for the vertices of the triangle opposite a vertex.  The
		// triangle opposite vertex j is
		//   <oppositeFace[j][0], oppositeFace[j][1], oppositeFace[j][2]>
		// and is listed in counterclockwise order when viewed from outside the
		// tetrahedron.
		static const int oppositeFace[4][3];

	private:
		void Permute (int u0, int u1, int u2);
	};
}

#endif // MATHEMATICS_MESHES_TETRAHEDRON_KEY_H

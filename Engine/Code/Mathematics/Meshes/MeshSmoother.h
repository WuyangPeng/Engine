// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 11:14)
#ifndef MATHEMATICS_MESHES_MESH_SMOOTHER_H
#define MATHEMATICS_MESHES_MESH_SMOOTHER_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"

namespace Mathematics
{
	template <typename Real>
	class  MeshSmoother
	{
	public:
		// The caller is responsible for deleting the input arrays.
		MeshSmoother (int numVertices, Vector3D<Real>* vertices, int numTriangles,const int* indices);
		
		virtual ~MeshSmoother ();
		
		// For deferred construction and destruction.  The caller is responsible
		// for deleting the input arrays.
		MeshSmoother ();
		void Create (int numVertices, Vector3D<Real>* vertices, int numTriangles, const int* indices);
		void Destroy ();
		
		// Input values from the constructor.
		int GetNumVertices () const;
		const Vector3D<Real>* GetVertices () const;
		int GetNumTriangles () const;
		const int* GetIndices () const;
		
		// Derived quantites from the input mesh.
		const Vector3D<Real>* GetNormals () const;
		const Vector3D<Real>* GetMeans () const;
		
		// Apply one iteration of the smoother.  The input time is supported for
		// applications where the surface evolution is time-dependent.
		void Update (Real t = Math<Real>::GetValue(0));
		
	protected:
		virtual bool VertexInfluenced (int i, Real t);
		virtual Real GetTangentWeight (int i, Real t);
		virtual Real GetNormalWeight (int i, Real t);
		
		int mNumVertices;
		Vector3D<Real>* mVertices;
		int mNumTriangles;
		const int* mIndices;
		
		Vector3D<Real>* mNormals;
		Vector3D<Real>* mMeans;
		int* mNeighborCounts;
	};
	
	using MeshSmootherf = MeshSmoother<float>;
	using MeshSmootherd = MeshSmoother<double>;
}

#endif // MATHEMATICS_MESHES_MESH_SMOOTHER_H

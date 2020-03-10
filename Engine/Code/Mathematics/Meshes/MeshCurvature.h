// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 11:14)

#ifndef MATHEMATICS_MESHES_MESH_CURVATURE_H
#define MATHEMATICS_MESHES_MESH_CURVATURE_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Matrix3.h"
#include "Mathematics/Algebra/Matrix2.h"

namespace Mathematics
{
	template <typename Real>
	class  MeshCurvature
	{
	public:
		// The caller is responsible for deleting the input arrays.
		MeshCurvature (int numVertices, const Vector3D<Real>* vertices, int numTriangles, const int* indices);

		virtual ~MeshCurvature ();

		// Input values from the constructor.
		int GetNumVertices () const;
		const Vector3D<Real>* GetVertices () const;
		int GetNumTriangles () const;
		const int* GetIndices () const;

		// Derived quantites from the input mesh.
		const Vector3D<Real>* GetNormals () const;
		const Real* GetMinCurvatures () const;
		const Real* GetMaxCurvatures () const;
		const Vector3D<Real>* GetMinDirections () const;
		const Vector3D<Real>* GetMaxDirections () const;

	protected:
		int mNumVertices;
		const Vector3D<Real>* mVertices;
		int mNumTriangles;
		const int* mIndices;

		Vector3D<Real>* mNormals;
		Real* mMinCurvatures;
		Real* mMaxCurvatures;
		Vector3D<Real>* mMinDirections;
		Vector3D<Real>* mMaxDirections;
	};

	using MeshCurvaturef = MeshCurvature<float>;
	using MeshCurvatured = MeshCurvature<double>;
}

#endif // MATHEMATICS_MESHES_MESH_CURVATURE_H

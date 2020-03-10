// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 11:13)

#ifndef MATHEMATICS_MESHES_CONFORMAL_MAP_H
#define MATHEMATICS_MESHES_CONFORMAL_MAP_H

#include "Mathematics/MathematicsDll.h"

#include "BasicMesh.h"
#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/NumericalAnalysis/LinearSystem.h"
#include "Mathematics/NumericalAnalysis/PolynomialRoots.h"

namespace Mathematics
{
	template <typename Real>
	class  ConformalMap
	{
	public:
		// The input mesh should be a closed, manifold surface.  That is, it must
		// have the topology of a sphere.
		//
		// The number of vertices in the input is numPoints.  The vertex array
		// is usually passed as points, but this input can be any data type you
		// prefer (points+attributes).  The number of triangles is numTriangles.
		// The triangles are represented as triples of indices into the vertex
		// array.  These triples are stored in indices.  The caller is responsible
		// for deleting the input arrays.
		ConformalMap (int numPoints, const Vector3D<Real>* points,int numTriangles, const int* indices, int punctureTriangle = 0);

		~ConformalMap ();

		// Conformal mapping of mesh to plane.  The array of coordinates has a
		// one-to-one correspondence with the input vertex array.
		const Vector2D<Real>* GetPlaneCoordinates () const;
		const Vector2D<Real>& GetPlaneMin () const;
		const Vector2D<Real>& GetPlaneMax () const;

		// Conformal mapping of mesh to sphere (centered at origin).  The array
		// of coordinates has a one-to-one correspondence with the input vertex
		// array.
		const Vector3D<Real>* GetSphereCoordinates () const;
		Real GetSphereRadius () const;

	private:
		Real ComputeRadius (const Vector2D<Real>& V0, const Vector2D<Real>& V1,const Vector2D<Real>& V2, Real areaFraction) const;

		// Conformal mapping to a plane.  The plane's (px,py) points correspond to
		// the mesh's (mx,my,mz) points.
		Vector2D<Real>* mPlanes;
		Vector2D<Real> mPlaneMin, mPlaneMax;

		// Conformal mapping to a sphere.  The sphere's (sx,sy,sz) points
		// correspond to the mesh's (mx,my,mz) points.
		Vector3D<Real>* mSpheres;
		Real mRadius;
	};

	using ConformalMapf = ConformalMap<float>;
	using ConformalMapd = ConformalMap<double>;
}

#endif // MATHEMATICS_MESHES_CONFORMAL_MAP_H

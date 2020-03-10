// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 18:14)

#ifndef PHYSICS_RIGID_BODY_POLYHEDRAL_MASS_PROPERTIES_DETAIL_H
#define PHYSICS_RIGID_BODY_POLYHEDRAL_MASS_PROPERTIES_DETAIL_H

#include "PolyhedralMassProperties.h"

namespace Physics
{
	template <typename Real>
	void ComputeMassProperties(const Mathematics::Vector3D<Real>* vertices, int numTriangles,const int* indices, bool bodyCoords, Real& mass,
							   Mathematics::Vector3D<Real>& center,Mathematics::Matrix3<Real>& inertia)
	{
		const Real oneDiv6 = (Real)(1.0 / 6.0);
		const Real oneDiv24 = (Real)(1.0 / 24.0);
		const Real oneDiv60 = (Real)(1.0 / 60.0);
		const Real oneDiv120 = (Real)(1.0 / 120.0);

		// order:  1, x, y, z, x^2, y^2, z^2, xy, yz, zx
		Real integral[10] = { (Real)0.0, (Real)0.0, (Real)0.0, (Real)0.0, (Real)0.0, (Real)0.0, (Real)0.0, (Real)0.0, (Real)0.0, (Real)0.0 };

		const int* index = indices;
		int i;
		for (i = 0; i < numTriangles; i++)
		{
			// Get vertices of triangle i.
			Mathematics::Vector3D<Real> v0 = vertices[*index++];
			Mathematics::Vector3D<Real> v1 = vertices[*index++];
			Mathematics::Vector3D<Real> v2 = vertices[*index++];

			// Get cross product of edges and normal vector.
			Mathematics::Vector3D<Real> V1mV0 = v1 - v0;
			Mathematics::Vector3D<Real> V2mV0 = v2 - v0;
			Mathematics::Vector3D<Real> N = Mathematics::Vector3DTools<Real>::CrossProduct(V1mV0, V2mV0);

			// Compute integral terms.
			Real tmp0, tmp1, tmp2;
			Real f1x, f2x, f3x, g0x, g1x, g2x;
			tmp0 = v0.GetXCoordinate() + v1.GetXCoordinate();
			f1x = tmp0 + v2.GetXCoordinate();
			tmp1 = v0.GetXCoordinate()*v0.GetXCoordinate();
			tmp2 = tmp1 + v1.GetXCoordinate()*tmp0;
			f2x = tmp2 + v2.GetXCoordinate()*f1x;
			f3x = v0.GetXCoordinate()*tmp1 + v1.GetXCoordinate()*tmp2 + v2.GetXCoordinate()*f2x;
			g0x = f2x + v0.GetXCoordinate()*(f1x + v0.GetXCoordinate());
			g1x = f2x + v1.GetXCoordinate()*(f1x + v1.GetXCoordinate());
			g2x = f2x + v2.GetXCoordinate()*(f1x + v2.GetXCoordinate());

			Real f1y, f2y, f3y, g0y, g1y, g2y;
			tmp0 = v0.GetYCoordinate() + v1.GetYCoordinate();
			f1y = tmp0 + v2.GetYCoordinate();
			tmp1 = v0.GetYCoordinate()*v0.GetYCoordinate();
			tmp2 = tmp1 + v1.GetYCoordinate()*tmp0;
			f2y = tmp2 + v2.GetYCoordinate()*f1y;
			f3y = v0.GetYCoordinate()*tmp1 + v1.GetYCoordinate()*tmp2 + v2.GetYCoordinate()*f2y;
			g0y = f2y + v0.GetYCoordinate()*(f1y + v0.GetYCoordinate());
			g1y = f2y + v1.GetYCoordinate()*(f1y + v1.GetYCoordinate());
			g2y = f2y + v2.GetYCoordinate()*(f1y + v2.GetYCoordinate());

			Real f1z, f2z, f3z, g0z, g1z, g2z;
			tmp0 = v0.GetZCoordinate() + v1.GetZCoordinate();
			f1z = tmp0 + v2.GetZCoordinate();
			tmp1 = v0.GetZCoordinate()*v0.GetZCoordinate();
			tmp2 = tmp1 + v1.GetZCoordinate()*tmp0;
			f2z = tmp2 + v2.GetZCoordinate()*f1z;
			f3z = v0.GetZCoordinate()*tmp1 + v1.GetZCoordinate()*tmp2 + v2.GetZCoordinate()*f2z;
			g0z = f2z + v0.GetZCoordinate()*(f1z + v0.GetZCoordinate());
			g1z = f2z + v1.GetZCoordinate()*(f1z + v1.GetZCoordinate());
			g2z = f2z + v2.GetZCoordinate()*(f1z + v2.GetZCoordinate());

			// Update integrals.
			integral[0] += N.GetXCoordinate()*f1x;
			integral[1] += N.GetXCoordinate()*f2x;
			integral[2] += N.GetYCoordinate()*f2y;
			integral[3] += N.GetZCoordinate()*f2z;
			integral[4] += N.GetXCoordinate()*f3x;
			integral[5] += N.GetYCoordinate()*f3y;
			integral[6] += N.GetZCoordinate()*f3z;
			integral[7] += N.GetXCoordinate()*(v0.GetYCoordinate()*g0x + v1.GetYCoordinate()*g1x + v2.GetYCoordinate()*g2x);
			integral[8] += N.GetYCoordinate()*(v0.GetZCoordinate()*g0y + v1.GetZCoordinate()*g1y + v2.GetZCoordinate()*g2y);
			integral[9] += N.GetZCoordinate()*(v0.GetXCoordinate()*g0z + v1.GetXCoordinate()*g1z + v2.GetXCoordinate()*g2z);
		}

		integral[0] *= oneDiv6;
		integral[1] *= oneDiv24;
		integral[2] *= oneDiv24;
		integral[3] *= oneDiv24;
		integral[4] *= oneDiv60;
		integral[5] *= oneDiv60;
		integral[6] *= oneDiv60;
		integral[7] *= oneDiv120;
		integral[8] *= oneDiv120;
		integral[9] *= oneDiv120;

		// mass
		mass = integral[0];

		// center of mass
		center = Mathematics::Vector3D<Real>(integral[1], integral[2], integral[3]) / mass;

		// inertia relative to world origin
		inertia[0][0] = integral[5] + integral[6];
		inertia[0][1] = -integral[7];
		inertia[0][2] = -integral[9];
		inertia[1][0] = inertia[0][1];
		inertia[1][1] = integral[4] + integral[6];
		inertia[1][2] = -integral[8];
		inertia[2][0] = inertia[0][2];
		inertia[2][1] = inertia[1][2];
		inertia[2][2] = integral[4] + integral[5];

		// inertia relative to center of mass
		if (bodyCoords)
		{
			inertia[0][0] -= mass * (center.GetYCoordinate()*center.GetYCoordinate() + center.GetZCoordinate()*center.GetZCoordinate());
			inertia[0][1] += mass * center.GetXCoordinate()*center.GetYCoordinate();
			inertia[0][2] += mass * center.GetZCoordinate()*center.GetXCoordinate();
			inertia[1][0] = inertia[0][1];
			inertia[1][1] -= mass * (center.GetZCoordinate()*center.GetZCoordinate() + center.GetXCoordinate()*center.GetXCoordinate());
			inertia[1][2] += mass * center.GetYCoordinate()*center.GetZCoordinate();
			inertia[2][0] = inertia[0][2];
			inertia[2][1] = inertia[1][2];
			inertia[2][2] -= mass * (center.GetXCoordinate()*center.GetXCoordinate() + center.GetYCoordinate()*center.GetYCoordinate());
		}
	}

}

#endif // PHYSICS_RIGID_BODY_POLYHEDRAL_MASS_PROPERTIES_DETAIL_H
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
	void ComputeMassProperties(const Mathematics::Vector3<Real>* vertices, int numTriangles,const int* indices, bool bodyCoords, Real& mass,
							   Mathematics::Vector3<Real>& center,Mathematics::Matrix3<Real>& inertia)
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
			Mathematics::Vector3<Real> v0 = vertices[*index++];
			Mathematics::Vector3<Real> v1 = vertices[*index++];
			Mathematics::Vector3<Real> v2 = vertices[*index++];

			// Get cross product of edges and normal vector.
			Mathematics::Vector3<Real> V1mV0 = v1 - v0;
			Mathematics::Vector3<Real> V2mV0 = v2 - v0;
			Mathematics::Vector3<Real> N = Mathematics::Vector3Tools<Real>::CrossProduct(V1mV0, V2mV0);

			// Compute integral terms.
			Real tmp0, tmp1, tmp2;
			Real f1x, f2x, f3x, g0x, g1x, g2x;
			tmp0 = v0.GetX() + v1.GetX();
			f1x = tmp0 + v2.GetX();
			tmp1 = v0.GetX()*v0.GetX();
			tmp2 = tmp1 + v1.GetX()*tmp0;
			f2x = tmp2 + v2.GetX()*f1x;
			f3x = v0.GetX()*tmp1 + v1.GetX()*tmp2 + v2.GetX()*f2x;
			g0x = f2x + v0.GetX()*(f1x + v0.GetX());
			g1x = f2x + v1.GetX()*(f1x + v1.GetX());
			g2x = f2x + v2.GetX()*(f1x + v2.GetX());

			Real f1y, f2y, f3y, g0y, g1y, g2y;
			tmp0 = v0.GetY() + v1.GetY();
			f1y = tmp0 + v2.GetY();
			tmp1 = v0.GetY()*v0.GetY();
			tmp2 = tmp1 + v1.GetY()*tmp0;
			f2y = tmp2 + v2.GetY()*f1y;
			f3y = v0.GetY()*tmp1 + v1.GetY()*tmp2 + v2.GetY()*f2y;
			g0y = f2y + v0.GetY()*(f1y + v0.GetY());
			g1y = f2y + v1.GetY()*(f1y + v1.GetY());
			g2y = f2y + v2.GetY()*(f1y + v2.GetY());

			Real f1z, f2z, f3z, g0z, g1z, g2z;
			tmp0 = v0.GetZ() + v1.GetZ();
			f1z = tmp0 + v2.GetZ();
			tmp1 = v0.GetZ()*v0.GetZ();
			tmp2 = tmp1 + v1.GetZ()*tmp0;
			f2z = tmp2 + v2.GetZ()*f1z;
			f3z = v0.GetZ()*tmp1 + v1.GetZ()*tmp2 + v2.GetZ()*f2z;
			g0z = f2z + v0.GetZ()*(f1z + v0.GetZ());
			g1z = f2z + v1.GetZ()*(f1z + v1.GetZ());
			g2z = f2z + v2.GetZ()*(f1z + v2.GetZ());

			// Update integrals.
			integral[0] += N.GetX()*f1x;
			integral[1] += N.GetX()*f2x;
			integral[2] += N.GetY()*f2y;
			integral[3] += N.GetZ()*f2z;
			integral[4] += N.GetX()*f3x;
			integral[5] += N.GetY()*f3y;
			integral[6] += N.GetZ()*f3z;
			integral[7] += N.GetX()*(v0.GetY()*g0x + v1.GetY()*g1x + v2.GetY()*g2x);
			integral[8] += N.GetY()*(v0.GetZ()*g0y + v1.GetZ()*g1y + v2.GetZ()*g2y);
			integral[9] += N.GetZ()*(v0.GetX()*g0z + v1.GetX()*g1z + v2.GetX()*g2z);
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
		center = Mathematics::Vector3<Real>(integral[1], integral[2], integral[3]) / mass;

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
			inertia[0][0] -= mass * (center.GetY()*center.GetY() + center.GetZ()*center.GetZ());
			inertia[0][1] += mass * center.GetX()*center.GetY();
			inertia[0][2] += mass * center.GetZ()*center.GetX();
			inertia[1][0] = inertia[0][1];
			inertia[1][1] -= mass * (center.GetZ()*center.GetZ() + center.GetX()*center.GetX());
			inertia[1][2] += mass * center.GetY()*center.GetZ();
			inertia[2][0] = inertia[0][2];
			inertia[2][1] = inertia[1][2];
			inertia[2][2] -= mass * (center.GetX()*center.GetX() + center.GetY()*center.GetY());
		}
	}

}

#endif // PHYSICS_RIGID_BODY_POLYHEDRAL_MASS_PROPERTIES_DETAIL_H
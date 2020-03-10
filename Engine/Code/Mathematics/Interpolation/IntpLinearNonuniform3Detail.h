// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 10:20)

#ifndef MATHEMATICS_INTERPOLATION_INTP_LINEAR_NONUNIFORM3_DETAIL_H
#define MATHEMATICS_INTERPOLATION_INTP_LINEAR_NONUNIFORM3_DETAIL_H

#include "IntpLinearNonuniform3.h"

namespace Mathematics
{
	template <typename Real>
	IntpLinearNonuniform3<Real>::IntpLinearNonuniform3(const Delaunay3<Real>& DT, Real* F, bool owner)
		:mDT(&DT),mF(F),mOwner(owner)
	{
	}

	template <typename Real>
	IntpLinearNonuniform3<Real>::~IntpLinearNonuniform3()
	{
		if (mOwner)
		{
			DELETE1(mF);
		}
	}

	template <typename Real>
	bool IntpLinearNonuniform3<Real>::Evaluate(const Vector3D<Real>& P, Real& F)
	{
		int i = mDT->GetContainingTetrahedron(P);
		if (i == -1)
		{
			return false;
		}

		// Get the barycentric coordinates of P with respect to the tetrahedron,
		// P = b0*V0 + b1*V1 + b2*V2 + b3*V3, where b0+b1+b2+b3 = 1.
		Real bary[4];
		bool valid = mDT->GetBarycentricSet(i, P, bary);
		MATHEMATICS_ASSERTION_0(valid, "Unexpected condition\n");
		if (!valid)
		{
			return false;
		}

		// Get the vertex indices for look up into the function-value array.
		int index[4];
		valid = mDT->GetIndexSet(i, index);
		MATHEMATICS_ASSERTION_0(valid, "Unexpected condition\n");
		if (!valid)
		{
			return false;
		}

		// Result is a barycentric combination of function values.
		F = bary[0] * mF[index[0]] + bary[1] * mF[index[1]] +
			bary[2] * mF[index[2]] + bary[3] * mF[index[3]];

		return true;
	}
}

#endif // MATHEMATICS_INTERPOLATION_INTP_LINEAR_NONUNIFORM3_DETAIL_H
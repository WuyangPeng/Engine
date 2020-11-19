// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 17:03)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SINGULAR_VALUE_DECOMPOSITION_GTE_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SINGULAR_VALUE_DECOMPOSITION_GTE_DETAIL_H

// NOTE: This code was written for the upcoming Geometric Tools Engine but
// has been back-ported to Wild Magic 5 to replace its badly implemented
// version.

#include "SingularValueDecompositionGTE.h"

template <typename Real>
Mathematics::SingularValueDecompositionGTE<Real>
	::SingularValueDecompositionGTE(int numRows, int numCols, unsigned int maxIterations)
	:mNumRows(0), mNumCols(0), mMaxIterations(0)
{
	if (numCols > 1 && numRows >= numCols && maxIterations > 0)
	{
		mNumRows = numRows;
		mNumCols = numCols;
		mMaxIterations = maxIterations;
		mMatrix.resize(numRows * numCols);
		mDiagonal.resize(numCols);
		mSuperdiagonal.resize(numCols - 1);
		mRGivens.reserve(maxIterations * (numCols - 1));
		mLGivens.reserve(maxIterations * (numCols - 1));
		mFixupDiagonal.resize(numCols);
		mPermutation.resize(numCols);
		mVisited.resize(numCols);
		mTwoInvUTU.resize(numCols);
		mTwoInvVTV.resize(numCols - 2);
		mUVector.resize(numRows);
		mVVector.resize(numCols);
		mWVector.resize(numRows);
	}
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::SingularValueDecompositionGTE<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT
 
template <typename Real>
unsigned int Mathematics::SingularValueDecompositionGTE<Real>
	::Solve(Real const* input, int sortType)
{
	if (mNumRows > 0)
	{
		auto numElements = mNumRows * mNumCols;
		std::copy(input, input + numElements, mMatrix.begin());
		Bidiagonalize();

		// Compute 'threshold = multiplier*epsilon*|B|' as the threshold for
		// diagonal entries effectively zero; that is, |d| <= |threshold|
		// implies that d is (effectively) zero.  TODO: Allow the caller to
		// pass 'multiplier' to the constructor.
		//
		// We will use the L2-norm |B|, which is the length of the elements
		// of B treated as an NM-tuple.  The following code avoids overflow
		// when accumulating the squares of the elements when those elements
		// are large.
		auto maxAbsComp = Math::FAbs(input[0]);
		for (auto i = 1; i < numElements; ++i)
		{
			auto absComp = Math::FAbs(input[i]);
			if (absComp > maxAbsComp)
			{
				maxAbsComp = absComp;
			}
		}

		auto norm = Math::GetValue(0);
		if (maxAbsComp > Math::GetValue(0))
		{
			auto invMaxAbsComp = Math::GetValue(1) / maxAbsComp;
			for (auto i = 0; i < numElements; ++i)
			{
				auto ratio = input[i] * invMaxAbsComp;
				norm += ratio * ratio;
			}
			norm = maxAbsComp * Math::Sqrt(norm);
		}

		auto const multiplier = static_cast<Real>(8);  // TODO: Expose to caller.
		auto const epsilon = std::numeric_limits<Real>::epsilon();
		auto const threshold = multiplier * epsilon * norm;

		mRGivens.clear();
		mLGivens.clear();
		for (auto j = 0u; j < mMaxIterations; ++j)
		{
			auto imin = -1;
			auto imax = -1;
			for (auto i = mNumCols - 2; i >= 0; --i)
			{
				// When a01 is much smaller than its diagonal neighbors, it is
				// effectively zero.
				auto a00 = mDiagonal[i];
				auto a01 = mSuperdiagonal[i];
				auto a11 = mDiagonal[i + 1];
				auto sum = Math::FAbs(a00) + Math::FAbs(a11);
				if (sum + Math::FAbs(a01) != sum)
				{
					if (imax == -1)
					{
						imax = i;
					}
					imin = i;
				}
				else
				{
					// The superdiagonal term is effectively zero compared to
					// the neighboring diagonal terms.
					if (imin >= 0)
					{
						break;
					}
				}
			}

			if (imax == -1)
			{
				// The algorithm has converged.
				EnsureNonnegativeDiagonal();
				ComputePermutation(sortType);
				return j;
			}

			// We need to test diagonal entries of B for zero.  For each zero
			// diagonal entry, zero the superdiagonal.
			if (DiagonalEntriesNonzero(imin, imax, threshold))
			{
				// Process the lower-right-most unreduced bidiagonal block.
				DoGolubKahanStep(imin, imax);
			}
		}
		return 0xFFFFFFFF;
	}
	else
	{
		return 0;
	}
}
//----------------------------------------------------------------------------
template <typename Real>
void Mathematics::SingularValueDecompositionGTE<Real>
	::GetSingularValues(Real* singularValues) const
{
	if (singularValues && mNumCols > 0)
	{
		if (mPermutation[0] >= 0)
		{
			// Sorting was requested.
			for (auto i = 0; i < mNumCols; ++i)
			{
				auto p = mPermutation[i];
				singularValues[i] = mDiagonal[p];
			}
		}
		else
		{
			// Sorting was not requested.
			memcpy(singularValues, &mDiagonal[0], mNumCols * sizeof(Real));
		}
	}
}
 
template <typename Real>
void Mathematics::SingularValueDecompositionGTE<Real>
	::GetU(Real* uMatrix) const
{
	if (!uMatrix || mNumCols == 0)
	{
		// Invalid input or the constructor failed.
		return;
	}

	// Start with the identity matrix.
	std::fill(uMatrix, uMatrix + mNumRows * mNumRows, Math<Real>::GetZero());
	for (int d = 0; d < mNumRows; ++d)
	{
		uMatrix[d + mNumRows * d] = Math::GetValue(1);
	}

	// Multiply the Householder reflections using backward accumulation.
	auto r = 0;
	auto c = 0;
	for (auto i0 = mNumCols - 1, i1 = i0 + 1; i0 >= 0; --i0, --i1)
	{
		// Copy the u vector and 2/Dot(u,u) from the matrix.
		auto twoinvudu = mTwoInvUTU[i0];
		auto const* column = &mMatrix[i0];
		mUVector[i0] = Math::GetValue(1);
		for (r = i1; r < mNumRows; ++r)
		{
			mUVector[r] = column[mNumCols*r];
		}

		// Compute the w vector.
		mWVector[i0] = twoinvudu;
		for (r = i1; r < mNumRows; ++r)
		{
			mWVector[r] = Math::GetValue(0);
			for (c = i1; c < mNumRows; ++c)
			{
				mWVector[r] += mUVector[c] * uMatrix[r + mNumRows * c];
			}
			mWVector[r] *= twoinvudu;
		}

		// Update the matrix, U <- U - u*w^T.
		for (r = i0; r < mNumRows; ++r)
		{
			for (c = i0; c < mNumRows; ++c)
			{
				uMatrix[c + mNumRows * r] -= mUVector[r] * mWVector[c];
			}
		}
	}

	// Multiply the Givens rotations.
	auto givens = mLGivens.begin();
	for (; givens != mLGivens.end(); ++givens)
	{
		auto j0 = givens->index0;
		auto j1 = givens->index1;
		for (r = 0; r < mNumRows; ++r, j0 += mNumRows, j1 += mNumRows)
		{
			auto& q0 = uMatrix[j0];
			auto& q1 = uMatrix[j1];
			auto prd0 = givens->cs * q0 - givens->sn * q1;
			auto prd1 = givens->sn * q0 + givens->cs * q1;
			q0 = prd0;
			q1 = prd1;
		}
	}

	if (mPermutation[0] >= 0)
	{
		// Sorting was requested.
		std::fill(mVisited.begin(), mVisited.end(), 0);
		for (c = 0; c < mNumCols; ++c)
		{
			if (mVisited[c] == 0 && mPermutation[c] != c)
			{
				// The item starts a cycle with 2 or more elements.
				auto start = c;
				auto current = c;
				auto next = 0;
				for (r = 0; r < mNumRows; ++r)
				{
					mWVector[r] = uMatrix[c + mNumRows * r];
				}
				while ((next = mPermutation[current]) != start)
				{
					mVisited[current] = 1;
					for (r = 0; r < mNumRows; ++r)
					{
						uMatrix[current + mNumRows * r] = uMatrix[next + mNumRows * r];
					}
					current = next;
				}
				mVisited[current] = 1;
				for (r = 0; r < mNumRows; ++r)
				{
					uMatrix[current + mNumRows * r] = mWVector[r];
				}
			}
		}
	}
}
 
template <typename Real>
void Mathematics::SingularValueDecompositionGTE<Real>
	::GetV(Real* vMatrix) const
{
	if (!vMatrix || mNumCols == 0)
	{
		// Invalid input or the constructor failed.
		return;
	}

	// Start with the identity matrix.
	std::fill(vMatrix, vMatrix + mNumCols * mNumCols, Math<Real>::GetZero());
	for (int d = 0; d < mNumCols; ++d)
	{
		vMatrix[d + mNumCols * d] = Math::GetValue(1);
	}

	// Multiply the Householder reflections using backward accumulation.
	auto i0 = mNumCols - 3;
	auto i1 = i0 + 1;
	auto i2 = i0 + 2;
	auto r = 0;
	auto c = 0;
	for (; i0 >= 0; --i0, --i1, --i2)
	{
		// Copy the v vector and 2/Dot(v,v) from the matrix.
		auto twoinvvdv = mTwoInvVTV[i0];
		auto const* row = &mMatrix[mNumCols*i0];
		mVVector[i1] = Math::GetValue(1);
		for (r = i2; r < mNumCols; ++r)
		{
			mVVector[r] = row[r];
		}

		// Compute the w vector.
		mWVector[i1] = twoinvvdv;
		for (r = i2; r < mNumCols; ++r)
		{
			mWVector[r] = Math::GetValue(0);
			for (c = i2; c < mNumCols; ++c)
			{
				mWVector[r] += mVVector[c] * vMatrix[r + mNumCols * c];
			}
			mWVector[r] *= twoinvvdv;
		}

		// Update the matrix, V <- V - v*w^T.
		for (r = i1; r < mNumCols; ++r)
		{
			for (c = i1; c < mNumCols; ++c)
			{
				vMatrix[c + mNumCols * r] -= mVVector[r] * mWVector[c];
			}
		}
	}

	// Multiply the Givens rotations.
	auto givens = mRGivens.begin();
	for (; givens != mRGivens.end(); ++givens)
	{
		auto j0 = givens->index0;
		auto j1 = givens->index1;
		for (c = 0; c < mNumCols; ++c, j0 += mNumCols, j1 += mNumCols)
		{
			auto& q0 = vMatrix[j0];
			auto& q1 = vMatrix[j1];
			auto prd0 = givens->cs * q0 - givens->sn * q1;
			auto prd1 = givens->sn * q0 + givens->cs * q1;
			q0 = prd0;
			q1 = prd1;
		}
	}

	// Fix-up the diagonal.
	for (auto r = 0; r < mNumCols; ++r)
	{
		for (auto c = 0; c < mNumCols; ++c)
		{
			vMatrix[c + mNumCols * r] *= mFixupDiagonal[c];
		}
	}

	if (mPermutation[0] >= 0)
	{
		// Sorting was requested.
		std::fill(mVisited.begin(), mVisited.end(), 0);
		for (c = 0; c < mNumCols; ++c)
		{
			if (mVisited[c] == 0 && mPermutation[c] != c)
			{
				// The item starts a cycle with 2 or more elements.
				auto start = c, current = c, next;
				for (r = 0; r < mNumCols; ++r)
				{
					mWVector[r] = vMatrix[c + mNumCols * r];
				}
				while ((next = mPermutation[current]) != start)
				{
					mVisited[current] = 1;
					for (r = 0; r < mNumCols; ++r)
					{
						vMatrix[current + mNumCols * r] = vMatrix[next + mNumCols * r];
					}
					current = next;
				}
				mVisited[current] = 1;
				for (r = 0; r < mNumCols; ++r)
				{
					vMatrix[current + mNumCols * r] = mWVector[r];
				}
			}
		}
	}
}
 
template <typename Real>
void Mathematics::SingularValueDecompositionGTE<Real>
	::Bidiagonalize()
{
	auto r = 0;
	auto c = 0;
	for (auto i = 0, ip1 = 1; i < mNumCols; ++i, ++ip1)
	{
		// Compute the U-Householder vector.
		auto length = Math::GetValue(0);
		for (r = i; r < mNumRows; ++r)
		{
			auto ur = mMatrix[i + mNumCols * r];
			mUVector[r] = ur;
			length += ur * ur;
		}
		auto udu = Math::GetValue(1);
		length = Math::Sqrt(length);
		if (length > Math::GetValue(0))
		{
			auto& u1 = mUVector[i];
			auto sgn = (u1 >= Math::GetValue(0) ? Math::GetValue(1) : Math::GetValue(-1));
			auto invDenom = Math::GetValue(1) / (u1 + sgn * length);
			u1 = Math::GetValue(1);
			for (r = ip1; r < mNumRows; ++r)
			{
				auto& ur = mUVector[r];
				ur *= invDenom;
				udu += ur * ur;
			}
		}

		// Compute the rank-1 offset u*w^T.
		auto invudu = Math::GetValue(1) / udu;
		auto twoinvudu = invudu * Math::GetValue(2);
		for (c = i; c < mNumCols; ++c)
		{
			mWVector[c] = Math::GetValue(0);
			for (r = i; r < mNumRows; ++r)
			{
				mWVector[c] += mMatrix[c + mNumCols * r] * mUVector[r];
			}
			mWVector[c] *= twoinvudu;
		}

		// Update the input matrix.
		for (r = i; r < mNumRows; ++r)
		{
			for (c = i; c < mNumCols; ++c)
			{
				mMatrix[c + mNumCols * r] -= mUVector[r] * mWVector[c];
			}
		}

		if (i < mNumCols - 2)
		{
			// Compute the V-Householder vectors.
			length = Math::GetValue(0);
			for (c = ip1; c < mNumCols; ++c)
			{
				auto vc = mMatrix[c + mNumCols * i];
				mVVector[c] = vc;
				length += vc * vc;
			}
			auto vdv = Math::GetValue(1);
			length = sqrt(length);
			if (length > Math::GetValue(0))
			{
				auto& v1 = mVVector[ip1];
				auto sgn = (v1 >= Math::GetValue(0) ? Math::GetValue(1) : Math::GetValue(-1));
				auto invDenom = Math::GetValue(1) / (v1 + sgn * length);
				v1 = Math::GetValue(1);
				for (c = ip1 + 1; c < mNumCols; ++c)
				{
					auto& vc = mVVector[c];
					vc *= invDenom;
					vdv += vc * vc;
				}
			}

			// Compute the rank-1 offset w*v^T.
			auto invvdv = Math::GetValue(1) / vdv;
			auto twoinvvdv = invvdv * Math::GetValue(2);
			for (r = i; r < mNumRows; ++r)
			{
				mWVector[r] = Math::GetValue(0);
				for (c = ip1; c < mNumCols; ++c)
				{
					mWVector[r] += mMatrix[c + mNumCols * r] * mVVector[c];
				}
				mWVector[r] *= twoinvvdv;
			}

			// Update the input matrix.
			for (r = i; r < mNumRows; ++r)
			{
				for (c = ip1; c < mNumCols; ++c)
				{
					mMatrix[c + mNumCols * r] -= mWVector[r] * mVVector[c];
				}
			}

			mTwoInvVTV[i] = twoinvvdv;
			for (c = i + 2; c < mNumCols; ++c)
			{
				mMatrix[c + mNumCols * i] = mVVector[c];
			}
		}

		mTwoInvUTU[i] = twoinvudu;
		for (r = ip1; r < mNumRows; ++r)
		{
			mMatrix[i + mNumCols * r] = mUVector[r];
		}
	}

	// Copy the diagonal and subdiagonal for cache coherence in the
	// Golub-Kahan iterations.
	auto k = 0;
	auto ksup = mNumCols - 1;
	auto index = 0;
	auto delta = mNumCols + 1;
	for (k = 0; k < ksup; ++k, index += delta)
	{
		mDiagonal[k] = mMatrix[index];
		mSuperdiagonal[k] = mMatrix[index + 1];
	}
	mDiagonal[k] = mMatrix[index];
}
 
template <typename Real>
void Mathematics::SingularValueDecompositionGTE<Real>
	::GetSinCos(Real x, Real y, Real& cs,Real& sn)
{
	// Solves sn*x + cs*y = 0 robustly.
	auto tau = Math::GetValue(0);
	if (y != Math::GetValue(0))
	{
		if (Math::FAbs(y) > Math::FAbs(x))
		{
			tau = -x / y;
			sn = Math::GetValue(1) / Math::Sqrt(Math::GetValue(1) + tau * tau);
			cs = sn * tau;
		}
		else
		{
			tau = -y / x;
			cs = Math::GetValue(1) / Math::Sqrt(Math::GetValue(1) + tau * tau);
			sn = cs * tau;
		}
	}
	else
	{
		cs = Math::GetValue(1);
		sn = Math::GetValue(0);
	}
}
 
template <typename Real>
bool Mathematics::SingularValueDecompositionGTE<Real>
	::DiagonalEntriesNonzero(int imin,int imax, Real threshold)
{
	for (auto i = imin; i <= imax; ++i)
	{
		if (Math::FAbs(mDiagonal[i]) <= threshold)
		{
			// Use planar rotations to case the superdiagonal entry out of
			// the matrix, thus producing a row of zeros.
			auto x = Math::GetValue(0);
			auto z = Math::GetValue(0); 
			auto cs = Math::GetValue(0); 
			auto sn = Math::GetValue(0);
			auto y = mSuperdiagonal[i];
			mSuperdiagonal[i] = Math::GetValue(0);
			for (auto j = i + 1; j <= imax + 1; ++j)
			{
				x = mDiagonal[j];
				GetSinCos(x, y, cs, sn);
				mLGivens.push_back(GivensRotation(i, j, cs, sn));
				mDiagonal[j] = cs * x - sn * y;
				if (j <= imax)
				{
					z = mSuperdiagonal[j];
					mSuperdiagonal[j] = cs * z;
					y = sn * z;
				}
			}
			return false;
		}
	}
	return true;
}
 
template <typename Real>
void Mathematics::SingularValueDecompositionGTE<Real>
	::DoGolubKahanStep(int imin, int imax)
{
	// The implicit shift.  Compute the eigenvalue u of the lower-right 2x2
	// block of A = B^T*B that is closer to b11.
	auto f0 = (imax >= Math::GetValue(1) ? mSuperdiagonal[imax - 1] : Math::GetValue(0));
	auto d1 = mDiagonal[imax];
	auto f1 = mSuperdiagonal[imax];
	auto d2 = mDiagonal[imax + 1];
	auto a00 = d1 * d1 + f0 * f0;
	auto a01 = d1 * f1;
	auto a11 = d2 * d2 + f1 * f1;
	auto dif = (a00 - a11) *  Math::GetRational(1,2);
	auto sgn = (dif >= Math::GetValue(0) ? Math::GetValue(1) : Math::GetValue(-1));
	auto a01sqr = a01 * a01;
	auto u = a11 - a01sqr / (dif + sgn * Math::Sqrt(dif*dif + a01sqr));
	auto x = mDiagonal[imin] * mDiagonal[imin] - u;
	auto y = mDiagonal[imin] * mSuperdiagonal[imin];

	auto a12 = Math::GetValue(0);
	auto a21 = Math::GetValue(0);
	auto a22 = Math::GetValue(0);
	auto a23 = Math::GetValue(0);
	auto cs = Math::GetValue(0); 
	auto sn = Math::GetValue(0);
	auto a02 = Math::GetValue(0);
	auto i0 = imin - 1;
	auto i1 = imin;
	auto i2 = imin + 1;
	for (; i1 <= imax; ++i0, ++i1, ++i2)
	{
		// Compute the Givens rotation G and save it for use in computing
		// V in U^T*A*V = S.
		GetSinCos(x, y, cs, sn);
		mRGivens.push_back(GivensRotation(i1, i2, cs, sn));

		// Update B0 = B*G.
		if (i1 > imin)
		{
			mSuperdiagonal[i0] = cs * mSuperdiagonal[i0] - sn * a02;
		}

		a11 = mDiagonal[i1];
		a12 = mSuperdiagonal[i1];
		a22 = mDiagonal[i2];
		mDiagonal[i1] = cs * a11 - sn * a12;
		mSuperdiagonal[i1] = sn * a11 + cs * a12;
		mDiagonal[i2] = cs * a22;
		a21 = -sn * a22;

		// Update the parameters for the next Givens rotations.
		x = mDiagonal[i1];
		y = a21;

		// Compute the Givens rotation G and save it for use in computing
		// U in U^T*A*V = S.
		GetSinCos(x, y, cs, sn);
		mLGivens.push_back(GivensRotation(i1, i2, cs, sn));

		// Update B1 = G^T*B0.
		a11 = mDiagonal[i1];
		a12 = mSuperdiagonal[i1];
		a22 = mDiagonal[i2];
		mDiagonal[i1] = cs * a11 - sn * a21;
		mSuperdiagonal[i1] = cs * a12 - sn * a22;
		mDiagonal[i2] = sn * a12 + cs * a22;

		if (i1 < imax)
		{
			a23 = mSuperdiagonal[i2];
			a02 = -sn * a23;
			mSuperdiagonal[i2] = cs * a23;

			// Update the parameters for the next Givens rotations.
			x = mSuperdiagonal[i1];
			y = a02;
		}
	}
}
 
template <typename Real>
void Mathematics::SingularValueDecompositionGTE<Real>
	::EnsureNonnegativeDiagonal()
{
	for (auto i = 0; i < mNumCols; ++i)
	{
		if (mDiagonal[i] >= Math::GetValue(0))
		{
			mFixupDiagonal[i] = Math::GetValue(1);
		}
		else
		{
			mDiagonal[i] = -mDiagonal[i];
			mFixupDiagonal[i] = Math::GetValue(-1);
		}
	}
}
 
template <typename Real>
void Mathematics::SingularValueDecompositionGTE<Real>
	::ComputePermutation(int sortType)
{
	if (sortType == 0)
	{
		// Set a flag for GetSingularValues() and GetOrthogonalMatrices() to
		// know that sorted output was not requested.
		mPermutation[0] = -1;
		return;
	}

	// Compute the permutation induced by sorting.  Initially, we start with
	// the identity permutation I = (0,1,...,N-1).
	std::vector<SortItem> items(mNumCols);
 
	for (auto i = 0; i < mNumCols; ++i)
	{
		items[i].singularValue = mDiagonal[i];
		items[i].index = i;
	}

	if (sortType > 0)
	{
		std::sort(items.begin(), items.end(), std::less<SortItem>());
	}
	else
	{
		std::sort(items.begin(), items.end(), std::greater<SortItem>());
	}

	auto item = items.begin();
	for (auto i = 0; item != items.end(); ++item, ++i)
	{
		mPermutation[i] = item->index;
	}

	// GetOrthogonalMatrices() has nontrivial code for computing the
	// orthogonal U and V from the reflections and rotations.  To avoid
	// complicating the code further when sorting is requested, U and V are
	// computed as in the unsorted case.  We then need to swap columns of
	// U and V to be consistent with the sorting of the singular values.  To
	// minimize copying due to column swaps, we use permutation P.  The
	// minimum number of transpositions to obtain P from I is N minus the
	// number of cycles of P.  Each cycle is reordered with a minimum number
	// of transpositions; that is, the singular items are cyclically swapped,
	// leading to a minimum amount of copying.  For example, if there is a
	// cycle i0 -> i1 -> i2 -> i3, then the copying is
	//   save = singularitem[i0];
	//   singularitem[i1] = singularitem[i2];
	//   singularitem[i2] = singularitem[i3];
	//   singularitem[i3] = save;
}

template <typename Real>
Mathematics::SingularValueDecompositionGTE<Real>::GivensRotation
	::GivensRotation()
{
	// No default initialization for fast creation of std::vector of objects
	// of this type.
}
 
template <typename Real>
Mathematics::SingularValueDecompositionGTE<Real>::GivensRotation
	::GivensRotation(int inIndex0, int inIndex1, Real inCs, Real inSn)
	:index0(inIndex0),index1(inIndex1),cs(inCs),sn(inSn)
{
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_SINGULAR_VALUE_DECOMPOSITION_GTE_DETAIL_H
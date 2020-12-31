// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 10:23)

#ifndef MATHEMATICS_INTERPOLATION_INTP_TRILINEAR3_DETAIL_H
#define MATHEMATICS_INTERPOLATION_INTP_TRILINEAR3_DETAIL_H

#include "IntpTrilinear3.h"

namespace Mathematics
{
	template <typename Real>
	IntpTrilinear3<Real>::IntpTrilinear3(int xBound, int yBound, int zBound,Real xMin, Real xSpacing, Real yMin, Real ySpacing, Real zMin,Real zSpacing, Real*** F)
	{
		// At least a 2x2x2 block of data points are needed to construct the
		// trilinear interpolation.
		MATHEMATICS_ASSERTION_0(xBound >= 2 && yBound >= 2 && zBound >= 2 && F,"Invalid input\n");
		MATHEMATICS_ASSERTION_0(xSpacing > Math<Real>::GetValue(0) && ySpacing > Math<Real>::GetValue(0) && zSpacing > Math<Real>::GetValue(0),"Invalid input\n");

		mXBound = xBound;
		mYBound = yBound;
		mZBound = zBound;
		m_Quantity = xBound * yBound*zBound;

		mXMin = xMin;
		mXSpacing = xSpacing;
		mInvXSpacing = (Math::GetValue(1)) / xSpacing;
		mXMax = xMin + xSpacing * (xBound - 1);

		mYMin = yMin;
		mYSpacing = ySpacing;
		mInvYSpacing = (Math::GetValue(1)) / ySpacing;
		mYMax = yMin + ySpacing * (yBound - 1);

		mZMin = zMin;
		mZSpacing = zSpacing;
		mInvZSpacing = (Math::GetValue(1)) / zSpacing;
		mZMax = yMin + zSpacing * (zBound - 1);

		mF = F;
	}

	template <typename Real>
	int IntpTrilinear3<Real>::GetXBound() const
	{
		return mXBound;
	}

	template <typename Real>
	int IntpTrilinear3<Real>::GetYBound() const
	{
		return mYBound;
	}

	template <typename Real>
	int IntpTrilinear3<Real>::GetZBound() const
	{
		return mZBound;
	}

	template <typename Real>
	int IntpTrilinear3<Real>::GetQuantity() const
	{
		return m_Quantity;
	}

	template <typename Real>
	Real*** IntpTrilinear3<Real>::GetF() const
	{
		return mF;
	}

	template <typename Real>
	Real IntpTrilinear3<Real>::GetXMin() const
	{
		return mXMin;
	}

	template <typename Real>
	Real IntpTrilinear3<Real>::GetXMax() const
	{
		return mXMax;
	}

	template <typename Real>
	Real IntpTrilinear3<Real>::GetXSpacing() const
	{
		return mXSpacing;
	}

	template <typename Real>
	Real IntpTrilinear3<Real>::GetYMin() const
	{
		return mYMin;
	}

	template <typename Real>
	Real IntpTrilinear3<Real>::GetYMax() const
	{
		return mYMax;
	}

	template <typename Real>
	Real IntpTrilinear3<Real>::GetYSpacing() const
	{
		return mYSpacing;
	}

	template <typename Real>
	Real IntpTrilinear3<Real>::GetZMin() const
	{
		return mZMin;
	}

	template <typename Real>
	Real IntpTrilinear3<Real>::GetZMax() const
	{
		return mZMax;
	}

	template <typename Real>
	Real IntpTrilinear3<Real>::GetZSpacing() const
	{
		return mZSpacing;
	}

	template <typename Real>
	Real IntpTrilinear3<Real>::operator() (Real x, Real y, Real z) const
	{
		// Check for inputs not in the domain of the function.
		if (x < mXMin || x > mXMax
			|| y < mYMin || y > mYMax
			|| z < mZMin || y > mZMax)
		{
			return Math<Real>::sm_MaxReal;
		}

		// Compute x-index and clamp to image.
		Real xIndex = (x - mXMin)*mInvXSpacing;
		int ix = (int)xIndex;
		if (ix < 0)
		{
			ix = 0;
		}
		else if (ix >= mXBound)
		{
			ix = mXBound - 1;
		}

		// Compute y-index and clamp to image.
		Real yIndex = (y - mYMin)*mInvYSpacing;
		int iy = (int)yIndex;
		if (iy < 0)
		{
			iy = 0;
		}
		else if (iy >= mYBound)
		{
			iy = mYBound - 1;
		}

		// Compute z-index and clamp to image.
		Real zIndex = (z - mZMin)*mInvZSpacing;
		int iz = (int)zIndex;
		if (iz < 0)
		{
			iz = 0;
		}
		else if (iz >= mZBound)
		{
			iz = mZBound - 1;
		}

		Real U[2];
		U[0] = Math::GetValue(1);
		U[1] = xIndex - ix;

		Real V[2];
		V[0] = Math::GetValue(1);
		V[1] = yIndex - iy;

		Real W[2];
		W[0] = Math::GetValue(1);
		W[1] = zIndex - iz;

		// Compute P = M*U, Q = M*V, Real = M*W.
		Real P[2], Q[2], r[2];
		int row, col;
		for (row = 0; row < 2; ++row)
		{
			P[row] = Math<Real>::GetValue(0);
			Q[row] = Math<Real>::GetValue(0);
			r[row] = Math<Real>::GetValue(0);
			for (col = 0; col < 2; ++col)
			{
				P[row] += msBlend[row][col] * U[col];
				Q[row] += msBlend[row][col] * V[col];
				r[row] += msBlend[row][col] * W[col];
			}
		}

		// compute the tensor product (M*U)(M*V)(M*W)*D where D is the 2x2x2
		// subimage containing (x,y,z)
		Real result = Math<Real>::GetValue(0);
		for (int slice = 0; slice < 2; ++slice)
		{
			int zClamp = iz + slice;
			if (zClamp >= mZBound)
			{
				zClamp = mZBound - 1;
			}

			for (row = 0; row < 2; ++row)
			{
				int yClamp = iy + row;
				if (yClamp >= mYBound)
				{
					yClamp = mYBound - 1;
				}

				for (col = 0; col < 2; ++col)
				{
					int xClamp = ix + col;
					if (xClamp >= mXBound)
					{
						xClamp = mXBound - 1;
					}

					result += P[col] * Q[row] * Real[slice] * mF[zClamp][yClamp][xClamp];
				}
			}
		}

		return result;
	}

	template <typename Real>
	Real IntpTrilinear3<Real>::operator() (int xOrder, int yOrder, int zOrder,Real x, Real y, Real z) const
	{
		// Check for inputs not in the domain of the function.
		if (x < mXMin || x > mXMax
			|| y < mYMin || y > mYMax
			|| z < mZMin || y > mZMax)
		{
			return Math<Real>::sm_MaxReal;
		}

		// Compute x-index and clamp to image.
		Real xIndex = (x - mXMin)*mInvXSpacing;
		int ix = (int)xIndex;
		if (ix < 0)
		{
			ix = 0;
		}
		else if (ix >= mXBound)
		{
			ix = mXBound - 1;
		}

		// Compute y-index and clamp to image.
		Real yIndex = (y - mYMin)*mInvYSpacing;
		int iy = (int)yIndex;
		if (iy < 0)
		{
			iy = 0;
		}
		else if (iy >= mYBound)
		{
			iy = mYBound - 1;
		}

		// Compute z-index and clamp to image.
		Real zIndex = (z - mZMin)*mInvZSpacing;
		int iz = (int)zIndex;
		if (iz < 0)
		{
			iz = 0;
		}
		else if (iz >= mZBound)
		{
			iz = mZBound - 1;
		}

		Real U[2], dx, xMult;
		switch (xOrder)
		{
		case 0:
			dx = xIndex - ix;
			U[0] = Math::GetValue(1);
			U[1] = dx;
			xMult = Math::GetValue(1);
			break;
		case 1:
			dx = xIndex - ix;
			U[0] = Math<Real>::GetValue(0);
			U[1] = Math::GetValue(1);
			xMult = mInvXSpacing;
			break;
		default:
			return Math<Real>::GetValue(0);
		}

		Real V[2], dy, yMult;
		switch (yOrder)
		{
		case 0:
			dy = yIndex - iy;
			V[0] = Math::GetValue(1);
			V[1] = dy;
			yMult = Math::GetValue(1);
			break;
		case 1:
			dy = yIndex - iy;
			V[0] = Math<Real>::GetValue(0);
			V[1] = Math::GetValue(1);
			yMult = mInvYSpacing;
			break;
		default:
			return Math<Real>::GetValue(0);
		}

		Real W[2], dz, zMult;
		switch (zOrder)
		{
		case 0:
			dz = zIndex - iz;
			W[0] = Math::GetValue(1);
			W[1] = dz;
			zMult = Math::GetValue(1);
			break;
		case 1:
			dz = zIndex - iz;
			W[0] = Math<Real>::GetValue(0);
			W[1] = Math::GetValue(1);
			zMult = mInvZSpacing;
			break;
		default:
			return Math<Real>::GetValue(0);
		}

		// Compute P = M*U, Q = M*V, and Real = M*W.
		Real P[2], Q[2], r[2];
		int row, col;
		for (row = 0; row < 2; ++row)
		{
			P[row] = Math<Real>::GetValue(0);
			Q[row] = Math<Real>::GetValue(0);
			r[row] = Math<Real>::GetValue(0);
			for (col = 0; col < 2; ++col)
			{
				P[row] += msBlend[row][col] * U[col];
				Q[row] += msBlend[row][col] * V[col];
				r[row] += msBlend[row][col] * W[col];
			}
		}

		// Compute the tensor product (M*U)(M*V)(M*W)*D where D is the 2x2x2
		// subimage containing (x,y,z).
		Real result = Math<Real>::GetValue(0);
		for (int slice = 0; slice < 2; ++slice)
		{
			int zClamp = iz + slice;
			if (zClamp >= mZBound)
			{
				zClamp = mZBound - 1;
			}

			for (row = 0; row < 2; ++row)
			{
				int yClamp = iy + row;
				if (yClamp >= mYBound)
				{
					yClamp = mYBound - 1;
				}

				for (col = 0; col < 2; ++col)
				{
					int xClamp = ix + col;
					if (xClamp >= mXBound)
					{
						xClamp = mXBound - 1;
					}

					result += P[col] * Q[row] * Real[slice] * mF[zClamp][yClamp][xClamp];
				}
			}
		}
		result *= xMult * yMult*zMult;

		return result;
	}



	// Explicit instantiation.

	template <typename Real>
	const Real IntpTrilinear3<Real>::msBlend[2][2] =
	{
		{ 1.0f, -1.0f },
		{ 0.0f,  1.0f }
	};





}


#endif // MATHEMATICS_INTERPOLATION_INTP_TRILINEAR3_DETAIL_H
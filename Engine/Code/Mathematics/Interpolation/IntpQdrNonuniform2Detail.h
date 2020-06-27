// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 10:21)

#ifndef MATHEMATICS_INTERPOLATION_INTP_QUADRATIC_NONUNIFORM2_DETAIL_H
#define MATHEMATICS_INTERPOLATION_INTP_QUADRATIC_NONUNIFORM2_DETAIL_H

#include "IntpQdrNonuniform2.h"
#include "Mathematics/Containment/ScribeCircle2Inscribe.h"

namespace Mathematics
{

	template <typename Real>
	IntpQdrNonuniform2<Real>::IntpQdrNonuniform2(const Delaunay2<Real>& DT,	Real* F, Real* FX, Real* FY, bool owner)
		:mDT(&DT),mF(F),mFX(FX),mFY(FY),mFOwner(owner),mFXFYOwner(owner)
	{
		ProcessTriangles();
	}

	template <typename Real>
	IntpQdrNonuniform2<Real>::IntpQdrNonuniform2(const Delaunay2<Real>& DT,Real* F, bool owner)
		:mDT(&DT),mF(F),mFOwner(owner),	mFXFYOwner(true)
	{
		EstimateDerivatives();
		ProcessTriangles();
	}

	template <typename Real>
	IntpQdrNonuniform2<Real>::~IntpQdrNonuniform2()
	{
		if (mFOwner)
		{
			DELETE1(mF);
		}

		if (mFXFYOwner)
		{
			DELETE1(mFX);
			DELETE1(mFY);
		}

		DELETE1(mTData);
	}

	template <typename Real>
	void IntpQdrNonuniform2<Real>::EstimateDerivatives()
	{
		int numVertices = mDT->GetNumVertices();
		const Vector2D<Real>* vertices = mDT->GetVertices();
		int numTriangles = mDT->GetNumSimplices();
		const int* indices = mDT->GetIndices();

		mFX = NEW1<Real>(numVertices);
		mFY = NEW1<Real>(numVertices);
		Real* FZ = NEW1<Real>(numVertices);
		memset(mFX, 0, numVertices * sizeof(Real));
		memset(mFY, 0, numVertices * sizeof(Real));
		memset(FZ, 0, numVertices * sizeof(Real));

		// Accumulate normals at spatial locations (averaging process).
		int i;
		for (i = 0; i < numTriangles; ++i)
		{
			// Get three vertices of triangle.
			int v0 = *indices++;
			int v1 = *indices++;
			int v2 = *indices++;

			// Compute normal vector of triangle (with positive z-component).
			Real dx1 = vertices[v1].GetXCoordinate() - vertices[v0].GetXCoordinate();
			Real dy1 = vertices[v1].GetYCoordinate() - vertices[v0].GetYCoordinate();
			Real dz1 = mF[v1] - mF[v0];
			Real dx2 = vertices[v2].GetXCoordinate() - vertices[v0].GetXCoordinate();
			Real dy2 = vertices[v2].GetYCoordinate() - vertices[v0].GetYCoordinate();
			Real dz2 = mF[v2] - mF[v0];
			Real nx = dy1 * dz2 - dy2 * dz1;
			Real ny = dz1 * dx2 - dz2 * dx1;
			Real nz = dx1 * dy2 - dx2 * dy1;
			if (nz < Math<Real>::sm_Zero)
			{
				nx = -nx;
				ny = -ny;
				nz = -nz;
			}

			mFX[v0] += nx;  mFY[v0] += ny;  FZ[v0] += nz;
			mFX[v1] += nx;  mFY[v1] += ny;  FZ[v1] += nz;
			mFX[v2] += nx;  mFY[v2] += ny;  FZ[v2] += nz;
		}

		// Scale the normals to form (x,y,-1).
		for (i = 0; i < numVertices; ++i)
		{
			if (Math<Real>::FAbs(FZ[i]) > Math<Real>::sm_ZeroTolerance)
			{
				Real inv = -(static_cast<Real>(1)) / FZ[i];
				mFX[i] *= inv;
				mFY[i] *= inv;
			}
			else
			{
				mFX[i] = Math<Real>::sm_Zero;
				mFY[i] = Math<Real>::sm_Zero;
			}
		}

		DELETE1(FZ);
	}

	template <typename Real>
	void IntpQdrNonuniform2<Real>::ProcessTriangles()
	{
		// Add degenerate triangles to boundary triangles so that interpolation
		// at the boundary can be treated in the same way as interpolation in
		// the interior.

		// Compute centers of inscribed circles for triangles.
		const Vector2D<Real>* vertices = mDT->GetVertices();
		int numTriangles = mDT->GetNumSimplices();
		const int* indices = mDT->GetIndices();
		mTData = NEW1<TriangleData>(numTriangles);
		int i;
		for (i = 0; i < numTriangles; ++i)
		{
			int v0 = *indices++;
			int v1 = *indices++;
			int v2 = *indices++;
			ScribeCircle2Inscribe<Real> inscribe(vertices[v0], vertices[v1], vertices[v2]);
			Circle2<Real> circle = inscribe.GetCircle2();
			mTData[i].Center = circle.GetCenter();
		}

		// Compute cross-edge intersections.
		for (i = 0; i < numTriangles; ++i)
		{
			ComputeCrossEdgeIntersections(i);
		}

		// Compute Bezier coefficients.
		for (i = 0; i < numTriangles; ++i)
		{
			ComputeCoefficients(i);
		}
	}

	template <typename Real>
	void IntpQdrNonuniform2<Real>::ComputeCrossEdgeIntersections(int i)
	{
		// Get the vertices of triangle i.
		Vector2D<Real> V[3];
		mDT->GetVertexSet(i, V);

		// Fet centers of adjacent triangles.
		int adjacent[3];
		mDT->GetAdjacentSet(i, adjacent);
		Vector2D<Real> U[3];
		for (int j = 0; j < 3; ++j)
		{
			int a = adjacent[j];
			if (a >= 0)
			{
				// Get center of adjacent triangle's circumscribing circle.
				U[j] = mTData[a].Center;
			}
			else
			{
				// No adjacent triangle, use center of edge.
				U[j] = (static_cast<Real>(0.5))*(V[(j + 2) % 3] + V[(j + 1) % 3]);
			}
		}

		Real m00, m01, m10, m11, r0, r1, invDet;

		// intersection on edge <V0,V1>
		m00 = V[0].GetYCoordinate() - V[1].GetYCoordinate();
		m01 = V[1].GetXCoordinate() - V[0].GetXCoordinate();
		m10 = mTData[i].Center.GetYCoordinate() - U[0].GetYCoordinate();
		m11 = U[0].GetXCoordinate() - mTData[i].Center.GetXCoordinate();
		r0 = m00 * V[0].GetXCoordinate() + m01 * V[0].GetYCoordinate();
		r1 = m10 * mTData[i].Center.GetXCoordinate() + m11 * mTData[i].Center.GetYCoordinate();
		invDet = (static_cast<Real>(1)) / (m00*m11 - m01 * m10);
		mTData[i].Intersect[0][0] = (m11*r0 - m01 * r1)*invDet;
		mTData[i].Intersect[0][1] = (m00*r1 - m10 * r0)*invDet;

		// intersection on edge <V1,V2>
		m00 = V[1].GetYCoordinate() - V[2].GetYCoordinate();
		m01 = V[2].GetXCoordinate() - V[1].GetXCoordinate();
		m10 = mTData[i].Center.GetYCoordinate() - U[1].GetYCoordinate();
		m11 = U[1].GetXCoordinate() - mTData[i].Center.GetXCoordinate();
		r0 = m00 * V[1].GetXCoordinate() + m01 * V[1].GetYCoordinate();
		r1 = m10 * mTData[i].Center.GetXCoordinate() + m11 * mTData[i].Center.GetYCoordinate();
		invDet = (static_cast<Real>(1)) / (m00*m11 - m01 * m10);
		mTData[i].Intersect[1][0] = (m11*r0 - m01 * r1)*invDet;
		mTData[i].Intersect[1][1] = (m00*r1 - m10 * r0)*invDet;

		// intersection on edge <V0,V2>
		m00 = V[0].GetYCoordinate() - V[2].GetYCoordinate();
		m01 = V[2].GetXCoordinate() - V[0].GetXCoordinate();
		m10 = mTData[i].Center.GetYCoordinate() - U[2].GetYCoordinate();
		m11 = U[2].GetXCoordinate() - mTData[i].Center.GetXCoordinate();
		r0 = m00 * V[0].GetXCoordinate() + m01 * V[0].GetYCoordinate();
		r1 = m10 * mTData[i].Center.GetXCoordinate() + m11 * mTData[i].Center.GetYCoordinate();
		invDet = (static_cast<Real>(1)) / (m00*m11 - m01 * m10);
		mTData[i].Intersect[2][0] = (m11*r0 - m01 * r1)*invDet;
		mTData[i].Intersect[2][1] = (m00*r1 - m10 * r0)*invDet;
	}

	template <typename Real>
	void IntpQdrNonuniform2<Real>::ComputeCoefficients(int i)
	{
		// Get the vertices of triangle i.
		Vector2D<Real> V[3];
		mDT->GetVertexSet(i, V);

		// Get the vertex indices of triangle i.
		int invDet[3];
		mDT->GetIndexSet(i, invDet);

		// Get the additional information for triangle i.
		TriangleData& tData = mTData[i];

		// get the sample data at main triangle vertices
		Jet jet[3];
		int j;
		for (j = 0; j < 3; ++j)
		{
			int k = invDet[j];
			jet[j].F = mF[k];
			jet[j].FX = mFX[k];
			jet[j].FY = mFY[k];
		}

		// Get centers of adjacent triangles.
		int adjacent[3];
		mDT->GetAdjacentSet(i, adjacent);
		Vector2D<Real> U[3];
		for (j = 0; j < 3; ++j)
		{
			int a = adjacent[j];
			if (a >= 0)
			{
				// Get center of adjacent triangle's circumscribing circle.
				U[j] = mTData[a].Center;
			}
			else
			{
				// No adjacent triangle, use center of edge.
				U[j] = (static_cast<Real>(0.5))*(V[(j + 2) % 3] + V[(j + 1) % 3]);
			}
		}

		// Compute intermediate terms.
		Real cenT[3], cen0[3], cen1[3], cen2[3];
		mDT->GetBarycentricSet(i, tData.Center, cenT);
		mDT->GetBarycentricSet(i, U[0], cen0);
		mDT->GetBarycentricSet(i, U[1], cen1);
		mDT->GetBarycentricSet(i, U[2], cen2);

		Real alpha = (cenT[1] * cen1[0] - cenT[0] * cen1[1]) / (cen1[0] - cenT[0]);
		Real beta = (cenT[2] * cen2[1] - cenT[1] * cen2[2]) / (cen2[1] - cenT[1]);
		Real gamma = (cenT[0] * cen0[2] - cenT[2] * cen0[0]) / (cen0[2] - cenT[2]);
		Real oneMinusAlpha = static_cast<Real>(1) - alpha;
		Real oneMinusBeta = static_cast<Real>(1) - beta;
		Real oneMinusGamma = static_cast<Real>(1) - gamma;

		Real tmp, A[9], B[9];

		tmp = cenT[0] * V[0].GetXCoordinate() + cenT[1] * V[1].GetXCoordinate() + cenT[2] * V[2].GetXCoordinate();
		A[0] = (static_cast<Real>(0.5))*(tmp - V[0].GetXCoordinate());
		A[1] = (static_cast<Real>(0.5))*(tmp - V[1].GetXCoordinate());
		A[2] = (static_cast<Real>(0.5))*(tmp - V[2].GetXCoordinate());
		A[3] = (static_cast<Real>(0.5))*beta*(V[2].GetXCoordinate() - V[0].GetXCoordinate());
		A[4] = (static_cast<Real>(0.5))*oneMinusGamma*(V[1].GetXCoordinate() - V[0].GetXCoordinate());
		A[5] = (static_cast<Real>(0.5))*gamma*(V[0].GetXCoordinate() - V[1].GetXCoordinate());
		A[6] = (static_cast<Real>(0.5))*oneMinusAlpha*(V[2].GetXCoordinate() - V[1].GetXCoordinate());
		A[7] = (static_cast<Real>(0.5))*alpha*(V[1].GetXCoordinate() - V[2].GetXCoordinate());
		A[8] = (static_cast<Real>(0.5))*oneMinusBeta*(V[0].GetXCoordinate() - V[2].GetXCoordinate());

		tmp = cenT[0] * V[0].GetYCoordinate() + cenT[1] * V[1].GetYCoordinate() + cenT[2] * V[2].GetYCoordinate();
		B[0] = (static_cast<Real>(0.5))*(tmp - V[0].GetYCoordinate());
		B[1] = (static_cast<Real>(0.5))*(tmp - V[1].GetYCoordinate());
		B[2] = (static_cast<Real>(0.5))*(tmp - V[2].GetYCoordinate());
		B[3] = (static_cast<Real>(0.5))*beta*(V[2].GetYCoordinate() - V[0].GetYCoordinate());
		B[4] = (static_cast<Real>(0.5))*oneMinusGamma*(V[1].GetYCoordinate() - V[0].GetYCoordinate());
		B[5] = (static_cast<Real>(0.5))*gamma*(V[0].GetYCoordinate() - V[1].GetYCoordinate());
		B[6] = (static_cast<Real>(0.5))*oneMinusAlpha*(V[2].GetYCoordinate() - V[1].GetYCoordinate());
		B[7] = (static_cast<Real>(0.5))*alpha*(V[1].GetYCoordinate() - V[2].GetYCoordinate());
		B[8] = (static_cast<Real>(0.5))*oneMinusBeta*(V[0].GetYCoordinate() - V[2].GetYCoordinate());

		// Compute Bezier coefficients.
		tData.Coeff[2] = jet[0].F;
		tData.Coeff[4] = jet[1].F;
		tData.Coeff[6] = jet[2].F;

		tData.Coeff[14] = jet[0].F + A[0] * jet[0].FX + B[0] * jet[0].FY;
		tData.Coeff[7] = jet[0].F + A[3] * jet[0].FX + B[3] * jet[0].FY;
		tData.Coeff[8] = jet[0].F + A[4] * jet[0].FX + B[4] * jet[0].FY;
		tData.Coeff[16] = jet[1].F + A[1] * jet[1].FX + B[1] * jet[1].FY;
		tData.Coeff[9] = jet[1].F + A[5] * jet[1].FX + B[5] * jet[1].FY;
		tData.Coeff[10] = jet[1].F + A[6] * jet[1].FX + B[6] * jet[1].FY;
		tData.Coeff[18] = jet[2].F + A[2] * jet[2].FX + B[2] * jet[2].FY;
		tData.Coeff[11] = jet[2].F + A[7] * jet[2].FX + B[7] * jet[2].FY;
		tData.Coeff[12] = jet[2].F + A[8] * jet[2].FX + B[8] * jet[2].FY;

		tData.Coeff[5] = alpha * tData.Coeff[10] + oneMinusAlpha * tData.Coeff[11];
		tData.Coeff[17] = alpha * tData.Coeff[16] + oneMinusAlpha * tData.Coeff[18];
		tData.Coeff[1] = beta * tData.Coeff[12] + oneMinusBeta * tData.Coeff[7];
		tData.Coeff[13] = beta * tData.Coeff[18] + oneMinusBeta * tData.Coeff[14];
		tData.Coeff[3] = gamma * tData.Coeff[8] + oneMinusGamma * tData.Coeff[9];
		tData.Coeff[15] = gamma * tData.Coeff[14] + oneMinusGamma * tData.Coeff[16];
		tData.Coeff[0] = cenT[0] * tData.Coeff[14] + cenT[1] * tData.Coeff[16] + cenT[2] * tData.Coeff[18];
	}

	template <typename Real>
	bool IntpQdrNonuniform2<Real>::Evaluate(const Vector2D<Real>& P, Real& F,Real& FX, Real& FY)
	{
		int i = mDT->GetContainingTriangle(P);
		if (i == -1)
		{
			return false;
		}

		// Get triangle information.
		Vector2D<Real> V[3];
		mDT->GetVertexSet(i, V);
		int invDet[3];
		mDT->GetIndexSet(i, invDet);
		TriangleData& tData = mTData[i];

		// Determine which of the six subtriangles contains the target point.
		Vector2D<Real> sub0 = tData.Center;
		Vector2D<Real> sub1;
		Vector2D<Real> sub2 = tData.Intersect[2];
		Real bary[3];
		int index;
		for (index = 1; index <= 6; ++index)
		{
			sub1 = sub2;
			if (index % 2)
			{
				sub2 = V[index / 2];
			}
			else
			{
				sub2 = tData.Intersect[index / 2 - 1];
			}

			BarycentricCoordinates<Real, 3> barycentricCoordinates =P.GetBarycentrics(sub0, sub1, sub2);
			bary[0] = barycentricCoordinates[0];
			bary[1] = barycentricCoordinates[1];
			bary[2] = barycentricCoordinates[2];
			if (bary[0] >= Math<Real>::sm_Zero && bary[1] >= Math<Real>::sm_Zero && bary[2] >= Math<Real>::sm_Zero)
			{
				// P is in triangle <Sub0,Sub1,Sub2>
				break;
			}
		}

		// This should not happen theoretically, but it can happen due to
		// numerical round-off errors.  Just in case, select an index and go
		// with it.  Probably better is to keep track of the dot products in
		// InTriangle and find the one closest to zero and use a triangle that
		// contains the edge as the one that contains the input point.
		MATHEMATICS_ASSERTION_0(index <= 6, "Unexpected condition\n");
		if (index > 6)
		{
			// Use this index because bary[] was computed last for it.
			index = 5;
		}

		// Fetch Bezier control points.
		Real bez[6] =
		{
			tData.Coeff[0],
			tData.Coeff[12 + index],
			tData.Coeff[13 + (index % 6)],
			tData.Coeff[index],
			tData.Coeff[6 + index],
			tData.Coeff[1 + (index % 6)]
		};

		// Evaluate Bezier quadratic.
		F = bary[0] * (bez[0] * bary[0] + bez[1] * bary[1] + bez[2] * bary[2]) +
			bary[1] * (bez[1] * bary[0] + bez[3] * bary[1] + bez[4] * bary[2]) +
			bary[2] * (bez[2] * bary[0] + bez[4] * bary[1] + bez[5] * bary[2]);

		// Evaluate barycentric derivatives of F.
		Real FU = (static_cast<Real>(2.0))*(bez[0] * bary[0] + bez[1] * bary[1] +bez[2] * bary[2]);
		Real FV = (static_cast<Real>(2.0))*(bez[1] * bary[0] + bez[3] * bary[1] +bez[4] * bary[2]);
		Real FW = (static_cast<Real>(2.0))*(bez[2] * bary[0] + bez[4] * bary[1] +bez[5] * bary[2]);
		Real duw = FU - FW;
		Real dvw = FV - FW;

		// Convert back to (x,y) coordinates.
		Real m00 = sub0.GetXCoordinate() - sub2.GetXCoordinate();
		Real m10 = sub0.GetYCoordinate() - sub2.GetYCoordinate();
		Real m01 = sub1.GetXCoordinate() - sub2.GetXCoordinate();
		Real m11 = sub1.GetYCoordinate() - sub2.GetYCoordinate();
		Real inv = (static_cast<Real>(1)) / (m00*m11 - m10 * m01);

		FX = inv * (m11*duw - m10 * dvw);
		FY = inv * (m00*dvw - m01 * duw);

		return true;
	}
}

#endif // MATHEMATICS_INTERPOLATION_INTP_QUADRATIC_NONUNIFORM2_DETAIL_H
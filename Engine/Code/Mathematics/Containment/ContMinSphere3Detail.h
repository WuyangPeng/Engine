// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 17:11)

#ifndef MATHEMATICS_CONTAINMENT_CONT_MIN_SPHERE3_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_MIN_SPHERE3_DETAIL_H

#include "ContMinSphere3.h"
#include "Mathematics/Algebra/Matrix3.h"
#include "CoreTools/Helper/MemoryMacro.h"

// All internal minimal sphere calculations store the squared radius in the
// radius member of Sphere3<Real>.  Only at the end is a sqrt computed.
template <typename Real>
Mathematics::MinSphere3<Real>
	::MinSphere3(int numPoints, const Vector3D<Real>* points, Sphere3<Real>& minimal, Real epsilon)
	: mEpsilon{ epsilon }
{
    mUpdate[0] = 0;
    mUpdate[1] = &MinSphere3<Real>::UpdateSupport1;
    mUpdate[2] = &MinSphere3<Real>::UpdateSupport2;
    mUpdate[3] = &MinSphere3<Real>::UpdateSupport3;
    mUpdate[4] = &MinSphere3<Real>::UpdateSupport4;

    Support support;
    Real distDiff;

    if (numPoints >= 1)
    {
        // Create identity permutation (0,1,...,numPoints-1).
        Vector3D<Real>** permuted = NEW1<Vector3D<Real>*>(numPoints);
        int i;
        for (i = 0; i < numPoints; ++i)
        {
            permuted[i] = (Vector3D<Real>*)&points[i];
        }

        // Generate random permutation.
        for (i = numPoints - 1; i > 0; --i)
        {
            int j = rand() % (i+1);
            if (j != i)
            {
                Vector3D<Real>* save = permuted[i];
                permuted[i] = permuted[j];
                permuted[j] = save;
            }
        }

        minimal = ExactSphere1(*permuted[0]);
        support.Quantity = 1;
        support.Index[0] = 0;

        // The previous version of the processing loop is
        //  i = 1;
        //  while (i < numPoints)
        //  {
        //      if (!support.Contains(i, permuted, mEpsilon))
        //      {
        //          if (!Contains(*permuted[i], minimal, distDiff))
        //          {
        //              UpdateFunction update = mUpdate[support.Quantity];
        //              Sphere3<Real> sphere =(this->*update)(i, permuted,
        //                  support);
        //              if (sphere.Radius > minimal.Radius)
        //              {
        //                  minimal = sphere;
        //                  i = 0;
        //                  continue;
        //              }
        //          }
        //      }
        //      ++i;
        //  }
        // This loop restarts from the beginning of the point list each time
        // the sphere needs updating.  Linus K‰llberg (Computer Science at
        // M‰lardalen University in Sweden) discovered that performance is
        // better when the remaining points in the array are processed before
        // restarting.  The points processed before the point that caused the
        // update are likely to be enclosed by the new sphere (or near the
        // sphere boundary) because they were enclosed by the previous sphere.
        // The chances are better that points after the current one will cause
        // growth of the bounding sphere.
        for (int i = 1 % numPoints, n = 0; i != n; i = (i + 1) % numPoints)
        {
            if (!support.Contains(i, permuted, mEpsilon))
            {
                if (!Contains(*permuted[i], minimal, distDiff))
                {
                    UpdateFunction update = mUpdate[support.Quantity];
                    Sphere3<Real> sphere =(this->*update)(i, permuted,
                        support);
					if (sphere.GetRadius() > minimal.GetRadius())
                    {
                        minimal = sphere;
                        n = i;
                    }
                }
            }
        }

        DELETE1(permuted);
    }
    else
    {
        MATHEMATICS_ASSERTION_0(false, "Input must contain points\n");
    }

    minimal.SetSphere(minimal.GetCenter(),Math<Real>::Sqrt(minimal.GetRadius()));
}

template <typename Real>
bool Mathematics::MinSphere3<Real>
	::Contains(const Vector3D<Real>& point,const Sphere3<Real>& sphere, Real& distDiff)
{
	auto diff = point - sphere.GetCenter();
	auto test = Vector3DTools<Real>::VectorMagnitudeSquared(diff);

    // NOTE:  In this algorithm, Sphere3 is storing the *squared radius*,
    // so the next line of code is not in error.
    distDiff = test - sphere.GetRadius();

    return distDiff <= Math<Real>::sm_Zero;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::MinSphere3<Real>
	::ExactSphere1(const Vector3D<Real>& P)
{
	Sphere3<Real> minimal{ P, Math<Real>::sm_Zero };
    return minimal;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::MinSphere3<Real>
	::ExactSphere2(const Vector3D<Real>& P0, const Vector3D<Real>& P1)
{
	auto diff = P1 - P0;
	Sphere3<Real> minimal{ (Real{0.5})*(P0 + P1), Real{0.25}*Vector3DTools<Real>::VectorMagnitudeSquared(diff) };
  
    return minimal;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::MinSphere3<Real>
	::ExactSphere3(const Vector3D<Real>& P0,const Vector3D<Real>& P1, const Vector3D<Real>& P2)
{
    // Compute the circle (in 3D) containing p0, p1, and p2.  The Center in
    // barycentric coordinates is K = u0*p0+u1*p1+u2*p2 where u0+u1+u2=1.
    // The Center is equidistant from the three points, so |K-p0| = |K-p1| =
    // |K-p2| = Real where Real is the radius of the circle.
    //
    // From these conditions,
    //   K-p0 = u0*A + u1*B - A
    //   K-p1 = u0*A + u1*B - B
    //   K-p2 = u0*A + u1*B
    // where A = p0-p2 and B = p1-p2, which leads to
    //   r^2 = |u0*A+u1*B|^2 - 2*Dot(A,u0*A+u1*B) + |A|^2
    //   r^2 = |u0*A+u1*B|^2 - 2*Dot(B,u0*A+u1*B) + |B|^2
    //   r^2 = |u0*A+u1*B|^2
    // Subtracting the last equation from the first two and writing
    // the equations as a linear system,
    //
    // +-                 -++   -+       +-        -+
    // | Dot(A,A) Dot(A,B) || u0 | = 0.5 | Dot(A,A) |
    // | Dot(B,A) Dot(B,B) || u1 |       | Dot(B,B) |
    // +-                 -++   -+       +-        -+
    //
    // The following code solves this system for u0 and u1, then
    // evaluates the third equation in r^2 to obtain r.

	auto A = P0 - P2;
	auto B = P1 - P2;
	auto AdA = Vector3DTools<Real>::DotProduct(A, A);
	auto AdB = Vector3DTools<Real>::DotProduct(A,B);
	auto BdB = Vector3DTools<Real>::DotProduct(B,B);
	auto det = AdA*BdB - AdB*AdB;

	Vector3D<Real> center;
	Real  radius;
    if (Math<Real>::FAbs(det) > Math<Real>::sm_Zero)
    {
        Real m00, m01, m10, m11, d0, d1;
        if (AdA >= BdB)
        {
            m00 = static_cast<Real>(1);
            m01 = AdB/AdA;
            m10 = m01;
            m11 = BdB/AdA;
            d0 = Real{0.5};
            d1 = (Real{0.5})*m11;
        }
        else
        {
            m00 = AdA/BdB;
            m01 = AdB/BdB;
            m10 = m01;
            m11 = static_cast<Real>(1);
            d0 = (Real{0.5})*m00;
            d1 = Real{0.5};
        }
		auto invDet = (static_cast<Real>(1))/(m00*m11 - m01*m10);
		auto u0 = invDet*(m11*d0 - m01*d1);
		auto u1 = invDet*(m00*d1 - m10*d0);
		auto u2 = static_cast<Real>(1) - u0 - u1;
		center = u0*P0 + u1*P1 + u2*P2;
		auto tmp = u0*A + u1*B;
		radius = Vector3DTools<Real>::VectorMagnitudeSquared(tmp);
    }
    else
    {
		center = Vector3D<Real>::sm_Zero;
		radius = Math<Real>::sm_MaxReal;
    }
	Sphere3<Real> minimal{ center,radius };
    return minimal;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::MinSphere3<Real>
	::ExactSphere4(const Vector3D<Real>& P0, const Vector3D<Real>& P1, const Vector3D<Real>& P2, const Vector3D<Real>& P3)
{
    // Compute the sphere containing p0, p1, p2, and p3.  The Center in
    // barycentric coordinates is K = u0*p0+u1*p1+u2*p2+u3*p3 where
    // u0+u1+u2+u3=1.  The Center is equidistant from the three points, so
    // |K-p0| = |K-p1| = |K-p2| = |K-p3| = Real where Real is the radius of the
    // sphere.
    //
    // From these conditions,
    //   K-p0 = u0*A + u1*B + u2*C - A
    //   K-p1 = u0*A + u1*B + u2*C - B
    //   K-p2 = u0*A + u1*B + u2*C - C
    //   K-p3 = u0*A + u1*B + u2*C
    // where A = p0-p3, B = p1-p3, and C = p2-p3 which leads to
    //   r^2 = |u0*A+u1*B+u2*C|^2 - 2*Dot(A,u0*A+u1*B+u2*C) + |A|^2
    //   r^2 = |u0*A+u1*B+u2*C|^2 - 2*Dot(B,u0*A+u1*B+u2*C) + |B|^2
    //   r^2 = |u0*A+u1*B+u2*C|^2 - 2*Dot(C,u0*A+u1*B+u2*C) + |C|^2
    //   r^2 = |u0*A+u1*B+u2*C|^2
    // Subtracting the last equation from the first three and writing
    // the equations as a linear system,
    //
    // +-                          -++   -+       +-        -+
    // | Dot(A,A) Dot(A,B) Dot(A,C) || u0 | = 0.5 | Dot(A,A) |
    // | Dot(B,A) Dot(B,B) Dot(B,C) || u1 |       | Dot(B,B) |
    // | Dot(C,A) Dot(C,B) Dot(C,C) || u2 |       | Dot(C,C) |
    // +-                          -++   -+       +-        -+
    //
    // If M = [A B C] is the matrix whose columns are the vectors A, B, and C;
    // if D is the 3x1 column 0.5*(Dot(A,A),Dot(B,B),Dot(C,C)); and if U is
    // the 3x1 column (u0,u1,u2), then the system is M^T*M*U = D.  The system
    // is solved in two steps:  V = M*U = M^{-T}*D, U = M^{-1}*V.  After
    // solving the system, r^2 is computed from the fourth equation listed
    // previously.

	auto A = P0 - P3;
	auto B = P1 - P3;
	auto C = P2 - P3;
	Matrix3<Real> M(A, B, C, MatrixMajorFlags::Row);
	Vector3D<Real> D{ Vector3DTools<Real>::DotProduct(A,A),
					  Vector3DTools<Real>::DotProduct(B, B),
					  Vector3DTools<Real>::DotProduct(C, C) };
    D *= Real{0.5};

    // TODO:  With mEpsilon == 0.0, there are data sets for which this
    // algorithm fails.  A small positive mEpsilon appears to help, but
    // this is a classic problem of computational geometry--determining
    // the correct sign of a determinant when using floating-point
    // arithmetic.  One of the goals of the Malleable Mathematics
    // Library is to eliminate such problems (using arbitrary precision
    // arithmetic or a filtered predicate).
	auto invM = M.Inverse(mEpsilon);
	 
	Vector3D<Real>center;
	Real radius;
    if (invM != Matrix3<Real>::sm_Zero)
    {
		auto V = D*invM;
		auto U = invM*V;
		auto U3 = static_cast<Real>(1) - U[0] - U[1] - U[2];
		center = U[0] * P0 + U[1] * P1 + U[2] * P2 + U3*P3;
		auto tmp = U[0]*A + U[1]*B + U[2]*C;
		radius = Vector3DTools<Real>::VectorMagnitudeSquared(tmp);
    }
    else
    {
		center = Vector3D<Real>::sm_Zero;
		radius = Math<Real>::sm_MaxReal;
    }

	Sphere3<Real> minimal{ center, radius };
    return minimal;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::MinSphere3<Real>
	::UpdateSupport1(int i,Vector3D<Real>** permuted, Support& support)
{
    const auto& P0 = *permuted[support.Index[0]];
    const auto& P1 = *permuted[i];

	auto minimal = ExactSphere2(P0, P1);
    support.Quantity = 2;
    support.Index[1] = i;

    return minimal;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::MinSphere3<Real>
	::UpdateSupport2(int i, Vector3D<Real>** permuted, Support& support)
{
    const Vector3D<Real>* point[2]
    {
        permuted[support.Index[0]],  // P0
        permuted[support.Index[1]]   // P1
    };
    const auto& P2 = *permuted[i];

    // Permutations of type 2, used for calling ExactSphere2(...).
    constexpr auto numType2 = 2;
    const int type2[numType2][2]
    {
        {0, /*2*/ 1},
        {1, /*2*/ 0}
    };

    // Permutations of type 3, used for calling ExactSphere3(...).
    constexpr auto numType3 = 1;  // {0, 1, 2}

    Sphere3<Real> sphere[numType2 + numType3];
    int indexSphere = 0;
	auto minRSqr = Math<Real>::sm_MaxReal;
    int indexMinRSqr = -1;
	Real distDiff, minDistDiff = Math<Real>::sm_MaxReal;
    int indexMinDistDiff = -1;

    // Permutations of type 2.
    int j;
    for (j = 0; j < numType2; ++j, ++indexSphere)
    {
        sphere[indexSphere] = ExactSphere2(*point[type2[j][0]], P2);
        if (sphere[indexSphere].GetRadius() < minRSqr)
        {
            if (Contains(*point[type2[j][1]], sphere[indexSphere], distDiff))
            {
				minRSqr = sphere[indexSphere].GetRadius();
                indexMinRSqr = indexSphere;
            }
            else if (distDiff < minDistDiff)
            {
                minDistDiff = distDiff;
                indexMinDistDiff = indexSphere;
            }
        }
    }

    // Permutations of type 3.
    sphere[indexSphere] = ExactSphere3(*point[0], *point[1], P2);
	if (sphere[indexSphere].GetRadius() < minRSqr)
    {
		minRSqr = sphere[indexSphere].GetRadius();
        indexMinRSqr = indexSphere;
    }

    // Theoreticaly, indexMinRSqr >= 0, but floating-point round-off errors
    // can lead to indexMinRSqr == -1.  When this happens, the minimal sphere
    // is chosen to be the one that has the minimum absolute errors between
    // the sphere and points (barely) outside the sphere.
    if (indexMinRSqr == -1)
    {
        indexMinRSqr = indexMinDistDiff;
    }

	auto minimal = sphere[indexMinRSqr];
    switch (indexMinRSqr)
    {
    case 0:
        support.Index[1] = i;
        break;
    case 1:
        support.Index[0] = i;
        break;
    case 2:
        support.Quantity = 3;
        support.Index[2] = i;
        break;
    }

    return minimal;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::MinSphere3<Real>
	::UpdateSupport3(int i, Vector3D<Real>** permuted, Support& support)
{
    const Vector3D<Real>* point[3]
    {
        permuted[support.Index[0]],  // P0
        permuted[support.Index[1]],  // P1
        permuted[support.Index[2]]   // P2
    };
    const auto& P3 = *permuted[i];

    // Permutations of type 2, used for calling ExactSphere2(...).
    constexpr auto numType2 = 3;
    const int type2[numType2][3] 
    {
        {0, /*3*/ 1, 2},
        {1, /*3*/ 0, 2},
        {2, /*3*/ 0, 1}
    };

    // Permutations of type 3, used for calling ExactSphere3(...).
    constexpr auto numType3 = 3;
    const int type3[numType3][3] 
    {
        {0, 1, /*3*/ 2},
        {0, 2, /*3*/ 1},
        {1, 2, /*3*/ 0}
    };

    // Permutations of type 4, used for calling ExactSphere4(...).
    const int numType4 = 1;  // {0, 1, 2, 3}

    Sphere3<Real> sphere[numType2 + numType3 + numType4];
    int indexSphere = 0;
	auto minRSqr = Math<Real>::sm_MaxReal;
    int indexMinRSqr = -1;
	Real distDiff, minDistDiff = Math<Real>::sm_MaxReal;
    int indexMinDistDiff = -1;

    // Permutations of type 2.
    int j;
    for (j = 0; j < numType2; ++j, ++indexSphere)
    {
        sphere[indexSphere] = ExactSphere2(*point[type2[j][0]], P3);
		if (sphere[indexSphere].GetRadius()  < minRSqr)
        {
            if (Contains(*point[type2[j][1]], sphere[indexSphere], distDiff)  &&  Contains(*point[type2[j][2]], sphere[indexSphere], distDiff))
            {
				minRSqr = sphere[indexSphere].GetRadius();
                indexMinRSqr = indexSphere;
            }
            else if (distDiff < minDistDiff)
            {
                minDistDiff = distDiff;
                indexMinDistDiff = indexSphere;
            }
        }
    }

    // Permutations of type 3.
    for (j = 0; j < numType3; ++j, ++indexSphere)
    {
        sphere[indexSphere] = ExactSphere3(*point[type3[j][0]], *point[type3[j][1]], P3);
		if (sphere[indexSphere].GetRadius()  < minRSqr)
        {
            if (Contains(*point[type3[j][2]], sphere[indexSphere], distDiff))
            {
				minRSqr = sphere[indexSphere].GetRadius();
                indexMinRSqr = indexSphere;
            }
            else if (distDiff < minDistDiff)
            {
                minDistDiff = distDiff;
                indexMinDistDiff = indexSphere;
            }
        }
    }

    // Permutations of type 4.
    sphere[indexSphere] = ExactSphere4(*point[0], *point[1], *point[2], P3);
	if (sphere[indexSphere].GetRadius() < minRSqr)
    {
		minRSqr = sphere[indexSphere].GetRadius();
        indexMinRSqr = indexSphere;
    }

    // Theoreticaly, indexMinRSqr >= 0, but floating-point round-off errors
    // can lead to indexMinRSqr == -1.  When this happens, the minimal sphere
    // is chosen to be the one that has the minimum absolute errors between
    // the sphere and points (barely) outside the sphere.
    if (indexMinRSqr == -1)
    {
        indexMinRSqr = indexMinDistDiff;
    }

    Sphere3<Real> minimal = sphere[indexMinRSqr];
    switch (indexMinRSqr)
    {
    case 0:
        support.Quantity = 2;
        support.Index[1] = i;
        break;
    case 1:
        support.Quantity = 2;
        support.Index[0] = i;
        break;
    case 2:
        support.Quantity = 2;
        support.Index[0] = support.Index[2];
        support.Index[1] = i;
        break;
    case 3:
        support.Index[2] = i;
        break;
    case 4:
        support.Index[1] = i;
        break;
    case 5:
        support.Index[0] = i;
        break;
    case 6:
        support.Quantity = 4;
        support.Index[3] = i;
        break;
    }

    return minimal;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::MinSphere3<Real>
	::UpdateSupport4(int i, Vector3D<Real>** permuted, Support& support)
{
    const Vector3D<Real>* point[4]
    {
        permuted[support.Index[0]],  // P0
        permuted[support.Index[1]],  // P1
        permuted[support.Index[2]],  // P2
        permuted[support.Index[3]]   // P3
    };
    const Vector3D<Real>& P4 = *permuted[i];

    // Permutations of type 2, used for calling ExactSphere2(...).
    constexpr auto numType2 = 4;
    const int type2[numType2][4]
    {
        {0, /*4*/ 1, 2, 3},
        {1, /*4*/ 0, 2, 3},
        {2, /*4*/ 0, 1, 3},
        {3, /*4*/ 0, 1, 2}
    };

    // Permutations of type 3, used for calling ExactSphere3(...).
    constexpr auto numType3 = 6;
    const int type3[numType3][4] 
    {
        {0, 1, /*4*/ 2, 3},
        {0, 2, /*4*/ 1, 3},
        {0, 3, /*4*/ 1, 2},
        {1, 2, /*4*/ 0, 3},
        {1, 3, /*4*/ 0, 2},
        {2, 3, /*4*/ 0, 1}
    };

    // Permutations of type 4, used for calling ExactSphere4(...).
    constexpr auto numType4 = 4;
    const int type4[numType4][4] 
    {
        {0, 1, 2, /*4*/ 3},
        {0, 1, 3, /*4*/ 2},
        {0, 2, 3, /*4*/ 1},
        {1, 2, 3, /*4*/ 0}
    };

    Sphere3<Real> sphere[numType2 + numType3 + numType4];
    int indexSphere = 0;
	auto minRSqr = Math<Real>::sm_MaxReal;
    int indexMinRSqr = -1;
	Real distDiff, minDistDiff = Math<Real>::sm_MaxReal;
	auto indexMinDistDiff = -1;

    // Permutations of type 2.
    int j;
    for (j = 0; j < numType2; ++j, ++indexSphere)
    {
        sphere[indexSphere] = ExactSphere2(*point[type2[j][0]], P4);
		if (sphere[indexSphere].GetRadius() < minRSqr)
        {
            if (Contains(*point[type2[j][1]], sphere[indexSphere], distDiff) &&  Contains(*point[type2[j][2]], sphere[indexSphere], distDiff) &&  Contains(*point[type2[j][3]], sphere[indexSphere], distDiff))
            {
				minRSqr = sphere[indexSphere].GetRadius();
                indexMinRSqr = indexSphere;
            }
            else if (distDiff < minDistDiff)
            {
                minDistDiff = distDiff;
                indexMinDistDiff = indexSphere;
            }
        }
    }

    // Permutations of type 3.
    for (j = 0; j < numType3; ++j, ++indexSphere)
    {
        sphere[indexSphere] = ExactSphere3(*point[type3[j][0]],*point[type3[j][1]], P4);
		if (sphere[indexSphere].GetRadius() < minRSqr)
        {
            if (Contains(*point[type3[j][2]], sphere[indexSphere], distDiff) &&  Contains(*point[type3[j][3]], sphere[indexSphere], distDiff))
            {
				minRSqr = sphere[indexSphere].GetRadius();
                indexMinRSqr = indexSphere;
            }
            else if (distDiff < minDistDiff)
            {
                minDistDiff = distDiff;
                indexMinDistDiff = indexSphere;
            }
        }
    }

    // Permutations of type 4.
    for (j = 0; j < numType4; ++j, ++indexSphere)
    {
        sphere[indexSphere] = ExactSphere4(*point[type4[j][0]], *point[type4[j][1]], *point[type4[j][2]], P4);
		if (sphere[indexSphere].GetRadius() < minRSqr)
        {
            if (Contains(*point[type4[j][3]], sphere[indexSphere], distDiff))
            {
				minRSqr = sphere[indexSphere].GetRadius();
                indexMinRSqr = indexSphere;
            }
            else if (distDiff < minDistDiff)
            {
                minDistDiff = distDiff;
                indexMinDistDiff = indexSphere;
            }
        }
    }

    // Theoreticaly, indexMinRSqr >= 0, but floating-point round-off errors
    // can lead to indexMinRSqr == -1.  When this happens, the minimal sphere
    // is chosen to be the one that has the minimum absolute errors between
    // the sphere and points (barely) outside the sphere.
    if (indexMinRSqr == -1)
    {
        indexMinRSqr = indexMinDistDiff;
    }

	auto minimal = sphere[indexMinRSqr];
    switch (indexMinRSqr)
    {
    case 0:
        support.Quantity = 2;
        support.Index[1] = i;
        break;
    case 1:
        support.Quantity = 2;
        support.Index[0] = i;
        break;
    case 2:
        support.Quantity = 2;
        support.Index[0] = support.Index[2];
        support.Index[1] = i;
        break;
    case 3:
        support.Quantity = 2;
        support.Index[0] = support.Index[3];
        support.Index[1] = i;
        break;
    case 4:
        support.Quantity = 3;
        support.Index[2] = i;
        break;
    case 5:
        support.Quantity = 3;
        support.Index[1] = i;
        break;
    case 6:
        support.Quantity = 3;
        support.Index[1] = support.Index[3];
        support.Index[2] = i;
        break;
    case 7:
        support.Quantity = 3;
        support.Index[0] = i;
        break;
    case 8:
        support.Quantity = 3;
        support.Index[0] = support.Index[3];
        support.Index[2] = i;
        break;
    case 9:
        support.Quantity = 3;
        support.Index[0] = support.Index[3];
        support.Index[1] = i;
        break;
    case 10:
        support.Index[3] = i;
        break;
    case 11:
        support.Index[2] = i;
        break;
    case 12:
        support.Index[1] = i;
        break;
    case 13:
        support.Index[0] = i;
        break;
    }

    return minimal;
}

template <typename Real>
bool Mathematics::MinSphere3<Real>::Support
	::Contains(int index, Vector3D<Real>** points,Real epsilon)
{
    for (auto i = 0; i < Quantity; ++i)
    {
		auto diff = *points[index] - *points[Index[i]];
		if (Vector3DTools<Real>::VectorMagnitudeSquared(diff) < epsilon)
        {
            return true;
        }
    }
    return false;
}

#endif // MATHEMATICS_CONTAINMENT_CONT_MIN_SPHERE3_DETAIL_H
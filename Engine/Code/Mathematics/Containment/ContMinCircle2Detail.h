// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 17:08)

#ifndef MATHEMATICS_CONTAINMENT_CONT_MIN_CIRCLE2_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_MIN_CIRCLE2_DETAIL_H

#include "ContMinCircle2.h"
#include "CoreTools/Helper/MemoryMacro.h"

// All internal minimal circle calculations store the squared radius in the
// radius member of Circle2.  Only at the end is a sqrt computed.

template <typename Real>
Mathematics::MinCircle2<Real>
	::MinCircle2(int numPoints, const Vector2D<Real>* points, Circle2<Real>& minimal, Real epsilon)
	:mEpsilon{ epsilon }
{
    mUpdate[0] = 0;
    mUpdate[1] = &MinCircle2<Real>::UpdateSupport1;
    mUpdate[2] = &MinCircle2<Real>::UpdateSupport2;
    mUpdate[3] = &MinCircle2<Real>::UpdateSupport3;

    Support support;
    Real distDiff;

    if (numPoints >= 1)
    {
        // Create identity permutation (0,1,...,numPoints-1).
        Vector2D<Real>** permuted = NEW1<Vector2D<Real>*>(numPoints);
        int i;
        for (i = 0; i < numPoints; ++i)
        {
            permuted[i] = (Vector2D<Real>*)&points[i];
        }
        
        // Generate random permutation.
        for (i = numPoints - 1; i > 0; --i)
        {
            int j = rand() % (i+1);
            if (j != i)
            {
                Vector2D<Real>* save = permuted[i];
                permuted[i] = permuted[j];
                permuted[j] = save;
            }
        }
        
        minimal = ExactCircle1(*permuted[0]);
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
        //              Circle2<Real> circle = (this->*update)(i, permuted,
        //                  support);
        //              if (circle.Radius > minimal.Radius)
        //              {
        //                  minimal = circle;
        //                  i = 0;
        //                  continue;
        //              }
        //          }
        //      }
        //      ++i;
        //  }
        // This loop restarts from the beginning of the point list each time
        // the circle needs updating.  Linus K‰llberg (Computer Science at
        // M‰lardalen University in Sweden) discovered that performance is
        // better when the remaining points in the array are processed before
        // restarting.  The points processed before the point that caused the
        // update are likely to be enclosed by the new circle (or near the
        // circle boundary) because they were enclosed by the previous circle.
        // The chances are better that points after the current one will cause
        // growth of the bounding circle.
        for (int i = 1 % numPoints, n = 0; i != n; i = (i + 1) % numPoints)
        {
            if (!support.Contains(i, permuted, mEpsilon))
            {
                if (!Contains(*permuted[i], minimal, distDiff))
                {
                    UpdateFunction update = mUpdate[support.Quantity];
                    Circle2<Real> circle =(this->*update)(i, permuted,  support);
					if (circle.GetRadius() > minimal.GetRadius())
                    {
                        minimal = circle;
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

	minimal.SetCircle(minimal.GetCenter(),Math<Real>::Sqrt(minimal.GetRadius()));
}

template <typename Real>
bool Mathematics::MinCircle2<Real>
	::Contains(const Vector2D<Real>& point,  const Circle2<Real>& circle, Real& distDiff)
{
    auto diff = point - circle.GetCenter();
	auto test = Vector2DTools<Real>::VectorMagnitudeSquared(diff);

    // NOTE:  In this algorithm, Circle2 is storing the *squared radius*,
    // so the next line of code is not in error.
    distDiff = test - circle.GetRadius();

    return distDiff <= Math<Real>::GetValue(0);
}

template <typename Real>
Mathematics::Circle2<Real> Mathematics::MinCircle2<Real>
	::ExactCircle1(const Vector2D<Real>& P)
{
	Circle2<Real> minimal{ P, Math<Real>::GetValue(0) };
    return minimal;
}

template <typename Real>
Mathematics::Circle2<Real> Mathematics::MinCircle2<Real>
	::ExactCircle2(const Vector2D<Real>& P0, const Vector2D<Real>& P1)
{
	auto diff = P1 - P0;
	Circle2<Real> minimal{ (Real{0.5})*(P0 + P1), (Real{0.25})*Vector2DTools<Real>::VectorMagnitudeSquared(diff) };
  
    return minimal;
}

template <typename Real>
Mathematics::Circle2<Real> Mathematics::MinCircle2<Real>
	::ExactCircle3(const Vector2D<Real>& P0, const Vector2D<Real>& P1, const Vector2D<Real>& P2)
{
	auto E10 = P1 - P0;
	auto E20 = P2 - P0;

    Real A[2][2] { { E10.GetX(), E10.GetY() },
				   { E20.GetX(), E20.GetY() } };

    Real B[2] { (Real{0.5})*Vector2DTools<Real>::VectorMagnitudeSquared(E10),
				(Real{0.5})*Vector2DTools<Real>::VectorMagnitudeSquared(E20)  };

  
	auto det = A[0][0]*A[1][1] - A[0][1]*A[1][0];

	Vector2D<Real> center;
	Real radius;
    if (Math<Real>::FAbs(det) > mEpsilon)
    {
		auto invDet = (static_cast<Real>(1))/det;
        Vector2D<Real> Q;
		Q.SetX((A[1][1] * B[0] - A[0][1] * B[1])*invDet);
		Q.SetY((A[0][0] * B[1] - A[1][0] * B[0])*invDet);
		center = P0 + Q;
		radius = Vector2DTools<Real>::VectorMagnitudeSquared(Q);
    }
    else
    {
		center = Vector2D<Real>::sm_Zero;
		radius = Math<Real>::sm_MaxReal;
    }

	Circle2<Real> minimal{ center,radius };
    return minimal;
}

template <typename Real>
Mathematics::Circle2<Real> Mathematics::MinCircle2<Real>
	::UpdateSupport1(int i, Vector2D<Real>** permuted, Support& support)
{
    const auto& P0 = *permuted[support.Index[0]];
    const auto& P1 = *permuted[i];

	auto minimal = ExactCircle2(P0, P1);
    support.Quantity = 2;
    support.Index[1] = i;

    return minimal;
}

template <typename Real>
Mathematics::Circle2<Real> Mathematics::MinCircle2<Real>
	::UpdateSupport2(int i,Vector2D<Real>** permuted, Support& support)
{
    const Vector2D<Real>* point[2]
    {
        permuted[support.Index[0]],  // P0
        permuted[support.Index[1]]   // P1
    };
    const auto& P2 = *permuted[i];

    // Permutations of type 2, used for calling ExactCircle2(...).
    const int numType2 = 2;
    const int type2[numType2][2] =
    {
        {0, /*2*/ 1},
        {1, /*2*/ 0}
    };

    // Permutations of type 3, used for calling ExactCircle3(...).
    const int numType3 = 1;  // {0, 1, 2}

    Circle2<Real> circle[numType2 + numType3];
    int indexCircle = 0;
	auto minRSqr = Math<Real>::sm_MaxReal;
    int indexMinRSqr = -1;
	Real distDiff, minDistDiff = Math<Real>::sm_MaxReal;
    int indexMinDistDiff = -1;

    // Permutations of type 2.
    int j;
    for (j = 0; j < numType2; ++j, ++indexCircle)
    {
        circle[indexCircle] = ExactCircle2(*point[type2[j][0]], P2);
        if (circle[indexCircle].GetRadius() < minRSqr)
        {
            if (Contains(*point[type2[j][1]], circle[indexCircle], distDiff))
            {
				minRSqr = circle[indexCircle].GetRadius();
                indexMinRSqr = indexCircle;
            }
            else if (distDiff < minDistDiff)
            {
                minDistDiff = distDiff;
                indexMinDistDiff = indexCircle;
            }
        }
    }

    // Permutations of type 3.
    circle[indexCircle] = ExactCircle3(*point[0], *point[1], P2);
	if (circle[indexCircle].GetRadius() < minRSqr)
    {
		minRSqr = circle[indexCircle].GetRadius();
        indexMinRSqr = indexCircle;
    }

    // Theoreticaly, indexMinRSqr >= 0, but floating-point round-off errors
    // can lead to indexMinRSqr == -1.  When this happens, the minimal sphere
    // is chosen to be the one that has the minimum absolute errors between
    // the sphere and points (barely) outside the sphere.
    if (indexMinRSqr == -1)
    {
        indexMinRSqr = indexMinDistDiff;
    }

	auto minimal = circle[indexMinRSqr];
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
Mathematics::Circle2<Real> Mathematics::MinCircle2<Real>
	::UpdateSupport3(int i, Vector2D<Real>** permuted, Support& support)
{
    const Vector2D<Real>* point[3]
    {
        permuted[support.Index[0]],  // P0
        permuted[support.Index[1]],  // P1
        permuted[support.Index[2]]   // P2
    };
    const auto& P3 = *permuted[i];

    // Permutations of type 2, used for calling ExactCircle2(...).
    const int numType2 = 3;
    const int type2[numType2][3] =
    {
        {0, /*3*/ 1, 2},
        {1, /*3*/ 0, 2},
        {2, /*3*/ 0, 1}
    };

    // Permutations of type 2, used for calling ExactCircle3(...).
    const int numType3 = 3;
    const int type3[numType3][3] =
    {
        {0, 1, /*3*/ 2},
        {0, 2, /*3*/ 1},
        {1, 2, /*3*/ 0}
    };

    Circle2<Real> circle[numType2 + numType3];
    int indexCircle = 0;
	auto minRSqr = Math<Real>::sm_MaxReal;
	auto indexMinRSqr = -1;
	Real distDiff, minDistDiff = Math<Real>::sm_MaxReal;
	auto indexMinDistDiff = -1;

    // Permutations of type 2.
    int j;
    for (j = 0; j < numType2; ++j, ++indexCircle)
    {
        circle[indexCircle] = ExactCircle2(*point[type2[j][0]], P3);
        if (circle[indexCircle].GetRadius() < minRSqr)
        {
            if (Contains(*point[type2[j][1]], circle[indexCircle], distDiff) &&  Contains(*point[type2[j][2]], circle[indexCircle], distDiff))
            {
				minRSqr = circle[indexCircle].GetRadius();
                indexMinRSqr = indexCircle;
            }
            else if (distDiff < minDistDiff)
            {
                minDistDiff = distDiff;
                indexMinDistDiff = indexCircle;
            }
        }
    }

    // Permutations of type 3.
    for (j = 0; j < numType3; ++j, ++indexCircle)
    {
        circle[indexCircle] = ExactCircle3(*point[type3[j][0]],*point[type3[j][1]], P3);
		if (circle[indexCircle].GetRadius() < minRSqr)
        {
            if (Contains(*point[type3[j][2]], circle[indexCircle], distDiff))
            {
				minRSqr = circle[indexCircle].GetRadius();
                indexMinRSqr = indexCircle;
            }
            else if (distDiff < minDistDiff)
            {
                minDistDiff = distDiff;
                indexMinDistDiff = indexCircle;
            }
        }
    }

    // Theoreticaly, indexMinRSqr >= 0, but floating-point round-off errors
    // can lead to indexMinRSqr == -1.  When this happens, the minimal circle
    // is chosen to be the one that has the minimum absolute errors between
    // the circle and points (barely) outside the circle.
    if (indexMinRSqr == -1)
    {
        indexMinRSqr = indexMinDistDiff;
    }

	auto minimal = circle[indexMinRSqr];
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
    }

    return minimal;
}

template <typename Real>
bool Mathematics::MinCircle2<Real>::Support
	::Contains(int index, Vector2D<Real>** points, Real epsilon)
{
    for (auto i = 0; i < Quantity; ++i)
    {
		auto diff = *points[index] - *points[Index[i]];
		if (Vector2DTools<Real>::VectorMagnitudeSquared(diff) < epsilon)
        {
            return true;
        }
    }
    return false;
}

#endif // MATHEMATICS_CONTAINMENT_CONT_MIN_CIRCLE2_DETAIL_H
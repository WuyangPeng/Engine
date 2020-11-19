// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 14:17)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_CYLINDER3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_CYLINDER3_DETAIL_H

#include "StaticTestIntersectorTriangle3Cylinder3.h"

template <typename Real>
Mathematics::StaticTestIntersectorTriangle3Cylinder3<Real>
	::StaticTestIntersectorTriangle3Cylinder3 ( const Triangle3& triangle, const Cylinder3& cylinder)
	:mTriangle{ triangle }, mCylinder{ cylinder }
{
	Test();
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::StaticTestIntersectorTriangle3Cylinder3<Real>
	::GetTriangle () const
{
    return mTriangle;
}

template <typename Real>
const Mathematics::Cylinder3<Real> Mathematics::StaticTestIntersectorTriangle3Cylinder3<Real>
	::GetCylinder () const
{
    return mCylinder;
}

template <typename Real>
void Mathematics::StaticTestIntersectorTriangle3Cylinder3<Real>
	::Test ()
{
    // Get an orthonormal basis {U,V,D}.
 
	auto vector3DOrthonormalBasis =  Vector3DTools::GenerateComplementBasis(mCylinder.GetAxis().GetDirection());
	auto U = vector3DOrthonormalBasis.GetUVector();
	auto V = vector3DOrthonormalBasis.GetVVector();

    // Compute coordinates of P[i] in system {C;U,V,D}.
    Vector3D temp[3];
    int i;
    for (i = 0; i < 3; ++i)
    {
		auto delta = mTriangle.GetVertex()[i] - mCylinder.GetAxis().GetOrigin();
        temp[i][0] = Vector3DTools::DotProduct(U,delta);
        temp[i][1] = Vector3DTools::DotProduct(V,delta);
        temp[i][2] = Vector3DTools::DotProduct(mCylinder.GetAxis().GetDirection(),delta);
    }

    // Sort by z-value.
    int j0, j1, j2;
    if (temp[0][2] < temp[1][2])
    {
        if (temp[2][2] < temp[0][2])
        {
            j0 = 2; j1 = 0; j2 = 1;
        }
        else if (temp[2][2] < temp[1][2])
        {
            j0 = 0; j1 = 2; j2 = 1;
        }
        else
        {
            j0 = 0; j1 = 1; j2 = 2;
        }
    }
    else
    {
        if (temp[2][2] < temp[1][2])
        {
            j0 = 2; j1 = 1; j2 = 0;
        }
        else if (temp[2][2] < temp[0][2])
        {
            j0 = 1; j1 = 2; j2 = 0;
        }
        else
        {
            j0 = 1; j1 = 0; j2 = 2;
        }
    }

    // Maintain the xy-components and z-components separately.  The
    // z-components are used for clipping against bottom and top of
    // cylinder.  The xy-components are used for containment tests
    // in disk x*x+y*y <= r*r.
    Vector2D Q[3] { Vector2D(temp[j0][0], temp[j0][1]), Vector2D(temp[j1][0], temp[j1][1]), Vector2D(temp[j2][0], temp[j2][1])  };

    // From sorting we know that z[0] <= z[1] <= z[2].
    Real z[3] { temp[j0][2], temp[j1][2], temp[j2][2] };

    // Fast no-intersection.
    const auto hhalf = 0.5f*mCylinder.GetHeight();
    if (z[2] < -hhalf || z[0] > hhalf)
    {
        // Triangle strictly below or above the cylinder.
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // Fast no-clipping.
    if (-hhalf <= z[0] && z[2] <= hhalf)
    {
        if( DiskOverlapsPolygon(3, Q))
		{
			this->SetIntersectionType(IntersectionType::Other);
		}
		else
		{
			this->SetIntersectionType(IntersectionType::Empty);
		}

		return;
    }

    // Clip against |z| <= h/2.  At this point we know that z2 >= -h/2 and
    // z0 <= h/2 with either z0 < -h/2 or z2 > h/2 (or both).
    Vector2D polygon[5];
    Real t, numer0, numer1, invDenom0, invDenom1;

    if (z[0] < -hhalf)
    {
        if (z[2] > hhalf)
        {
            if (z[1] >= hhalf)
            {
                numer0 = -hhalf - z[0];
                numer1 = +hhalf - z[0];
                invDenom0 = (Math::GetValue(1))/(z[1] - z[0]);
                invDenom1 = (Math::GetValue(1))/(z[2] - z[0]);
                t = numer0*invDenom1;
                polygon[0] = Q[0] + t*(Q[2] - Q[0]);
                t = numer0*invDenom0;
                polygon[1] = Q[0] + t*(Q[1] - Q[0]);
                t = numer1*invDenom0;
                polygon[2] = Q[0] + t*(Q[1] - Q[0]);
                t = numer1*invDenom1;
                polygon[3] = Q[0] + t*(Q[2] - Q[0]);
                if(DiskOverlapsPolygon(4, polygon))
				{
					this->SetIntersectionType(IntersectionType::Other);
				}
				else
				{
					this->SetIntersectionType(IntersectionType::Empty);
				}

				return;
            }
            else if (z[1] <= -hhalf)
            {
                numer0 = -hhalf - z[2];
                numer1 = +hhalf - z[2];
                invDenom0 = (Math::GetValue(1))/(z[1] - z[2]);
                invDenom1 = (Math::GetValue(1))/(z[0] - z[2]);
                t = numer0*invDenom1;
                polygon[0] = Q[2] + t*(Q[0] - Q[2]);
                t = numer0*invDenom0;
                polygon[1] = Q[2] + t*(Q[1] - Q[2]);
                t = numer1*invDenom0;
                polygon[2] = Q[2] + t*(Q[1] - Q[2]);
                t = numer1*invDenom1;
                polygon[3] = Q[2] + t*(Q[0] - Q[2]);
                if(DiskOverlapsPolygon(4, polygon))
				{
					this->SetIntersectionType(IntersectionType::Other);
				}
				else
				{
					this->SetIntersectionType(IntersectionType::Empty);
				}

				return;
            }
            else
            {
                numer0 = -hhalf - z[0];
                numer1 = +hhalf - z[0];
                invDenom0 = (Math::GetValue(1))/(z[1] - z[0]);
                invDenom1 = (Math::GetValue(1))/(z[2] - z[0]);
                t = numer0*invDenom1;
                polygon[0] = Q[0] + t*(Q[2] - Q[0]);
                t = numer0*invDenom0;
                polygon[1] = Q[0] + t*(Q[1] - Q[0]);
                t = numer1*invDenom0;
                polygon[2] = Q[1];
                polygon[3] = Q[0] + t*(Q[1] - Q[0]);
                t = numer1*invDenom1;
                polygon[4] = Q[0] + t*(Q[2] - Q[0]);
                if( DiskOverlapsPolygon(5, polygon))
				{
					this->SetIntersectionType(IntersectionType::Other);
				}
				else
				{
					this->SetIntersectionType(IntersectionType::Empty);
				}

				return;
            }
        }
        else if (z[2] > -hhalf)
        {
            if (z[1] <= -hhalf)
            {
                numer0 = -hhalf - z[2];
                invDenom0 = (Math::GetValue(1))/(z[1] - z[2]);
                invDenom1 = (Math::GetValue(1))/(z[0] - z[2]);
                t = numer0*invDenom0;
                polygon[0] = Q[2] + t*(Q[1] - Q[2]);
                t = numer0*invDenom1;
                polygon[1] = Q[2] + t*(Q[0] - Q[2]);
                polygon[2] = Q[2];
                if( DiskOverlapsPolygon(3, polygon))
				{
					this->SetIntersectionType(IntersectionType::Other);
				}
				else
				{
					this->SetIntersectionType(IntersectionType::Empty);
				}

				return;
            }
            else
            {
                numer0 = -hhalf - z[0];
                invDenom0 = (Math::GetValue(1))/(z[2] - z[0]);
                invDenom1 = (Math::GetValue(1))/(z[1] - z[0]);
                t = numer0*invDenom0;
                polygon[0] = Q[0] + t*(Q[2] - Q[0]);
                t = numer0*invDenom1;
                polygon[1] = Q[0] + t*(Q[1] - Q[0]);
                polygon[2] = Q[1];
                polygon[3] = Q[2];
                if( DiskOverlapsPolygon(4, polygon))
				{
					this->SetIntersectionType(IntersectionType::Other);
				}
				else
				{
					this->SetIntersectionType(IntersectionType::Empty);
				}

				return;
            }
        }
        else
        {
            if (z[1] < -hhalf)
            {
                if( DiskOverlapsPoint(Q[2]))
				{
					this->SetIntersectionType(IntersectionType::Other);
				}
				else
				{
					this->SetIntersectionType(IntersectionType::Empty);
				}

				return;
            }
            else
            {
                if( DiskOverlapsSegment(Q[2], Q[1]))
				{
					this->SetIntersectionType(IntersectionType::Other);
				}
				else
				{
					this->SetIntersectionType(IntersectionType::Empty);
				}

				return;
            }
        }
    }
    else if (z[0] < hhalf)
    {
        if (z[1] >= hhalf)
        {
            numer0 = -hhalf - z[0];
            invDenom0 = (Math::GetValue(1))/(z[2] - z[0]);
            invDenom1 = (Math::GetValue(1))/(z[1] - z[0]);
            t = numer0*invDenom0;
            polygon[0] = Q[0] + t*(Q[2] - Q[0]);
            t = numer0*invDenom1;
            polygon[1] = Q[0] + t*(Q[1] - Q[0]);
            polygon[2] = Q[0];
            if( DiskOverlapsPolygon(3, polygon))
			{
				this->SetIntersectionType(IntersectionType::Other);
			}
			else
			{
				this->SetIntersectionType(IntersectionType::Empty);
			}
			
			return;
        }
        else
        {
            numer0 = -hhalf - z[2];
            invDenom0 = (Math::GetValue(1))/(z[1] - z[2]);
            invDenom1 = (Math::GetValue(1))/(z[0] - z[2]);
            t = numer0*invDenom0;
            polygon[0] = Q[2] + t*(Q[1] - Q[2]);
            t = numer0*invDenom1;
            polygon[1] = Q[2] + t*(Q[0] - Q[2]);
            polygon[2] = Q[0];
            polygon[3] = Q[1];
            if( DiskOverlapsPolygon(4, polygon))
			{
				this->SetIntersectionType(IntersectionType::Other);
			}
			else
			{
				this->SetIntersectionType(IntersectionType::Empty);
			}

			return;
        }
    }
    else
    {
        if (z[1] > hhalf)
        {
            if( DiskOverlapsPoint(Q[0]))
			{
				this->SetIntersectionType(IntersectionType::Other);
			}
			else
			{
				this->SetIntersectionType(IntersectionType::Empty);
			}

			return;
        }
        else
        {
            if( DiskOverlapsSegment(Q[0], Q[1]))
			{
				this->SetIntersectionType(IntersectionType::Other);
			}
			else
			{
				this->SetIntersectionType(IntersectionType::Empty);
			}

			return;
        }
    }
}

template <typename Real>
bool Mathematics::StaticTestIntersectorTriangle3Cylinder3<Real>
	::DiskOverlapsPoint (const Vector2D& Q) const
{
    return Q[0]*Q[0] + Q[1]*Q[1] <= mCylinder.GetRadius()*mCylinder.GetRadius();
}

template <typename Real>
bool Mathematics::StaticTestIntersectorTriangle3Cylinder3<Real>
	::DiskOverlapsSegment (const Vector2D& Q0, const Vector2D& Q1) const
{
	auto rSqr = mCylinder.GetRadius()*mCylinder.GetRadius();
	auto D = Q0 - Q1;
	auto dot = Vector2DTools<Real>::DotProduct(Q0,D);
    if (dot <= Math<Real>::GetZero())
    {
        return Vector2DTools<Real>::DotProduct(Q0,Q0) <= rSqr;
    }

	auto lenSqr = Vector2DTools<Real>::DotProduct(D,D);
    if (dot >= lenSqr)
    {
        return Vector2DTools<Real>::DotProduct(Q1,Q1) <= rSqr;
    }

    dot = Vector2DTools<Real>::DotPerp(D,Q0);
    return dot*dot <= lenSqr*rSqr;
}

template <typename Real>
bool Mathematics::StaticTestIntersectorTriangle3Cylinder3<Real>
	::DiskOverlapsPolygon (int numVertices, const Vector2D* Q) const
{
    // Test whether the polygon contains (0,0).
    int positive = 0, negative = 0;
    int i0, i1;
    for (i0 = numVertices-1, i1 = 0; i1 < numVertices; i0 = i1++)
    {
		auto dot = Vector2DTools<Real>::DotPerp(Q[i0],(Q[i0] - Q[i1]));
        if (dot > Math<Real>::GetZero())
        {
            ++positive;
        }
        else if (dot < Math<Real>::GetZero())
        {
            ++negative;
        }
    }
    if (positive == 0 || negative == 0)
    {
        // The polygon contains (0,0), so the disk and polygon overlap.
        return true;
    }

    // Test whether any edge is overlapped by the polygon.
    for (i0 = numVertices-1, i1 = 0; i1 < numVertices; i0 = i1++)
    {
        if (DiskOverlapsSegment(Q[i0], Q[i1]))
        {
            return true;
        }
    }

    return false;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_CYLINDER3_DETAIL_H
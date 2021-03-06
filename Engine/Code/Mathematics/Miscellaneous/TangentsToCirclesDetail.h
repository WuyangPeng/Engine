// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/16 13:26)

#ifndef MATHEMATICS_MISCELLANEOUS_TANGENTS_TO_CIRCLES_DETAIL_H
#define MATHEMATICS_MISCELLANEOUS_TANGENTS_TO_CIRCLES_DETAIL_H

#include "TangentsToCircles.h"

namespace Mathematics
{
	template <typename Real>
	static void GetDirections(const Vector2D<Real>& W, Real a,Vector2D<Real>& dir0, Vector2D<Real>& dir1)
	{
		Real a2 = a * a;
		Real wx2 = W.GetX()*W.GetX();
		Real wy2 = W.GetY()*W.GetY();
		Real c2 = wx2 + wy2;
		Real minusHalfInvC2 = ((Real)-0.5) / c2;
		Real c0, c1, discr, root, inv;

		if (Math<Real>::FAbs(W.GetX()) >= Math<Real>::FAbs(W.GetY()))
		{
			c0 = a2 - wx2;
			c1 = -(Math::GetValue(2))*a*W.GetY();
			discr = c1 * c1 - ((Real)4.0)*c0*c2;
			root = Math<Real>::Sqrt(Math<Real>::FAbs(discr));
			inv = (Math::GetValue(1)) / W.GetX();
			dir0[1] = (c1 + root)*minusHalfInvC2;
			dir0[0] = (a - W.GetY()*dir0.GetY())*inv;
			dir1[1] = (c1 - root)*minusHalfInvC2;
			dir1[0] = (a - W.GetY()*dir1.GetY())*inv;
		}
		else
		{
			c0 = a2 - wy2;
			c1 = -(Math::GetValue(2))*a*W.GetX();
			discr = c1 * c1 - ((Real)4.0)*c0*c2;
			root = Math<Real>::Sqrt(Math<Real>::FAbs(discr));
			inv = (Math::GetValue(1)) / W.GetY();
			dir0[0] = (c1 + root)*minusHalfInvC2;
			dir0[1] = (a - W.GetX()*dir0.GetX())*inv;
			dir1[0] = (c1 - root)*minusHalfInvC2;
			dir1[1] = (a - W.GetX()*dir1.GetX())*inv;
		}
	}

	template <typename Real>
	bool GetTangentsToCircles(const Circle2<Real>& circle0,const Circle2<Real>& circle1, Line2<Real> line[4])
	{
		Vector2D<Real> W = circle1.GetCenter() - circle0.GetCenter();
		Real wLenSqr = Vector2DTools<Real>::VectorMagnitudeSquared(W);
		Real rSum = circle0.GetRadius() + circle1.GetRadius();
		if (wLenSqr <= rSum * rSum)
		{
			// Circles are either intersecting or nested.
			return false;
		}

		Real r0Sqr = circle0.GetRadius() *circle0.GetRadius();
		Real tmp, a;

		Real rDiff = circle1.GetRadius() - circle0.GetRadius();
		if (Math<Real>::FAbs(rDiff) >= Math<Real>::GetZeroTolerance())
		{
			// Solve (R1^2-R0^2)*s^2 + 2*R0^2*s - R0^2 = 0..
			Real r1Sqr = circle1.GetRadius() *circle1.GetRadius();
			Real c0 = -r0Sqr;
			Real c1 = (Math::GetValue(2))*r0Sqr;
			Real c2 = circle1.GetRadius() *circle1.GetRadius() - r0Sqr;
			Real minusHalfInvC2 = ((Real)-0.5) / c2;
			Real discr = Math<Real>::FAbs(c1*c1 - ((Real)4)*c0*c2);
			Real root = Math<Real>::Sqrt(discr);
			Real s, oneMinusS;

			// Get the first root.
			s = (c1 + root)*minusHalfInvC2;
			line[0].SetOrigin(circle0.GetCenter() + s * W);
			line[1].SetOrigin(line[0].GetOrigin());
			if (s >=  Math::GetRational(1,2))
			{
				tmp = Math<Real>::FAbs(wLenSqr - r0Sqr / (s*s));
				a = Math<Real>::Sqrt(tmp);
			}
			else
			{
				oneMinusS = Math::GetValue(1) - s;
				tmp = Math<Real>::FAbs(wLenSqr - r1Sqr / (oneMinusS*oneMinusS));
				a = Math<Real>::Sqrt(tmp);
			}
			Vector2D<Real> direction0;
			Vector2D<Real> direction1;
			GetDirections(W, a, direction0, direction1);
			line[0].SetDirection(direction0);
			line[1].SetDirection(direction1);

			// Get the second root.
			s = (c1 - root)*minusHalfInvC2;
			line[2].SetOrigin(circle0.GetCenter() + s * W);
			line[3].SetOrigin(line[2].GetOrigin());
			if (s >=  Math::GetRational(1,2))
			{
				tmp = Math<Real>::FAbs(wLenSqr - r0Sqr / (s*s));
				a = Math<Real>::Sqrt(tmp);
			}
			else
			{
				oneMinusS = Math::GetValue(1) - s;
				tmp = Math<Real>::FAbs(wLenSqr - r1Sqr / (oneMinusS*oneMinusS));
				a = Math<Real>::Sqrt(tmp);
			}

			Vector2D<Real> direction2;
			Vector2D<Real> direction3;
			GetDirections(W, a, direction2, direction3);
			line[2].SetDirection(direction2);
			line[3].SetDirection(direction3);
		}
		else
		{
			// Circles effectively have same radius.

			// Midpoint of circle centers.
			Vector2D<Real> mid = ( Math::GetRational(1,2))*(circle0.GetCenter() + circle1.GetCenter());

			// Tangent lines passing through midpoint.
			tmp = Math<Real>::FAbs(wLenSqr - ((Real)4)*r0Sqr);
			a = Math<Real>::Sqrt(tmp);
			Vector2D<Real> direction0;
			Vector2D<Real> direction1;
			GetDirections(W, a, direction0, direction1);
			line[0].SetDirection(direction0);
			line[1].SetDirection(direction1);
			line[0].SetOrigin(mid);
			line[1].SetOrigin(mid);

			// Normalize W.
			W /= Math<Real>::Sqrt(wLenSqr);

			// Tangent lines parallel to normalized W:
			//   1.  D = W
			//   2.  a. P = mid+R0*perp(W), perp(a,b) = (b,-a)
			//       b. P = mid-R0*perp(W)
			line[2].SetOrigin(Vector2D<Real>(mid.GetX() + circle0.GetRadius()*W.GetY(),
				mid.GetY() - circle0.GetRadius()*W.GetX()));
			line[2].SetDirection(W);
			line[3].SetOrigin(Vector2D<Real>(mid.GetX() - circle0.GetRadius()*W.GetY(),
				mid.GetY() + circle0.GetRadius()*W.GetX()));
			line[3].SetDirection(W);
		}

		return true;
	}


}


#endif // MATHEMATICS_MISCELLANEOUS_TANGENTS_TO_CIRCLES_DETAIL_H
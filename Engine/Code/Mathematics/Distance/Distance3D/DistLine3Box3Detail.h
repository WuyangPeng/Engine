// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 13:19)

#ifndef MATHEMATICS_DISTANCE_DIST_LINE3_BOX3_DETAIL_H 
#define MATHEMATICS_DISTANCE_DIST_LINE3_BOX3_DETAIL_H 

#include "DistLine3Box3.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h" 

template <typename Real>
Mathematics::DistLine3Box3<Real>
	::DistLine3Box3(const Line3& line, const Box3& box)
	:ParentType{}, mLine{ line }, mBox{ box }, mLineParameter{}
{
}

template <typename Real>
typename const Mathematics::DistLine3Box3<Real>::Line3 Mathematics::DistLine3Box3<Real>
	::GetLine() const
{
	return mLine;
}

template <typename Real>
typename const Mathematics::DistLine3Box3<Real>::Box3 Mathematics::DistLine3Box3<Real>
	::GetBox() const
{
	return mBox;
}

template <typename Real>
typename const Mathematics::DistLine3Box3<Real>::DistanceResult Mathematics::DistLine3Box3<Real>
	::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
	auto kMOrigin = mLine.GetOrigin() + t * lhsVelocity;
	auto kMCenter = mBox.GetCenter() + t * rhsVelocity;
	Line3 kMLine{ kMOrigin,mLine.GetDirection() };
	Box3 kMBox{ kMCenter,mBox.GetFirstAxis(),
				mBox.GetSecondAxis(),mBox.GetThirdAxis(),mBox.GetFirstExtent(),
				mBox.GetSecondExtent(),mBox.GetThirdExtent() };

	return DistLine3Box3<Real>{ kMLine, kMBox }.GetSquared();
}

template <typename Real>
Real Mathematics::DistLine3Box3<Real>
	::GetLineParameter() const
{
	return mLineParameter;
}

template <typename Real>
typename const Mathematics::DistLine3Box3<Real>::DistanceResult Mathematics::DistLine3Box3<Real>
	::GetSquared() const
{
	// Compute coordinates of line in box coordinate system.
	auto diff = mLine.GetOrigin() - mBox.GetCenter();
	Vector3D point{ Vector3DTools::DotProduct(diff,mBox.GetFirstAxis()),
					Vector3DTools::DotProduct(diff,mBox.GetSecondAxis()),
					Vector3DTools::DotProduct(diff,mBox.GetThirdAxis()) };
	Vector3D direction{ Vector3DTools::DotProduct(mLine.GetDirection(),mBox.GetFirstAxis()),
						Vector3DTools::DotProduct(mLine.GetDirection(),mBox.GetSecondAxis()),
						Vector3DTools::DotProduct(mLine.GetDirection(),mBox.GetThirdAxis()) };

	// Apply reflections so that direction vector has nonnegative components.
	bool reflect[3]{};

	for (auto i = 0; i < 3; ++i)
	{
		if (direction[i] < Math<Real>::sm_Zero)
		{
			point[i] = -point[i];
			direction[i] = -direction[i];
			reflect[i] = true;
		}
		else
		{
			reflect[i] = false;
		}
	}

	Real sqrDistance{};
	mLineParameter = Math<Real>::sm_Zero;

	if (direction.GetXCoordinate() > Math<Real>::sm_Zero)
	{
		if (direction.GetYCoordinate() > Math<Real>::sm_Zero)
		{
			if (direction.GetZCoordinate() > Math<Real>::sm_Zero)  // (+,+,+)
			{
				CaseNoZeros(point, direction, sqrDistance);
			}
			else  // (+,+,0)
			{
				Case0(0, 1, 2, point, direction, sqrDistance);
			}
		}
		else
		{
			if (direction.GetZCoordinate() > Math<Real>::sm_Zero)  // (+,0,+)
			{
				Case0(0, 2, 1, point, direction, sqrDistance);
			}
			else  // (+,0,0)
			{
				Case00(0, 1, 2, point, direction, sqrDistance);
			}
		}
	}
	else
	{
		if (direction.GetYCoordinate() > Math<Real>::sm_Zero)
		{
			if (direction.GetZCoordinate() > Math<Real>::sm_Zero)  // (0,+,+)
			{
				Case0(1, 2, 0, point, direction, sqrDistance);
			}
			else  // (0,+,0)
			{
				Case00(1, 0, 2, point, direction, sqrDistance);
			}
		}
		else
		{
			if (direction.GetZCoordinate() > Math<Real>::sm_Zero)  // (0,0,+)
			{
				Case00(2, 0, 1, point, direction, sqrDistance);
			}
			else  // (0,0,0)
			{
				Case000(point, sqrDistance);
			}
		}
	}

	// Compute closest point on line.
	auto  mClosestPoint0 = mLine.GetOrigin() + mLineParameter * mLine.GetDirection();

	// Compute closest point on box.
	auto mClosestPoint1 = mBox.GetCenter();
	for (auto i = 0; i < 3; ++i)
	{
		// Undo the reflections applied previously.
		if (reflect[i])
		{
			point[i] = -point[i];
		}

		mClosestPoint1 += point[i] * mBox.GetAxis(i);
	}

	return DistanceResult{ sqrDistance,Math<Real>::sm_Zero,mClosestPoint0,mClosestPoint1 };
}

template <typename Real>
void Mathematics::DistLine3Box3<Real>
	::Face(int i0, int i1, int i2, Vector3D& pnt, const Vector3D& dir, const Vector3D& PmE, Real& sqrDistance) const
{
	Vector3D PpE;
	auto lenSqr = Math<Real>::sm_Zero;
	auto inv = Math<Real>::sm_Zero;
	auto tmp = Math<Real>::sm_Zero;
	auto param = Math<Real>::sm_Zero;
	auto t = Math<Real>::sm_Zero;
	auto delta = Math<Real>::sm_Zero;

	PpE[i1] = pnt[i1] + mBox.GetExtent(i1);
	PpE[i2] = pnt[i2] + mBox.GetExtent(i2);
	if (dir[i0] * PpE[i1] >= dir[i1] * PmE[i0])
	{
		if (dir[i0] * PpE[i2] >= dir[i2] * PmE[i0])
		{
			// v[i1] >= -e[i1], v[i2] >= -e[i2] (distance = 0)
			pnt[i0] = mBox.GetExtent(i0);
			inv = Math<Real>::sm_One / dir[i0];
			pnt[i1] -= dir[i1] * PmE[i0] * inv;
			pnt[i2] -= dir[i2] * PmE[i0] * inv;
			mLineParameter = -PmE[i0] * inv;
		}
		else
		{
			// v[i1] >= -e[i1], v[i2] < -e[i2]
			lenSqr = dir[i0] * dir[i0] + dir[i2] * dir[i2];
			tmp = lenSqr * PpE[i1] - dir[i1] * (dir[i0] * PmE[i0] + dir[i2] * PpE[i2]);
			if (tmp <= (static_cast<Real>(2) * lenSqr * mBox.GetExtent(i1)))
			{
				t = tmp / lenSqr;
				lenSqr += dir[i1] * dir[i1];
				tmp = PpE[i1] - t;
				delta = dir[i0] * PmE[i0] + dir[i1] * tmp + dir[i2] * PpE[i2];
				param = -delta / lenSqr;
				sqrDistance += PmE[i0] * PmE[i0] + tmp * tmp + PpE[i2] * PpE[i2] + delta * param;

				mLineParameter = param;
				pnt[i0] = mBox.GetExtent(i0);
				pnt[i1] = t - mBox.GetExtent(i1);
				pnt[i2] = -mBox.GetExtent(i2);
			}
			else
			{
				lenSqr += dir[i1] * dir[i1];
				delta = dir[i0] * PmE[i0] + dir[i1] * PmE[i1] + dir[i2] * PpE[i2];
				param = -delta / lenSqr;
				sqrDistance += PmE[i0] * PmE[i0] + PmE[i1] * PmE[i1] + PpE[i2] * PpE[i2] + delta * param;

				mLineParameter = param;
				pnt[i0] = mBox.GetExtent(i0);
				pnt[i1] = mBox.GetExtent(i1);
				pnt[i2] = -mBox.GetExtent(i2);
			}
		}
	}
	else
	{
		if (dir[i0] * PpE[i2] >= dir[i2] * PmE[i0])
		{
			// v[i1] < -e[i1], v[i2] >= -e[i2]
			lenSqr = dir[i0] * dir[i0] + dir[i1] * dir[i1];
			tmp = lenSqr * PpE[i2] - dir[i2] * (dir[i0] * PmE[i0] + dir[i1] * PpE[i1]);
			if (tmp <= (static_cast<Real>(2))*lenSqr*mBox.GetExtent(i2))
			{
				t = tmp / lenSqr;
				lenSqr += dir[i2] * dir[i2];
				tmp = PpE[i2] - t;
				delta = dir[i0] * PmE[i0] + dir[i1] * PpE[i1] + dir[i2] * tmp;
				param = -delta / lenSqr;
				sqrDistance += PmE[i0] * PmE[i0] + PpE[i1] * PpE[i1] + tmp * tmp + delta * param;

				mLineParameter = param;
				pnt[i0] = mBox.GetExtent(i0);
				pnt[i1] = -mBox.GetExtent(i1);
				pnt[i2] = t - mBox.GetExtent(i2);
			}
			else
			{
				lenSqr += dir[i2] * dir[i2];
				delta = dir[i0] * PmE[i0] + dir[i1] * PpE[i1] + dir[i2] * PmE[i2];
				param = -delta / lenSqr;
				sqrDistance += PmE[i0] * PmE[i0] + PpE[i1] * PpE[i1] + PmE[i2] * PmE[i2] + delta * param;

				mLineParameter = param;
				pnt[i0] = mBox.GetExtent(i0);
				pnt[i1] = -mBox.GetExtent(i1);
				pnt[i2] = mBox.GetExtent(i2);
			}
		}
		else
		{
			// v[i1] < -e[i1], v[i2] < -e[i2]
			lenSqr = dir[i0] * dir[i0] + dir[i2] * dir[i2];
			tmp = lenSqr * PpE[i1] - dir[i1] * (dir[i0] * PmE[i0] + dir[i2] * PpE[i2]);
			if (tmp >= Math<Real>::sm_Zero)
			{
				// v[i1]-edge is closest
				if (tmp <= (static_cast<Real>(2))*lenSqr*mBox.GetExtent(i1))
				{
					t = tmp / lenSqr;
					lenSqr += dir[i1] * dir[i1];
					tmp = PpE[i1] - t;
					delta = dir[i0] * PmE[i0] + dir[i1] * tmp + dir[i2] * PpE[i2];
					param = -delta / lenSqr;
					sqrDistance += PmE[i0] * PmE[i0] + tmp * tmp + PpE[i2] * PpE[i2] + delta * param;

					mLineParameter = param;
					pnt[i0] = mBox.GetExtent(i0);
					pnt[i1] = t - mBox.GetExtent(i1);
					pnt[i2] = -mBox.GetExtent(i2);
				}
				else
				{
					lenSqr += dir[i1] * dir[i1];
					delta = dir[i0] * PmE[i0] + dir[i1] * PmE[i1] + dir[i2] * PpE[i2];
					param = -delta / lenSqr;
					sqrDistance += PmE[i0] * PmE[i0] + PmE[i1] * PmE[i1] + PpE[i2] * PpE[i2] + delta * param;

					mLineParameter = param;
					pnt[i0] = mBox.GetExtent(i0);
					pnt[i1] = mBox.GetExtent(i1);
					pnt[i2] = -mBox.GetExtent(i2);
				}
				return;
			}

			lenSqr = dir[i0] * dir[i0] + dir[i1] * dir[i1];
			tmp = lenSqr * PpE[i2] - dir[i2] * (dir[i0] * PmE[i0] + dir[i1] * PpE[i1]);
			if (tmp >= Math<Real>::sm_Zero)
			{
				// v[i2]-edge is closest
				if (tmp <= (static_cast<Real>(2))*lenSqr*mBox.GetExtent(i2))
				{
					t = tmp / lenSqr;
					lenSqr += dir[i2] * dir[i2];
					tmp = PpE[i2] - t;
					delta = dir[i0] * PmE[i0] + dir[i1] * PpE[i1] + dir[i2] * tmp;
					param = -delta / lenSqr;
					sqrDistance += PmE[i0] * PmE[i0] + PpE[i1] * PpE[i1] + tmp * tmp + delta * param;

					mLineParameter = param;
					pnt[i0] = mBox.GetExtent(i0);
					pnt[i1] = -mBox.GetExtent(i1);
					pnt[i2] = t - mBox.GetExtent(i2);
				}
				else
				{
					lenSqr += dir[i2] * dir[i2];
					delta = dir[i0] * PmE[i0] + dir[i1] * PpE[i1] + dir[i2] * PmE[i2];
					param = -delta / lenSqr;
					sqrDistance += PmE[i0] * PmE[i0] + PpE[i1] * PpE[i1] + PmE[i2] * PmE[i2] + delta * param;

					mLineParameter = param;
					pnt[i0] = mBox.GetExtent(i0);
					pnt[i1] = -mBox.GetExtent(i1);
					pnt[i2] = mBox.GetExtent(i2);
				}
				return;
			}

			// (v[i1],v[i2])-corner is closest
			lenSqr += dir[i2] * dir[i2];
			delta = dir[i0] * PmE[i0] + dir[i1] * PpE[i1] + dir[i2] * PpE[i2];
			param = -delta / lenSqr;
			sqrDistance += PmE[i0] * PmE[i0] + PpE[i1] * PpE[i1] + PpE[i2] * PpE[i2] + delta * param;

			mLineParameter = param;
			pnt[i0] = mBox.GetExtent(i0);
			pnt[i1] = -mBox.GetExtent(i1);
			pnt[i2] = -mBox.GetExtent(i2);
		}
	}
}

template <typename Real>
void Mathematics::DistLine3Box3<Real>
	::CaseNoZeros(Vector3D& pnt, const Vector3D& dir, Real& sqrDistance) const
{
	Vector3D PmE{ pnt.GetXCoordinate() - mBox.GetExtent(0),	pnt.GetYCoordinate() - mBox.GetExtent(1),pnt.GetZCoordinate() - mBox.GetExtent(2) };

	auto prodDxPy = dir.GetXCoordinate() * PmE.GetYCoordinate();
	auto prodDyPx = dir.GetYCoordinate() * PmE.GetXCoordinate();
	auto prodDzPx = Math<Real>::sm_Zero;
	auto prodDxPz = Math<Real>::sm_Zero; 
	auto prodDzPy = Math<Real>::sm_Zero;
	auto prodDyPz = Math<Real>::sm_Zero;

	if (prodDyPx >= prodDxPy)
	{
		prodDzPx = dir.GetZCoordinate() * PmE.GetXCoordinate();
		prodDxPz = dir.GetXCoordinate() * PmE.GetZCoordinate();
		if (prodDzPx >= prodDxPz)
		{
			// line intersects x = e0
			Face(0, 1, 2, pnt, dir, PmE, sqrDistance);
		}
		else
		{
			// line intersects z = e2
			Face(2, 0, 1, pnt, dir, PmE, sqrDistance);
		}
	}
	else
	{
		prodDzPy = dir.GetZCoordinate()*PmE.GetYCoordinate();
		prodDyPz = dir.GetYCoordinate()*PmE.GetZCoordinate();
		if (prodDzPy >= prodDyPz)
		{
			// line intersects y = e1
			Face(1, 2, 0, pnt, dir, PmE, sqrDistance);
		}
		else
		{
			// line intersects z = e2
			Face(2, 0, 1, pnt, dir, PmE, sqrDistance);
		}
	}
}

template <typename Real>
void Mathematics::DistLine3Box3<Real>
	::Case0(int i0, int i1, int i2, Vector3D& pnt, const Vector3D& dir, Real& sqrDistance) const
{
	auto PmE0 = pnt[i0] - mBox.GetExtent(i0);
	auto PmE1 = pnt[i1] - mBox.GetExtent(i1);
	auto prod0 = dir[i1] * PmE0;
	auto prod1 = dir[i0] * PmE1;
	auto delta = Math<Real>::sm_Zero;
	auto invLSqr = Math<Real>::sm_Zero;
	auto inv = Math<Real>::sm_Zero;

	if (prod0 >= prod1)
	{
		// line intersects P[i0] = e[i0]
		pnt[i0] = mBox.GetExtent(i0);

		auto PpE1 = pnt[i1] + mBox.GetExtent(i1);
		delta = prod0 - dir[i0] * PpE1;
		if (delta >= Math<Real>::sm_Zero)
		{
			invLSqr = (static_cast<Real>(1)) / (dir[i0] * dir[i0] + dir[i1] * dir[i1]);
			sqrDistance += delta * delta*invLSqr;
			pnt[i1] = -mBox.GetExtent(i1);
			mLineParameter = -(dir[i0] * PmE0 + dir[i1] * PpE1) * invLSqr;
		}
		else
		{
			inv = (static_cast<Real>(1)) / dir[i0];
			pnt[i1] -= prod0 * inv;
			mLineParameter = -PmE0 * inv;
		}
	}
	else
	{
		// line intersects P[i1] = e[i1]
		pnt[i1] = mBox.GetExtent(i1);

		Real PpE0 = pnt[i0] + mBox.GetExtent(i0);
		delta = prod1 - dir[i1] * PpE0;
		if (delta >= Math<Real>::sm_Zero)
		{
			invLSqr = (static_cast<Real>(1)) / (dir[i0] * dir[i0] + dir[i1] * dir[i1]);
			sqrDistance += delta * delta*invLSqr;
			pnt[i0] = -mBox.GetExtent(i0);
			mLineParameter = -(dir[i0] * PpE0 + dir[i1] * PmE1)*invLSqr;
		}
		else
		{
			inv = (static_cast<Real>(1)) / dir[i1];
			pnt[i0] -= prod1 * inv;
			mLineParameter = -PmE1 * inv;
		}
	}

	if (pnt[i2] < -mBox.GetExtent(i2))
	{
		delta = pnt[i2] + mBox.GetExtent(i2);
		sqrDistance += delta * delta;
		pnt[i2] = -mBox.GetExtent(i2);
	}
	else if (pnt[i2] > mBox.GetExtent(i2))
	{
		delta = pnt[i2] - mBox.GetExtent(i2);
		sqrDistance += delta * delta;
		pnt[i2] = mBox.GetExtent(i2);
	}
}

template <typename Real>
void Mathematics::DistLine3Box3<Real>
	::Case00(int i0, int i1, int i2, Vector3D& pnt, const Vector3D& dir, Real& sqrDistance) const
{
	auto delta = Math<Real>::sm_Zero;

	mLineParameter = (mBox.GetExtent(i0) - pnt[i0]) / dir[i0];

	pnt[i0] = mBox.GetExtent(i0);

	if (pnt[i1] < -mBox.GetExtent(i1))
	{
		delta = pnt[i1] + mBox.GetExtent(i1);
		sqrDistance += delta * delta;
		pnt[i1] = -mBox.GetExtent(i1);
	}
	else if (pnt[i1] > mBox.GetExtent(i1))
	{
		delta = pnt[i1] - mBox.GetExtent(i1);
		sqrDistance += delta * delta;
		pnt[i1] = mBox.GetExtent(i1);
	}

	if (pnt[i2] < -mBox.GetExtent(i2))
	{
		delta = pnt[i2] + mBox.GetExtent(i2);
		sqrDistance += delta * delta;
		pnt[i2] = -mBox.GetExtent(i2);
	}
	else if (pnt[i2] > mBox.GetExtent(i2))
	{
		delta = pnt[i2] - mBox.GetExtent(i2);
		sqrDistance += delta * delta;
		pnt[i2] = mBox.GetExtent(i2);
	}
}

template <typename Real>
void Mathematics::DistLine3Box3<Real>
	::Case000(Vector3D& pnt, Real& sqrDistance) const
{
	auto delta = Math<Real>::sm_Zero;

	if (pnt.GetXCoordinate() < -mBox.GetExtent(0))
	{
		delta = pnt.GetXCoordinate() + mBox.GetExtent(0);
		sqrDistance += delta * delta;
		pnt.SetXCoordinate(-mBox.GetExtent(0));
	}
	else if (pnt.GetXCoordinate() > mBox.GetExtent(0))
	{
		delta = pnt.GetXCoordinate() - mBox.GetExtent(0);
		sqrDistance += delta * delta;
		pnt.SetXCoordinate(mBox.GetExtent(0));
	}

	if (pnt.GetYCoordinate() < -mBox.GetExtent(1))
	{
		delta = pnt.GetYCoordinate() + mBox.GetExtent(1);
		sqrDistance += delta * delta;
		pnt.SetYCoordinate(-mBox.GetExtent(1));
	}
	else if (pnt.GetYCoordinate() > mBox.GetExtent(1))
	{
		delta = pnt.GetYCoordinate() - mBox.GetExtent(1);
		sqrDistance += delta * delta;
		pnt.SetYCoordinate(mBox.GetExtent(1));
	}

	if (pnt.GetZCoordinate() < -mBox.GetExtent(2))
	{
		delta = pnt.GetZCoordinate() + mBox.GetExtent(2);
		sqrDistance += delta * delta;
		pnt.SetZCoordinate(-mBox.GetExtent(2));
	}
	else if (pnt.GetZCoordinate() > mBox.GetExtent(2))
	{
		delta = pnt.GetZCoordinate() - mBox.GetExtent(2);
		sqrDistance += delta * delta;
		pnt.SetZCoordinate(mBox.GetExtent(2));
	}
}

#endif // MATHEMATICS_DISTANCE_DIST_LINE3_BOX3_DETAIL_H
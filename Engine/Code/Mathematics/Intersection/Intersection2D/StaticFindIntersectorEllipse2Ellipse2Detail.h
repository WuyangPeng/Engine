// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 15:38)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ELLIPSE2_ELLIPSE2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ELLIPSE2_ELLIPSE2_DETAIL_H

#include "StaticFindIntersectorEllipse2Ellipse2.h"
#include "StaticTestIntersectorBox2Box2.h"
#include "Mathematics/NumericalAnalysis/PolynomialRoots.h" 

template <typename Real>
Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>
	::StaticFindIntersectorEllipse2Ellipse2(const Ellipse2& ellipse0, const Ellipse2& ellipse1, const Real epsilon)
	:ParentType{ epsilon }, DIGITS_ACCURACY{ 10 }, mEllipse0{ ellipse0 }, mEllipse1{ ellipse1 }
{
	Find();
}

template <typename Real>
Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>
	::~StaticFindIntersectorEllipse2Ellipse2()
{

}

template <typename Real>
const Mathematics::Ellipse2<Real>& Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>
	::GetEllipse0() const
{
	return mEllipse0;
}

template <typename Real>
const Mathematics::Ellipse2<Real>& Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>
	::GetEllipse1() const
{
	return mEllipse1;
}

template <typename Real>
void Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>
	::Find()
{
	mQuantity = 0;

	// Test for separation of oriented bounding boxes of ellipses.  This is
	// a fast-out attempt.
	Box2<Real> box0{ mEllipse0.GetCenter(), mEllipse0.GetAxis0(), mEllipse0.GetAxis1(), mEllipse0.GetExtent0(), mEllipse0.GetExtent1() };
	Box2<Real> box1{ mEllipse1.GetCenter(), mEllipse1.GetAxis0(), mEllipse1.GetAxis1(), mEllipse1.GetExtent0(), mEllipse1.GetExtent1() };

	if (!StaticTestIntersectorBox2Box2<Real>(box0, box1).IsIntersection())
	{
		// The boxes do not overlap, so neither do the ellipses.
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	// Compute the 4th-degree polynomial whose roots lead to intersections of
	// the ellipses, and then compute its roots.
	auto poly = GetQuartic(mEllipse0, mEllipse1);
	PolynomialRoots<Real> proots{ Math::sm_ZeroTolerance };
	proots.FindBisection(poly, DIGITS_ACCURACY);
	auto yCount = proots.GetCount();

	if (yCount == 0)
	{
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	// TODO:  Adjust the comments.
	// Compute the coefficients of a polynomial in s = sin(angle) and
	// c = cos(angle) that relates ellipse0 to ellipse1
	// affinely transformed to a circle.  The polynomial is
	//   d0 + d1*c + d2*s + d3*c^2 + d4*c*s + d5*s^2 = 0
	// where c^2 + s^2 = 1.
	auto  C0mC1 = mEllipse0.GetCenter() - mEllipse1.GetCenter();
	auto M1 = mEllipse1.GetMatrix();
	auto  M1C0mC1 = M1 * C0mC1;
	auto  M1A0 = M1 * mEllipse0.GetAxis0();
	auto  M1A1 = M1 * mEllipse0.GetAxis1();
	Real coeff[6]{};
	coeff[0] = Vector2DTools::DotProduct(M1C0mC1, C0mC1) - static_cast<Real>(1);
	coeff[1] = (static_cast<Real>(2)) * mEllipse0.GetExtent0() * Vector2DTools::DotProduct(M1A0, C0mC1);
	coeff[2] = (static_cast<Real>(2)) * mEllipse0.GetExtent1() * Vector2DTools::DotProduct(M1A1, C0mC1);
	coeff[3] = mEllipse0.GetExtent0() * mEllipse0.GetExtent0() * Vector2DTools::DotProduct(M1A0, mEllipse0.GetAxis0());
	coeff[4] = (static_cast<Real>(2)) * mEllipse0.GetExtent0() * mEllipse0.GetExtent1() * Vector2DTools::DotProduct(M1A0, mEllipse0.GetAxis1());
	coeff[5] = mEllipse0.GetExtent1() * mEllipse0.GetExtent1() * Vector2DTools::DotProduct(M1A1, mEllipse0.GetAxis1());

	// Evaluate the quadratics, saving the values to test later for closeness
	// to zero and for root polishing.
	auto ellipse2Coefficients0 = mEllipse0.ToCoefficients();
	auto ellipse2Coefficients1 = mEllipse1.ToCoefficients();
	auto qp0 = ellipse2Coefficients0.GetCoefficients();
	auto qp1 = ellipse2Coefficients1.GetCoefficients();
	std::vector<Measurement> measure(8);  // store <x,y,sqrt(Q0^2+S1^2)>
	Vector2D point;
	auto i = 0;
	auto begin = proots.GetBegin();
	auto end = proots.GetEnd();
	auto ix = 0;
	for (; begin != end; ++begin)
	{
		point[1] = *begin;
		PolynomialRoots<Real> ar{ Math::sm_ZeroTolerance };
		Polynomial<Real> apoly{ 2 };
		apoly[0] = qp0[0] + point[1] * (qp0[2] + point[1] * qp0[5]);
		apoly[1] = qp0[1] + point[1] * qp0[4];
		apoly[2] = qp0[3];
		ar.FindBisection(apoly, DIGITS_ACCURACY);

		auto arBegin = ar.GetBegin();
		auto arEnd = ar.GetEnd();
		int iy = 0;
		for (; arBegin != arEnd; ++arBegin)
		{
			point[0] = *arBegin;
			auto q0 = mEllipse0.Evaluate(point);
			auto q1 = mEllipse1.Evaluate(point);

			Real angle0 = Math::sm_Zero;
			auto transverse = RefinePoint(coeff, point, q0, q1, angle0);

			i = ix + 2 * iy;
			measure[i].Point = point;
			measure[i].Q0 = q0;
			measure[i].Q1 = q1;
			measure[i].Norm = Math::Sqrt(q0*q0 + q1 * q1);
			measure[i].Angle0 = angle0;
			measure[i].Transverse = transverse;

			++iy;
		}

		++ix;
	}
	std::sort(measure.begin(), measure.end());

	for (i = 0; i < 8; ++i)
	{
		if (measure[i].Norm < Math::sm_ZeroTolerance)
		{
			auto j = 0;
			auto adiff = Math::sm_Zero;
			for (j = 0; j < mQuantity; ++j)
			{
				adiff = measure[i].Angle0 - measure[j].Angle0;
				if (Math::FAbs(adiff) < Math::sm_ZeroTolerance)
				{
					break;
				}
			}
			if (j == mQuantity)
			{
				mPoint[mQuantity] = measure[i].Point;
				mTransverse[mQuantity] = measure[i].Transverse;
				if (++mQuantity == 4)
				{
					break;
				}
			}
		}
	}

	if (mQuantity == 0)
	{
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	this->SetIntersectionType(IntersectionType::Point);
	return;
}

template <typename Real>
int Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>
	::GetQuantity() const
{
	return mQuantity;
}

template <typename Real>
const Mathematics::Vector2D<Real>& Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>
	::GetPoint(int i) const
{
	return mPoint[i];
}

template <typename Real>
const Mathematics::Ellipse2<Real>& Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>
	::GetIntersectionEllipse() const
{
	return mEllipse0;
}

template <typename Real>
bool Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>
	::IsTransverseIntersection(int i) const
{
	return mTransverse[i];
}

template <typename Real>
typename Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>::Classification Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>
	::GetClassification() const
{
	// Get the parameters of ellipe0.
	auto K0 = mEllipse0.GetCenter();
	Matrix2<Real> R0{ mEllipse0.GetAxis0(), mEllipse0.GetAxis1(), MatrixMajorFlags::Row };
	Matrix2<Real> D0{ (static_cast<Real>(1)) / (mEllipse0.GetExtent0() * mEllipse0.GetExtent0()),
					  (static_cast<Real>(1)) / (mEllipse0.GetExtent1() * mEllipse0.GetExtent1()) };

	// Get the parameters of ellipse1.
	auto K1 = mEllipse1.GetCenter();
	Matrix2<Real> R1{ mEllipse1.GetAxis0(),mEllipse1.GetAxis1(), MatrixMajorFlags::Row };
	Matrix2<Real> D1{ (static_cast<Real>(1)) / (mEllipse1.GetExtent0() * mEllipse1.GetExtent0()),
					  (static_cast<Real>(1)) / (mEllipse1.GetExtent1() * mEllipse1.GetExtent1()) };

	// Compute K2.
	Matrix2<Real> D0NegHalf{ mEllipse0.GetExtent0(),mEllipse0.GetExtent1() };
	Matrix2<Real> D0Half{ (static_cast<Real>(1)) / mEllipse0.GetExtent0(),(static_cast<Real>(1)) / mEllipse0.GetExtent1() };
	auto K2 = D0Half * ((K1 - K0)*R0);

	// Compute M2.
	auto R1TR0D0NegHalf = TransposeTimes(R1, R0*D0NegHalf);
	auto M2 = TransposeTimes(R1TR0D0NegHalf, D1)*R1TR0D0NegHalf;

	// Factor M2 = Real*D*Real^T.
	Matrix2<Real> R, D;
	auto matrix2EigenDecomposition = M2.EigenDecomposition();
	R = matrix2EigenDecomposition.GetRotation();
	D = matrix2EigenDecomposition.GetDiagonal();

	// Compute K = Real^T*K2.
	auto K = K2 * R;

	// Transformed ellipsoid0 is Z^T*Z = 1 and transformed ellipsoid1 is
	// (Z-K)^T*D*(Z-K) = 0.

	// The minimum and maximum squared distances from the origin of points on
	// transformed ellipse1 are used to determine whether the ellipses
	// intersect, are separated, or one contains the other.
	auto minSqrDistance = Math::sm_MaxReal;
	auto maxSqrDistance = Math<Real>::sm_Zero;
	auto i = 0;

	if (K == Vector2D::sm_Zero)
	{
		// The special case of common centers must be handled separately.  It
		// is not possible for the ellipsoids to be separated.
		for (i = 0; i < 2; ++i)
		{
			auto invD = (static_cast<Real>(1)) / D[i][i];
			if (invD < minSqrDistance)
			{
				minSqrDistance = invD;
			}
			if (invD > maxSqrDistance)
			{
				maxSqrDistance = invD;
			}
		}

		if (maxSqrDistance < static_cast<Real>(1))
		{
			return EC_ELLIPSE0_CONTAINS_ELLIPSE1;
		}
		else if (minSqrDistance > static_cast<Real>(1))
		{
			return EC_ELLIPSE1_CONTAINS_ELLIPSE0;
		}
		else
		{
			return EC_ELLIPSES_INTERSECTING;
		}
	}

	// The closest point P0 and farthest point P1 are solutions to
	// s0*D*(P0 - K) = P0 and s1*D1*(P1 - K) = P1 for some scalars s0 and s1
	// that are roots to the function
	//   f(s) = d0*k0^2/(d0*s-1)^2 + d1*k1^2/(d1*s-1)^2 - 1
	// where D = diagonal(d0,d1) and K = (k0,k1).
	auto d0 = D[0][0], d1 = D[1][1];
	auto c0 = K2[0] * K2[0], c1 = K2[1] * K2[1];

	// Sort the values so that d0 >= d1.  This allows us to bound the roots of
	// f(s), of which there are at most 4.
	std::vector<std::pair<Real, Real> > param(2);
	if (d0 >= d1)
	{
		param[0] = std::make_pair(d0, c0);
		param[1] = std::make_pair(d1, c1);
	}
	else
	{
		param[0] = std::make_pair(d1, c1);
		param[1] = std::make_pair(d0, c0);
	}

	std::vector<std::pair<Real, Real> > valid;
	valid.reserve(2);
	if (param[0].first > param[1].first)
	{
		// d0 > d1
		for (i = 0; i < 2; ++i)
		{
			if (param[i].second > Math<Real>::sm_Zero)
			{
				valid.push_back(param[i]);
			}
		}
	}
	else
	{
		// d0 = d1
		param[0].second += param[1].second;
		if (param[0].second > Math<Real>::sm_Zero)
		{
			valid.push_back(param[0]);
		}
	}

	auto numValid = valid.size();
	auto numRoots = 0;
	Real roots[4]{};
	if (numValid == 2)
	{
		GetRoots(valid[0].first, valid[1].first, valid[0].second, valid[1].second, numRoots, roots);
	}
	else if (numValid == 1)
	{
		GetRoots(valid[0].first, valid[0].second, numRoots, roots);
	}
	else
	{
		// numValid cannot be zero because we already handled case K = 0
		MATHEMATICS_ASSERTION_0(false, "Unexpected condition.\n");
		return EC_ELLIPSES_INTERSECTING;
	}

	for (auto i = 0; i < numRoots; ++i)
	{
		auto s = roots[i];
		auto p0 = d0 * K[0] * s / (d0*s - static_cast<Real>(1));
		auto p1 = d1 * K[1] * s / (d1*s - static_cast<Real>(1));
		auto sqrDistance = p0 * p0 + p1 * p1;
		if (sqrDistance < minSqrDistance)
		{
			minSqrDistance = sqrDistance;
		}
		if (sqrDistance > maxSqrDistance)
		{
			maxSqrDistance = sqrDistance;
		}
	}

	if (maxSqrDistance < static_cast<Real>(1))
	{
		return EC_ELLIPSE0_CONTAINS_ELLIPSE1;
	}

	if (minSqrDistance > static_cast<Real>(1))
	{
		if (d0 * c0 + d1 * c1 > static_cast<Real>(1))
		{
			return EC_ELLIPSES_SEPARATED;
		}
		else
		{
			return EC_ELLIPSE1_CONTAINS_ELLIPSE0;
		}
	}

	return EC_ELLIPSES_INTERSECTING;
}

template <typename Real>
void Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>
	::BisectF(Real d0, Real d1, Real d0c0, Real d1c1, Real smin, Real fmin, Real smax, Real fmax, Real& s, Real& f)
{
	auto increasing = (fmin < Math<Real>::sm_Zero);

	constexpr auto maxIterations = 256;
	for (auto i = 0; i < maxIterations; ++i)
	{
		s = (static_cast<Real>(0.5)) * (smin + smax);
		if (smin < s)
		{
			if (s < smax)
			{
				auto invN0 = (static_cast<Real>(1)) / (d0*s - static_cast<Real>(1));
				auto invN1 = (static_cast<Real>(1)) / (d1*s - static_cast<Real>(1));
				auto invN0Sqr = invN0 * invN0;
				auto invN1Sqr = invN1 * invN1;
				f = d0c0 * invN0Sqr + d1c1 * invN1Sqr - static_cast<Real>(1);
				if (f < Math<Real>::sm_Zero)
				{
					if (increasing)
					{
						smin = s;
						fmin = f;
					}
					else
					{
						smax = s;
						fmax = f;
					}
				}
				else if (f > Math<Real>::sm_Zero)
				{
					if (increasing)
					{
						smax = s;
						fmax = f;
					}
					else
					{
						smin = s;
						fmin = f;
					}
				}
				else
				{
					break;
				}
			}
			else
			{
				f = fmax;
				break;
			}
		}
		else
		{
			f = fmin;
			break;
		}
	}
}

template <typename Real>
void Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>
	::BisectDF(Real d0, Real d1, Real d0c0, Real d1c1, Real smin, Real dfmin, Real smax, Real dfmax, Real& s, Real& df)
{
	constexpr auto maxIterations = 256;
	for (auto i = 0; i < maxIterations; ++i)
	{
		s = (static_cast<Real>(0.5))*(smin + smax);
		if (smin < s)
		{
			if (s < smax)
			{
				auto invN0 = (static_cast<Real>(1)) / (d0*s - static_cast<Real>(1));
				auto invN1 = (static_cast<Real>(1)) / (d1*s - static_cast<Real>(1));
				auto invN0Cub = invN0 * invN0*invN0;
				auto invN1Cub = invN1 * invN1*invN1;
				df = (static_cast<Real>(-2) * (d0 * d0c0 * invN0Cub + d1 * d1c1 * invN1Cub));
				if (df < Math<Real>::sm_Zero)
				{
					smin = s;
					dfmin = df;
				}
				else if (df > Math<Real>::sm_Zero)
				{
					smax = s;
					dfmax = df;
				}
				else
				{
					break;
				}
			}
			else
			{
				df = dfmax;
				break;
			}
		}
		else
		{
			df = dfmin;
			break;
		}
	}
}

template <typename Real>
void Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>
	::GetRoots(Real d0, Real d1, Real c0, Real c1, int& numRoots, Real* roots)
{
	// f(s) = d0*c0/(d0*s-1)^2 + d1*c1/(d1*s-1)^2 - 1
	// with d0 > d1

	numRoots = 0;

	auto epsilon = static_cast<Real>(0.001);
	auto multiplier0 = Math::Sqrt((static_cast<Real>(2)) / (static_cast<Real>(1) - epsilon));
	auto multiplier1 = Math::Sqrt((static_cast<Real>(1)) / (static_cast<Real>(1) + epsilon));
	auto d0c0 = d0 * c0;
	auto d1c1 = d1 * c1;
	auto sqrtd0c0 = Math::Sqrt(d0c0);
	auto sqrtd1c1 = Math::Sqrt(d1c1);
	auto invD0 = (static_cast<Real>(1)) / d0;
	auto invD1 = (static_cast<Real>(1)) / d1;
	auto temp0 = Math::sm_Zero;
	auto temp1 = Math::sm_Zero;
	auto smin = Math::sm_Zero; 
	auto smax = Math::sm_Zero; 
	auto s = Math::sm_Zero;
	auto fmin = Math::sm_Zero; 
	auto fmax = Math::sm_Zero; 
	auto f = Math::sm_Zero;
	auto invN0 = Math::sm_Zero;
	auto invN1 = Math::sm_Zero; 
	auto invN0Sqr = Math::sm_Zero; 
	auto invN1Sqr = Math::sm_Zero;

	// Compute root in (-infinity,1/d0).
	temp0 = (static_cast<Real>(1) - multiplier0 * sqrtd0c0) * invD0;
	temp1 = (static_cast<Real>(1) - multiplier0 * sqrtd1c1) * invD1;
	smin = (temp0 < temp1 ? temp0 : temp1);
	invN0 = (static_cast<Real>(1)) / (d0 * smin - static_cast<Real>(1));
	invN1 = (static_cast<Real>(1)) / (d1 * smin - static_cast<Real>(1));
	invN0Sqr = invN0 * invN0;
	invN1Sqr = invN1 * invN1;
	fmin = d0c0 * invN0Sqr + d1c1 * invN1Sqr - static_cast<Real>(1);
	MATHEMATICS_ASSERTION_0(fmin < Math<Real>::sm_Zero, "Unexpected condition.\n");
	smax = (static_cast<Real>(1) - multiplier1 * sqrtd0c0) * invD0;
	invN0 = (static_cast<Real>(1)) / (d0*smax - static_cast<Real>(1));
	invN1 = (static_cast<Real>(1)) / (d1*smax - static_cast<Real>(1));
	invN0Sqr = invN0 * invN0;
	invN1Sqr = invN1 * invN1;
	fmax = d0c0 * invN0Sqr + d1c1 * invN1Sqr - static_cast<Real>(1);
	MATHEMATICS_ASSERTION_0(fmax > Math<Real>::sm_Zero, "Unexpected condition.\n");
	BisectF(d0, d1, d0c0, d1c1, smin, fmin, smax, fmax, s, f);
	roots[numRoots++] = s;

	// Compute roots (if any) in (1/d0,1/d1).
	Real smid, fmid, df;
	BisectDF(d0, d1, d0c0, d1c1, invD0, -Math::sm_MaxReal, invD1, Math::sm_MaxReal, smid, df);
	invN0 = (static_cast<Real>(1)) / (d0 * smid - static_cast<Real>(1));
	invN1 = (static_cast<Real>(1)) / (d1 * smid - static_cast<Real>(1));
	invN0Sqr = invN0 * invN0;
	invN1Sqr = invN1 * invN1;
	fmid = d0c0 * invN0Sqr + d1c1 * invN1Sqr - static_cast<Real>(1);
	if (fmid < Math<Real>::sm_Zero)
	{
		BisectF(d0, d1, d0c0, d1c1, invD0, Math::sm_MaxReal, smid, fmid, s, f);
		roots[numRoots++] = s;
		BisectF(d0, d1, d0c0, d1c1, smid, fmid, invD1, Math::sm_MaxReal, s, f);
		roots[numRoots++] = s;
	}

	// Compute root in (1/d1,+infinity).
	temp0 = (static_cast<Real>(1) + multiplier0 * sqrtd0c0) * invD0;
	temp1 = (static_cast<Real>(1) + multiplier0 * sqrtd1c1) * invD1;
	smax = (temp0 > temp1 ? temp0 : temp1);
	invN0 = (static_cast<Real>(1)) / (d0*smax - static_cast<Real>(1));
	invN1 = (static_cast<Real>(1)) / (d1*smax - static_cast<Real>(1));
	invN0Sqr = invN0 * invN0;
	invN1Sqr = invN1 * invN1;
	fmax = d0c0 * invN0Sqr + d1c1 * invN1Sqr - static_cast<Real>(1);
	MATHEMATICS_ASSERTION_0(fmax < Math<Real>::sm_Zero, "Unexpected condition.\n");
	smin = (static_cast<Real>(1) + multiplier1 * sqrtd1c1)*invD1;
	invN0 = (static_cast<Real>(1)) / (d0*smin - static_cast<Real>(1));
	invN1 = (static_cast<Real>(1)) / (d1*smin - static_cast<Real>(1));
	invN0Sqr = invN0 * invN0;
	invN1Sqr = invN1 * invN1;
	fmin = d0c0 * invN0Sqr + d1c1 * invN1Sqr - static_cast<Real>(1);
	MATHEMATICS_ASSERTION_0(fmin > Math<Real>::sm_Zero, "Unexpected condition.\n");
	BisectF(d0, d1, d0c0, d1c1, smin, fmin, smax, fmax, s, f);
	roots[numRoots++] = s;
}

template <typename Real>
void Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>
	::GetRoots(Real d0, Real c0, int& numRoots, Real* roots)
{
	// f(s) = d0*c0/(d0*s-1)^2 - 1
	auto temp = Math::Sqrt(d0*c0);
	auto inv = (static_cast<Real>(1)) / d0;
	numRoots = 2;
	roots[0] = (static_cast<Real>(1) - temp)*inv;
	roots[1] = (static_cast<Real>(1) + temp)*inv;
}

template <typename Real>
Mathematics::Polynomial<Real> Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>
	::GetQuartic(const Ellipse2& ellipse0, const Ellipse2& ellipse1)
{
	auto ellipse2Coefficients0 = ellipse0.ToCoefficients();
	auto ellipse2Coefficients1 = ellipse1.ToCoefficients();
	auto p0 = ellipse2Coefficients0.GetCoefficients();
	auto p1 = ellipse2Coefficients1.GetCoefficients();

	// The polynomials are
	//   P0 = a0 + a1*x + a2*y + a3*x^2 + a4*x*y + a5*y^2
	//      = (a0 + a2*y + a5*y^2) + (a1 + a4*y)*x + (a3)*x^2
	//      = u0(y) + u1(y)*x + u2(y)*x^2
	//   P1 = b0 + b1*x + b2*y + b3*x^2 + b4*x*y + b5*y^2
	//      = (b0 + b2*y + b5*y^2) + (b1 + b4*y)*x + (b3)*x^2
	//      = v0(y) + v1(y)*x + v2(y)*x^2
	// The Bezout determinant eliminates the variable x when solving the
	// equations P0(x,y) = 0 and P1(x,y) = 0.  We have
	//   0 = P0 = u0 + u1*x + u2*x^2
	//   0 = P1 = v0 + v1*x + v2*x^2
	//   0 = v2*P0 - u2*P1 = (u0*v2 - u2*v0) + (u1*v2 - u2*v1)*x
	//   0 = v1*P0 - u1*P1 = (u0*v1 - u1*v0) + (u2*v1 - u1*v2)*x^2
	// Solve the equation 0 = v2*P0-u2*P1 for x and substitute in the other
	// equation and simplify to
	//   Q(y) = (u0*v1-v1*u0)*(u1*v2-u2*v1) - (u0*v2-u2*v0)^2 = 0
	//        = c0 + c1*y + c2*y^2 + c3*y^3 + c4*y^4
	// Define dij = ai*bj - aj*bi for various indices i and j.  For example,
	// d01 = a0*b1-b1*a0.  The coefficients of Q(y) are
	//   c0 = d01*d13 - d30^2
	//   c1 = d01*d43 + (d04+d21)*d13 - 2*d30*d32
	//   c2 = (d04+d21)*d43 + (d24+d51)*d13 - 2*d30*d35 - d32^2
	//   c3 = (d24+d51)*d43 + d54*d13 - 2*d32*d35
	//   c4 = d54*d43 - d35^2

	auto d01 = p0[0] * p1[1] - p0[1] * p1[0];
	auto d04 = p0[0] * p1[4] - p0[4] * p1[0];
	auto d13 = p0[1] * p1[3] - p0[3] * p1[1];
	auto d21 = p0[2] * p1[1] - p0[1] * p1[2];
	auto d24 = p0[2] * p1[4] - p0[4] * p1[2];
	auto d30 = p0[3] * p1[0] - p0[0] * p1[3];
	auto d32 = p0[3] * p1[2] - p0[2] * p1[3];
	auto d35 = p0[3] * p1[5] - p0[5] * p1[3];
	auto d43 = p0[4] * p1[3] - p0[3] * p1[4];
	auto d51 = p0[5] * p1[1] - p0[1] * p1[5];
	auto d54 = p0[5] * p1[4] - p0[4] * p1[5];
	auto d04p21 = d04 + d21;
	auto d24p51 = d24 + d51;

	Polynomial<Real> poly{ 4 };
	poly[0] = d01 * d13 - d30 * d30;
	poly[1] = d01 * d43 + d04p21 * d13 - (static_cast<Real>(2)) * d30 * d32;
	poly[2] = d04p21 * d43 + d24p51 * d13 - (static_cast<Real>(2)) * d30 * d35 - d32 * d32;
	poly[3] = d24p51 * d43 + d54 * d13 - (static_cast<Real>(2)) * d32 * d35;
	poly[4] = d54 * d43 - d35 * d35;

	return poly;
}

template <typename Real>
bool Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>
	::RefinePoint(const Real coeff[6], Vector2D& point, Real& q0, Real& q1, Real& angle0)
{
	// The incoming polynomial is
	//   f(angle) = d0 + d1*c + d2*s + d3*c^2 + d4*c*s + d5*s^2
	// where s = sin(angle) and c = cos(angle).  The derivative is
	//   f'(angle) = -d1*s + d2*c + (d5 - d3)*2*c*s + d4*(c^2 - s^2)

	auto diff = point - mEllipse0.GetCenter();
	auto cs = Vector2DTools::DotProduct(diff, mEllipse0.GetAxis0()) / mEllipse0.GetExtent0();
	auto sn = Vector2DTools::DotProduct(diff, mEllipse0.GetAxis1()) / mEllipse0.GetExtent1();
	auto a0 = Math::ATan2(sn, cs);
	auto f0 = coeff[0] + coeff[1] * cs + coeff[2] * sn + coeff[3] * cs*cs + coeff[4] * cs*sn + coeff[5] * sn*sn;
	auto df0 = -coeff[1] * sn + coeff[2] * cs + (static_cast<Real>(2))*(coeff[5] - coeff[3])*cs*sn + coeff[4] * (cs*cs - sn * sn);

	Real a1 = Math<Real>::sm_Zero, f1, df1;

	// The value f0 should match q1 (to within floating-point round-off
	// error).  Try to force f0 to zero using bisection.  This requires
	// finding an angle such that the corresponding function value is
	// opposite in sign to f0.  If the search fails, the input point is
	// either a tangential intersection or not an intersection at all.
	const auto maxIterations = 32;
	auto i = 0;
	for (i = 0; i < maxIterations; ++i)
	{
		a1 = a0 - f0 / df0;
		cs = Math::Cos(a1);
		sn = Math::Sin(a1);
		f1 = coeff[0] + coeff[1] * cs + coeff[2] * sn + coeff[3] * cs*cs + coeff[4] * cs*sn + coeff[5] * sn*sn;

		if (f0*f1 < Math<Real>::sm_Zero)
		{
			// Switch to bisection.
			break;
		}

		df1 = -coeff[1] * sn + coeff[2] * cs + (static_cast<Real>(2))*(coeff[5] - coeff[3])*cs*sn + coeff[4] * (cs*cs - sn * sn);

		if (df1*df0 < Math<Real>::sm_Zero)
		{
			// Try a steeper slope in hopes of finding an opposite sign
			// value.
			df0 *= static_cast<Real>(2);
			continue;
		}

		if (Math::FAbs(f1) < Math::FAbs(f0))
		{
			// We failed to find an opposite-sign value, but the new
			// function value is closer to zero, so try again with the
			// new value.
			a0 = a1;
			f0 = f1;
			df0 = df1;
		}
	}

	auto angle = a0;
	auto transverse = false;
	if (i < maxIterations)
	{
		// Apply bisection.  Determine number of iterations to get 10 digits
		// of accuracy.
		auto tmp0 = Math::Log(Math::FAbs(a1 - a0));
		auto tmp1 = (static_cast<Real>(DIGITS_ACCURACY)) * Math::Log(static_cast<Real>(10));
		auto arg = (tmp0 + tmp1) / Math::Log(static_cast<Real>(2));
		maxIterations = static_cast<int>(arg + static_cast<Real>(0.5));
		for (i = 0; i < maxIterations; ++i)
		{
			angle = (static_cast<Real>(0.5))*(a0 + a1);
			cs = Math::Cos(angle);
			sn = Math::Sin(angle);
			f1 = coeff[0] + coeff[1] * cs + coeff[2] * sn + coeff[3] * cs*cs + coeff[4] * cs*sn + coeff[5] * sn*sn;

			auto product = f0 * f1;
			if (product < Math<Real>::sm_Zero)
			{
				a1 = angle;
			}
			else if (product > Math<Real>::sm_Zero)
			{
				a0 = angle;
				f0 = f1;
			}
			else
			{
				break;
			}
		}
		transverse = true;
	}
	else
	{
		transverse = false;
	}

	point = mEllipse0.GetCenter() + mEllipse0.GetExtent0()*cs*mEllipse0.GetAxis0() + mEllipse0.GetExtent1() * sn * mEllipse0.GetAxis1();

	q0 = mEllipse0.Evaluate(point);
	q1 = mEllipse1.Evaluate(point);
	angle0 = angle;

	return transverse;
}

// IntrEllipse2Ellipse2::Measurement

template <typename Real>
Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>::Measurement
	::Measurement()
	:Point{ Math::sm_MaxReal, Math::sm_MaxReal }, Q0{ Math::sm_MaxReal }, Q1{ Math::sm_MaxReal }, Norm{ Math::sm_MaxReal }, Angle0{ Math::sm_MaxReal }, Transverse{ false }
{
}

template <typename Real>
bool Mathematics::StaticFindIntersectorEllipse2Ellipse2<Real>::Measurement
	::operator< (const Measurement& measure) const
{
	if (Transverse == measure.Transverse)
	{
		return Norm < measure.Norm;
	}
	else
	{
		return Transverse;
	}
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ELLIPSE2_ELLIPSE2_DETAIL_H
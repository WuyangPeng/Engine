// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/12 19:30)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_TRIANGLE2_TRIANGLE2_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_TRIANGLE2_TRIANGLE2_DETAIL_H

#include "DynamicTestIntersectorTriangle2Triangle2.h"

template <typename Real>
Mathematics::DynamicTestIntersectorTriangle2Triangle2<Real>
	::DynamicTestIntersectorTriangle2Triangle2(const Triangle2& triangle0, const Triangle2& triangle1, Real tmax, const Vector2D& velocity0,  const Vector2D& velocity1, const Real epsilon)
	:ParentType{ tmax, velocity0, velocity1, epsilon }, mTriangle0{ triangle0 }, mTriangle1{ triangle1 }
{
	Test();
}

template <typename Real>
const Mathematics::Triangle2<Real> Mathematics::DynamicTestIntersectorTriangle2Triangle2<Real>
	::GetTriangle0() const
{
    return mTriangle0;
}

template <typename Real>
const Mathematics::Triangle2<Real> Mathematics::DynamicTestIntersectorTriangle2Triangle2<Real>
	::GetTriangle1() const
{
    return mTriangle1;
}
  
template <typename Real>
void Mathematics::DynamicTestIntersectorTriangle2Triangle2<Real>
	::Test()
{
    // Process as if V0-triangle is stationary and V1-triangle is moving.
	auto W = this->GetRhsVelocity() - this->GetLhsVelocity();
    int side = 0;  // 0 = NONE, -1 = LEFT, +1 = RIGHT
    Real tfirst{};
	auto tlast = Math::sm_MaxReal;

    Configuration cfg0, cfg1, tcfg0, tcfg1;
    int i0, i1, i2;
    Vector2D D;
    Real speed;

    // Process edges of V0-triangle.
    for (i0 = 1, i1 = 2, i2 = 0; i2 < 3; i0 = i1, i1 = i2++)
    {
        // Test axis V0[i1] + t*perp(V0[i2]-V0[i1]), perp(x,y) = (y,-x).
		D.SetXCoordinate(mTriangle0.GetVertex()[i2].GetYCoordinate() - mTriangle0.GetVertex()[i1].GetYCoordinate());
		D.SetYCoordinate(mTriangle0.GetVertex()[i1].GetXCoordinate() - mTriangle0.GetVertex()[i2].GetXCoordinate());
		speed = Vector2DTools::DotProduct(D, W);

		ComputeTwo(cfg0, mTriangle0.GetVertex(), D, i0, i1, i2);
		ComputeThree(cfg1, mTriangle1.GetVertex(), D, mTriangle0.GetVertex()[i1]);

		if (NoIntersect(cfg0, cfg1, this->GetTMax(), speed, side, tcfg0, tcfg1,tfirst, tlast))
        {
			this->SetIntersectionType(IntersectionType::Empty);
			return;
        }
    }

    // Process edges of V1-triangle.
    for (i0 = 1, i1 = 2, i2 = 0; i2 < 3; i0 = i1, i1 = i2++)
    {
        // Test axis V1[i1] + t*perp(V1[i2]-V1[i1]), perp(x,y) = (y,-x).
		D.SetXCoordinate(mTriangle1.GetVertex()[i2].GetYCoordinate() - mTriangle1.GetVertex()[i1].GetYCoordinate());
		D.SetYCoordinate(mTriangle1.GetVertex()[i1].GetXCoordinate() - mTriangle1.GetVertex()[i2].GetXCoordinate());
		speed = Vector2DTools::DotProduct(D, W);

		ComputeTwo(cfg1, mTriangle1.GetVertex(), D, i0, i1, i2);
		ComputeThree(cfg0, mTriangle0.GetVertex(), D, mTriangle1.GetVertex()[i1]);

		if (NoIntersect(cfg0, cfg1, this->GetTMax(), speed, side, tcfg0, tcfg1,tfirst, tlast))
        {
			this->SetIntersectionType(IntersectionType::Empty);
			return;
        }
    }

	SetContactTime(tfirst);	
	this->SetIntersectionType(IntersectionType::Point);
}
 

template <typename Real>
int Mathematics::DynamicTestIntersectorTriangle2Triangle2<Real>
::WhichSide(const Vector2D V[3], const Vector2D& P, const Vector2D& D)
{
	// Vertices are projected to the form P+t*D.  Return value is +1 if all
	// t > 0, -1 if all t < 0, 0 otherwise, in which case the line splits the
	// triangle.

	int positive = 0, negative = 0, zero = 0;
	for (auto i = 0; i < 3; ++i)
	{
		auto t = Vector2DTools::DotProduct(D, (V[i] - P));
		if (t >Real{})
		{
			++positive;
		}
		else if (t < Real{})
		{
			++negative;
		}
		else
		{
			++zero;
		}

		if (positive > 0 && negative > 0)
		{
			return 0;
		}
	}
	return (zero == 0 ? (positive > 0 ? 1 : -1) : 0);
}

template <typename Real>
void Mathematics::DynamicTestIntersectorTriangle2Triangle2<Real>
::ClipConvexPolygonAgainstLine(const Vector2D& N, Real c, int& quantity, Vector2D V[6])
{
	// The input vertices are assumed to be in counterclockwise order.  The
	// ordering is an invariant of this function.

	// Test on which side of line the vertices are.
	int positive = 0, negative = 0, pIndex = -1;
	Real test[6];
	int i;
	for (i = 0; i < quantity; ++i)
	{
		test[i] = Vector2DTools::DotProduct(N, V[i]) - c;
		if (test[i] >Real{})
		{
			positive++;
			if (pIndex < 0)
			{
				pIndex = i;
			}
		}
		else if (test[i] < Real{})
		{
			negative++;
		}
	}

	if (positive > 0)
	{
		if (negative > 0)
		{
			// Line transversely intersects polygon.
			Vector2D CV[6];
			int cQuantity = 0, cur, prv;
			Real t;

			if (pIndex > 0)
			{
				// First clip vertex on line.
				cur = pIndex;
				prv = cur - 1;
				t = test[cur] / (test[cur] - test[prv]);
				CV[cQuantity++] = V[cur] + t*(V[prv] - V[cur]);

				// Vertices on positive side of line.
				while (cur < quantity && test[cur] >Real{})
				{
					CV[cQuantity++] = V[cur++];
				}

				// Last clip vertex on line.
				if (cur < quantity)
				{
					prv = cur - 1;
				}
				else
				{
					cur = 0;
					prv = quantity - 1;
				}
				t = test[cur] / (test[cur] - test[prv]);
				CV[cQuantity++] = V[cur] + t*(V[prv] - V[cur]);
			}
			else  // pIndex is 0
			{
				// Vertices on positive side of line.
				cur = 0;
				while (cur < quantity && test[cur] >Real{})
				{
					CV[cQuantity++] = V[cur++];
				}

				// Last clip vertex on line.
				prv = cur - 1;
				t = test[cur] / (test[cur] - test[prv]);
				CV[cQuantity++] = V[cur] + t*(V[prv] - V[cur]);

				// Skip vertices on negative side.
				while (cur < quantity && test[cur] <= Real{})
				{
					++cur;
				}

				// First clip vertex on line.
				if (cur < quantity)
				{
					prv = cur - 1;
					t = test[cur] / (test[cur] - test[prv]);
					CV[cQuantity++] = V[cur] + t*(V[prv] - V[cur]);

					// Vertices on positive side of line.
					while (cur < quantity && test[cur] >Real{})
					{
						CV[cQuantity++] = V[cur++];
					}
				}
				else
				{
					// cur = 0
					prv = quantity - 1;
					t = test[0] / (test[0] - test[prv]);
					CV[cQuantity++] = V[0] + t*(V[prv] - V[0]);
				}
			}

			quantity = cQuantity;
			memcpy(V, CV, cQuantity*sizeof(Vector2D));
		}
		// else polygon fully on positive side of line, nothing to do.
	}
	else
	{
		// Polygon does not intersect positive side of line, clip all.
		quantity = 0;
	}
}

template <typename Real>
void Mathematics::DynamicTestIntersectorTriangle2Triangle2<Real>
	::ComputeTwo(Configuration& cfg, const std::vector<Vector2D>& V,const Vector2D& D, int i0, int i1, int i2)
{
	cfg.Map = M12;
	cfg.Index[0] = i0;
	cfg.Index[1] = i1;
	cfg.Index[2] = i2;
	cfg.Min = Vector2DTools::DotProduct(D, (V[i0] - V[i1]));
	cfg.Max = Real{};
}

template <typename Real>
void Mathematics::DynamicTestIntersectorTriangle2Triangle2<Real>
	::ComputeThree(Configuration& cfg, const std::vector<Vector2D>& V, const Vector2D& D, const Vector2D& P)
{
	auto d0 = Vector2DTools::DotProduct(D, (V[0] - P));
	auto d1 = Vector2DTools::DotProduct(D, (V[1] - P));
	auto d2 = Vector2DTools::DotProduct(D, (V[2] - P));

	// Make sure that m_aiIndex[...] is an even permutation of (0,1,2)
	// whenever the map value is M12 or M21.  This is needed to guarantee
	// the intersection of overlapping edges is properly computed.

	if (d0 <= d1)
	{
		if (d1 <= d2)  // d0 <= d1 <= d2
		{
			if (d0 != d1)
			{
				cfg.Map = (d1 != d2 ? M11 : M12);
			}
			else
			{
				cfg.Map = M21;
			}

			cfg.Index[0] = 0;
			cfg.Index[1] = 1;
			cfg.Index[2] = 2;
			cfg.Min = d0;
			cfg.Max = d2;
		}
		else if (d0 <= d2)  // d0 <= d2 < d1
		{
			if (d0 != d2)
			{
				cfg.Map = M11;
				cfg.Index[0] = 0;
				cfg.Index[1] = 2;
				cfg.Index[2] = 1;
			}
			else
			{
				cfg.Map = M21;
				cfg.Index[0] = 2;
				cfg.Index[1] = 0;
				cfg.Index[2] = 1;
			}

			cfg.Min = d0;
			cfg.Max = d1;
		}
		else  // d2 < d0 <= d1
		{
			cfg.Map = (d0 != d1 ? M12 : M11);
			cfg.Index[0] = 2;
			cfg.Index[1] = 0;
			cfg.Index[2] = 1;
			cfg.Min = d2;
			cfg.Max = d1;
		}
	}
	else
	{
		if (d2 <= d1)  // d2 <= d1 < d0
		{
			if (d2 != d1)
			{
				cfg.Map = M11;
				cfg.Index[0] = 2;
				cfg.Index[1] = 1;
				cfg.Index[2] = 0;
			}
			else
			{
				cfg.Map = M21;
				cfg.Index[0] = 1;
				cfg.Index[1] = 2;
				cfg.Index[2] = 0;
			}

			cfg.Min = d2;
			cfg.Max = d0;
		}
		else if (d2 <= d0)  // d1 < d2 <= d0
		{
			cfg.Map = (d2 != d0 ? M11 : M12);
			cfg.Index[0] = 1;
			cfg.Index[1] = 2;
			cfg.Index[2] = 0;
			cfg.Min = d1;
			cfg.Max = d0;
		}
		else  // d1 < d0 < d2
		{
			cfg.Map = M11;
			cfg.Index[0] = 1;
			cfg.Index[1] = 0;
			cfg.Index[2] = 2;
			cfg.Min = d1;
			cfg.Max = d2;
		}
	}
}

template <typename Real>
bool Mathematics::DynamicTestIntersectorTriangle2Triangle2<Real>
	::NoIntersect(const Configuration& cfg0, const Configuration& cfg1, Real tmax, Real speed, int& side, Configuration& tcfg0, Configuration& tcfg1, Real& tfirst, Real& tlast)
{
	Real invSpeed, t;

	if (cfg1.Max < cfg0.Min)
	{
		// V1-interval initially on left of V0-interval.
		if (speed <= Real{})
		{
			// Intervals moving apart.
			return true;
		}

		// Update first time.
		invSpeed = ((Real)1) / speed;
		t = (cfg0.Min - cfg1.Max)*invSpeed;
		if (t > tfirst)
		{
			tfirst = t;
			side = -1;
			tcfg0 = cfg0;
			tcfg1 = cfg1;
		}

		// Test for exceedance of time interval.
		if (tfirst > tmax)
		{
			return true;
		}

		// Update last time.
		t = (cfg0.Max - cfg1.Min)*invSpeed;
		if (t < tlast)
		{
			tlast = t;
		}

		// Test for separation.
		if (tfirst > tlast)
		{
			return true;
		}
	}
	else if (cfg0.Max < cfg1.Min)
	{
		// V1-interval initially on right of V0-interval.
		if (speed >= Real{})
		{
			// Intervals moving apart.
			return true;
		}

		// Update first time.
		invSpeed = ((Real)1) / speed;
		t = (cfg0.Max - cfg1.Min)*invSpeed;
		if (t > tfirst)
		{
			tfirst = t;
			side = 1;
			tcfg0 = cfg0;
			tcfg1 = cfg1;
		}

		// Test for exceedance of time interval.
		if (tfirst > tmax)
		{
			return true;
		}

		// Update last time.
		t = (cfg0.Min - cfg1.Max)*invSpeed;
		if (t < tlast)
		{
			tlast = t;
		}

		// Test for separation.
		if (tfirst > tlast)
		{
			return true;
		}
	}
	else
	{
		// V0-interval and V1-interval initially overlap.
		if (speed > Real{})
		{
			// Update last time.
			invSpeed = ((Real)1) / speed;
			t = (cfg0.Max - cfg1.Min)*invSpeed;
			if (t < tlast)
			{
				tlast = t;
			}

			// Test for separation.
			if (tfirst > tlast)
			{
				return true;
			}
		}
		else if (speed < Real{})
		{
			// Update last time.
			invSpeed = ((Real)1) / speed;
			t = (cfg0.Min - cfg1.Max)*invSpeed;
			if (t < tlast)
			{
				tlast = t;
			}

			// Test for separation.
			if (tfirst > tlast)
			{
				return true;
			}
		}
	}

	return false;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorTriangle2Triangle2<Real>
	::GetIntersection(const Configuration& cfg0, const Configuration& cfg1, int side, const Vector2D V0[3], const Vector2D V1[3], int& quantity, Vector2D vertex[6])
{
	Vector2D edge, diff;
	const Vector2D* origin;
	Real invEdE, emin, emax;
	int i;

	if (side == 1)  // V1-interval contacts V0-interval on right.
	{
		if (cfg0.Map == M21 || cfg0.Map == M11)
		{
			quantity = 1;
			vertex[0] = V0[cfg0.Index[2]];
		}
		else if (cfg1.Map == M12 || cfg1.Map == M11)
		{
			quantity = 1;
			vertex[0] = V1[cfg1.Index[0]];
		}
		else  // cfg0.Map == M12 && cfg1.Map == M21 (edge overlap).
		{
			origin = &V0[cfg0.Index[1]];
			edge = V0[cfg0.Index[2]] - *origin;
			invEdE = ((Real)1) / Vector2DTools::DotProduct(edge, edge);
			diff = V1[cfg1.Index[1]] - *origin;
			emin = Vector2DTools::DotProduct(edge, diff)*invEdE;
			diff = V1[cfg1.Index[0]] - *origin;
			emax = Vector2DTools::DotProduct(edge, diff)*invEdE;
			MATHEMATICS_ASSERTION_0(emin <= emax, "Unexpected condition\n");
			StaticFindIntersector1<Real> intr{ Real{}, (Real)1, emin, emax };
			quantity = intr.GetNumIntersections();
			MATHEMATICS_ASSERTION_0(quantity > 0, "Unexpected condition\n");
			for (i = 0; i < quantity; ++i)
			{
				vertex[i] = *origin + intr.GetIntersection(i)*edge;
			}
		}
	}
	else if (side == -1)  // V1-interval contacts V0-interval on left.
	{
		if (cfg1.Map == M21 || cfg1.Map == M11)
		{
			quantity = 1;
			vertex[0] = V1[cfg1.Index[2]];
		}
		else if (cfg0.Map == M12 || cfg0.Map == M11)
		{
			quantity = 1;
			vertex[0] = V0[cfg0.Index[0]];
		}
		else  // cfg1.Map == M12 && cfg0.Map == M21 (edge overlap).
		{
			origin = &V1[cfg1.Index[1]];
			edge = V1[cfg1.Index[2]] - *origin;
			invEdE = ((Real)1) / Vector2DTools::DotProduct(edge, edge);
			diff = V0[cfg0.Index[1]] - *origin;
			emin = Vector2DTools::DotProduct(edge, diff)*invEdE;
			diff = V0[cfg0.Index[0]] - *origin;
			emax = Vector2DTools::DotProduct(edge, diff)*invEdE;
			MATHEMATICS_ASSERTION_0(emin <= emax, "Unexpected condition\n");
			StaticFindIntersector1<Real> intr{ Real{}, (Real)1, emin, emax };
			quantity = intr.GetNumIntersections();
			MATHEMATICS_ASSERTION_0(quantity > 0, "Unexpected condition\n");
			for (i = 0; i < quantity; ++i)
			{
				vertex[i] = *origin + intr.GetIntersection(i)*edge;
			}
		}
	}
	else  // Triangles were initially intersecting.
	{
		Triangle2 tri0{ V0[0], V0[1], V0[2] };
		Triangle2 tri1{ V1[0], V1[1], V1[2] };
		StaticFindIntersectorTriangle2Triangle2<Real> intr{ tri0, tri1 };

		quantity = intr.GetQuantity();
		for (i = 0; i < quantity; ++i)
		{
			vertex[i] = intr.GetPoint(i);
		}
	}
}



#endif // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_TRIANGLE2_TRIANGLE2_DETAIL_H
// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 19:07)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_QUADRIC_SURFACE_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_QUADRIC_SURFACE_DETAIL_H
 
#include "QuadricSurface.h"

namespace Mathematics
{

template <typename Real>
QuadricSurface<Real>::QuadricSurface ()
{
    memset(mCoeff,0,10*sizeof(Real));
}

template <typename Real>
QuadricSurface<Real>::QuadricSurface (const Real coeff[10])
{
    for (int i = 0; i < 10; ++i)
    {
        mCoeff[i] = coeff[i];
    }

    // Compute A, B, C.
    mC = mCoeff[0];
    mB[0] = mCoeff[1];
    mB[1] = mCoeff[2];
    mB[2] = mCoeff[3];
    mA[0][0] = mCoeff[4];
    mA[0][1] = (Real{0.5})*mCoeff[5];
    mA[0][2] = (Real{0.5})*mCoeff[6];
    mA[1][0] = mA[0][1];
    mA[1][1] = mCoeff[7];
    mA[1][2] = (Real{0.5})*mCoeff[8];
    mA[2][0] = mA[0][2];
    mA[2][1] = mA[1][2];
    mA[2][2] = mCoeff[9];
}

template <typename Real>
const Real* QuadricSurface<Real>::GetCoefficients () const
{
    return mCoeff;
}

template <typename Real>
const Matrix3<Real>& QuadricSurface<Real>::GetA () const
{
    return mA;
}

template <typename Real>
const Vector3<Real>& QuadricSurface<Real>::GetB () const
{
    return mB;
}

template <typename Real>
Real QuadricSurface<Real>::GetC () const
{
    return mC;
}

template <typename Real>
Real QuadricSurface<Real>::F (const Vector3<Real>& pos) const
{
	Real f = Vector3Tools<Real>::DotProduct(pos,(mA*pos + mB)) + mC;
    return f;
}

template <typename Real>
Real QuadricSurface<Real>::FX (const Vector3<Real>& pos) const
{
    Real sum = mA[0][0]*pos[0] + mA[0][1]*pos[1] + mA[0][2]*pos[2];
    Real fx = (Math::GetValue(2))*sum + mB[0];
    return fx;
}

template <typename Real>
Real QuadricSurface<Real>::FY (const Vector3<Real>& pos) const
{
    Real sum = mA[1][0]*pos[0] + mA[1][1]*pos[1] + mA[1][2]*pos[2];
    Real fy = (Math::GetValue(2))*sum + mB[1];
    return fy;
}

template <typename Real>
Real QuadricSurface<Real>::FZ (const Vector3<Real>& pos) const
{
    Real sum = mA[2][0]*pos[0] + mA[2][1]*pos[1] + mA[2][2]*pos[2];
    Real fz = (Math::GetValue(2))*sum + mB[2];
    return fz;
}

template <typename Real>
Real QuadricSurface<Real>::FXX (const Vector3<Real>&) const
{
    Real fxx = (Math::GetValue(2))*mA[0][0];
    return fxx;
}

template <typename Real>
Real QuadricSurface<Real>::FXY (const Vector3<Real>&) const
{
    Real fxy = (Math::GetValue(2))*mA[0][1];
    return fxy;
}

template <typename Real>
Real QuadricSurface<Real>::FXZ (const Vector3<Real>&) const
{
    Real fxz = (Math::GetValue(2))*mA[0][2];
    return fxz;
}

template <typename Real>
Real QuadricSurface<Real>::FYY (const Vector3<Real>&) const
{
    Real fyy = (Math::GetValue(2))*mA[1][1];
    return fyy;
}

template <typename Real>
Real QuadricSurface<Real>::FYZ (const Vector3<Real>&) const
{
    Real fyz = (Math::GetValue(2))*mA[1][2];
    return fyz;
}

template <typename Real>
Real QuadricSurface<Real>::FZZ (const Vector3<Real>&) const
{
    Real fzz = (Math::GetValue(2))*mA[2][2];
    return fzz;
}

template <typename Real>
int QuadricSurface<Real>::GetType () const
{
    // Convert the coefficients to their rational representations and
    // compute various derived quantities.
    RReps reps(mCoeff);

    // Use Sturm sequences to determine the signs of the roots.
    int positiveRoots, negativeRoots, zeroRoots;
    GetRootSigns(reps, positiveRoots, negativeRoots, zeroRoots);

    // Classify the solution set to the equation.
    int type = QT_NONE;
    switch (zeroRoots)
    {
    case 0:
        type = ClassifyZeroRoots0(reps,positiveRoots);
        break;
    case 1:
        type = ClassifyZeroRoots1(reps,positiveRoots);
        break;
    case 2:
        type = ClassifyZeroRoots2(reps,positiveRoots);
        break;
    case 3:
        type = ClassifyZeroRoots3(reps);
        break;
    }
    return type;
}

template <typename Real>
void QuadricSurface<Real>::GetRootSigns (RReps& reps,int& positiveRoots, int& negativeRoots, int& zeroRoots)
{
    // Use Sturm sequences to determine the signs of the roots.
    int signChangeMI, signChange0, signChangePI, distinctNonzeroRoots;
    QRational value[4];
	if (reps.C0 != QRational(0))
    {
        reps.C3 = QRational(2,9)*reps.C2*reps.C2 - QRational(2,3)*reps.C1;
        reps.C4 = reps.C0 - QRational(1,9)*reps.C1*reps.C2;

		if (reps.C3 != QRational(0))
        {
            reps.C5 = -(reps.C1 + ((QRational(2)*reps.C2*reps.C3 +
                QRational(3)*reps.C4)*reps.C4)/(reps.C3*reps.C3));

			value[0] = QRational(1);
            value[1] = -reps.C3;
            value[2] = reps.C5;
            signChangeMI = 1 + GetSignChanges(3, value);

            value[0] = -reps.C0;
            value[1] = reps.C1;
            value[2] = reps.C4;
            value[3] = reps.C5;
            signChange0 = GetSignChanges(4, value);

			value[0] = QRational(1);
            value[1] = reps.C3;
            value[2] = reps.C5;
            signChangePI = GetSignChanges(3, value);
        }
        else
        {
            value[0] = -reps.C0;
            value[1] = reps.C1;
            value[2] = reps.C4;
            signChange0 = GetSignChanges(3, value);

			value[0] = QRational(1);
            value[1] = reps.C4;
            signChangePI = GetSignChanges(2, value);
            signChangeMI = 1 + signChangePI;
        }

        positiveRoots = signChange0 - signChangePI;
        MATHEMATICS_ASSERTION_0(positiveRoots >= 0, "Unexpected condition\n");
        negativeRoots = signChangeMI - signChange0;
        MATHEMATICS_ASSERTION_0(negativeRoots >= 0, "Unexpected condition\n");
        zeroRoots = 0;

        distinctNonzeroRoots = positiveRoots + negativeRoots;
        if (distinctNonzeroRoots == 2)
        {
            if (positiveRoots == 2)
            {
                positiveRoots = 3;
            }
            else if (negativeRoots == 2)
            {
                negativeRoots = 3;
            }
            else
            {
                // One root is positive and one is negative.  One root has
                // multiplicity 2, the other of multiplicity 1.  Distinguish
                // between the two cases by computing the sign of the
                // polynomial at the inflection point L = c2/3.
                QRational X = QRational(1,3)*reps.C2;
                QRational poly = X*(X*(X-reps.C2)+reps.C1)-reps.C0;
				if (poly > QRational(0))
                {
                    positiveRoots = 2;
                }
                else
                {
                    negativeRoots = 2;
                }
            }
        }
        else if (distinctNonzeroRoots == 1)
        {
            // Root of multiplicity 3.
            if (positiveRoots == 1)
            {
                positiveRoots = 3;
            }
            else
            {
                negativeRoots = 3;
            }
        }

        return;
    }

	if (reps.C1 != QRational(0))
    {
        reps.C3 = QRational(1,4)*reps.C2*reps.C2 - reps.C1;

		value[0] = QRational(- 1);
        value[1] = reps.C3;
        signChangeMI = 1 + GetSignChanges(2,value);

        value[0] = reps.C1;
        value[1] = -reps.C2;
        value[2] = reps.C3;
        signChange0 = GetSignChanges(3,value);

		value[0] = QRational(1);
        value[1] = reps.C3;
        signChangePI = GetSignChanges(2,value);

        positiveRoots = signChange0 - signChangePI;
        MATHEMATICS_ASSERTION_0(positiveRoots >= 0, "Unexpected condition\n");
        negativeRoots = signChangeMI - signChange0;
        MATHEMATICS_ASSERTION_0(negativeRoots >= 0, "Unexpected condition\n");
        zeroRoots = 1;

        distinctNonzeroRoots = positiveRoots + negativeRoots;
        if (distinctNonzeroRoots == 1)
        {
            positiveRoots = 2;
        }

        return;
    }

	if (reps.C2 != QRational(0))
    {
        zeroRoots = 2;
		if (reps.C2 > QRational(0))
        {
            positiveRoots = 1;
            negativeRoots = 0;
        }
        else
        {
            positiveRoots = 0;
            negativeRoots = 1;
        }
        return;
    }

    positiveRoots = 0;
    negativeRoots = 0;
    zeroRoots = 3;
}

template <typename Real>
int QuadricSurface<Real>::GetSignChanges (int quantity,const QRational* value)
{
    int signChanges = 0;
    QRational zero(0);

    QRational prev = value[0];
    for (int i = 1; i < quantity; ++i)
    {
        QRational next = value[i];
        if (next != zero)
        {
            if (prev*next < zero)
            {
                ++signChanges;
            }

            prev = next;
        }
    }

    return signChanges;
}

template <typename Real>
int QuadricSurface<Real>::ClassifyZeroRoots0 (const RReps& reps, int positiveRoots)
{
    // The inverse matrix is
    // +-                      -+
    // |  Sub00  -Sub01   Sub02 |
    // | -Sub01   Sub11  -Sub12 | * (1/det)
    // |  Sub02  -Sub12   Sub22 |
    // +-                      -+
    QRational fourDet = QRational(4)*reps.C0;

    QRational qForm = reps.B0*(reps.Sub00*reps.B0 -reps.Sub01*reps.B1 + reps.Sub02*reps.B2) - reps.B1*(reps.Sub01*reps.B0 - reps.Sub11*reps.B1 +
					  reps.Sub12*reps.B2) + reps.B2*(reps.Sub02*reps.B0 - reps.Sub12*reps.B1 + reps.Sub22*reps.B2);

    QRational r = QRational(1,4)*qForm/fourDet - reps.C;
	if (r > QRational(0))
    {
        if (positiveRoots == 3)
        {
            return QT_ELLIPSOID;
        }
        else if (positiveRoots == 2)
        {
            return QT_HYPERBOLOID_ONE_SHEET;
        }
        else if (positiveRoots == 1)
        {
            return QT_HYPERBOLOID_TWO_SHEETS;
        }
        else
        {
            return QT_NONE;
        }
    }
	else if (r < QRational(0))
    {
        if (positiveRoots == 3)
        {
            return QT_NONE;
        }
        else if (positiveRoots == 2)
        {
            return QT_HYPERBOLOID_TWO_SHEETS;
        }
        else if (positiveRoots == 1)
        {
            return QT_HYPERBOLOID_ONE_SHEET;
        }
        else
        {
            return QT_ELLIPSOID;
        }
    }

    // else Real == 0
    if (positiveRoots == 3 || positiveRoots == 0)
    {
        return QT_POINT;
    }

    return QT_ELLIPTIC_CONE;
}

template <typename Real>
int QuadricSurface<Real>::ClassifyZeroRoots1 (const RReps& reps,int positiveRoots)
{
    // Generate an orthonormal set {p0,p1,p2}, where p0 is an eigenvector
    // of A corresponding to eigenvalue zero.
    QSVector P0, P1, P2;

	if (reps.Sub00 != QRational(0) || reps.Sub01 != QRational(0) || reps.Sub02 != QRational(0))
    {
        // Rows 1 and 2 are linearly independent.
        P0 = QSVector(reps.Sub00, -reps.Sub01, reps.Sub02);
        P1 = QSVector(reps.A01, reps.A11, reps.A12);
		P2 = Cross(P0, P1);
        return ClassifyZeroRoots1(reps, positiveRoots, P0, P1, P2);
    }

	if (reps.Sub01 != QRational(0) || reps.Sub11 != QRational(0) || reps.Sub12 != QRational(0))
    {
        // Rows 2 and 0 are linearly independent.
        P0 = QSVector(-reps.Sub01, reps.Sub11, -reps.Sub12);
        P1 = QSVector(reps.A02, reps.A12, reps.A22);
		P2 = Cross(P0,P1);
        return ClassifyZeroRoots1(reps, positiveRoots, P0, P1, P2);
    }

    // Rows 0 and 1 are linearly independent.
    P0 = QSVector(reps.Sub02, -reps.Sub12, reps.Sub22);
    P1 = QSVector(reps.A00, reps.A01, reps.A02);
	P2 = Cross(P0,P1);
    return ClassifyZeroRoots1(reps, positiveRoots, P0, P1, P2);
}

template <typename Real>
int QuadricSurface<Real>::ClassifyZeroRoots1 (const RReps& reps, int positiveRoots, const QSVector& P0, const QSVector& P1,const QSVector& P2)
{
	QRational E0 = P0.GetX()*reps.B0 + P0.GetY()*reps.B1 +P0.GetZ()*reps.B2;

	if (E0 != QRational(0))
    {
        if (positiveRoots == 1)
        {
            return QT_HYPERBOLIC_PARABOLOID;
        }
        else
        {
            return QT_ELLIPTIC_PARABOLOID;
        }
    }

    // Matrix F.
	QRational F11 = P1.GetX()*(reps.A00*P1.GetX() + reps.A01*P1.GetY() +
					reps.A02*P1.GetZ()) + P1.GetY()*(reps.A01*P1.GetX() +
					reps.A11*P1.GetY() + reps.A12*P1.GetZ()) + P1.GetZ()*(
					reps.A02*P1.GetX() + reps.A12*P1.GetY() + reps.A22*P1.GetZ());

	QRational F12 = P2.GetX()*(reps.A00*P1.GetX() + reps.A01*P1.GetY() +
					reps.A02*P1.GetZ()) + P2.GetY()*(reps.A01*P1.GetX() +
					reps.A11*P1.GetY() + reps.A12*P1.GetZ()) + P2.GetZ()*(
					reps.A02*P1.GetX() + reps.A12*P1.GetY() + reps.A22*P1.GetZ());

	QRational F22 = P2.GetX()*(reps.A00*P2.GetX() + reps.A01*P2.GetY() +
					reps.A02*P2.GetZ()) + P2.GetY()*(reps.A01*P2.GetX() +
					reps.A11*P2.GetY() + reps.A12*P2.GetZ()) + P2.GetZ()*(
					reps.A02*P2.GetX() + reps.A12*P2.GetY() + reps.A22*P2.GetZ());

    // Vector g.
	QRational G1 = P1.GetX()*reps.B0 + P1.GetY()*reps.B1 + P1.GetZ()*reps.B2;
	QRational G2 = P2.GetX()*reps.B0 + P2.GetY()*reps.B1 + P2.GetZ()*reps.B2;

    // Compute g^T*F^{-1}*g/4 - c.
    QRational fourDet = QRational(4)*(F11*F22 - F12*F12);
    QRational r = (G1*(F22*G1-F12*G2)+G2*(F11*G2-F12*G1))/fourDet - reps.C;

	if (r > QRational(0))
    {
        if (positiveRoots == 2)
        {
            return QT_ELLIPTIC_CYLINDER;
        }
        else if (positiveRoots == 1)
        {
            return QT_HYPERBOLIC_CYLINDER;
        }
        else
        {
            return QT_NONE;
        }
    }
	else if (r < QRational(0))
    {
        if (positiveRoots == 2)
        {
            return QT_NONE;
        }
        else if (positiveRoots == 1)
        {
            return QT_HYPERBOLIC_CYLINDER;
        }
        else
        {
            return QT_ELLIPTIC_CYLINDER;
        }
    }

    // else Real == 0
    return (positiveRoots == 1 ? QT_TWO_PLANES : QT_LINE);
}

template <typename Real>
int QuadricSurface<Real>::ClassifyZeroRoots2 (const RReps& reps, int positiveRoots)
{
    // Generate an orthonormal set {p0,p1,p2}, where p0 and p1 are
    // eigenvectors of A corresponding to eigenvalue zero.  The vector p2 is
    // an eigenvector of A corresponding to eigenvalue c2.
    QSVector P0, P1, P2;

	if (reps.A00 != QRational(0) || reps.A01 != QRational(0) || reps.A02 != QRational(0))
    {
        // row 0 is not zero
        P2 = QSVector(reps.A00,reps.A01,reps.A02);
    }
	else if (reps.A01 != QRational(0) || reps.A11 != QRational(0) || reps.A12 != QRational(0))
    {
        // row 1 is not zero
        P2 = QSVector(reps.A01,reps.A11,reps.A12);
    }
    else
    {
        // row 2 is not zero
        P2 = QSVector(reps.A02,reps.A12,reps.A22);
    }

	if (P2.GetX() != QRational(0))
    {
		P1.SetX( P2.GetY());
		P1.SetY(-P2.GetX());
		P1.SetZ(QRational(0));
    }
    else
    {
		P1.SetX(QRational(0));
		P1.SetY( P2.GetZ());
		P1.SetZ( -P2.GetY());
    }
	P0 = Cross(P1,P2);

    return ClassifyZeroRoots2(reps, positiveRoots, P0, P1, P2);
}

template <typename Real>
int QuadricSurface<Real>::ClassifyZeroRoots2 (const RReps& reps, int positiveRoots, const QSVector& P0, const QSVector& P1, const QSVector& P2)
{
	QRational E0 = P0.GetX()*reps.B0 + P0.GetY()*reps.B1 + P0.GetZ()*reps.B1;
	if (E0 != QRational(0))
    {
        return QT_PARABOLIC_CYLINDER;
    }

	QRational E1 = P1.GetX()*reps.B0 + P1.GetY()*reps.B1 + P1.GetZ()*reps.B1;
	if (E1 != QRational(0))
    {
        return QT_PARABOLIC_CYLINDER;
    }

	QRational F1 = reps.C2*(Dot(P2,P2));
	QRational E2 = P2.GetX()*reps.B0 + P2.GetY()*reps.B1 + P2.GetZ()*reps.B1;
    QRational r = E2*E2/(QRational(4)*F1) - reps.C;
	if (r > QRational(0))
    {
        if (positiveRoots == 1)
        {
            return QT_TWO_PLANES;
        }
        else
        {
            return QT_NONE;
        }
    }
	else if (r < QRational(0))
    {
        if (positiveRoots == 1)
        {
            return QT_NONE;
        }
        else
        {
            return QT_TWO_PLANES;
        }
    }

    // else Real == 0
    return QT_PLANE;
}

template <typename Real>
int QuadricSurface<Real>::ClassifyZeroRoots3 (const RReps& reps)
{
	if (reps.B0 != QRational(0) || reps.B1 != QRational(0) || reps.B2 != QRational(0))
    {
        return QT_PLANE;
    }

    return QT_NONE;
}

template <typename Real>
QuadricSurface<Real>::RReps::RReps (const Real coeff[10])
{
    QRational oneHalf(1,2);

    C = QRational(coeff[0]);
    B0 = QRational(coeff[1]);
    B1 = QRational(coeff[2]);
    B2 = QRational(coeff[3]);
    A00 = QRational(coeff[4]);
    A01 = oneHalf*QRational(coeff[5]);
    A02 = oneHalf*QRational(coeff[6]);
    A11 = QRational(coeff[7]);
    A12 = oneHalf*QRational(coeff[8]);
    A22 = QRational(coeff[9]);

    Sub00 = A11*A22 - A12*A12;
    Sub01 = A01*A22 - A12*A02;
    Sub02 = A01*A12 - A02*A11;
    Sub11 = A00*A22 - A02*A02;
    Sub12 = A00*A12 - A02*A01;
    Sub22 = A00*A11 - A01*A01;
    C0 = A00*Sub00 - A01*Sub01 + A02*Sub02;
    C1 = Sub00 + Sub11 + Sub22;
    C2 = A00 + A11 + A22;
}

 

}

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_QUADRIC_SURFACE_DETAIL_H
// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 14:07)

#ifndef MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_ITEM_DETAIL_H
#define MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_ITEM_DETAIL_H

#include "GreatArcFit3Item.h"
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::GreatArcFit3Item<Real>
	::GreatArcFit3Item(const Vector3D& uVector, const Vector3D& vVector, const Vector3D& point)
	:m_UDot{ Vector3DTools<Real>::DotProduct(uVector,point) }, m_VDot{ Vector3DTools<Real>::DotProduct(vVector,point) }, m_Angle{ Math<Real>::ATan2(m_VDot, m_UDot) }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::GreatArcFit3Item<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::GreatArcFit3Item<Real>
	::GetUDot() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_UDot;
}

template <typename Real>
Real Mathematics::GreatArcFit3Item<Real>
	::GetVDot() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_VDot;
}

template <typename Real>
Real Mathematics::GreatArcFit3Item<Real>
	::GetAngle() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Angle;
}

template <typename Real>
bool Mathematics
	::operator<(const GreatArcFit3Item<Real>& lhs, const GreatArcFit3Item<Real>& rhs)
{
	return lhs.GetAngle() < rhs.GetAngle();
}

#endif // MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_ITEM_DETAIL_H
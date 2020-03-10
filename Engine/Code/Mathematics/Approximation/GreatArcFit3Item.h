// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/10 11:11)

#ifndef MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_ITEM_H
#define MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_ITEM_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"

namespace Mathematics
{ 
	template <typename Real>
	class GreatArcFit3Item
	{
	public:		
		using ClassType = GreatArcFit3Item<Real>;
		using Vector3D = Vector3D<Real>; 

	public:
		explicit GreatArcFit3Item(const Vector3D& uVector, const Vector3D& vVector,const Vector3D& point);

		CLASS_INVARIANT_DECLARE;

		Real GetUDot() const;
		Real GetVDot() const;
		Real GetAngle() const;

	private:
		Real m_UDot;
		Real m_VDot;
		Real m_Angle;       
    };

	// ÷ß≥÷≈≈–Ú°£
	template <typename Real>
	bool operator< (const GreatArcFit3Item<Real>& lhs, const GreatArcFit3Item<Real>& rhs);
}

#endif // MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_ITEM_H

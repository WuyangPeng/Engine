// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 16:59)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTOR_CONFIGURATION_DETAIL_H
#define MATHEMATICS_INTERSECTION_INTERSECTOR_CONFIGURATION_DETAIL_H

#include "IntersectorConfiguration.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_INTERSECTOR_CONFIGURATION_DETAIL) 

template <typename Real>
Mathematics::IntersectorConfiguration<Real>
	::IntersectorConfiguration()
	:mMap{}, mIndex{}, mMin{}, mMax{}
{

}

#endif // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_INTERSECTOR_CONFIGURATION_DETAIL)

#endif // MATHEMATICS_INTERSECTION_INTERSECTOR_CONFIGURATION_DETAIL_H
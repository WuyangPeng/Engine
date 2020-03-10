// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/11 14:18)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

#ifndef MATHEMATICS_INCLUDED_INTERSECTOR_AXIS_DETAIL
	#define MATHEMATICS_INCLUDED_INTERSECTOR_AXIS_DETAIL
#endif // MATHEMATICS_INCLUDED_INTERSECTOR_AXIS_DETAIL

#include "IntersectorAxisDetail.h"

namespace Mathematics
{
	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	class IntersectorAxis<float>;	
	
	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	class IntersectorAxis<double>; 
}

#endif // MATHEMATICS_EXPORT_TEMPLATE
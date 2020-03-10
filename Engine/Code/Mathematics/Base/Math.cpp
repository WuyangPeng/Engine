// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 19:42)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

#ifndef MATHEMATICS_INCLUDED_MATH_DETAIL
	#define MATHEMATICS_INCLUDED_MATH_DETAIL
#endif // MATHEMATICS_INCLUDED_MATH_DETAIL

#include "MathDetail.h" 

namespace Mathematics
{
	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	class Math<float>;

	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	class Math<double>;
}

#endif // MATHEMATICS_EXPORT_TEMPLATE



 
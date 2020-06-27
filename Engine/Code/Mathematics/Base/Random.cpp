// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 09:43)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

#ifndef MATHEMATICS_INCLUDED_RANDOM_DETAIL
	#define MATHEMATICS_INCLUDED_RANDOM_DETAIL
#endif // MATHEMATICS_INCLUDED_RANDOM_DETAIL

#include "RandomDetail.h" 

namespace Mathematics
{
	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	class Random<float>;

	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	class Random<double>;
}

#endif // MATHEMATICS_EXPORT_TEMPLATE




// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 11:14)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

#ifndef MATHEMATICS_INCLUDED_AQUATERNION_DETAIL
	#define MATHEMATICS_INCLUDED_AQUATERNION_DETAIL
#endif // MATHEMATICS_INCLUDED_AQUATERNION_DETAIL

#include "AQuaternionDetail.h" 
#include "AVectorDetail.h"
#include "MatrixDetail.h"

namespace Mathematics
{
	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	class AQuaternion<float>;

	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	class AQuaternion<double>;
}

#endif // MATHEMATICS_EXPORT_TEMPLATE




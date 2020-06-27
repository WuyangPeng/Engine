// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 11:19)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

#ifndef MATHEMATICS_INCLUDED_VECTOR4D_TOOLS_DETAIL
	#define MATHEMATICS_INCLUDED_VECTOR4D_TOOLS_DETAIL
#endif // MATHEMATICS_INCLUDED_VECTOR4D_TOOLS_DETAIL

#include "Vector4DDetail.h"  
#include "Vector4DToolsDetail.h"  
#include "AxesAlignBoundingBox4DDetail.h"

namespace Mathematics
{
	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	class Vector4DTools<float>;

	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	class Vector4DTools<double>;
}

#endif // MATHEMATICS_EXPORT_TEMPLATE




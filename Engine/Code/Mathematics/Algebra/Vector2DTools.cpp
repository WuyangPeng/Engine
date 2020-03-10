// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/04 14:26)

#include "Mathematics/MathematicsExport.h"
 
#ifdef MATHEMATICS_EXPORT_TEMPLATE

#ifndef MATHEMATICS_INCLUDED_VECTOR2D_TOOLS_DETAIL
	#define MATHEMATICS_INCLUDED_VECTOR2D_TOOLS_DETAIL
#endif // MATHEMATICS_INCLUDED_VECTOR2D_TOOLS_DETAIL

#include "Vector2DDetail.h"  
#include "Vector2DToolsDetail.h"  
#include "AxesAlignBoundingBox2DDetail.h"

namespace Mathematics
{
	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	class Vector2DTools<float>;

	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	class Vector2DTools<double>;
}

#endif // MATHEMATICS_EXPORT_TEMPLATE
 


 
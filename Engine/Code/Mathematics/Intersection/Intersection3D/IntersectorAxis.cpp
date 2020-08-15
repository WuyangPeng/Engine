// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 15:00)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

#ifndef MATHEMATICS_INCLUDED_INTERSECTOR_AXIS_DETAIL
	#define MATHEMATICS_INCLUDED_INTERSECTOR_AXIS_DETAIL
#endif // MATHEMATICS_INCLUDED_INTERSECTOR_AXIS_DETAIL
    #include "System/Helper/PragmaWarning.h"
    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26446)
    #include "IntersectorAxisDetail.h"
 
namespace Mathematics
{
	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	class IntersectorAxis<float>;	
	
	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	class IntersectorAxis<double>; 
}
#include STSTEM_WARNING_POP
#endif // MATHEMATICS_EXPORT_TEMPLATE
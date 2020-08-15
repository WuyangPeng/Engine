// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 11:18)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

#ifndef MATHEMATICS_INCLUDED_QUATERNION_DETAIL
	#define MATHEMATICS_INCLUDED_QUATERNION_DETAIL
#endif // MATHEMATICS_INCLUDED_QUATERNION_DETAIL

#include "QuaternionDetail.h" 
#include "Matrix3Detail.h"
#include "Vector3DDetail.h"
#include "Vector3DToolsDetail.h"
#include "QuaternionFactorDetail.h"
 #include "System/Helper/PragmaWarning.h"
    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26446)
    #include SYSTEM_WARNING_DISABLE(26482)
namespace Mathematics
{
	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	class Quaternion<float>;

	template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE
	class Quaternion<double>;
}
#include STSTEM_WARNING_POP
#endif // MATHEMATICS_EXPORT_TEMPLATE




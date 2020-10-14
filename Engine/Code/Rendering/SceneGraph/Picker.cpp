// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/22 17:54)

#include "Rendering/RenderingExport.h"

#include "Picker.h"
#include "PickRecord.h"
#include "Detail/PickerImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;

DELAY_COPY_CONSTRUCTION_DEFINE(Rendering, Picker)

Rendering::Picker
	::Picker(const ConstSpatialSharedPtr& scene, const APoint& origin, const AVector& direction, float tMin, float tMax) 
	:m_Impl{ make_shared<ImplType>(scene,origin,direction,tMin,tMax) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Rendering, Picker)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Picker,IsRecordsExist, bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Picker,GetClosestToZero, const Rendering::PickRecord)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Picker,GetClosestNonnegative, const Rendering::PickRecord)		
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Picker,GetClosestNonpositive, const Rendering::PickRecord)								
 
  

 
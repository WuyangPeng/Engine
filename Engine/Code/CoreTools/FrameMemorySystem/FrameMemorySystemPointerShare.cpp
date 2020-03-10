// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:19)

#include "CoreTools/CoreToolsExport.h"

#include "FrameMemorySystemPointerShare.h"
#include "Detail/FrameMemorySystemPointerShareImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;

CoreTools::FrameMemorySystemPointerShare
	::FrameMemorySystemPointerShare(uint8_t* ptr, int size, uint8_t*& lowerFramePointer, uint8_t*& upperFramePointer, FrameMemorySystemHeap type)
	:m_Impl{ make_shared<ImplType>(ptr,size,lowerFramePointer,upperFramePointer,type) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, FrameMemorySystemPointerShare)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, FrameMemorySystemPointerShare, GetFramePointer, uint8_t*)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, FrameMemorySystemPointerShare, GetFramePointer, const uint8_t*)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, FrameMemorySystemPointerShare, GetPtrSize, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, FrameMemorySystemPointerShare, GetFrameMemorySystemHeapType, CoreTools::FrameMemorySystemHeap)
// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:18)

#include "CoreTools/CoreToolsExport.h"

#include "BaseFrameMemorySystem.h"
#include "Detail/BaseFrameMemorySystemImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;

CoreTools::BaseFrameMemorySystem
	::BaseFrameMemorySystem(int sizeInBytes, int byteAlignment)
	:m_Impl{ make_shared<ImplType>(sizeInBytes,byteAlignment) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, BaseFrameMemorySystem)

const CoreTools::FrameMemorySystemPointerShare CoreTools::BaseFrameMemorySystem
	::AllocFrameMemory(int bytes, FrameMemorySystemHeap heapType)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->AllocFrameMemory(bytes, heapType);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, BaseFrameMemorySystem, ReleaseFrame, FrameMemorySystemPointerShare, void)



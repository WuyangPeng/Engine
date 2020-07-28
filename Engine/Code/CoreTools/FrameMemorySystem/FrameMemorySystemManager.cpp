// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:18)

#include "CoreTools/CoreToolsExport.h"

#include "BaseFrameMemorySystem.h"
#include "FrameMemorySystemManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "System/Helper/PragmaWarning.h"
CoreTools::FrameMemorySystemManager
	::FrameMemorySystemManager(BaseFrameMemorySystem& frameMemorySystem, int bytes, FrameMemorySystemHeap heapType)
	:m_FrameMemorySystem{ frameMemorySystem }, m_Pointer{ m_FrameMemorySystem.AllocFrameMemory(bytes,heapType) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::FrameMemorySystemManager
	::~FrameMemorySystemManager() noexcept
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;

	EXCEPTION_TRY
	{
		
#include STSTEM_WARNING_PUSH
		#include SYSTEM_WARNING_DISABLE(26447)
		m_FrameMemorySystem.ReleaseFrame(m_Pointer);
	#include STSTEM_WARNING_POP
	}
	EXCEPTION_ALL_CATCH(CoreTools)	
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, FrameMemorySystemManager)

const CoreTools::FrameMemorySystemPointerShare CoreTools::FrameMemorySystemManager
	::GetFrameMemorySystemPointer() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Pointer;
}

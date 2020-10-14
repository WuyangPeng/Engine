// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 15:50)

#include "CoreTools/CoreToolsExport.h"

#include "BufferInStream.h"
#include "Detail/BufferInStreamImpl.h" 
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h" 

using std::make_shared;

CoreTools::BufferInStream ::BufferInStream(const ConstFileBufferSharedPtr& bufferInformation, int startPoint)
    : m_Impl{ make_shared<ImplType>(bufferInformation, startPoint) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, BufferInStream)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, BufferInStream, GetTopLevel, const CoreTools::InTopLevel)



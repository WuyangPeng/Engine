///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/24 23:06)

#include "CoreTools/CoreToolsExport.h"

#include "BufferInStream.h"
#include "Detail/BufferInStreamImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::BufferInStream::BufferInStream(const ConstFileBufferSharedPtr& bufferInformation, int startPoint)
    : impl{ bufferInformation, startPoint }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, BufferInStream)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, BufferInStream, GetTopLevel, const CoreTools::InTopLevel)

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 15:36)

#include "CoreTools/CoreToolsExport.h"

#include "BufferInStream.h"
#include "Detail/BufferInStreamImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::BufferInStream::BufferInStream(const ConstFileBufferSharedPtr& bufferInformation, int startPoint)
    : impl{ bufferInformation, startPoint }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, BufferInStream)

CoreTools::InTopLevel CoreTools::BufferInStream::GetTopLevel() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetTopLevel();
}

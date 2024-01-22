/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 09:58)

#include "CoreTools/CoreToolsExport.h"

#include "BufferOutStream.h"
#include "Detail/BufferOutStreamImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::BufferOutStream::BufferOutStream(const OutTopLevel& topLevel)
    : impl{ topLevel }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, BufferOutStream)

CoreTools::ConstFileBufferSharedPtr CoreTools::BufferOutStream::GetBufferOutStreamInformation() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->GetBufferOutStreamInformation();
}

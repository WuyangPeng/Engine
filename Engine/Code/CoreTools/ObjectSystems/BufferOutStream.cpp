///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/24 23:06)

#include "CoreTools/CoreToolsExport.h"

#include "BufferOutStream.h"
#include "Detail/BufferOutStreamImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::BufferOutStream::BufferOutStream(const OutTopLevel& topLevel)
    : impl{ topLevel }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, BufferOutStream)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, BufferOutStream, GetBufferOutStreamInformation, CoreTools::FileBufferSharedPtr)

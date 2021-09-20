//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/22 14:58)

#include "CoreTools/CoreToolsExport.h"

#include "BufferInStream.h"
#include "Detail/BufferInStreamImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

CoreTools::BufferInStream::BufferInStream(const ConstFileBufferSharedPtr& bufferInformation, int startPoint)
    : impl{  bufferInformation, startPoint  }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, BufferInStream)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, BufferInStream, GetTopLevel, const CoreTools::InTopLevel)

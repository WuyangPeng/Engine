//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/22 14:59)

#include "CoreTools/CoreToolsExport.h"

#include "BufferOutStream.h"
#include "Detail/BufferOutStreamImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

CoreTools::BufferOutStream::BufferOutStream(const OutTopLevel& topLevel)
    : m_Impl{ make_shared<ImplType>(topLevel) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, BufferOutStream)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, BufferOutStream, GetBufferOutStreamInformation, CoreTools::FileBufferSharedPtr)

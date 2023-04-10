///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/03 17:42)

#include "CoreTools/CoreToolsExport.h"

#include "OStreamShared.h"
#include "Detail/OStreamImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::OStreamShared::OStreamShared(bool isCout)
    : impl{ isCout }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::OStreamShared::OStreamShared(const std::string& fileName)
    : impl{ fileName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, OStreamShared)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, OStreamShared, GetStream, std::ostream&)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, OStreamShared, IsCout, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, OStreamShared, IsCerr, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, OStreamShared, IsFile, bool)

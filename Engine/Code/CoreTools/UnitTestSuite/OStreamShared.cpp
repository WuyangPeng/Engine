///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/14 21:36)

#include "CoreTools/CoreToolsExport.h"

#include "OStreamShared.h"
#include "Detail/OStreamImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;
using std::ostream;
using std::string;

CoreTools::OStreamShared::OStreamShared(bool isCout)
    : impl{ isCout }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::OStreamShared::OStreamShared(const string& fileName)
    : impl{ fileName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, OStreamShared)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, OStreamShared, GetStream, ostream&)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, OStreamShared, IsCout, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, OStreamShared, IsCerr, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, OStreamShared, IsFile, bool)

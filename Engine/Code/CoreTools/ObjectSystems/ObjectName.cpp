//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/22 16:40)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectName.h"
#include "Detail/ObjectNameImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;
using std::string;

CoreTools::ObjectName::ObjectName(const string& name)
    : impl{ make_shared<ImplType>(name) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::ObjectName::ObjectName(const ObjectName& rhs)
    : impl{ std::make_shared<ImplType>(*rhs.impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}
CoreTools::ObjectName& CoreTools::ObjectName::operator=(const ObjectName& rhs)
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
    ObjectName temp{ rhs };
    Swap(temp);
    return *this;
}
void CoreTools::ObjectName::Swap(ObjectName& rhs) noexcept
{
    
    std::swap(impl, rhs.impl);
}
CoreTools::ObjectName::ObjectName(ObjectName&& rhs) noexcept
    : impl{ std::move(rhs.impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}
CoreTools::ObjectName& CoreTools::ObjectName::operator=(ObjectName&& rhs) noexcept
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
    impl = std::move(rhs.impl);
    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ObjectName)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, ObjectName, GetName, string)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, ObjectName, SetName, string, void)

bool CoreTools::ObjectName::IsExactly(const ObjectName& name) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->IsExactly(*name.impl);
}

void CoreTools::ObjectName::SwapObjectName(ObjectName& name) noexcept
{
    

    Swap(name);
}

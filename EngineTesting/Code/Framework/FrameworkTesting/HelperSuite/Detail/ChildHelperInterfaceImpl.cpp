///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/27 11:04) 

#include "ChildHelperInterfaceImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::const_pointer_cast;

Framework::ChildHelperInterfaceImpl::ChildHelperInterfaceImpl(int containerSize)
    : container(containerSize)
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, ChildHelperInterfaceImpl)

Framework::MiddleLayerInterfaceSharedPtr Framework::ChildHelperInterfaceImpl::GetMiddleLayerInterface(int index)
{
    FRAMEWORK_CLASS_IS_VALID_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26473)

    return const_pointer_cast<MiddleLayerInterface>(static_cast<const ClassType*>(this)->GetMiddleLayerInterface(index));

#include STSTEM_WARNING_POP
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::ChildHelperInterfaceImpl::GetMiddleLayerInterface(int index) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return container.at(index).lock();
}

void Framework::ChildHelperInterfaceImpl::SetMiddleLayerInterface(int index, const MiddleLayerInterfaceSharedPtr& middleLayer)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    container.at(index) = middleLayer;
}

int Framework::ChildHelperInterfaceImpl::GetSize() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(container.size());
}

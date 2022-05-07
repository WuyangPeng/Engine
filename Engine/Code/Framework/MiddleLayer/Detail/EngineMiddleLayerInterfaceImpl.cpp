///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 11:13)

#include "Framework/FrameworkExport.h"

#include "EngineMiddleLayerInterfaceImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::const_pointer_cast;

Framework::EngineMiddleLayerInterfaceImpl::EngineMiddleLayerInterfaceImpl(int containerSize)
    : container(containerSize)
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, EngineMiddleLayerInterfaceImpl)

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceImpl::GetMiddleLayerInterface(int index)
{
    FRAMEWORK_CLASS_IS_VALID_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26473)

    return const_pointer_cast<MiddleLayerInterface>(static_cast<const ClassType*>(this)->GetMiddleLayerInterface(index));

#include STSTEM_WARNING_POP
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceImpl::GetMiddleLayerInterface(int index) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return container.at(index).lock();
}

void Framework::EngineMiddleLayerInterfaceImpl::SetMiddleLayerInterface(int index, const MiddleLayerInterfaceSharedPtr& middleLayer)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    container.at(index) = middleLayer;
}

int Framework::EngineMiddleLayerInterfaceImpl::GetSize() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(container.size());
}

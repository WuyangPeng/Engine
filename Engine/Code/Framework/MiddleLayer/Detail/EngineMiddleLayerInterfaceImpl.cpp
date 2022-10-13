///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.2 (2022/08/31 17:21)

#include "Framework/FrameworkExport.h"

#include "EngineMiddleLayerInterfaceImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Framework::EngineMiddleLayerInterfaceImpl::EngineMiddleLayerInterfaceImpl(int containerSize)
    : container(containerSize)
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, EngineMiddleLayerInterfaceImpl)

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceImpl::GetMiddleLayerInterface(int index)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return std::const_pointer_cast<MiddleLayerInterface>(static_cast<const ClassType&>(*this).GetMiddleLayerInterface(index));
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceImpl::GetMiddleLayerInterface(int index) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    auto result = container.at(index).lock();

    if (result == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("���ص�middleLayerΪ��ָ�롣"s));
    }

    return result;
}

void Framework::EngineMiddleLayerInterfaceImpl::SetMiddleLayerInterface(int index, const MiddleLayerInterfaceSharedPtr& middleLayer)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (middleLayer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("middleLayerΪ��ָ�롣"s));
    }

    container.at(index) = middleLayer;
}

int Framework::EngineMiddleLayerInterfaceImpl::GetSize() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(container.size());
}

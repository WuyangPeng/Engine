///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/25 20:13)

#ifndef CORE_TOOLS_MESSAGE_EVENT_CALLBACK_PARAMETERS_DETAIL_H
#define CORE_TOOLS_MESSAGE_EVENT_CALLBACK_PARAMETERS_DETAIL_H

#include "CallbackParameters.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename ConstSubclass>
std::shared_ptr<const ConstSubclass> CoreTools::CallbackParameters::GetParametersInterfacePolymorphicDowncast(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return boost::polymorphic_pointer_downcast<ConstSubclass>(GetParametersInterfaceValue(index));
}

template <typename ConstSubclass>
std::shared_ptr<const ConstSubclass> CoreTools::CallbackParameters::GetParametersInterfacePolymorphicCast(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return boost::polymorphic_pointer_cast<ConstSubclass>(GetParametersInterfaceValue(index));
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_CALLBACK_PARAMETERS_DETAIL_H

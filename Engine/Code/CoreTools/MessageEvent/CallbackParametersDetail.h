/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 09:47)

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

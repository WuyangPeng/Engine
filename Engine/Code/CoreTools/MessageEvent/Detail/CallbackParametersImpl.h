///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/26 12:57)

#ifndef CORE_TOOLS_MESSAGE_EVENT_CALLBACK_PARAMETERS_IMPL_H
#define CORE_TOOLS_MESSAGE_EVENT_CALLBACK_PARAMETERS_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/Any.h"

#include <any>
#include <vector>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CallbackParametersImpl final
    {
    public:
        using ClassType = CallbackParametersImpl;

    public:
        explicit CallbackParametersImpl(int count);

        CLASS_INVARIANT_DECLARE;

        template <typename T>
        void SetValue(int index, T&& value);

        template <typename T>
        NODISCARD T GetValue(int index) const;

        NODISCARD int GetContainerSize() const;

    private:
        using Container = std::vector<std::any>;

    private:
        Container container;
    };
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_CALLBACK_PARAMETERS_IMPL_H

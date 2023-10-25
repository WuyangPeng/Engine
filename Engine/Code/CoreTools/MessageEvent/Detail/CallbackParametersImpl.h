///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:24)

#ifndef CORE_TOOLS_MESSAGE_EVENT_CALLBACK_PARAMETERS_IMPL_H
#define CORE_TOOLS_MESSAGE_EVENT_CALLBACK_PARAMETERS_IMPL_H

#include "CoreTools/CoreToolsDll.h"

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

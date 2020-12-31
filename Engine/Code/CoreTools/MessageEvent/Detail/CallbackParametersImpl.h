//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/26 15:13)

#ifndef CORE_TOOLS_MESSAGE_EVENT_CALLBACK_PARAMETERS_IMPL_H
#define CORE_TOOLS_MESSAGE_EVENT_CALLBACK_PARAMETERS_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/Any.h"

#include <boost/call_traits.hpp>
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
        void SetValue(int index, typename boost::call_traits<T>::param_type value);

        template <typename T>
        [[nodiscard]] const T GetValue(int index);

        [[nodiscard]] int GetContainerSize() const;

    private:
        using Container = std::vector<boost::any>;

    private:
        Container m_Container;
    };
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_CALLBACK_PARAMETERS_IMPL_H

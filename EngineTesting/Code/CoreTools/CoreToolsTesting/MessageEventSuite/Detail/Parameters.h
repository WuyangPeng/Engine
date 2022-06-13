///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 16:02)

#ifndef CORE_TOOLS_MESSAGE_EVENT_SUITE_PARAMETERS_H
#define CORE_TOOLS_MESSAGE_EVENT_SUITE_PARAMETERS_H

#include "CoreTools/MessageEvent/ParametersInterface.h"

namespace CoreTools
{
    class Parameters : public ParametersInterface
    {
    public:
        using ClassType = Parameters;
        using ParentType = ParametersInterface;
        using ParametersSharedPtr = std::shared_ptr<Parameters>;

    public:
        NODISCARD static ParametersSharedPtr Create(int value);

        explicit Parameters(int value) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetValue() const noexcept;
        void SetValue(int aValue) noexcept;

        NODISCARD BaseSharedPtr Clone() const override;

        NODISCARD ParametersSharedPtr CloneClassType() const;

    private:
        int value;
    };

    using ParametersSharedPtr = std::shared_ptr<Parameters>;
    using ConstParametersSharedPtr = std::shared_ptr<const Parameters>;
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_SUITE_PARAMETERS_H
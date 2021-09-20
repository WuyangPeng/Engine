// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:58)

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
        explicit Parameters(int value) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        int GetValue() const noexcept;
        void SetValue(int Value) noexcept;

        const BaseSharedPtr Clone() const override;

        const ParametersSharedPtr CloneClassType() const;

    private:
        int m_Value;
    };

    using ParametersSharedPtr = std::shared_ptr<Parameters>;
    using ConstParametersSharedPtr = std::shared_ptr<const Parameters>;
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_SUITE_PARAMETERS_H
// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:39)

#ifndef CORE_TOOLS_PROPERTIES_SUITE_PROPERTY_BASE_H
#define CORE_TOOLS_PROPERTIES_SUITE_PROPERTY_BASE_H

#include "CoreTools/Helper/UserMacro.h"
#include "CoreTools/Properties/PropertyDetail.h"

namespace CoreTools
{
    class PropertiesBase
    {
    public:
        using ClassType = PropertiesBase;

    public:
        PropertiesBase() noexcept;

        CLASS_INVARIANT_DECLARE;

    private:
        int GetFifthValue() const noexcept;
        void SetFifthValue(int value) noexcept;

    public:
        class PropFifthValue
        {
        };

        CoreTools::Property<PropFifthValue, ClassType, int, int, &ClassType::SetFifthValue, &ClassType::GetFifthValue> FifthValue;

    private:
        int m_FifthValue;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_SUITE_PROPERTY_BASE_H
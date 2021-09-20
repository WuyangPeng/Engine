// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:40)

#ifndef CORE_TOOLS_PROPERTIES_SUITE_PROPERTY_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_SUITE_PROPERTY_EXTERNAL_H

#include "CoreTools/Helper/UserMacro.h"
#include "CoreTools/Properties/PropertyGetExternalOffsetDetail.h"
#include "CoreTools/Properties/PropertyGetInternalOffsetDetail.h"

#include <string>

namespace CoreTools
{
#pragma pack(push, 1)
    class PropertyOffset
    {
    public:
        using ClassType = PropertyOffset;

        CLASS_INVARIANT_DECLARE;

        PropertyOffset();

        const std::string& GetInternalValue() const noexcept;

    private:
        static ptrdiff_t GetOffset() noexcept;

        const std::string& GetValue() const noexcept;

        using PropertyGetExternalOffset = PropertyGetExternalOffset<ClassType, const std::string&, &GetValue, GetOffset>;
        using PropertyGetInternalOffset = PropertyGetInternalOffset<ClassType, std::string, const std::string&, &GetValue, GetOffset>;

        PropertyGetInternalOffset m_InternalOffset;

        std::string m_Value;

    public:
        PropertyGetExternalOffset m_Offset;
    };
#pragma pack(pop)
}

#endif  // CORE_TOOLS_PROPERTIES_SUITE_PROPERTY_EXTERNAL_H

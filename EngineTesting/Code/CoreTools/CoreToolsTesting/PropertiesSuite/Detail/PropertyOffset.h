///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:41)

#ifndef CORE_TOOLS_PROPERTIES_SUITE_PROPERTY_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_SUITE_PROPERTY_EXTERNAL_H

#include "CoreTools/Contract/ContractFwd.h"
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

    public:
        CLASS_INVARIANT_DECLARE;

        explicit PropertyOffset(DisableNotThrow disableNotThrow);

        NODISCARD const std::string& GetInternalValue() const noexcept;

    private:
        NODISCARD static ptrdiff_t GetOffset() noexcept;

        NODISCARD const std::string& GetValue() const noexcept;

        using PropertyGetExternalOffset = PropertyGetExternalOffset<ClassType, const std::string&, &GetValue, GetOffset>;
        using PropertyGetInternalOffset = PropertyGetInternalOffset<ClassType, std::string, const std::string&, &GetValue, GetOffset>;

        PropertyGetInternalOffset internalOffset;

        std::string value;

    public:
        PropertyGetExternalOffset offset;
    };

#pragma pack(pop)
}

#endif  // CORE_TOOLS_PROPERTIES_SUITE_PROPERTY_EXTERNAL_H

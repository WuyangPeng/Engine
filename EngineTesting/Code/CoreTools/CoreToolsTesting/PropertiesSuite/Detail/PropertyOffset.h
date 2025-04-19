/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/04/23 12:53)

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

        using PropertyGetExternalOffset = PropertyGetExternalOffset<ClassType, const std::string&, &ClassType::GetValue, GetOffset>;
        using PropertyGetInternalOffset = PropertyGetInternalOffset<ClassType, std::string, const std::string&, &ClassType::GetValue, GetOffset>;

        PropertyGetInternalOffset internalOffset;

        std::string value;

    public:
        PropertyGetExternalOffset offset;
    };

#pragma pack(pop)
}

#endif  // CORE_TOOLS_PROPERTIES_SUITE_PROPERTY_EXTERNAL_H

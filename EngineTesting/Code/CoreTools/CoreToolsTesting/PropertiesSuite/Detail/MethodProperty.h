// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:39)

#ifndef CORE_TOOLS_PROPERTIES_SUITE_METHOD_PROPERTY_H
#define CORE_TOOLS_PROPERTIES_SUITE_METHOD_PROPERTY_H

#include "CoreTools/Helper/UserMacro.h"
#include "CoreTools/Properties/MethodPropertyGetDetail.h"
#include "CoreTools/Properties/MethodPropertyGetExternalDetail.h"
#include "CoreTools/Properties/MethodPropertyGetSetDetail.h"
#include "CoreTools/Properties/MethodPropertyGetSetExternalDetail.h"
#include "CoreTools/Properties/MethodPropertySetDetail.h"
#include "CoreTools/Properties/MethodPropertySetExternalDetail.h"

#include <string>

namespace CoreTools
{
    class MethodProperty
    {
    public:
        using ClassType = MethodProperty;

        CLASS_INVARIANT_DECLARE;

        MethodProperty() noexcept;

    private:
        const int& GetFirstValue() const noexcept;
        void SetFirstValue(const int& value) noexcept;

    public:
        static ptrdiff_t FirstValueGetOffset() noexcept;
        using MethodPropertyGet = MethodPropertyGet<int, const int&, ClassType, &ClassType::FirstValueGetOffset, &ClassType::GetFirstValue>;
        MethodPropertyGet m_GetType;

        static ptrdiff_t FirstValueSetOffset() noexcept;
        using MethodPropertySet = MethodPropertySet<int, const int&, ClassType, &ClassType::FirstValueSetOffset, &ClassType::SetFirstValue>;
        MethodPropertySet m_SetType;

        static ptrdiff_t FirstValueGetSetOffset() noexcept;
        using MethodPropertyGetSet = MethodPropertyGetSet<int, const int&, const int&, ClassType, &ClassType::FirstValueGetSetOffset, &ClassType::GetFirstValue, &ClassType::SetFirstValue>;
        MethodPropertyGetSet m_GetSetType;

        static ptrdiff_t FirstValueGetExternalOffset() noexcept;
        using MethodPropertyGetExternal = MethodPropertyGetExternal<const int&, ClassType, &ClassType::FirstValueGetExternalOffset, &ClassType::GetFirstValue>;
        MethodPropertyGetExternal m_GetExternalType;

        static ptrdiff_t FirstValueSetExternalOffset() noexcept;
        using MethodPropertySetExternal = MethodPropertySetExternal<const int&, ClassType, &ClassType::FirstValueSetExternalOffset, &ClassType::SetFirstValue>;
        MethodPropertySetExternal m_SetExternalType;

        static ptrdiff_t FirstValueGetSetExternalOffset() noexcept;
        using MethodPropertyGetSetExternal = MethodPropertyGetSetExternal<const int&, const int&, ClassType, &ClassType::FirstValueGetSetExternalOffset, &ClassType::GetFirstValue, &ClassType::SetFirstValue>;
        MethodPropertyGetSetExternal m_GetSetExternalType;

    private:
        int m_FirstValue;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_SUITE_METHOD_PROPERTY_H

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:41)

#ifndef CORE_TOOLS_PROPERTIES_SUITE_METHOD_PROPERTY_H
#define CORE_TOOLS_PROPERTIES_SUITE_METHOD_PROPERTY_H

#include "CoreTools/Helper/UserMacro.h"
#include "CoreTools/Properties/MethodPropertyGetDetail.h"
#include "CoreTools/Properties/MethodPropertyGetExternalDetail.h"
#include "CoreTools/Properties/MethodPropertyGetSetDetail.h"
#include "CoreTools/Properties/MethodPropertyGetSetExternalDetail.h"
#include "CoreTools/Properties/MethodPropertySetDetail.h"
#include "CoreTools/Properties/MethodPropertySetExternalDetail.h"

namespace CoreTools
{
    class MethodProperty
    {
    public:
        using ClassType = MethodProperty;

    public:
        MethodProperty() noexcept;

        CLASS_INVARIANT_DECLARE;

    private:
        NODISCARD const int& GetValue() const noexcept;
        void SetValue(const int& aValue) noexcept;

    public:
        static ptrdiff_t FirstValueGetOffset() noexcept;
        using MethodPropertyGet = MethodPropertyGet<int, const int&, ClassType, &ClassType::FirstValueGetOffset, &ClassType::GetValue>;
        MethodPropertyGet getType;

        static ptrdiff_t FirstValueSetOffset() noexcept;
        using MethodPropertySet = MethodPropertySet<int, const int&, ClassType, &ClassType::FirstValueSetOffset, &ClassType::SetValue>;
        MethodPropertySet setType;

        static ptrdiff_t FirstValueGetSetOffset() noexcept;
        using MethodPropertyGetSet = MethodPropertyGetSet<int, const int&, const int&, ClassType, &ClassType::FirstValueGetSetOffset, &ClassType::GetValue, &ClassType::SetValue>;
        MethodPropertyGetSet getSetType;

        static ptrdiff_t FirstValueGetExternalOffset() noexcept;
        using MethodPropertyGetExternal = MethodPropertyGetExternal<const int&, ClassType, &ClassType::FirstValueGetExternalOffset, &ClassType::GetValue>;
        MethodPropertyGetExternal getExternalType;

        static ptrdiff_t FirstValueSetExternalOffset() noexcept;
        using MethodPropertySetExternal = MethodPropertySetExternal<const int&, ClassType, &ClassType::FirstValueSetExternalOffset, &ClassType::SetValue>;
        MethodPropertySetExternal setExternalType;

        static ptrdiff_t FirstValueGetSetExternalOffset() noexcept;
        using MethodPropertyGetSetExternal = MethodPropertyGetSetExternal<const int&, const int&, ClassType, &ClassType::FirstValueGetSetExternalOffset, &ClassType::GetValue, &ClassType::SetValue>;
        MethodPropertyGetSetExternal getSetExternalType;

    private:
        int value;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_SUITE_METHOD_PROPERTY_H

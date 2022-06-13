///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 11:26)

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
        NODISCARD const int& GetFirstValue() const noexcept;
        void SetFirstValue(const int& value) noexcept;

    public:
        static ptrdiff_t FirstValueGetOffset() noexcept;
        using MethodPropertyGet = MethodPropertyGet<int, const int&, ClassType, &ClassType::FirstValueGetOffset, &ClassType::GetFirstValue>;
        MethodPropertyGet getType;

        static ptrdiff_t FirstValueSetOffset() noexcept;
        using MethodPropertySet = MethodPropertySet<int, const int&, ClassType, &ClassType::FirstValueSetOffset, &ClassType::SetFirstValue>;
        MethodPropertySet setType;

        static ptrdiff_t FirstValueGetSetOffset() noexcept;
        using MethodPropertyGetSet = MethodPropertyGetSet<int, const int&, const int&, ClassType, &ClassType::FirstValueGetSetOffset, &ClassType::GetFirstValue, &ClassType::SetFirstValue>;
        MethodPropertyGetSet getSetType;

        static ptrdiff_t FirstValueGetExternalOffset() noexcept;
        using MethodPropertyGetExternal = MethodPropertyGetExternal<const int&, ClassType, &ClassType::FirstValueGetExternalOffset, &ClassType::GetFirstValue>;
        MethodPropertyGetExternal getExternalType;

        static ptrdiff_t FirstValueSetExternalOffset() noexcept;
        using MethodPropertySetExternal = MethodPropertySetExternal<const int&, ClassType, &ClassType::FirstValueSetExternalOffset, &ClassType::SetFirstValue>;
        MethodPropertySetExternal setExternalType;

        static ptrdiff_t FirstValueGetSetExternalOffset() noexcept;
        using MethodPropertyGetSetExternal = MethodPropertyGetSetExternal<const int&, const int&, ClassType, &ClassType::FirstValueGetSetExternalOffset, &ClassType::GetFirstValue, &ClassType::SetFirstValue>;
        MethodPropertyGetSetExternal getSetExternalType;

    private:
        int firstValue;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_SUITE_METHOD_PROPERTY_H

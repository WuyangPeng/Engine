/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 09:54)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_NAME_IMPL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_NAME_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

// Object类的名字
namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ObjectNameImpl final
    {
    public:
        using ClassType = ObjectNameImpl;

    public:
        explicit ObjectNameImpl(std::string name) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetName() const;
        NODISCARD bool IsExactly(const ObjectNameImpl& aName) const noexcept;

        void SetName(const std::string& aName);

    private:
        std::string name;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_NAME_IMPL_H

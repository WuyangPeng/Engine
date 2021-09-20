//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/21 10:23)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_NAME_IMPL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_NAME_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools
{
    // Object类的名字
    class CORE_TOOLS_HIDDEN_DECLARE ObjectNameImpl final
    {
    public:
        using ClassType = ObjectNameImpl;

    public:
        explicit ObjectNameImpl(const std::string& name);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] std::string GetName() const;
        [[nodiscard]] bool IsExactly(const ObjectNameImpl& name) const noexcept;

        void SetName(const std::string& name);

    private:
        std::string m_Name;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_NAME_IMPL_H

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/11 22:09)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_NAME_IMPL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_NAME_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

/// Object�������
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

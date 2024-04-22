/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/14 21:01)

#ifndef CORE_TOOLS_HELPER_SUITE_TESTING_NO_OBJECT_PTR_IMPL_H
#define CORE_TOOLS_HELPER_SUITE_TESTING_NO_OBJECT_PTR_IMPL_H

#include "CoreTools/Helper/UserMacro.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"

namespace CoreTools
{
    class TestingNoObjectPtrImpl final
    {
    public:
        using ClassType = TestingNoObjectPtrImpl;

    public:
        TestingNoObjectPtrImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        void Load(BufferSource& source) noexcept;
        void Link(ObjectLink& source) noexcept;

        void Register(ObjectRegister& target) const noexcept;
        void Save(BufferTarget& target) const noexcept;
        NODISCARD int GetStreamingSize() const noexcept;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_TESTING_NO_OBJECT_PTR_IMPL_H
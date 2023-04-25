///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 20:55)

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
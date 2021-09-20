///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/19 15:06)

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

        void Load(const BufferSourceSharedPtr& source) noexcept;
        void Link(const ObjectLinkSharedPtr source) noexcept;

        void Register(const ObjectRegisterSharedPtr& target) const noexcept;
        void Save(const BufferTargetSharedPtr& target) const noexcept;
        NODISCARD int GetStreamingSize() const noexcept;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_TESTING_NO_OBJECT_PTR_IMPL_H
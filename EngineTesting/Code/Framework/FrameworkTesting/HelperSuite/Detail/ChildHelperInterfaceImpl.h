///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 20:17)

#ifndef FRAMEWORK_HELPER_SUITE_CHILD_HELPER_INTERFACE_IMPL_H
#define FRAMEWORK_HELPER_SUITE_CHILD_HELPER_INTERFACE_IMPL_H

#include "Framework/MiddleLayer/MiddleLayerInterface.h"

#include <vector>

namespace Framework
{
    class ChildHelperInterfaceImpl
    {
    public:
        using ClassType = ChildHelperInterfaceImpl;

    public:
        explicit ChildHelperInterfaceImpl(int containerSize);

        CLASS_INVARIANT_DECLARE;

        MiddleLayerInterfaceSharedPtr GetMiddleLayerInterface(int index);
        ConstMiddleLayerInterfaceSharedPtr GetMiddleLayerInterface(int index) const;

        void SetMiddleLayerInterface(int index, const MiddleLayerInterfaceSharedPtr& middleLayer);
        int GetSize() const;

    private:
        using WeakPointer = std::weak_ptr<MiddleLayerInterface>;
        using Container = std::vector<WeakPointer>;

    private:
        Container container;
    };

}

#endif  // FRAMEWORK_HELPER_SUITE_CHILD_HELPER_INTERFACE_IMPL_H

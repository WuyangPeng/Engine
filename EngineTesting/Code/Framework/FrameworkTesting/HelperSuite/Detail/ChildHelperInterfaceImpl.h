///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/27 11:06)

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

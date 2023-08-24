///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/11 19:20)

#ifndef FRAMEWORK_HELPER_SUITE_HELPER_MANAGER_INTERFACE_IMPL_H
#define FRAMEWORK_HELPER_SUITE_HELPER_MANAGER_INTERFACE_IMPL_H

#include "Framework/MiddleLayer/MiddleLayerInterface.h"

#include <vector>

namespace Framework
{
    class HelperManagerInterfaceImpl
    {
    public:
        using ClassType = HelperManagerInterfaceImpl;

    public:
        explicit HelperManagerInterfaceImpl(int containerSize);

        CLASS_INVARIANT_DECLARE;

        NODISCARD MiddleLayerInterfaceSharedPtr GetMiddleLayerInterface(int index);
        NODISCARD ConstMiddleLayerInterfaceSharedPtr GetMiddleLayerInterface(int index) const;

        void SetMiddleLayerInterface(int index, const MiddleLayerInterfaceSharedPtr& middleLayer);
        NODISCARD int GetSize() const;

    private:
        using WeakPointer = std::weak_ptr<MiddleLayerInterface>;
        using Container = std::vector<WeakPointer>;

    private:
        Container container;
    };

}

#endif  // FRAMEWORK_HELPER_SUITE_HELPER_MANAGER_INTERFACE_IMPL_H

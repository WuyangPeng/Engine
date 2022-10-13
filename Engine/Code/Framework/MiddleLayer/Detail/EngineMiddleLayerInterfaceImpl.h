///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.2 (2022/08/31 17:21)

#ifndef FRAMEWORK_MIDDLE_LAYER_ENGINE_MIDDLE_LAYER_INTERFACE_IMPL_H
#define FRAMEWORK_MIDDLE_LAYER_ENGINE_MIDDLE_LAYER_INTERFACE_IMPL_H

#include "Framework/FrameworkDll.h"

#include "Framework/MiddleLayer/MiddleLayerInterface.h"

#include <vector>

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE EngineMiddleLayerInterfaceImpl
    {
    public:
        using ClassType = EngineMiddleLayerInterfaceImpl;

    public:
        explicit EngineMiddleLayerInterfaceImpl(int containerSize);

        CLASS_INVARIANT_DECLARE;

        NODISCARD MiddleLayerInterfaceSharedPtr GetMiddleLayerInterface(int index);
        NODISCARD ConstMiddleLayerInterfaceSharedPtr GetMiddleLayerInterface(int index) const;

        void SetMiddleLayerInterface(int index, const MiddleLayerInterfaceSharedPtr& middleLayer);
        NODISCARD int GetSize() const;

    private:
        using MiddleLayerInterfaceWeakPtr = std::weak_ptr<MiddleLayerInterface>;
        using Container = std::vector<MiddleLayerInterfaceWeakPtr>;

    private:
        Container container;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_ENGINE_MIDDLE_LAYER_INTERFACE_IMPL_H

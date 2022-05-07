///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/06 16:00)

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
        using WeakPointer = std::weak_ptr<MiddleLayerInterface>;
        using Container = std::vector<WeakPointer>;

    private:
        Container container;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_ENGINE_MIDDLE_LAYER_INTERFACE_IMPL_H

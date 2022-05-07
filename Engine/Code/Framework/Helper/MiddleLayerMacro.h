///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/05 16:14)

#ifndef FRAMEWORK_HELPER_MIDDLE_LAYER_MACRO_H
#define FRAMEWORK_HELPER_MIDDLE_LAYER_MACRO_H

#include "System/Helper/EnumCast.h"

#define ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(moduleName)                                   \
public:                                                                                   \
    void Set##moduleName##Manager(const MiddleLayerInterfaceSharedPtr& manager) override; \
                                                                                          \
protected:                                                                                \
    MiddleLayerInterfaceSharedPtr Get##moduleName##Manager() override;                    \
    ConstMiddleLayerInterfaceSharedPtr Get##moduleName##Manager() const override

#define ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(namespaceName, className, moduleName)                                                   \
    void namespaceName::className##ManagerInterface::Set##moduleName##Manager(const MiddleLayerInterfaceSharedPtr& manager)        \
    {                                                                                                                              \
        FRAMEWORK_CLASS_IS_VALID_1;                                                                                                \
        return impl->SetMiddleLayerInterface(System::EnumCastUnderlying(className##MiddleLayer::moduleName), manager);             \
    }                                                                                                                              \
    namespaceName::MiddleLayerInterfaceSharedPtr namespaceName::className##ManagerInterface::Get##moduleName##Manager()            \
    {                                                                                                                              \
        FRAMEWORK_CLASS_IS_VALID_1;                                                                                                \
        return impl->GetMiddleLayerInterface(System::EnumCastUnderlying(className##MiddleLayer::moduleName));                      \
    }                                                                                                                              \
    namespaceName::ConstMiddleLayerInterfaceSharedPtr namespaceName::className##ManagerInterface::Get##moduleName##Manager() const \
    {                                                                                                                              \
        FRAMEWORK_CLASS_IS_VALID_CONST_1;                                                                                          \
        return impl->GetMiddleLayerInterface(System::EnumCastUnderlying(className##MiddleLayer::moduleName));                      \
    }

#define ENGINE_MIDDLE_LAYER_CHILD_COMPONENTS_DEFINE(namespaceName, className, parentName, moduleName)                       \
    void namespaceName::className##Interface::Set##moduleName##Manager(const MiddleLayerInterfaceSharedPtr& manager)        \
    {                                                                                                                       \
        FRAMEWORK_CLASS_IS_VALID_1;                                                                                         \
        return impl->SetMiddleLayerInterface(System::EnumCastUnderlying(parentName##MiddleLayer::moduleName), manager);     \
    }                                                                                                                       \
    namespaceName::MiddleLayerInterfaceSharedPtr namespaceName::className##Interface::Get##moduleName##Manager()            \
    {                                                                                                                       \
        FRAMEWORK_CLASS_IS_VALID_1;                                                                                         \
        return impl->GetMiddleLayerInterface(System::EnumCastUnderlying(parentName##MiddleLayer::moduleName));              \
    }                                                                                                                       \
    namespaceName::ConstMiddleLayerInterfaceSharedPtr namespaceName::className##Interface::Get##moduleName##Manager() const \
    {                                                                                                                       \
        FRAMEWORK_CLASS_IS_VALID_CONST_1;                                                                                   \
        return impl->GetMiddleLayerInterface(System::EnumCastUnderlying(parentName##MiddleLayer::moduleName));              \
    }

#endif  // FRAMEWORK_HELPER_MIDDLE_LAYER_MACRO_H

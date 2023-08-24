///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/08 19:53)

#ifndef FRAMEWORK_HELPER_MIDDLE_LAYER_MACRO_H
#define FRAMEWORK_HELPER_MIDDLE_LAYER_MACRO_H

#include "System/Helper/EnumCast.h"

#define ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(moduleName)                                                \
public:                                                                                                \
    void Set##moduleName##Manager(const MiddleLayerInterfaceSharedPtr& manager) override;              \
                                                                                                       \
protected:                                                                                             \
    MiddleLayerInterfaceSharedPtr Get##moduleName##Manager() override;                                 \
    ConstMiddleLayerInterfaceSharedPtr Get##moduleName##Manager() const override;                      \
    template <typename MiddleLayerType>                                                                \
    std::shared_ptr<MiddleLayerType> Get##moduleName##Manager()                                        \
    {                                                                                                  \
        return boost::polymorphic_pointer_downcast<MiddleLayerType>(Get##moduleName##Manager());       \
    }                                                                                                  \
    template <typename MiddleLayerType>                                                                \
    std::shared_ptr<const MiddleLayerType> Get##moduleName##Manager() const                            \
    {                                                                                                  \
        return boost::polymorphic_pointer_downcast<const MiddleLayerType>(Get##moduleName##Manager()); \
    }

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

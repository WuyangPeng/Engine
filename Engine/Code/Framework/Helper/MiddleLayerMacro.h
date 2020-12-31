// Copyright (c) 2010-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.3.0.1 (2020/05/20 10:54)

#ifndef FRAMEWORK_HELPER_MIDDLE_LAYER_MACRO_H
#define FRAMEWORK_HELPER_MIDDLE_LAYER_MACRO_H

#include "System/Helper/EnumCast.h"

#define ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(moduleName) \
	    public: void Set##moduleName##Manager(const MiddleLayerInterfaceSharedPtr& manager) override; \
		protected: const MiddleLayerInterfaceSharedPtr Get##moduleName##Manager() override; \
		const ConstMiddleLayerInterfaceSharedPtr Get##moduleName##Manager() const override

#define ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(namespaceName,className,moduleName) \
	    void namespaceName::className##ManagerInterface::Set##moduleName##Manager(const MiddleLayerInterfaceSharedPtr& manager) \
		{ IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT; return m_Impl->SetMiddleLayerInterface(System::EnumCastUnderlying(className##MiddleLayer::moduleName), manager); } \
		const namespaceName::MiddleLayerInterfaceSharedPtr namespaceName::className##ManagerInterface::Get##moduleName##Manager() \
        { IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;	return m_Impl->GetMiddleLayerInterface(System::EnumCastUnderlying(className##MiddleLayer::moduleName)); } \
        const namespaceName::ConstMiddleLayerInterfaceSharedPtr namespaceName::className##ManagerInterface::Get##moduleName##Manager() const \
		{ FRAMEWORK_CLASS_IS_VALID_CONST_0; return m_Impl->GetMiddleLayerInterface(System::EnumCastUnderlying(className##MiddleLayer::moduleName)); }

#define ENGINE_MIDDLE_LAYER_CHILD_COMPONENTS_DEFINE(namespaceName,className,parentName,moduleName) \
	    void namespaceName::className##Interface::Set##moduleName##Manager(const MiddleLayerInterfaceSharedPtr& manager) \
		{ IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT; return m_Impl->SetMiddleLayerInterface(System::EnumCastUnderlying(parentName##MiddleLayer::moduleName), manager); } \
		const namespaceName::MiddleLayerInterfaceSharedPtr namespaceName::className##Interface::Get##moduleName##Manager() \
        { IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;	return m_Impl->GetMiddleLayerInterface(System::EnumCastUnderlying(parentName##MiddleLayer::moduleName)); } \
        const namespaceName::ConstMiddleLayerInterfaceSharedPtr namespaceName::className##Interface::Get##moduleName##Manager() const \
		{ FRAMEWORK_CLASS_IS_VALID_CONST_0; return m_Impl->GetMiddleLayerInterface(System::EnumCastUnderlying(parentName##MiddleLayer::moduleName)); }

#endif // FRAMEWORK_HELPER_MIDDLE_LAYER_MACRO_H

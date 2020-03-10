// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.4 (2019/07/31 17:43)

#ifndef FRAMEWORK_MACRO_MIDDLE_LAYER_MACRO_H
#define FRAMEWORK_MACRO_MIDDLE_LAYER_MACRO_H

#define ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(moduleName) \
	    public: virtual void Set##moduleName##Manager(MiddleLayerInterfaceSmartPointer& manager); \
		protected: 	virtual const MiddleLayerInterfaceSmartPointer Get##moduleName##Manager(); \
		virtual const ConstMiddleLayerInterfaceSmartPointer GetConst##moduleName##Manager() const

#define ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(namespaceName,className,moduleName) \
	    void namespaceName::className##ManagerInterface::Set##moduleName##Manager(MiddleLayerInterfaceSmartPointer& manager) { \
	    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT; return m_Impl->SetMiddleLayerInterface \
        (static_cast<int>(className##MiddleLayer::moduleName), manager); } \
		const namespaceName::MiddleLayerInterfaceSmartPointer namespaceName::className##ManagerInterface::Get##moduleName##Manager() \
        { IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;	return m_Impl->GetMiddleLayerInterface \
	    (static_cast<int>(className##MiddleLayer::moduleName)); } \
        const namespaceName::ConstMiddleLayerInterfaceSmartPointer namespaceName::className##ManagerInterface:: \
        GetConst##moduleName##Manager() const {	FRAMEWORK_CLASS_IS_VALID_CONST_0; \
        return m_Impl->GetConstMiddleLayerInterface(static_cast<int>(className##MiddleLayer::moduleName)); }

#define ENGINE_MIDDLE_LAYER_CHILD_COMPONENTS_DEFINE(namespaceName,className,parentName,moduleName) \
	    void namespaceName::className##Interface::Set##moduleName##Manager(MiddleLayerInterfaceSmartPointer& manager) { \
	    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT; return m_Impl->SetMiddleLayerInterface \
        (static_cast<int>(parentName##MiddleLayer::moduleName), manager); } \
		const namespaceName::MiddleLayerInterfaceSmartPointer namespaceName::className##Interface::Get##moduleName##Manager() \
        { IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;	return m_Impl->GetMiddleLayerInterface \
	    (static_cast<int>(parentName##MiddleLayer::moduleName)); } \
        const namespaceName::ConstMiddleLayerInterfaceSmartPointer namespaceName::className##Interface:: \
        GetConst##moduleName##Manager() const {	FRAMEWORK_CLASS_IS_VALID_CONST_0; \
        return m_Impl->GetConstMiddleLayerInterface(static_cast<int>(parentName##MiddleLayer::moduleName)); }

#endif // FRAMEWORK_MACRO_MIDDLE_LAYER_MACRO_H

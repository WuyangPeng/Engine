// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/18 10:33)

#ifndef CORE_TOOLS_HELPER_NAME_MACRO_H
#define CORE_TOOLS_HELPER_NAME_MACRO_H

#include "MemberFunctionMacro.h"

#include <vector>

#define CORE_TOOLS_NAMES_DECLARE \
		public: using ObjectSmartPointerContainer = std::vector<ObjectSmartPointer>; \
	    using ConstObjectSmartPointerContainer = std::vector<ConstObjectSmartPointer>; \
        virtual const ObjectSmartPointer GetObjectByName(const std::string& name); \
		virtual const ObjectSmartPointerContainer GetAllObjectsByName(const std::string& name); \
		virtual const ConstObjectSmartPointer GetConstObjectByName(const std::string& name) const; \
        virtual const ConstObjectSmartPointerContainer GetAllConstObjectsByName(const std::string& name) const

#define CORE_TOOLS_NAMES_OVERRIDE_DECLARE \
        const ObjectSmartPointer GetObjectByName(const std::string& name) override; \
		const ObjectSmartPointerContainer GetAllObjectsByName(const std::string& name) override; \
		const ConstObjectSmartPointer GetConstObjectByName(const std::string& name) const override; \
        const ConstObjectSmartPointerContainer GetAllConstObjectsByName(const std::string& name) const override

#define CORE_TOOLS_NAMES_IMPL_DECLARE \
        public: using ObjectSmartPointerContainer = std::vector<CoreTools::ObjectSmartPointer>; \
		using ConstObjectSmartPointerContainer = std::vector<CoreTools::ConstObjectSmartPointer>; \
		const CoreTools::ObjectSmartPointer GetObjectByName(const std::string& name); \
		const ObjectSmartPointerContainer GetAllObjectsByName(const std::string& name); \
		const CoreTools::ConstObjectSmartPointer GetConstObjectByName (const std::string& name) const; \
		const ConstObjectSmartPointerContainer GetAllConstObjectsByName(const std::string& name) const

#define CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(namespaceName,className) \
	    const CoreTools::ObjectSmartPointer namespaceName::className::GetObjectByName(const std::string& name) { \
        IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT; auto found = ParentType::GetObjectByName(name); \
        if (found) { return found; } else { return m_Impl->GetObjectByName(name); } } \
		const namespaceName::className::ObjectSmartPointerContainer namespaceName::className::GetAllObjectsByName(const std::string& name) { \
		IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT; auto parentObjects = ParentType::GetAllObjectsByName(name); \
        auto implObjects = m_Impl->GetAllObjectsByName(name); \
        parentObjects.insert(parentObjects.end(),implObjects.begin(), implObjects.end()); return parentObjects; } \
		const CoreTools::ConstObjectSmartPointer namespaceName::className::GetConstObjectByName(const std::string& name) const { \
		CLASS_IS_VALID_CONST_0; auto found = ParentType::GetConstObjectByName(name); \
		if (found) { return found; } else { return m_Impl->GetConstObjectByName(name); } } \
		const namespaceName::className::ConstObjectSmartPointerContainer namespaceName::className::GetAllConstObjectsByName(const std::string& name) const { \
		CLASS_IS_VALID_CONST_0; auto parentObjects = ParentType::GetAllConstObjectsByName(name); \
		auto implObjects = m_Impl->GetAllConstObjectsByName(name); \
		parentObjects.insert(parentObjects.end(),implObjects.begin(), implObjects.end()); return parentObjects; } 

#endif // CORE_TOOLS_HELPER_RTTI_MACRO_H

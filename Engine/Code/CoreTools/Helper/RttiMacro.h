// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/18 10:28)

#ifndef CORE_TOOLS_HELPER_RTTI_MACRO_H
#define CORE_TOOLS_HELPER_RTTI_MACRO_H

#include "CoreTools/ObjectSystems/Rtti.h"

#define CORE_TOOLS_RTTI_DECLARE \
		public: virtual const CoreTools::Rtti& GetRttiType() const; static const CoreTools::Rtti sm_Type; 

#define CORE_TOOLS_RTTI_OVERRIDE_DECLARE \
		public: virtual const CoreTools::Rtti& GetRttiType() const override; static const CoreTools::Rtti sm_Type; 

#define CORE_TOOLS_RTTI_DEFINE(namespaceName,className) \
		const CoreTools::Rtti& namespaceName::className::GetRttiType() const { return sm_Type; } \
        const CoreTools::Rtti namespaceName::className::sm_Type{ #namespaceName"."#className,&ParentType::sm_Type };

#define CORE_TOOLS_RTTI_BASE_DEFINE(namespaceName,className) \
		const CoreTools::Rtti& namespaceName::className::GetRttiType() const { return sm_Type; } \
        const CoreTools::Rtti namespaceName::className::sm_Type{ #namespaceName"."#className,nullptr };

#endif // CORE_TOOLS_HELPER_RTTI_MACRO_H

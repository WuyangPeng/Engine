// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/18 10:28)

// 单例类所需要的宏
#ifndef CORE_TOOLS_HELPER_SINGLETON_MACRO_H
#define CORE_TOOLS_HELPER_SINGLETON_MACRO_H

#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h" 
#include "CoreTools/Base/SingletonDetail.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#if !defined(TCRE_USE_GCC)

	#define SINGLETON_GET_PTR_DECLARE(className)
	#define SINGLETON_GET_PTR_DEFINE(namespaceName,className)
	
#else // TCRE_USE_GCC

	#define SINGLETON_GET_PTR_DECLARE(className) \
			public: static className* GetSingletonPtr() noexcept; \
			public: static className& GetSingleton() noexcept
	#define SINGLETON_GET_PTR_DEFINE(namespaceName,className) \
			namespaceName::className* namespaceName::className::GetSingletonPtr() noexcept { \
			return ParentType::GetSingletonPtr(); }\
			namespaceName::className& namespaceName::className::GetSingleton() noexcept { \
			return ParentType::GetSingleton(); } 

#endif // !TCRE_USE_GCC

#define SINGLETON_CREATE_AND_DESTROY_DECLARE(className) \
	    public: using ParentType = Singleton<className>; \
		public:	static void Create(); static void Destroy() noexcept; \
		private: static void DoCreate(); className(); ~className()

#define SINGLETON_INITIALIZE_DECLARE(className) \
        NON_COPY_CLASSES_TYPE_DECLARE(className); \
		SINGLETON_GET_PTR_DECLARE(className); \
		SINGLETON_CREATE_AND_DESTROY_DECLARE(className)   

#define SINGLETON_CREATE_AND_DESTROY_INTERNAL_DEFINE(namespaceName,className,mutexType) \
        void namespaceName::className::Create() { MUTEX_ENTER_GLOBAL; try { DoCreate(); } catch (...) { Destroy(); throw; } } \
        void namespaceName::className::DoCreate() { MUTEX_ENTER_GLOBAL; if(SYSTEM_MULTIPLE_CONCATENATOR(sm_,className,Mutex) == nullptr) \
		SYSTEM_MULTIPLE_CONCATENATOR(sm_,className,Mutex) = new mutexType; \
		if(SYSTEM_CONCATENATOR(sm_,className) == nullptr) SYSTEM_CONCATENATOR(sm_,className) = new className; } \
		void namespaceName::className::Destroy() noexcept { delete SYSTEM_CONCATENATOR(sm_,className); \
		SYSTEM_CONCATENATOR(sm_,className) = nullptr; delete SYSTEM_MULTIPLE_CONCATENATOR(sm_,className,Mutex); \
		SYSTEM_MULTIPLE_CONCATENATOR(sm_,className,Mutex) = nullptr; }  

#define SINGLETON_CREATE_AND_DESTROY_DEFINE(namespaceName,className) \
		SINGLETON_CREATE_AND_DESTROY_INTERNAL_DEFINE(namespaceName,className,CoreTools::Mutex) 

#define SINGLETON_INITIALIZE_DEFINE(namespaceName,className) \
	    SINGLETON_GET_PTR_DEFINE(namespaceName,className); \
	    SINGLETON_CREATE_AND_DESTROY_DEFINE(namespaceName,className)

#define SINGLETON_DEFINE(namespaceName,className) \
	    namespaceName::className::className():m_Impl{ std::make_shared<ImplType>() } { MUTEX_ENTER_MEMBER; \
		SELF_CLASS_IS_VALID_1; } namespaceName::className::~className() { MUTEX_ENTER_MEMBER; SELF_CLASS_IS_VALID_1; }

#define SINGLETON_MUTEX_DEFINE(namespaceName,className)    \
	    CORE_TOOLS_MUTEX_EXTERN(namespaceName); \
		namespaceName::className* SYSTEM_CONCATENATOR(namespaceName::className::sm_,className) = nullptr; \
        CoreTools::Mutex* SYSTEM_MULTIPLE_CONCATENATOR(namespaceName::className::sm_,className,Mutex) = nullptr

#define SINGLETON_INSTANCE_DECLARE(className) \
		private: static className* SYSTEM_CONCATENATOR(sm_,className); \
		static CoreTools::Mutex* SYSTEM_MULTIPLE_CONCATENATOR(sm_,className,Mutex)

#define SINGLETON_IMPL_DECLARE(className) \
	    private: using ImplType = SYSTEM_CONCATENATOR(className,Impl); \
		private: using SYSTEM_CONCATENATOR(className,ImplPtr) = std::shared_ptr<ImplType>; \
	    private: SYSTEM_CONCATENATOR(className,ImplPtr) m_Impl

#define SINGLETON_MEMBER_DECLARE(className) \
	    SINGLETON_INSTANCE_DECLARE(className); \
		SINGLETON_IMPL_DECLARE(className)

#define SINGLETON_MEMBER_DECLARE_USE_SHARED(className) \
        private: static className* SYSTEM_CONCATENATOR(sm_,className); \
		static std::shared_mutex* SYSTEM_MULTIPLE_CONCATENATOR(sm_,className,Mutex); \
		SINGLETON_IMPL_DECLARE(className)

#define SINGLETON_MUTEX_DEFINE_USE_SHARED(namespaceName,className) \
	    CORE_TOOLS_MUTEX_EXTERN(namespaceName); \
		namespaceName::className* SYSTEM_CONCATENATOR(namespaceName::className::sm_,className) = nullptr; \
        std::shared_mutex* SYSTEM_MULTIPLE_CONCATENATOR(namespaceName::className::sm_,className,Mutex) = nullptr

#define SINGLETON_INITIALIZE_DEFINE_USE_SHARED(namespaceName,className) \
		SINGLETON_CREATE_AND_DESTROY_INTERNAL_DEFINE(namespaceName,className,std::shared_mutex) 

#define SINGLETON_MUTEX_ENTER_GLOBAL(namespaceName) const CoreTools::ScopedMutex holder{ SYSTEM_MULTIPLE_CONCATENATOR(Get,namespaceName,Mutex)() }
#define SINGLETON_MUTEX_ENTER_MEMBER const CoreTools::ScopedMutex holder{ GetMutex() }

#endif // CORE_TOOLS_HELPER_SINGLETON_MACRO_H

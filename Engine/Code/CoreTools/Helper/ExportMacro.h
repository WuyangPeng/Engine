// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/18 10:13)

#ifndef CORE_TOOLS_HELPER_EXPORT_MACRO_H
#define CORE_TOOLS_HELPER_EXPORT_MACRO_H

#include "CoreTools/ImplHelper/ImplStaticAssertHelper.h"

#include <boost/noncopyable.hpp>
#include <memory>

#define EXPORT_SHARED_PTR(namespaceName,implClassName,exportName) \
	    namespace namespaceName { class implClassName; } \
        template class exportName std::shared_ptr<namespaceName::implClassName>

#define EXPORT_UNIQUE_PTR(namespaceName,implClassName,exportName) \
	    namespace namespaceName { class implClassName; } \
		template class exportName std::_Compressed_pair<std::default_delete<namespaceName::implClassName>, namespaceName::implClassName*>; \
		template class exportName std::unique_ptr<namespaceName::implClassName> 

#define EXPORT_CLASS(exportName,className) \
	    class SYSTEM_CONCATENATOR(exportName,_DEFAULT_DECLARE) className

#define EXPORT_NONCOPYABLE_CLASS(exportName) \
	    EXPORT_CLASS(exportName,boost::noncopyable_::noncopyable)

#define CORE_TOOLS_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(CoreTools,implClassName,CORE_TOOLS_DEFAULT_DECLARE)

#define NETWORK_EXPORT_SHARED_PTR(implClassName) \
        EXPORT_SHARED_PTR(Network,implClassName,NETWORK_DEFAULT_DECLARE)

#define DATABASE_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(Database,implClassName,DATABASE_DEFAULT_DECLARE)

#define SCRIPT_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(Script,implClassName,SCRIPT_DEFAULT_DECLARE)

#define MATHEMATICS_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(Mathematics,implClassName,MATHEMATICS_DEFAULT_DECLARE)

#define SOUND_EFFECT_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(SoundEffect,implClassName,SOUND_EFFECT_DEFAULT_DECLARE)

#define INPUT_OUTPUT_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(InputOutput,implClassName,INPUT_OUTPUT_DEFAULT_DECLARE)

#define RESOURCE_MANAGER_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(ResourceManager,implClassName,RESOURCE_MANAGER_DEFAULT_DECLARE)

#define RENDERING_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(Rendering,implClassName,RENDERING_DEFAULT_DECLARE)

#define PHYSICS_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(Physics,implClassName,PHYSICS_DEFAULT_DECLARE)

#define IMAGICS_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(Imagics,implClassName,IMAGICS_DEFAULT_DECLARE)

#define ANIMATION_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(Animation,implClassName,ANIMATION_DEFAULT_DECLARE)

#define ARTIFICIAL_INTELLEGENCE_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(ArtificialIntellegence,implClassName,ARTIFICIAL_INTELLEGENCE_DEFAULT_DECLARE)

#define USER_INTERFACE_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(UserInterface,implClassName,USER_INTERFACE_DEFAULT_DECLARE)

#define ASSIST_TOOLS_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(AssistTools,implClassName,ASSIST_TOOLS_DEFAULT_DECLARE)

#define FRAMEWORK_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(Framework,implClassName,FRAMEWORK_DEFAULT_DECLARE)

#define CORE_TOOLS_EXPORT_UNIQUE_PTR(implClassName) \
	    EXPORT_UNIQUE_PTR(CoreTools,implClassName,CORE_TOOLS_DEFAULT_DECLARE)

#define NETWORK_EXPORT_UNIQUE_PTR(implClassName) \
        EXPORT_UNIQUE_PTR(Network,implClassName,NETWORK_DEFAULT_DECLARE)

#define DATABASE_EXPORT_UNIQUE_PTR(implClassName) \
	    EXPORT_UNIQUE_PTR(Database,implClassName,DATABASE_DEFAULT_DECLARE)

#define SCRIPT_EXPORT_UNIQUE_PTR(implClassName) \
	    EXPORT_UNIQUE_PTR(Script,implClassName,SCRIPT_DEFAULT_DECLARE)

#define MATHEMATICS_EXPORT_UNIQUE_PTR(implClassName) \
	    EXPORT_UNIQUE_PTR(Mathematics,implClassName,MATHEMATICS_DEFAULT_DECLARE)

#define SOUND_EFFECT_EXPORT_UNIQUE_PTR(implClassName) \
	    EXPORT_UNIQUE_PTR(SoundEffect,implClassName,SOUND_EFFECT_DEFAULT_DECLARE)

#define INPUT_OUTPUT_EXPORT_UNIQUE_PTR(implClassName) \
	    EXPORT_UNIQUE_PTR(InputOutput,implClassName,INPUT_OUTPUT_DEFAULT_DECLARE)

#define RESOURCE_MANAGER_EXPORT_UNIQUE_PTR(implClassName) \
	    EXPORT_UNIQUE_PTR(ResourceManager,implClassName,RESOURCE_MANAGER_DEFAULT_DECLARE)

#define RENDERING_EXPORT_UNIQUE_PTR(implClassName) \
	    EXPORT_UNIQUE_PTR(Rendering,implClassName,RENDERING_DEFAULT_DECLARE)

#define PHYSICS_EXPORT_UNIQUE_PTR(implClassName) \
	    EXPORT_UNIQUE_PTR(Physics,implClassName,PHYSICS_DEFAULT_DECLARE)

#define IMAGICS_EXPORT_UNIQUE_PTR(implClassName) \
	    EXPORT_UNIQUE_PTR(Imagics,implClassName,IMAGICS_DEFAULT_DECLARE)

#define ANIMATION_EXPORT_UNIQUE_PTR(implClassName) \
	    EXPORT_UNIQUE_PTR(Animation,implClassName,ANIMATION_DEFAULT_DECLARE)

#define ARTIFICIAL_INTELLEGENCE_EXPORT_UNIQUE_PTR(implClassName) \
	    EXPORT_UNIQUE_PTR(ArtificialIntellegence,implClassName,ARTIFICIAL_INTELLEGENCE_DEFAULT_DECLARE)

#define USER_INTERFACE_EXPORT_UNIQUE_PTR(implClassName) \
	    EXPORT_UNIQUE_PTR(UserInterface,implClassName,USER_INTERFACE_DEFAULT_DECLARE)

#define ASSIST_TOOLS_EXPORT_UNIQUE_PTR(implClassName) \
	    EXPORT_UNIQUE_PTR(AssistTools,implClassName,ASSIST_TOOLS_DEFAULT_DECLARE)

#define FRAMEWORK_EXPORT_UNIQUE_PTR(implClassName) \
	    EXPORT_UNIQUE_PTR(Framework,implClassName,FRAMEWORK_DEFAULT_DECLARE)

#define TYPE_DECLARE(className) \
	    using ClassType = className;using ImplType = SYSTEM_CONCATENATOR(className,Impl)

#define SHARE_CLASSES_TYPE_DECLARE(className) \
	    TYPE_DECLARE(className);using ClassShareType = CoreTools::ShareClasses 

#define PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(className) \
	    TYPE_DECLARE(className);using ClassShareType = CoreTools::PerformanceUnsharedClasses 

#define COPY_UNSHARE_CLASSES_TYPE_DECLARE(className) \
	    TYPE_DECLARE(className);className(const className& rhs); \
		className& operator= (const className& rhs); using ClassShareType = CoreTools::CopyUnsharedClasses 	

#define COPY_UNSHARE_CLASSES_TYPE_DECLARE_USE_SWAP(className) \
		private: void Swap(className& rhs) noexcept;public: COPY_UNSHARE_CLASSES_TYPE_DECLARE(className)       

#define DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(className) \
	    TYPE_DECLARE(className); private: void Copy(); public: using ClassShareType = CoreTools::DelayCopyUnsharedClasses 

#define NON_COPY_CLASSES_TYPE_DECLARE(className) \
	    TYPE_DECLARE(className);using ClassShareType = CoreTools::NonCopyClasses 

#define IMPL_TYPE_DECLARE(className) \
	    using SYSTEM_CONCATENATOR(className,ImplPtr) = std::shared_ptr<ImplType>; private: SYSTEM_CONCATENATOR(className,ImplPtr) m_Impl

#define IMPL_MOVE_OPERATOR_DECLARE(className) \
		className(className&& rhs) noexcept; className& operator=(className&& rhs) noexcept

#define IMPL_MOVE_OPERATOR_COMPLETE_DECLARE(className) \
		IMPL_MOVE_OPERATOR_DECLARE(className); CLASS_INVARIANT_DECLARE

#define IMPL_COPY_OPERATOR_DECLARE(className) \
		className(const className& rhs); className& operator=(const className& rhs)

#define IMPL_MOVE_AND_COPY_OPERATOR_COMPLETE_DECLARE(className) \
		IMPL_MOVE_OPERATOR_COMPLETE_DECLARE(className); IMPL_COPY_OPERATOR_DECLARE(className)

#endif // CORE_TOOLS_HELPER_EXPORT_MACRO_H

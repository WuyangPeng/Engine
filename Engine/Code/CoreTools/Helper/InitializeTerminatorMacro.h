// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/18 10:21)

#ifndef CORE_TOOLS_HELPER_INITIALIZE_TERMINATE_MACRO_H
#define CORE_TOOLS_HELPER_INITIALIZE_TERMINATE_MACRO_H

#include "CoreTools/ObjectSystems/InitTerm.h"

#define CORE_TOOLS_INIT_TERM_INITIALIZE_DECLARE \
        public: static bool RegisterInitialize (); static void Initialize (); \
        private: static bool sm_InitializeRegistered;

#define CORE_TOOLS_INIT_TERM_INITIALIZE_DEFINE(namespaceName,className) \
        bool namespaceName::className::sm_InitializeRegistered { false }; \
		bool namespaceName::className::RegisterInitialize() { \
		if (!sm_InitializeRegistered) { InitTerm::AddInitializer(className::Initialize); \
        sm_InitializeRegistered = true; } return sm_InitializeRegistered; }

#define CORE_TOOLS_INIT_TERM_INITIALIZE_REGISTER(namespaceName,className) \
	    namespace { auto SYSTEM_MULTIPLE_CONCATENATOR(g_InitializeRegistered,namespaceName,className) = namespaceName::className::RegisterInitialize(); }

#define CORE_TOOLS_INIT_TERM_TERMINATE_DECLARE \
        public: static bool RegisterTerminate (); static void Terminate (); \
        private: static bool sm_TerminateRegistered;

#define CORE_TOOLS_INIT_TERM_TERMINATE_DEFINE(namespaceName,className) \
        bool namespaceName::className::sm_TerminateRegistered { false }; \
		bool namespaceName::className::RegisterTerminate() { \
		if (!sm_TerminateRegistered) { InitTerm::AddTerminator(className::Terminate); \
        sm_TerminateRegistered = true;  } return sm_TerminateRegistered; }

#define CORE_TOOLS_INIT_TERM_TERMINATE_REGISTER(namespaceName,className) \
	    namespace {	auto SYSTEM_MULTIPLE_CONCATENATOR(g_TerminateRegistered,namespaceName,className) = namespaceName::className::RegisterTerminate(); }

#endif // CORE_TOOLS_HELPER_INITIALIZE_TERMINATE_MACRO_H

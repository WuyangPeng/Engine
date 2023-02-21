///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.2 (2023/02/05 15:11)

#ifndef CORE_TOOLS_HELPER_SUITE_H
#define CORE_TOOLS_HELPER_SUITE_H

#include "AssertException/AssertExecuteLoopNotThrowTesting.h"
#include "AssertException/AssertNotThrowExceptionTesting.h"
#include "AssertException/AssertThrowExceptionTesting.h"
#include "AssertTest/AssertTestApproximateTesting.h"
#include "AssertTest/AssertTestConditionTesting.h"
#include "AssertTest/AssertTestExceptionThrowTesting.h"
#include "AssertTest/AssertTestNullptrTesting.h"
#include "AssertTest/AssertTestOperatorTesting.h"
#include "AssertTest/AssertTestRangeTesting.h"
#include "ClassInvariant/ClassInvariantMacroTesting.h"
#include "ClassInvariant/ModuleClassInvariantMacroTesting.h"
#include "CustomAssert/CustomAssertMacroTesting.h"
#include "CustomAssert/ModuleCustomAssertMacroTesting.h"
#include "Exception/ExceptionCatchMacroTesting.h"
#include "Exception/ExceptionMacroTesting.h"
#include "Export/CopyModuleExportMacroTesting.h"
#include "Export/CopyUnsharedExportMacroTesting.h"
#include "Export/DelayCopyUnsharedExportMacroTesting.h"
#include "Export/ExportMacroTesting.h"
#include "Export/ModuleExportMacroTesting.h"
#include "Export/NonCopyExportMacroTesting.h"
#include "Export/PerformanceUnsharedExportMacroTesting.h"
#include "Export/SharedExportMacroTesting.h"
#include "FunctionDescribedMacroTesting.h"
#include "GetRequiredBitsTesting.h"
#include "HashCombineTesting.h"
#include "InitializeTerminatorMacroTesting.h"
#include "Log/LogConsoleMacroTesting.h"
#include "Log/LogDefaultMacroTesting.h"
#include "Log/LogEngineMacroTesting.h"
#include "Log/LogFileAndConsoleMacroTesting.h"
#include "Log/LogFileMacroTesting.h"
#include "Log/LogTriggerAssertMacroTesting.h"
#include "MainFunctionMacroTesting.h"
#include "MemberFunction/CallConstMemberFunctionMacroTesting.h"
#include "MemberFunction/CopyMemberFunctionStaticAssertMacroTesting.h"
#include "MemberFunction/MemberFunctionMacroTesting.h"
#include "MemberFunction/MemberFunctionNoexceptMacroTesting.h"
#include "MemberFunction/MemberFunctionStaticAssertMacroTesting.h"
#include "MemoryMacroTesting.h"
#include "NameMacroTesting.h"
#include "PropertiesMacroTesting.h"
#include "Rtti/RttiMacroBaseTesting.h"
#include "Rtti/RttiMacroFinalTesting.h"
#include "Rtti/RttiMacroTesting.h"
#include "SafetyLimitMacroTesting.h"
#include "SharedPtrMacroTesting.h"
#include "SingletonMacroTesting.h"
#include "Stream/DebugStreamMacroTesting.h"
#include "Stream/DefaultTestingNoObjectPtrTesting.h"
#include "Stream/DefaultTestingObjectPtrTesting.h"
#include "Stream/TestingNoObjectPtrTesting.h"
#include "Stream/TestingObjectPtrTesting.h"
#include "Stream/TestingObjectSizeTesting.h"
#include "Stream/TestingObjectTesting.h"
#include "UnitTestSuite/UnitTestSuiteMacroTesting.h"
#include "UserMacroTesting.h"

#endif  // CORE_TOOLS_HELPER_SUITE_H
// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:36)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateMacroImpl.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExceptionMacro.h" 
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
const System::String AssistTools::GenerateTemplateMacroImpl
	::sm_Extension(SYSTEM_TEXT(".h"));
 #include STSTEM_WARNING_POP
AssistTools::GenerateTemplateMacroImpl
	::GenerateTemplateMacroImpl(const System::String& templateFileName,  const Replace& replace)
	:ParentType(templateFileName, sm_Extension,replace) 
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateMacroImpl)

void AssistTools::GenerateTemplateMacroImpl
	::GenerateTo(const System::String& resourceDirectory, const System::String& newProjectName, const CopyrightData& copyrightData, 
	             const System::String& solutionName, const System::String& managerName,
				 const System::String& projectCapital,const System::String& managerCapital) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

	VariableType newVariable = GetCopyrightVariable(copyrightData);
	newVariable.insert(make_pair(GetOriginal(GenerateTemplateReplace::SolutionName), solutionName));
	newVariable.insert(make_pair(GetOriginal(GenerateTemplateReplace::ManagerName), managerName));
	newVariable.insert(make_pair(GetOriginal(GenerateTemplateReplace::ProjectCapital), projectCapital));
	newVariable.insert(make_pair(GetOriginal(GenerateTemplateReplace::ManagerCapital), managerCapital)); 

	return ParentType::Generate (resourceDirectory, newProjectName, newVariable);
}

/*
 æ¿˝ƒ£∞Â£∫ 

ExportMacro.h

// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#ifndef %ProjectCapital%_%ManagerCapital%_MACRO_EXPORT_MACRO_H
#define %ProjectCapital%_%ManagerCapital%_MACRO_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h" 

#define %ProjectCapital%_%ManagerCapital%_EXPORT_SHARED_PTR(implClassName) \
	    EXPORT_SHARED_PTR(%SolutionName%%ManagerName%,implClassName,%ProjectCapital%_%ManagerCapital%_DEFAULT_DECLARE) 

#endif // %ProjectCapital%_%ManagerCapital%_MACRO_EXPORT_MACRO_H

ClassInvariantMacro.h

// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#ifndef %ProjectCapital%_%ManagerCapital%_MACRO_%ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_MACRO_H
#define %ProjectCapital%_%ManagerCapital%_MACRO_%ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_MACRO_H

#include "UserMacro.h"

#if 0 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_LEVEL

	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_0 CLASS_IS_VALID_0
	#define %ProjectCapital%_%ManagerCapital%_SELF_CLASS_IS_VALID_0 SELF_CLASS_IS_VALID_0

#else // %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_LEVEL < 0

	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_0 (static_cast<void>(0))
	#define %ProjectCapital%_%ManagerCapital%_SELF_CLASS_IS_VALID_0 (static_cast<void>(0))

#endif // 0 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_LEVEL

#if 1 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_LEVEL

	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_1 CLASS_IS_VALID_1
	#define %ProjectCapital%_%ManagerCapital%_SELF_CLASS_IS_VALID_1 SELF_CLASS_IS_VALID_1

#else // %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_LEVEL < 1

	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_1 (static_cast<void>(0))
	#define %ProjectCapital%_%ManagerCapital%_SELF_CLASS_IS_VALID_1 (static_cast<void>(0))

#endif // 1 <= CLASS_INVARIANT_LEVEL

#if 2 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_LEVEL

	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_2 CLASS_IS_VALID_2
	#define %ProjectCapital%_%ManagerCapital%_SELF_CLASS_IS_VALID_2 SELF_CLASS_IS_VALID_2

#else // %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_LEVEL < 2

	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_2 (static_cast<void>(0))
	#define %ProjectCapital%_%ManagerCapital%_SELF_CLASS_IS_VALID_2 (static_cast<void>(0))

#endif // 2 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_LEVEL

#if 3 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_LEVEL

	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_3 CLASS_IS_VALID_3
	#define %ProjectCapital%_%ManagerCapital%_SELF_CLASS_IS_VALID_3 SELF_CLASS_IS_VALID_3

#else // %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_LEVEL < 3

	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_3 (static_cast<void>(0))
	#define %ProjectCapital%_%ManagerCapital%_SELF_CLASS_IS_VALID_3 (static_cast<void>(0))

#endif // 3 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_LEVEL

#if 4 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_LEVEL

	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_4 CLASS_IS_VALID_4
	#define %ProjectCapital%_%ManagerCapital%_SELF_CLASS_IS_VALID_4 SELF_CLASS_IS_VALID_4

#else // %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_LEVEL < 4

	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_4 (static_cast<void>(0))
	#define %ProjectCapital%_%ManagerCapital%_SELF_CLASS_IS_VALID_4 (static_cast<void>(0))

#endif // 4 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_LEVEL

#if 5 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_LEVEL

	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_5 CLASS_IS_VALID_5
	#define %ProjectCapital%_%ManagerCapital%_SELF_CLASS_IS_VALID_5 SELF_CLASS_IS_VALID_5

#else // %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_LEVEL < 5

	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_5 (static_cast<void>(0))
	#define %ProjectCapital%_%ManagerCapital%_SELF_CLASS_IS_VALID_5 (static_cast<void>(0))

#endif // 5 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_LEVEL

#if 6 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_LEVEL

	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_6 CLASS_IS_VALID_6
	#define %ProjectCapital%_%ManagerCapital%_SELF_CLASS_IS_VALID_6 SELF_CLASS_IS_VALID_6

#else // CLASS_INVARIANT_LEVEL < 6

	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_6 (static_cast<void>(0))
	#define %ProjectCapital%_%ManagerCapital%_SELF_CLASS_IS_VALID_6 (static_cast<void>(0))

#endif // 6 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_LEVEL

#if 7 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_LEVEL

	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_7 CLASS_IS_VALID_7
	#define %ProjectCapital%_%ManagerCapital%_SELF_CLASS_IS_VALID_7 SELF_CLASS_IS_VALID_7

#else // %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_LEVEL < 7

	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_7 (static_cast<void>(0))
	#define %ProjectCapital%_%ManagerCapital%_SELF_CLASS_IS_VALID_7 (static_cast<void>(0))

#endif // 7 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_LEVEL

#if 8 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_LEVEL

	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_8 CLASS_IS_VALID_8
	#define %ProjectCapital%_%ManagerCapital%_SELF_CLASS_IS_VALID_8 SELF_CLASS_IS_VALID_8

#else // %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_LEVEL < 8

	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_8 (static_cast<void>(0))
	#define %ProjectCapital%_%ManagerCapital%_SELF_CLASS_IS_VALID_8 (static_cast<void>(0))

#endif // 8 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_LEVEL

#if 9 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_LEVEL

	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_9 CLASS_IS_VALID_9
	#define %ProjectCapital%_%ManagerCapital%_SELF_CLASS_IS_VALID_9 SELF_CLASS_IS_VALID_9

#else // %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_LEVEL < 9

	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_9 (static_cast<void>(0))
	#define %ProjectCapital%_%ManagerCapital%_SELF_CLASS_IS_VALID_9 (static_cast<void>(0))

#endif // 9 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_LEVEL

#if 0 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_CONST_LEVEL
	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_CONST_0 CLASS_IS_VALID_CONST_0
#else // %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_CONST_LEVEL < 0
	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_CONST_0 (static_cast<void>(0))
#endif // 0 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_CONST_LEVEL

#if 1 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_CONST_LEVEL
	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_CONST_1 CLASS_IS_VALID_CONST_1
#else // %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_CONST_LEVEL < 1
	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_CONST_1 (static_cast<void>(0))
#endif // 1 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_CONST_LEVEL

#if 2 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_CONST_LEVEL
	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_CONST_2 CLASS_IS_VALID_CONST_2
#else // %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_CONST_LEVEL < 2
	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_CONST_2 (static_cast<void>(0))
#endif // 2 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_CONST_LEVEL

#if 3 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_CONST_LEVEL
	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_CONST_3 CLASS_IS_VALID_CONST_3
#else // %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_CONST_LEVEL < 3
	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_CONST_3 (static_cast<void>(0))
#endif // 3 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_CONST_LEVEL

#if 4 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_CONST_LEVEL
	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_CONST_4 CLASS_IS_VALID_CONST_4
#else // %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_CONST_LEVEL < 4
	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_CONST_4 (static_cast<void>(0))
#endif // 4 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_CONST_LEVEL

#if 5 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_CONST_LEVEL
	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_CONST_5 CLASS_IS_VALID_CONST_5
#else // %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_CONST_LEVEL < 5
	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_CONST_5 (static_cast<void>(0))
#endif // 5 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_CONST_LEVEL

#if 6 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_CONST_LEVEL
	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_CONST_6 CLASS_IS_VALID_CONST_6
#else // %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_CONST_LEVEL < 6
	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_CONST_6 (static_cast<void>(0))
#endif // 6 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_CONST_LEVEL

#if 7 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_CONST_LEVEL
	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_CONST_7 CLASS_IS_VALID_CONST_7
#else // %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_CONST_LEVEL < 7
	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_CONST_7 (static_cast<void>(0))
#endif // 7 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_CONST_LEVEL

#if 8 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_CONST_LEVEL
	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_CONST_8 CLASS_IS_VALID_CONST_8
#else // %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_CONST_LEVEL < 8
	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_CONST_8 (static_cast<void>(0))
#endif // 8 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_CONST_LEVEL

#if 9 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_CONST_LEVEL
	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_CONST_9 CLASS_IS_VALID_CONST_9
#else // %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_CONST_LEVEL < 9
	#define %ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_CONST_9 (static_cast<void>(0))
#endif // 9 <= %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_CONST_LEVEL

#endif // %ProjectCapital%_%ManagerCapital%_MACRO_%ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_MACRO_H

CustomAssertMacro.h

// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#ifndef %ProjectCapital%_%ManagerCapital%_MACRO_%ProjectCapital%_%ManagerCapital%_CUSTOM_ASSERT_MACRO_H
#define %ProjectCapital%_%ManagerCapital%_MACRO_%ProjectCapital%_%ManagerCapital%_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"

#if 0 <= %ProjectCapital%_%ManagerCapital%_ASSERT_LEVEL

#define %ProjectCapital%_%ManagerCapital%_ASSERTION_0(condition, format, ...) \
        ASSERTION_0((condition), (format), __VA_ARGS__)
#define %ProjectCapital%_%ManagerCapital%_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition,functionDescribed,format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_0((condition),(functionDescribed),(format), __VA_ARGS__)

#else // %ProjectCapital%_%ManagerCapital%_ASSERT_LEVEL < 0

#define %ProjectCapital%_%ManagerCapital%_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
#define %ProjectCapital%_%ManagerCapital%_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition,functionDescribed,format, ...) (static_cast<void>(0))

#endif //0 <= %ProjectCapital%_%ManagerCapital%_ASSERT_LEVEL

#if 1 <= %ProjectCapital%_%ManagerCapital%_ASSERT_LEVEL

#define %ProjectCapital%_%ManagerCapital%_ASSERTION_1(condition, format, ...) \
        ASSERTION_1((condition), (format), __VA_ARGS__)
#define %ProjectCapital%_%ManagerCapital%_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition,functionDescribed,format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_1((condition),(functionDescribed),(format), __VA_ARGS__)

#else // %ProjectCapital%_%ManagerCapital%_ASSERT_LEVEL < 1

#define %ProjectCapital%_%ManagerCapital%_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
#define %ProjectCapital%_%ManagerCapital%_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition,functionDescribed,format, ...) (static_cast<void>(0))

#endif // 1 <= %ProjectCapital%_%ManagerCapital%_ASSERT_LEVEL

#if 2 <= %ProjectCapital%_%ManagerCapital%_ASSERT_LEVEL

#define %ProjectCapital%_%ManagerCapital%_ASSERTION_2(condition, format, ...) \
        ASSERTION_2((condition), (format), __VA_ARGS__)
#define %ProjectCapital%_%ManagerCapital%_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition,functionDescribed,format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_2((condition),(functionDescribed),(format), __VA_ARGS__)

#else // %ProjectCapital%_%ManagerCapital%_ASSERT_LEVEL < 2

#define %ProjectCapital%_%ManagerCapital%_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
#define %ProjectCapital%_%ManagerCapital%_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition,functionDescribed,format, ...) (static_cast<void>(0))

#endif // 2 <= %ProjectCapital%_%ManagerCapital%_ASSERT_LEVEL

#if 3 <= %ProjectCapital%_%ManagerCapital%_ASSERT_LEVEL

#define %ProjectCapital%_%ManagerCapital%_ASSERTION_3(condition, format, ...) \
        ASSERTION_3((condition), (format), __VA_ARGS__)
#define %ProjectCapital%_%ManagerCapital%_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition,functionDescribed,format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_3((condition),(functionDescribed),(format), __VA_ARGS__)

#else // %ProjectCapital%_%ManagerCapital%_ASSERT_LEVEL < 3

#define %ProjectCapital%_%ManagerCapital%_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
#define %ProjectCapital%_%ManagerCapital%_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition,functionDescribed,format, ...) (static_cast<void>(0))

#endif // 3 <= %ProjectCapital%_%ManagerCapital%_ASSERT_LEVEL

#if 4 <= %ProjectCapital%_%ManagerCapital%_ASSERT_LEVEL

#define %ProjectCapital%_%ManagerCapital%_ASSERTION_4(condition, format, ...) \
        ASSERTION_4((condition), (format), __VA_ARGS__)
#define %ProjectCapital%_%ManagerCapital%_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_4((condition),(functionDescribed),(format), __VA_ARGS__)

#else // %ProjectCapital%_%ManagerCapital%_ASSERT_LEVEL < 4

#define %ProjectCapital%_%ManagerCapital%_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
#define %ProjectCapital%_%ManagerCapital%_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition,functionDescribed,format, ...) (static_cast<void>(0))

#endif // 4 <= %ProjectCapital%_%ManagerCapital%_ASSERT_LEVEL

#endif // %ProjectCapital%_%ManagerCapital%_MACRO_%ProjectCapital%_%ManagerCapital%_CUSTOM_ASSERT_MACRO_H

MacroFwd.h

// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#ifndef %ProjectCapital%_%ManagerCapital%_MACRO_FWD_H
#define %ProjectCapital%_%ManagerCapital%_MACRO_FWD_H

#include "UserMacro.h"
#include "ExportMacro.h" 
#include "%SolutionName%%ManagerName%ClassInvariantMacro.h"
#include "%SolutionName%%ManagerName%CustomAssertMacro.h"

#endif // %ProjectCapital%_%ManagerCapital%_MACRO_FWD_H

Macro.h

// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#ifndef %ProjectCapital%_%ManagerCapital%_MACRO_H
#define %ProjectCapital%_%ManagerCapital%_MACRO_H

#include "UserMacro.h"
#include "ExportMacro.h"
#include "%SolutionName%%ManagerName%ClassInvariantMacro.h"
#include "%SolutionName%%ManagerName%CustomAssertMacro.h"

#endif // %ProjectCapital%_%ManagerCapital%_MACRO_H

UserMacro.h

// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#ifndef %ProjectCapital%_%ManagerCapital%_MACRO_USER_MACRO_H
#define %ProjectCapital%_%ManagerCapital%_MACRO_USER_MACRO_H

#include "Framework/Macro/UserMacro.h" 
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Contract/Assertion.h"

#if !defined(%ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_LEVEL)
	#define %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_LEVEL 8
#endif // %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_LEVEL

#if !defined(%ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_CONST_LEVEL)
	#define %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_CONST_LEVEL 8
#endif // %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_CONST_LEVEL

#if !defined(%ProjectCapital%_%ManagerCapital%_ASSERT_LEVEL)
	#define %ProjectCapital%_%ManagerCapital%_ASSERT_LEVEL 4
#endif // %ProjectCapital%_%ManagerCapital%_ASSERT_LEVEL

#if CLASS_INVARIANT_LEVEL < %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_LEVEL
	#error "≤ª±‰ Ωº∂±∂®“Â¥ÌŒÛ°£"
#endif // CLASS_INVARIANT_LEVEL < %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_LEVEL

#if CLASS_INVARIANT_CONST_LEVEL < %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_CONST_LEVEL
	#error "≤ª±‰ Ωº∂±∂®“Â¥ÌŒÛ°£"
#endif // CLASS_INVARIANT_CONST_LEVEL < %ProjectCapital%_%ManagerCapital%_CLASS_INVARIANT_CONST_LEVEL

#if ASSERT_LEVEL < %ProjectCapital%_%ManagerCapital%_ASSERT_LEVEL
	#error "∂œ—‘º∂±∂®“Â¥ÌŒÛ°£"
#endif // ASSERT_LEVEL < %ProjectCapital%_%ManagerCapital%_ASSERT_LEVEL
 
#endif // %ProjectCapital%_%ManagerCapital%_MACRO_USER_MACRO_H
*/
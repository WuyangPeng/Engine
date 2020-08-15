// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 11:29)

#include "CoreTools/CoreToolsExport.h"

#include "Mutex.h"
#include "System/Helper/PragmaWarning.h"

#include "CoreTools/ClassInvariant/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
CoreTools::Mutex::Mutex(MutexCreate mutexCreate) : ParentType{ mutexCreate }
{
    ParentType::Initialize();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP

CoreTools::Mutex::~Mutex()
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26447)

    EXCEPTION_TRY
    {
        ParentType::Delete();
    }
    EXCEPTION_ALL_CATCH(CoreTools)

#include STSTEM_WARNING_POP
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, Mutex)

void CoreTools::Mutex::Initialize()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CoreTools::DoNothing();
}

void CoreTools::Mutex::Delete()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CoreTools::DoNothing();
}
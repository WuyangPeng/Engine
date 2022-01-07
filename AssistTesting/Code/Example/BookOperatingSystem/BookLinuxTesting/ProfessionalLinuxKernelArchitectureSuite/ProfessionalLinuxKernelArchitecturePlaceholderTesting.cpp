///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.4 (2021/06/12 13:13)

#include "ProfessionalLinuxKernelArchitecturePlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookOperatingSystem/ProfessionalLinuxKernelArchitecture/Helper/ProfessionalLinuxKernelArchitectureClassInvariantMacro.h"

BookLinux::ProfessionalLinuxKernelArchitecture::ProfessionalLinuxKernelArchitecturePlaceholderTesting::ProfessionalLinuxKernelArchitecturePlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    PROFESSIONAL_LINUX_KERNEL_ARCHITECTURE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookLinux::ProfessionalLinuxKernelArchitecture, ProfessionalLinuxKernelArchitecturePlaceholderTesting)

void BookLinux::ProfessionalLinuxKernelArchitecture::ProfessionalLinuxKernelArchitecturePlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookLinux::ProfessionalLinuxKernelArchitecture::ProfessionalLinuxKernelArchitecturePlaceholderTesting::MainTest() noexcept
{
}

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 13:10)

#ifndef SYSTEM_SECURITY_SUITE_ACCESS_CHECK_TESTING_BASE_H
#define SYSTEM_SECURITY_SUITE_ACCESS_CHECK_TESTING_BASE_H

#include "System/FileManager/Fwd/FileFlagsFwd.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <array>
#include <vector>

namespace System
{
    class AccessCheckTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = AccessCheckTestingBase;
        using ParentType = UnitTest;

    public:
        explicit AccessCheckTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected: 
        using FileHandleDesiredAccessContainer = std::vector<FileHandleDesiredAccess>;
        using FileHandleDesiredAccessContainerConstIter = FileHandleDesiredAccessContainer::const_iterator;

    protected:
        NODISCARD FileHandleDesiredAccessContainerConstIter begin() const noexcept;
        NODISCARD FileHandleDesiredAccessContainerConstIter end() const noexcept;
        NODISCARD CharBufferType GetFileSecurityBuffer();
        void CloseTokenTest(WindowsHandle tokenHandle);
        NODISCARD WindowsHandle OpenProcessToken();
        NODISCARD WindowsHandle DuplicateToken(WindowsHandle tokenHandle);

    private:
        FileHandleDesiredAccessContainer fileHandleDesiredAccesses;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ACCESS_CHECK_TESTING_BASE_H
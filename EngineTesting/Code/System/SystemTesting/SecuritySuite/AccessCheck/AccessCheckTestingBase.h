///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/26 21:24)

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
        static constexpr auto bufferSize = 512u;
        using BufferType = std::array<char, bufferSize>;
        using FileHandleDesiredAccessContainer = std::vector<FileHandleDesiredAccess>;
        using FileHandleDesiredAccessContainerConstIter = FileHandleDesiredAccessContainer::const_iterator;

    protected:
        NODISCARD FileHandleDesiredAccessContainerConstIter begin() const noexcept;
        NODISCARD FileHandleDesiredAccessContainerConstIter end() const noexcept;
        NODISCARD BufferType GetFileSecurityBuffer();
        void CloseTokenTest(WindowsHandle tokenHandle);
        NODISCARD WindowsHandle OpenProcessToken();
        NODISCARD WindowsHandle DuplicateToken(WindowsHandle tokenHandle);

    private:
        FileHandleDesiredAccessContainer fileHandleDesiredAccesses;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ACCESS_CHECK_TESTING_BASE_H
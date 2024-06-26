/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/12 10:22)

#include "FileMappingTestingBase.h"
#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/MemoryTools/Flags/ViewOfFileFlags.h"
#include "System/MemoryTools/Flags/VirtualToolsFlags.h"
#include "System/MemoryTools/ViewOfFile.h"
#include "System/Time/DeltaTime.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/TemplateTools/MaxElement.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::FileMappingTestingBase::FileMappingTestingBase(const OStreamShared& stream)
    : ParentType{ stream },
      memoryProtects{ MemoryProtect::WriteCopy,
                      MemoryProtect::ReadOnly,
                      MemoryProtect::ReadWrite,
                      MemoryProtect::ExecuteWriteCopy,
                      MemoryProtect::ExecuteRead,
                      MemoryProtect::ExecuteReadWrite },
      fileMapProtections{ FileMapProtection::Default,
                          FileMapProtection::Commit,
                          FileMapProtection::Reserve },
      fileMapDesiredAccesses{ FileMapDesiredAccess::Write,
                              FileMapDesiredAccess::Read,
                              FileMapDesiredAccess::AllAccess,
                              FileMapDesiredAccess::Execute },
      mapping{ { MemoryProtect::WriteCopy, FileHandleDesiredAccess::ReadWrite },
               { MemoryProtect::ReadOnly, FileHandleDesiredAccess::ReadWrite },
               { MemoryProtect::ReadWrite, FileHandleDesiredAccess::ReadWrite },
               { MemoryProtect::ExecuteWriteCopy, FileHandleDesiredAccess::Read | FileHandleDesiredAccess::Execute },
               { MemoryProtect::ExecuteRead, FileHandleDesiredAccess::Read | FileHandleDesiredAccess::Execute },
               { MemoryProtect::ExecuteReadWrite, FileHandleDesiredAccess::ReadWrite | FileHandleDesiredAccess::Execute } },
      maxSize{ CoreTools::MaxElement({ memoryProtects.size(), fileMapProtections.size(), fileMapDesiredAccesses.size() }) },
      randomEngine{ GetEngineRandomSeed() }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FileMappingTestingBase)

void System::FileMappingTestingBase::RandomShuffle()
{
    SYSTEM_CLASS_IS_VALID_1;

    std::ranges::shuffle(memoryProtects, randomEngine);
    std::ranges::shuffle(fileMapProtections, randomEngine);
    std::ranges::shuffle(fileMapDesiredAccesses, randomEngine);
}

size_t System::FileMappingTestingBase::GetMaxSize() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return maxSize;
}

System::MemoryProtect System::FileMappingTestingBase::GetMemoryProtect(size_t index) const
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return memoryProtects.at(index % memoryProtects.size());
}

System::FileMapProtection System::FileMappingTestingBase::GetFileMapProtection(size_t index) const
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return fileMapProtections.at(index % fileMapProtections.size());
}

System::FileMapDesiredAccess System::FileMappingTestingBase::GetFileMapDesiredAccess(size_t index) const
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return fileMapDesiredAccesses.at(index % fileMapDesiredAccesses.size());
}

System::FileHandleDesiredAccess System::FileMappingTestingBase::GetMapping(MemoryProtect memoryProtect)
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    const auto iter = mapping.find(memoryProtect);
    ASSERT_UNEQUAL_FAILURE_THROW(iter, mapping.end(), "mapping����ʧ�ܡ�");

    return iter->second;
}

System::String System::FileMappingTestingBase::GetFileMappingName() const
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return SYSTEM_TEXT("Resource/FileMappingTesting/FileMappingTest.txt");
}

System::String System::FileMappingTestingBase::GetLoopTestFileName() const
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return SYSTEM_TEXT("FileMappingTestingFileMap") + ToString(GetTimeInSeconds()) + GetEngineeringTypesSuffix();
}

void System::FileMappingTestingBase::CloseFileTest(WindowsHandle fileHandle)
{
    SYSTEM_CLASS_IS_VALID_1;

    ASSERT_TRUE(CloseSystemFile(fileHandle));
}

void System::FileMappingTestingBase::CloseFileMappingTest(WindowsHandle fileHandle)
{
    SYSTEM_CLASS_IS_VALID_1;

    ASSERT_TRUE(CloseFileMapping(fileHandle));
}

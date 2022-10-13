///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 15:40)

#include "FileOutStreamTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/FileManager/CFileManagerHelper.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/FileOutStream.h"
#include "CoreTools/ObjectSystems/NullObject.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/Stream.h"

#include <vector>

using std::string;
using std::vector;
using namespace std::literals;

namespace CoreTools
{
    const auto gTopLevel = "Top Level"s;
    const string gThreeZeroSuffix(3, '\0');
    const string gTwoZeroSuffix(2, '\0');
    const string gOneZeroSuffix(1, '\0');

    const auto gFileName = SYSTEM_TEXT("FileOutStream.txt"s);
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, FileOutStreamTesting)

void CoreTools::FileOutStreamTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WriteNullObjectTest);
}

void CoreTools::FileOutStreamTesting::WriteNullObjectTest() noexcept
{
}

string CoreTools::FileOutStreamTesting::GetNullObjectContent(int uniqueID, const string& rttiTypeName) const
{
    string integerDescribe(8, '\0');

    string nullObjectContent;

    // RTTI 类型名
    nullObjectContent += GetAligningString(rttiTypeName);

    // UniqueID
    integerDescribe.at(0) = boost::numeric_cast<char>(uniqueID);
    nullObjectContent += integerDescribe;

    return nullObjectContent;
}

string CoreTools::FileOutStreamTesting::GetAligningString(const string& original) const
{
    string integerDescribe(4, '\0');
    string aligning;

    integerDescribe.at(0) = boost::numeric_cast<char>(original.size());
    aligning += integerDescribe + original;
    const int padding = original.size() % 4;
    switch (padding)
    {
        case 1:
            aligning += gThreeZeroSuffix;
            break;
        case 2:
            aligning += gTwoZeroSuffix;
            break;
        case 3:
            aligning += gOneZeroSuffix;
            break;
        default:
            break;
    }

    return aligning;
}

string CoreTools::FileOutStreamTesting::GetTopLevelContent() const
{
    string integerDescribe(4, '\0');

    // “Top Level”字符串
    integerDescribe.at(0) = boost::numeric_cast<char>(gTopLevel.size());
    return integerDescribe + gTopLevel + gThreeZeroSuffix;
}

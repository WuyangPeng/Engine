// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 14:28)

#include "FileOutStreamTesting.h"
#include "Detail/NullObject.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/FileManager/CFileManagerHelper.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"


#include "CoreTools/ObjectSystems/FileOutStream.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/Stream.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include <vector>

using std::string;
using std::vector;
using namespace std::literals;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
namespace CoreTools
{
    const auto g_TopLevel = "Top Level"s;
    const string g_ThreeZeroSuffix(3, '\0');
    const string g_TwoZeroSuffix(2, '\0');
    const string g_OneZeroSuffix(1, '\0');

    const auto g_FileName = SYSTEM_TEXT("FileOutStream.txt"s);
}
#include STSTEM_WARNING_POP
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, FileOutStreamTesting)

void CoreTools::FileOutStreamTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WriteNullObjectTest);
}

void CoreTools::FileOutStreamTesting ::WriteNullObjectTest() noexcept
{
}

string CoreTools::FileOutStreamTesting ::GetNullObjectContent(int uniqueID, const string& rttiTypeName) const
{
    string integerDescribe(8, '\0');

    string nullObjectContent;

    // RTTI ¿‡–Õ√˚
    nullObjectContent += GetAligningString(rttiTypeName);

    // UniqueID
    integerDescribe.at(0) = boost::numeric_cast<char>(uniqueID);
    nullObjectContent += integerDescribe;

    return nullObjectContent;
}

string CoreTools::FileOutStreamTesting ::GetAligningString(const string& original) const
{
    string integerDescribe(4, '\0');
    string aligning;

    integerDescribe.at(0) = boost::numeric_cast<char>(original.size());
    aligning += integerDescribe + original;
    const int padding = original.size() % 4;
    switch (padding)
    {
        case 1:
            aligning += g_ThreeZeroSuffix;
            break;
        case 2:
            aligning += g_TwoZeroSuffix;
            break;
        case 3:
            aligning += g_OneZeroSuffix;
            break;
        default:
            break;
    }

    return aligning;
}

string CoreTools::FileOutStreamTesting ::GetTopLevelContent() const
{
    string integerDescribe(4, '\0');

    // °∞Top Level°±◊÷∑˚¥Æ
    integerDescribe.at(0) = boost::numeric_cast<char>(g_TopLevel.size());
    return integerDescribe + g_TopLevel + g_ThreeZeroSuffix;
}

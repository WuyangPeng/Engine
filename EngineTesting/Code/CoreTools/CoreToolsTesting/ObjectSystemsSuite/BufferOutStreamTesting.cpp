// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.2.3 (2020/03/06 14:17)

#include "BufferOutStreamTesting.h"
#include "Detail/BoolObject.h"
#include "Detail/EnumObject.h"
#include "Detail/IntObject.h"
#include "Detail/NullObject.h"
#include "Detail/PointerObject.h"
#include "Detail/StringObject.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/MemoryTools/SmartPointerManager.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

using std::pair;
using std::string;
using namespace std::literals;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
namespace CoreTools
{
    const string g_TopLevel{ "Top Level"s };
    const string g_ThreeZeroSuffix(3, '\0');
    const string g_TwoZeroSuffix(2, '\0');
    const string g_OneZeroSuffix(1, '\0');
}
#include STSTEM_WARNING_POP
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, BufferOutStreamTesting)

void CoreTools::BufferOutStreamTesting ::MainTest() noexcept
{
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
string CoreTools::BufferOutStreamTesting ::GetBoolObjectContent(int uniqueID, const string& rttiTypeName) const
{
    string uniqueIDDescribe(8, '\0');
    string integerDescribe(4, '\0');
    string trueDescribe(4, '\xFF');
    string falseDescribe(4, '\0');

    string boolObjectContent;

    // RTTI 类型名
    boolObjectContent += GetAligningString(rttiTypeName);

    // UniqueID
    uniqueIDDescribe[0] = boost::numeric_cast<char>(uniqueID);
    boolObjectContent += uniqueIDDescribe;

    // WriteBool
    boolObjectContent += falseDescribe;

    // WriteBoolWithNumber
    integerDescribe[0] = 5;
    boolObjectContent += integerDescribe;

    for (auto i = 0; i < 5; ++i)
    {
        boolObjectContent += trueDescribe;
    }

    // WriteBoolWithoutNumber
    for (auto i = 0; i < 5; ++i)
    {
        boolObjectContent += falseDescribe;
    }

    return boolObjectContent;
}

string CoreTools::BufferOutStreamTesting ::GetStringObjectContent(int uniqueID, const string& rttiTypeName) const
{
    string uniqueIDDescribe(8, '\0');
    string integerDescribe(4, '\0');
    string describe1{ "FristString"s };
    string describe2{ "SecondString"s };

    string stringObjectContent;

    // RTTI 类型名
    stringObjectContent += GetAligningString(rttiTypeName);

    // UniqueID
    uniqueIDDescribe[0] = boost::numeric_cast<char>(uniqueID);
    stringObjectContent += uniqueIDDescribe;

    // WriteString
    stringObjectContent += GetAligningString(describe1);

    // WriteStringWithNumber
    integerDescribe[0] = 5;
    stringObjectContent += integerDescribe;

    for (auto i = 0; i < 5; ++i)
    {
        stringObjectContent += GetAligningString(describe2);
    }

    // WriteStringWithoutNumber
    for (auto i = 0; i < 5; ++i)
    {
        stringObjectContent += GetAligningString(describe1);
    }

    return stringObjectContent;
}

string CoreTools::BufferOutStreamTesting ::GetIntObjectContent(int uniqueID, const string& rttiTypeName) const
{
    string uniqueIDDescribe(8, '\0');
    string integerDescribe(4, '\0');
    string fiveDescribe{ integerDescribe };
    fiveDescribe[0] = 5;
    string fourDescribe{ integerDescribe };
    fourDescribe[0] = 4;

    string intObjectContent;

    // RTTI 类型名
    intObjectContent += GetAligningString(rttiTypeName);

    // UniqueID
    uniqueIDDescribe[0] = boost::numeric_cast<char>(uniqueID);
    intObjectContent += uniqueIDDescribe;

    // WriteInt
    intObjectContent += fiveDescribe;

    // WriteIntWithNumber
    integerDescribe[0] = 5;
    intObjectContent += integerDescribe;

    for (auto i = 0; i < 5; ++i)
    {
        intObjectContent += fourDescribe;
    }

    // WriteIntWithoutNumber
    for (auto i = 0; i < 5; ++i)
    {
        intObjectContent += fiveDescribe;
    }

    return intObjectContent;
}

string CoreTools::BufferOutStreamTesting ::GetEnumObjectContent(int uniqueID, const string& rttiTypeName) const
{
    string uniqueIDDescribe(8, '\0');
    string integerDescribe(4, '\0');
    string fiveDescribe{ integerDescribe };
    fiveDescribe[0] = 5;
    string tenDescribe{ integerDescribe };
    tenDescribe[0] = 10;

    string enumObjectContent;

    // RTTI 类型名
    enumObjectContent += GetAligningString(rttiTypeName);

    // UniqueID
    uniqueIDDescribe[0] = boost::numeric_cast<char>(uniqueID);
    enumObjectContent += uniqueIDDescribe;

    // WriteEnum
    enumObjectContent += fiveDescribe;

    // WriteEnumWithNumber
    integerDescribe[0] = 5;
    enumObjectContent += integerDescribe;

    for (auto i = 0; i < 5; ++i)
    {
        enumObjectContent += tenDescribe;
    }

    // WriteEnumWithoutNumber
    for (auto i = 0; i < 5; ++i)
    {
        enumObjectContent += fiveDescribe;
    }

    return enumObjectContent;
}

string CoreTools::BufferOutStreamTesting ::GetNullObjectContent(int uniqueID, const string& rttiTypeName) const
{
    string uniqueIDDescribe(8, '\0');
    string integerDescribe(4, '\0');

    string nullObjectContent;

    // RTTI 类型名
    nullObjectContent += GetAligningString(rttiTypeName);

    // UniqueID
    uniqueIDDescribe[0] = boost::numeric_cast<char>(uniqueID);
    nullObjectContent += uniqueIDDescribe;

    return nullObjectContent;
}

string CoreTools::BufferOutStreamTesting ::GetPointerObjectContent(int uniqueID, const string& rttiTypeName) const
{
    string uniqueIDDescribe(8, '\0');
    string integerDescribe(4, '\0');

    string pointerObjectContent;

    // RTTI 类型名
    pointerObjectContent += GetAligningString(rttiTypeName);

    // UniqueID
    uniqueIDDescribe[0] = boost::numeric_cast<char>(uniqueID);
    pointerObjectContent += uniqueIDDescribe;

    // SharedPtr
    // WritePointer
    uniqueIDDescribe[0] = boost::numeric_cast<char>(++uniqueID);
    pointerObjectContent += uniqueIDDescribe;

    // WritePointerWithNumber
    integerDescribe[0] = 5;
    pointerObjectContent += integerDescribe;

    for (auto i = 0; i < 5; ++i)
    {
        uniqueIDDescribe[0] = boost::numeric_cast<char>(++uniqueID);
        pointerObjectContent += uniqueIDDescribe;
    }

    // WritePointerWithoutNumber
    for (auto i = 0; i < 5; ++i)
    {
        uniqueIDDescribe[0] = boost::numeric_cast<char>(++uniqueID);
        pointerObjectContent += uniqueIDDescribe;
    }

    return pointerObjectContent;
}

string CoreTools::BufferOutStreamTesting ::GetTopLevelContent() const
{
    string integerDescribe(4, '\0');

    // “Top Level”字符串
    integerDescribe[0] = boost::numeric_cast<char>(g_TopLevel.size());
    return integerDescribe + g_TopLevel + g_ThreeZeroSuffix;
}

string CoreTools::BufferOutStreamTesting ::GetAligningString(const string& original) const
{
    string integerDescribe(4, '\0');
    string aligning;

    integerDescribe[0] = boost::numeric_cast<char>(original.size());
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

#include STSTEM_WARNING_POP
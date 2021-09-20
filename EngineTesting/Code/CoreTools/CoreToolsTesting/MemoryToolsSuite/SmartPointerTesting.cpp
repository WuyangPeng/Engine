// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 12:21)

#include "SmartPointerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MemoryTools/SmartPointer1DArrayDetail.h"
#include "CoreTools/MemoryTools/SmartPointer2DArrayDetail.h"
#include "CoreTools/MemoryTools/SmartPointer3DArrayDetail.h"
#include "CoreTools/MemoryTools/SmartPointer4DArrayDetail.h"
#include "CoreTools/MemoryTools/SmartPointerSingleDetail.h"

#include <map>
#include <string>
#include <vector>

using std::map;
using std::pair;
using std::string;
using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, SmartPointerTesting)

void CoreTools::SmartPointerTesting ::MainTest()
{
    SmartPointerManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(SingleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Array1DTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Array2DTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Array3DTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Array4DTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ManagerTest);

    SmartPointerManager::Destroy();
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26403)
#include SYSTEM_WARNING_DISABLE(26400)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26409)
void CoreTools::SmartPointerTesting ::SingleTest()
{
    auto pointer1 = NEW0 int;
    SmartPointerSingle<int> pointer2{ pointer1 };
    SmartPointerSingle<int> pointer3{ pointer2 };
    SmartPointerSingle<int> pointer4 = pointer1;

    ASSERT_EQUAL(pointer1, pointer2);
    ASSERT_THREE_EQUAL(pointer2, pointer3, pointer4);
    ASSERT_TRUE(pointer1 == pointer2);
    ASSERT_FALSE(pointer1 != pointer2);
    ASSERT_TRUE(pointer2 == pointer1);
    ASSERT_FALSE(pointer2 != pointer1);
    ASSERT_TRUE(pointer2 == pointer3);
    ASSERT_FALSE(pointer2 != pointer3);

    auto pointer5 = NEW0 int;
    pointer4 = pointer5;

    ASSERT_EQUAL(pointer4, pointer5);
    ASSERT_UNEQUAL(pointer4, pointer3);
    ASSERT_EQUAL(pointer4.GetData(), pointer5);
    ASSERT_UNEQUAL(pointer4.GetData(), pointer2);

    *pointer4 = 5;

    ASSERT_EQUAL(*pointer5, 5);

    SmartPointerSingle<int> pointer6{ nullptr };
    SmartPointerSingle<int> pointer7{ pointer6 };

    ASSERT_EQUAL(pointer6, pointer7);
    ASSERT_EQUAL_NULL_PTR(pointer6);
    ASSERT_EQUAL_NULL_PTR(pointer7);

    string* pointer8{ NEW0 string("pointer8") };
    const SmartPointerSingle<string> pointer9{ pointer8 };

    ASSERT_EQUAL(pointer9->size(), pointer8->size());
    ASSERT_EQUAL(*pointer9, *pointer8);
}

void CoreTools::SmartPointerTesting ::Array1DTest()
{
    auto pointer1 = NEW1<int>(9);
    SmartPointer1DArray<int> pointer2{ pointer1 };
    SmartPointer1DArray<int> pointer3{ pointer2 };
    SmartPointer1DArray<int> pointer4 = pointer1;

    ASSERT_EQUAL(pointer1, pointer2);
    ASSERT_THREE_EQUAL(pointer2, pointer3, pointer4);
    ASSERT_TRUE(pointer1 == pointer2);
    ASSERT_FALSE(pointer1 != pointer2);
    ASSERT_TRUE(pointer2 == pointer1);
    ASSERT_FALSE(pointer2 != pointer1);
    ASSERT_TRUE(pointer2 == pointer3);
    ASSERT_FALSE(pointer2 != pointer3);

    auto pointer5 = NEW1<int>(19);
    pointer4 = pointer5;

    ASSERT_EQUAL(pointer4, pointer5);
    ASSERT_UNEQUAL(pointer4, pointer3);
    ASSERT_EQUAL(pointer4.GetData(), pointer5);
    ASSERT_UNEQUAL(pointer4.GetData(), pointer2);

    *pointer4 = 5;

    ASSERT_EQUAL(*pointer5, 5);

    SmartPointer1DArray<int> pointer6{ nullptr };
    SmartPointer1DArray<int> pointer7{ pointer6 };

    ASSERT_EQUAL(pointer6, pointer7);
    ASSERT_EQUAL_NULL_PTR(pointer6);
    ASSERT_EQUAL_NULL_PTR(pointer7);

    string* pointer8{ NEW1<string>(5) };
    const SmartPointer1DArray<string> pointer9{ pointer8 };

    ASSERT_EQUAL(pointer9->size(), pointer8->size());
    ASSERT_EQUAL(*pointer9, *pointer8);
}

void CoreTools::SmartPointerTesting ::Array2DTest()
{
    auto pointer1 = NEW2<int>(9, 1);
    SmartPointer2DArray<int> pointer2{ pointer1 };
    SmartPointer2DArray<int> pointer3{ pointer2 };
    SmartPointer2DArray<int> pointer4 = pointer1;

    ASSERT_EQUAL(pointer1, pointer2);
    ASSERT_THREE_EQUAL(pointer2, pointer3, pointer4);
    ASSERT_TRUE(pointer1 == pointer2);
    ASSERT_FALSE(pointer1 != pointer2);
    ASSERT_TRUE(pointer2 == pointer1);
    ASSERT_FALSE(pointer2 != pointer1);
    ASSERT_TRUE(pointer2 == pointer3);
    ASSERT_FALSE(pointer2 != pointer3);

    auto pointer5 = NEW2<int>(19, 8);
    pointer4 = pointer5;

    ASSERT_EQUAL(pointer4, pointer5);
    ASSERT_UNEQUAL(pointer4, pointer3);
    ASSERT_EQUAL(pointer4.GetData(), pointer5);
    ASSERT_UNEQUAL(pointer4.GetData(), pointer2);

    **pointer4 = 5;

    ASSERT_EQUAL(**pointer5, 5);

    SmartPointer2DArray<int> pointer6{ nullptr };
    SmartPointer2DArray<int> pointer7{ pointer6 };

    ASSERT_EQUAL(pointer6, pointer7);
    ASSERT_EQUAL_NULL_PTR(pointer6);
    ASSERT_EQUAL_NULL_PTR(pointer7);

    string** pointer8 = NEW2<string>(5, 4);
    const SmartPointer2DArray<string> pointer9{ pointer8 };

    ASSERT_EQUAL(*pointer9, *pointer8);
}

void CoreTools::SmartPointerTesting ::Array3DTest()
{
    auto pointer1 = NEW3<int>(9, 1, 1);
    SmartPointer3DArray<int> pointer2{ pointer1 };
    SmartPointer3DArray<int> pointer3{ pointer2 };
    SmartPointer3DArray<int> pointer4 = pointer1;

    ASSERT_EQUAL(pointer1, pointer2);
    ASSERT_THREE_EQUAL(pointer2, pointer3, pointer4);
    ASSERT_TRUE(pointer1 == pointer2);
    ASSERT_FALSE(pointer1 != pointer2);
    ASSERT_TRUE(pointer2 == pointer1);
    ASSERT_FALSE(pointer2 != pointer1);
    ASSERT_TRUE(pointer2 == pointer3);
    ASSERT_FALSE(pointer2 != pointer3);

    auto pointer5 = NEW3<int>(19, 8, 1);
    pointer4 = pointer5;

    ASSERT_EQUAL(pointer4, pointer5);
    ASSERT_UNEQUAL(pointer4, pointer3);
    ASSERT_EQUAL(pointer4.GetData(), pointer5);
    ASSERT_UNEQUAL(pointer4.GetData(), pointer2);

    ***pointer4 = 5;

    ASSERT_EQUAL(***pointer5, 5);

    SmartPointer3DArray<int> pointer6{ nullptr };
    SmartPointer3DArray<int> pointer7{ pointer6 };

    ASSERT_EQUAL(pointer6, pointer7);
    ASSERT_EQUAL_NULL_PTR(pointer6);
    ASSERT_EQUAL_NULL_PTR(pointer7);

    auto pointer8 = NEW3<string>(5, 4, 7);
    const SmartPointer3DArray<string> pointer9{ pointer8 };

    ASSERT_EQUAL(*pointer9, *pointer8);
}

void CoreTools::SmartPointerTesting ::Array4DTest()
{
    auto pointer1 = NEW4<int>(9, 1, 1, 8);
    SmartPointer4DArray<int> pointer2{ pointer1 };
    SmartPointer4DArray<int> pointer3{ pointer2 };
    SmartPointer4DArray<int> pointer4 = pointer1;

    ASSERT_EQUAL(pointer1, pointer2);
    ASSERT_THREE_EQUAL(pointer2, pointer3, pointer4);
    ASSERT_TRUE(pointer1 == pointer2);
    ASSERT_FALSE(pointer1 != pointer2);
    ASSERT_TRUE(pointer2 == pointer1);
    ASSERT_FALSE(pointer2 != pointer1);
    ASSERT_TRUE(pointer2 == pointer3);
    ASSERT_FALSE(pointer2 != pointer3);

    auto pointer5 = NEW4<int>(19, 8, 1, 9);
    pointer4 = pointer5;

    ASSERT_EQUAL(pointer4, pointer5);
    ASSERT_UNEQUAL(pointer4, pointer3);
    ASSERT_EQUAL(pointer4.GetData(), pointer5);
    ASSERT_UNEQUAL(pointer4.GetData(), pointer2);

    ****pointer4 = 5;

    ASSERT_EQUAL(****pointer5, 5);

    SmartPointer4DArray<int> pointer6{ nullptr };
    SmartPointer4DArray<int> pointer7{ pointer6 };

    ASSERT_EQUAL(pointer6, pointer7);
    ASSERT_EQUAL_NULL_PTR(pointer6);
    ASSERT_EQUAL_NULL_PTR(pointer7);

    auto pointer8 = NEW4<string>(5, 4, 7, 8);
    const SmartPointer4DArray<string> pointer9{ pointer8 };

    ASSERT_EQUAL(*pointer9, *pointer8);
}

void CoreTools::SmartPointerTesting ::ManagerTest()
{
    auto pointer = NEW4<int>(9, 1, 1, 8);

    ASSERT_FALSE(SMART_POINTER_SINGLETON.IsSmartPointer(pointer));

    auto value = SMART_POINTER_SINGLETON.IncreaseReference(pointer);

    ASSERT_TRUE(SMART_POINTER_SINGLETON.IsSmartPointer(pointer));

    value = SMART_POINTER_SINGLETON.CopyIncreaseReference(pointer);

    value = SMART_POINTER_SINGLETON.DecreaseReference(pointer);

    ASSERT_TRUE(SMART_POINTER_SINGLETON.IsSmartPointer(pointer));

    value = SMART_POINTER_SINGLETON.DecreaseReference(pointer);

    ASSERT_FALSE(SMART_POINTER_SINGLETON.IsSmartPointer(pointer));

    DELETE4(pointer);
}

#include STSTEM_WARNING_POP
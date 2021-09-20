///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.2 (2021/04/11 13:40)

#include "CleanCppSustainableSoftwareDevelopmentChapter2TestTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h" 
#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/Chapter2/BookInventoryTest.h"
#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/Chapter2/ChessEngineTest.h"
#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/Chapter2/ComplexNumberCalculatorTest.h"
#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/Chapter2/CustomerCacheTest.h"
#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/Chapter2/HeaterControlTest.h"
#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/Chapter2/InvoiceTest.h"
#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/Chapter2/UserAccountTest.h"
#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/Helper/CleanCppSustainableSoftwareDevelopmentClassInvariantMacro.h"

BookAdvanced::CleanCppSustainableSoftwareDevelopment::CleanCppSustainableSoftwareDevelopmentChapter2TestTesting::CleanCppSustainableSoftwareDevelopmentChapter2TestTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAdvanced::CleanCppSustainableSoftwareDevelopment, CleanCppSustainableSoftwareDevelopmentChapter2TestTesting)

void BookAdvanced::CleanCppSustainableSoftwareDevelopment::CleanCppSustainableSoftwareDevelopmentChapter2TestTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAdvanced::CleanCppSustainableSoftwareDevelopment::CleanCppSustainableSoftwareDevelopmentChapter2TestTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CustomerCache);
    ASSERT_NOT_THROW_EXCEPTION_0(ComplexNumberCalculator);
    ASSERT_NOT_THROW_EXCEPTION_0(Invoice);

    ASSERT_NOT_THROW_EXCEPTION_0(UserAccount);
    ASSERT_NOT_THROW_EXCEPTION_0(ChessEngine);
    ASSERT_NOT_THROW_EXCEPTION_0(BookInventory);
}

void BookAdvanced::CleanCppSustainableSoftwareDevelopment::CleanCppSustainableSoftwareDevelopmentChapter2TestTesting::CustomerCache() noexcept
{
    CustomerCacheTest customerCacheTest{};

    customerCacheTest.CacheIsEmpty_AddElement_SizeIsOne();
    customerCacheTest.CacheContainsOneElement_RemoveElement_SizeIsZero();
}

void BookAdvanced::CleanCppSustainableSoftwareDevelopment::CleanCppSustainableSoftwareDevelopmentChapter2TestTesting::ComplexNumberCalculator() noexcept
{
    const ComplexNumberCalculatorTest complexNumberCalculatorTest{};

    complexNumberCalculatorTest.GivenTwoComplexNumbers_Add_Works();
}

void BookAdvanced::CleanCppSustainableSoftwareDevelopment::CleanCppSustainableSoftwareDevelopmentChapter2TestTesting::Invoice() noexcept
{
    const InvoiceTest invoiceTest{};

    invoiceTest.InvoiceIsReadyForAccounting_GetInvoiceDate_ReturnsToday();
}

void BookAdvanced::CleanCppSustainableSoftwareDevelopment::CleanCppSustainableSoftwareDevelopmentChapter2TestTesting::UserAccount() noexcept
{
    const UserAccountTest userAccountTest{};

    userAccountTest.CreatingNewAccountWithExistingEmailAddressThrowsException();
}

void BookAdvanced::CleanCppSustainableSoftwareDevelopment::CleanCppSustainableSoftwareDevelopmentChapter2TestTesting::ChessEngine() noexcept
{
    ChessEngineTest chessEngineTest{};

    chessEngineTest.APawnCanNotMoveBackwards();
    chessEngineTest.ACastlingIsNotAllowedIfInvolvedKingHasBeenMovedBefore();
    chessEngineTest.ACastlingIsNotAllowedIfInvolvedRookHasBeenMovedBefore();
}

void BookAdvanced::CleanCppSustainableSoftwareDevelopment::CleanCppSustainableSoftwareDevelopmentChapter2TestTesting::HeaterControl() noexcept
{
    const UserAccountTest userAccountTest{};

    userAccountTest.CreatingNewAccountWithExistingEmailAddressThrowsException();
}

void BookAdvanced::CleanCppSustainableSoftwareDevelopment::CleanCppSustainableSoftwareDevelopmentChapter2TestTesting::BookInventory() noexcept
{
    BookInventoryTest bookInventoryTest{};

    bookInventoryTest.ABookThatIsInTheInventoryCanBeBorrowedByAuthorizedPeople();
    bookInventoryTest.ABookThatIsAlreadyBorrowedCanNotBeBorrowedTwice();
}

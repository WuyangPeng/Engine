///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/04/09 21:20)

#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/CleanCppSustainableSoftwareDevelopmentExport.h"

#include "Customer.h"
#include "Customer1.h"
#include "Customer2.h"
#include "Customer3.h"
#include "Customer4.h"
#include "CustomerDAO.h"
#include "FakeDAOForTest.h"
#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/Helper/CleanCppSustainableSoftwareDevelopmentClassInvariantMacro.h"

using std::string;

CLASS_INVARIANT_STUB_DEFINE(BookAdvanced::CleanCppSustainableSoftwareDevelopment, Customer)

string BookAdvanced::CleanCppSustainableSoftwareDevelopment::Customer::Main1(const string& value) const
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CLASS_IS_VALID_CONST_9;

    Customer1 customer1{};

    customer1.SetForename(value);

    return customer1.GetForename();
}

void BookAdvanced::CleanCppSustainableSoftwareDevelopment::Customer::Main2() const
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CLASS_IS_VALID_CONST_9;

    Customer2 customer0{};
    customer0.Save();

    Customer2 customer1{ true };
    customer1.Save();

    Customer2 customer2{ true };
    customer2.Save();
}

void BookAdvanced::CleanCppSustainableSoftwareDevelopment::Customer::Main3() const noexcept
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CLASS_IS_VALID_CONST_9;

    Customer3 customer{};

    FakeDAOForTest fakeDAOForTest{};
    customer.Save(fakeDAOForTest);

    CustomerDAO customerDAO{};
    customer.Save(customerDAO);
}

void BookAdvanced::CleanCppSustainableSoftwareDevelopment::Customer::Main4() const noexcept
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CLASS_IS_VALID_CONST_9;

    FakeDAOForTest fakeDAOForTest{};
    Customer4 customer0{ fakeDAOForTest };
    customer0.Save();

    CustomerDAO customerDAO{};
    Customer4 customer1{ customerDAO };
    customer1.Save();
}

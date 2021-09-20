///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.4 (2021/05/26 17:59)

#ifndef SYSTEM_SECURITY_SUITE_H
#define SYSTEM_SECURITY_SUITE_H

#include "AccessCheck/AccessCheckTesting.h"
#include "AccessCheck/MapGenericMaskTesting.h"
#include "AddAccess/AddAccessAllowedAceTesting.h"
#include "AddAccess/AddAccessAllowedAceUseAceFlagsTesting.h"
#include "AddAccess/AddAccessAllowedObjectAceTesting.h"
#include "AddAccess/AddAccessDeniedAceTesting.h"
#include "AddAccess/AddAccessDeniedObjectAceTesting.h"
#include "AddAccess/AddAuditAccessAceTesting.h"
#include "AddAccess/AddAuditAccessObjectAceTesting.h"
#include "CreateSecurity/ConvertToAutoInheritPrivateObjectSecurityTesting.h"
#include "CreateSecurity/CreateFilePrivateObjectSecurityTesting.h"
#include "CreateSecurity/CreatePrivateObjectSecurityTesting.h"
#include "CreateSecurity/CreatePrivateObjectSecurityUseAutoInheritTesting.h"
#include "CreateSecurity/CreatePrivateObjectSecurityWithMultipleInheritanceTesting.h"
#include "CreateSecurity/FileSecurityTesting.h"
#include "CreateSecurity/KernelObjectSecurityTesting.h"
#include "CreateSecurity/SecurityAccessMaskTesting.h"
#include "CreateSecurity/SetPrivateObjectSecurityTesting.h"
#include "LookupPrivilegeTesting.h"
#include "SecurityAce/AddAccessControlEntriesTesting.h"
#include "SecurityAce/AddMandatoryAceTesting.h"
#include "SecurityAce/FindFirstFreeAccessControlEntriesTesting.h"
#include "SecurityAcl/AclInformationTesting.h"
#include "SecurityAcl/InitializeAclTesting.h"
#include "SecurityBase/AccessesGrantedTesting.h"
#include "SecurityBase/AdjustTokenTesting.h"
#include "SecurityBase/DuplicateTokenTesting.h"
#include "SecurityBase/IsSystemTokenElevatedTesting.h"
#include "SecurityBase/QuerySecurityAccessMaskTesting.h"
#include "SecurityBase/RestrictedTokenTesting.h"
#include "SecurityBase/TokenInformationTesting.h"
#include "SecurityDescriptor/InitializeSecurityDescriptorTesting.h"
#include "SecurityDescriptor/SecurityDescriptorControlTesting.h"
#include "SecurityDescriptor/SecurityDescriptorDaclTesting.h"
#include "SecurityDescriptor/SecurityDescriptorGroupTesting.h"
#include "SecurityDescriptor/SecurityDescriptorOwnerTesting.h"
#include "SecurityDescriptor/SecurityDescriptorRMControlTesting.h"
#include "SecurityDescriptor/SecurityDescriptorSaclTesting.h"
#include "SecurityDescriptor/UserObjectSecurityTesting.h"
#include "SecuritySid/CopySecurityIdentifierTesting.h"
#include "SecuritySid/GetSubAuthorityTesting.h"
#include "SecuritySid/InitializeSecurityIdentifierTesting.h"
#include "SecuritySid/WellKnownSidTesting.h"

#endif  // SYSTEM_SECURITY_SUITE_H
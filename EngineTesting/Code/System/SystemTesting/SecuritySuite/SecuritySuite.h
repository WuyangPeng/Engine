/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 13:09)

#ifndef SYSTEM_SECURITY_SUITE_H
#define SYSTEM_SECURITY_SUITE_H

#include "AccessCheck/AccessCheckByTypeResultListTesting.h"
#include "AccessCheck/AccessCheckByTypeTesting.h"
#include "AccessCheck/AccessCheckTesting.h"
#include "AccessCheck/EnlistmentMapGenericMaskTesting.h"
#include "AccessCheck/FileMapGenericMaskTesting.h"
#include "AccessCheck/MapGenericMaskTesting.h"
#include "AccessCheck/ResourceManagerMapGenericMaskTesting.h"
#include "AccessCheck/TransactionManagerMapGenericMaskTesting.h"
#include "AccessCheck/TransactionMapGenericMaskTesting.h"
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
#include "LookupPrivilege/GetLookupPrivilegeDisplayNameTesting.h"
#include "LookupPrivilege/GetLookupPrivilegeNameTesting.h"
#include "LookupPrivilege/GetLookupPrivilegeValueTesting.h"
#include "SecurityAce/AddAccessControlEntriesTesting.h"
#include "SecurityAce/AddMandatoryAceTesting.h"
#include "SecurityAce/FindFirstFreeAccessControlEntriesTesting.h"
#include "SecurityAcl/AclInformationTesting.h"
#include "SecurityAcl/InitializeAclTesting.h"
#include "SecurityBase/AccessesGrantedEnlistmentMapTesting.h"
#include "SecurityBase/AccessesGrantedFileMapTesting.h"
#include "SecurityBase/AccessesGrantedResourceManagerMapTesting.h"
#include "SecurityBase/AccessesGrantedTransactionManagerMapTesting.h"
#include "SecurityBase/AccessesGrantedTransactionMapTesting.h"
#include "SecurityBase/AdjustTokenGroupsTesting.h"
#include "SecurityBase/AdjustTokenPrivilegesTesting.h"
#include "SecurityBase/DuplicateTokenTesting.h"
#include "SecurityBase/IsSystemTokenElevatedTesting.h"
#include "SecurityBase/QuerySecurityAccessMaskTesting.h"
#include "SecurityBase/RestrictedTokenTesting.h"
#include "SecurityBase/TokenInformationTesting.h"
#include "SecurityDescriptor/InitializeSecurityDescriptorTesting.h"
#include "SecurityDescriptor/SecurityDescriptorControlTesting.h"
#include "SecurityDescriptor/SecurityDescriptorDiscretionaryAccessControlListTesting.h"
#include "SecurityDescriptor/SecurityDescriptorGroupTesting.h"
#include "SecurityDescriptor/SecurityDescriptorOwnerTesting.h"
#include "SecurityDescriptor/SecurityDescriptorResourceManagerControlTesting.h"
#include "SecurityDescriptor/SecurityDescriptorSystemAccessControlListTesting.h"
#include "SecurityDescriptor/UserObjectSecurityTesting.h"
#include "SecuritySid/AllocateAndInitializeSecurityIdentifierTesting.h"
#include "SecuritySid/CopySecurityIdentifierTesting.h"
#include "SecuritySid/GetSubAuthorityTesting.h"
#include "SecuritySid/InitializeSecurityIdentifierTesting.h"
#include "SecuritySid/WellKnownSidTesting.h"

#endif  // SYSTEM_SECURITY_SUITE_H
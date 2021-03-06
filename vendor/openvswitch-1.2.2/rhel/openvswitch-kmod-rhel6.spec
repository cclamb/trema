# Generated automatically -- do not modify!    -*- buffer-read-only: t -*-
# Spec file for Open vSwitch kernel modules on Red Hat Enterprise
# Linux 6.

# Copyright (C) 2011 Nicira Networks, Inc.
#
# Copying and distribution of this file, with or without modification,
# are permitted in any medium without royalty provided the copyright
# notice and this notice are preserved.  This file is offered as-is,
# without warranty of any kind.

Name:           openvswitch
Version:        1.2.2
Release:        1%{?dist}
Summary:        Open vSwitch kernel module

Group:          System/Kernel
License:        GPLv2
URL:            http://openvswitch.org/
Source0:        %{name}-%{version}.tar.gz
BuildRoot:      %(mktemp -ud %{_tmppath}/%{name}-%{version}-%{release}-XXXXXX)
BuildRequires:  %kernel_module_package_buildreqs

# Without this we get an empty openvswitch-debuginfo package (whose name
# conflicts with the openvswitch-debuginfo package for OVS userspace).
%undefine _enable_debug_packages

# Uncomment to build "debug" packages
#kernel_module_package default debug

# Build only for standard kernel variant(s)
%kernel_module_package default

%description
Open vSwitch Linux kernel module.

%prep

%setup

%build
for flavor in %flavors_to_build; do
	mkdir _$flavor
	(cd _$flavor && ../configure --with-linux="%{kernel_source $flavor}")
	%{__make} -C _$flavor/datapath/linux %{?_smp_mflags}
done

%install
export INSTALL_MOD_PATH=$RPM_BUILD_ROOT
export INSTALL_MOD_DIR=extra/%{name}
for flavor in %flavors_to_build ; do
         make -C %{kernel_source $flavor} modules_install \
                 M=$PWD/_$flavor/datapath/linux
done

%clean
rm -rf $RPM_BUILD_ROOT

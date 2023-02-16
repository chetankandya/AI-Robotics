# Install script for directory: /home/cheka108/TDDE05/catkin_ws/src/air_labs/air_lab1/modules/air_lab1

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/cheka108/TDDE05/catkin_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/courses/TDDE05/software/lrs-pkg/inst/lib/march/modules/air_lab1_march_factories.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/courses/TDDE05/software/lrs-pkg/inst/lib/march/modules/air_lab1_march_factories.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/courses/TDDE05/software/lrs-pkg/inst/lib/march/modules/air_lab1_march_factories.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/courses/TDDE05/software/lrs-pkg/inst/lib/march/modules/air_lab1_march_factories.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/courses/TDDE05/software/lrs-pkg/inst/lib/march/modules" TYPE SHARED_LIBRARY FILES "/home/cheka108/TDDE05/catkin_ws/devel/.private/air_lab1/lib/air_lab1_march_factories.so")
  if(EXISTS "$ENV{DESTDIR}/courses/TDDE05/software/lrs-pkg/inst/lib/march/modules/air_lab1_march_factories.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/courses/TDDE05/software/lrs-pkg/inst/lib/march/modules/air_lab1_march_factories.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/courses/TDDE05/software/lrs-pkg/inst/lib/march/modules/air_lab1_march_factories.so"
         OLD_RPATH "/courses/TDDE05/software/lrs-pkg/inst/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/bin/strip" "$ENV{DESTDIR}/courses/TDDE05/software/lrs-pkg/inst/lib/march/modules/air_lab1_march_factories.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()


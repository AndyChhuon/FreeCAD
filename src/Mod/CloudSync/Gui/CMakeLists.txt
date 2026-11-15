# SPDX-License-Identifier: LGPL-2.1-or-later

include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_CURRENT_BINARY_DIR}
)

set(CloudSyncGui_LIBS
    CloudSync
    FreeCADGui
)

qt_add_resources(CloudSync_QRC_SRCS
    Resources/CloudSync.qrc
    OPTIONS ${FREECAD_RCC_OPTIONS}
)

SET(CloudSyncGui_SRCS
    ${CloudSync_QRC_SRCS}
    AppCloudSyncGui.cpp
    Command.cpp
    PreCompiled.h
    Workbench.cpp
    Workbench.h
)

add_library(CloudSyncGui SHARED ${CloudSyncGui_SRCS})
target_link_libraries(CloudSyncGui ${CloudSyncGui_LIBS})

SET_BIN_DIR(CloudSyncGui)
SET_PYTHON_PREFIX_SUFFIX(CloudSyncGui)

install(TARGETS CloudSyncGui DESTINATION ${CMAKE_INSTALL_LIBDIR})

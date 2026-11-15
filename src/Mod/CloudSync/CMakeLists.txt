# SPDX-License-Identifier: LGPL-2.1-or-later

add_subdirectory(App)
if(BUILD_GUI)
    add_subdirectory(Gui)
endif(BUILD_GUI)

set(CloudSync_Scripts
    Init.py
)

if(BUILD_GUI)
    list (APPEND CloudSync_Scripts InitGui.py)
endif(BUILD_GUI)

add_custom_target(CloudSyncScripts ALL
    SOURCES ${CloudSync_Scripts}
)

fc_target_copy_resource_flat(CloudSyncScripts
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}/Mod/CloudSync
    ${CloudSync_Scripts}
)

install(
    FILES
        ${CloudSync_Scripts}
    DESTINATION
        Mod/CloudSync
)

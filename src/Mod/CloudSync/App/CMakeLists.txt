# SPDX-License-Identifier: LGPL-2.1-or-later

set(CloudSync_LIBS
    FreeCADApp
)

SET(CloudSync_SRCS
    AppCloudSync.cpp
    PreCompiled.h
)

add_library(CloudSync SHARED ${CloudSync_SRCS})
target_link_libraries(CloudSync ${CloudSync_LIBS})


SET_BIN_DIR(CloudSync)
SET_PYTHON_PREFIX_SUFFIX(CloudSync)

install(TARGETS CloudSync DESTINATION ${CMAKE_INSTALL_LIBDIR})

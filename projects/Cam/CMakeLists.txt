#--------------------------------------------------------------------------
# Cam project
#--------------------------------------------------------------------------

PROJECT(Cam)
FILE(GLOB Cam_headers code/*.h)
FILE(GLOB Cam_sources code/*.cc)

SET(files_Cam ${Cam_headers} ${Cam_sources})
SOURCE_GROUP("Cam" FILES ${files_Cam})

ADD_LIBRARY(Cam STATIC ${files_Cam})
TARGET_LINK_LIBRARIES(Cam core render Matlibrary)
ADD_DEPENDENCIES(Cam core render Matlibrary)

TARGET_INCLUDE_DIRECTORIES(Cam INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/code/)
#--------------------------------------------------------------------------
# ObjLoader project
#--------------------------------------------------------------------------

PROJECT(ObjLoader)
FILE(GLOB ObjLoader_headers code/*.h)
FILE(GLOB ObjLoader_sources code/*.cc)

SET(files_ObjLoader ${ObjLoader_headers} ${ObjLoader_sources})
SOURCE_GROUP("ObjLoader" FILES ${files_ObjLoader})

ADD_LIBRARY(ObjLoader STATIC ${files_ObjLoader})
TARGET_LINK_LIBRARIES(ObjLoader core render Matlibrary)
ADD_DEPENDENCIES(ObjLoader core render Matlibrary)

TARGET_INCLUDE_DIRECTORIES(ObjLoader INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/code/)
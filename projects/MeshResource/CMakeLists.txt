#--------------------------------------------------------------------------
# MeshResource project
#--------------------------------------------------------------------------

PROJECT(MeshResource)
FILE(GLOB MeshResource_headers code/*.h)
FILE(GLOB MeshResource_sources code/*.cc)

SET(files_MeshResource ${MeshResource_headers} ${MeshResource_sources})
SOURCE_GROUP("MeshResource" FILES ${files_MeshResource})

ADD_LIBRARY(MeshResource STATIC ${files_MeshResource})
TARGET_LINK_LIBRARIES(MeshResource core render Matlibrary)
ADD_DEPENDENCIES(MeshResource core render Matlibrary)

TARGET_INCLUDE_DIRECTORIES(MeshResource INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/code/)